#include <algorithm>
#include <chrono>
#include <iomanip>
#include <iostream>
#include <optional>
#include <random>
#include <vector>
#include <functional>
#include "gsl/gsl-lite.hpp"

#include "maxsum1.cpp"
#include "maxsum2.cpp"
#include "maxsum3.cpp"
#include "maxsum4.cpp"


template <typename F, typename T>
std::pair<double, int> time(F f, T const &a) {
	auto const start = std::chrono::high_resolution_clock::now();
	int const ret = f(a);
	auto const elapsed = std::chrono::high_resolution_clock::now() - start;
	double const seconds = std::chrono::duration<double>(elapsed).count();
	return {seconds, ret};
}


template <typename T>
void check_results(T const &results) {
	std::optional<int> reference;
	for (auto &&res : results) {
		if (!reference) {
			reference = res;
			continue;
		}

		if (res && *reference != *res) {
			throw std::logic_error("Incorrect sums!");
		}
	}
}


constexpr int REPETITIONS = 3;

class test_func_t {
	using func_t = std::function<int(gsl::span<int>)>;
	func_t func;
	double const max_time;
	double last_time = 0;
public:
	test_func_t(func_t func_, double max_time_) : func{func_}, max_time{max_time_} {}

	template <typename T>
	std::optional<int> operator()(T const &a) {
		using std::cout;
		cout << std::setw(7);
		if (last_time < max_time) {
			std::array<std::pair<double, int>, REPETITIONS> results;
			std::generate(begin(results), end(results), [this, &a](){ return time(func, a); });
			last_time = std::min_element(begin(results), end(results), [](auto const &x, auto const &y) { return x.first < y.first; })->first;
			cout << std::setprecision(3) << std::fixed << last_time;
			cout.flush();
			return {results[0].second};
		} else {
			cout << "nan";
			cout.flush();
			return {};
		}
	}
};


void test(size_t maxNumOfValues, int high) {
	using std::cout;
	size_t numOfValues = 100;

	std::mt19937 rng;
	std::uniform_int_distribution<int> uni {-high/2, high/2};
	std::vector<int> memory(maxNumOfValues);
	std::generate(begin(memory), end(memory), [&uni, &rng](){ return uni(rng); });
	test_func_t t1{maxsum1<gsl::span<int>>, 5};
	test_func_t t2{maxsum2<gsl::span<int>>, 5};
	test_func_t t3{maxsum3<gsl::span<int>>, 5};
	test_func_t t4{maxsum4<gsl::span<int>>, 5};

	while (numOfValues <= maxNumOfValues) {
		auto a{gsl::span{memory.data(), numOfValues}};

		cout << std::setw(12) << numOfValues;
		cout.flush();
		std::vector<std::optional<int>> results = {t1(a), t2(a), t3(a), t4(a)};
		cout << "\n";

		check_results(results);

		if (std::none_of(begin(results), end(results), [](std::optional<int>& x){
					return x.has_value();
					}
				))
			return;

		numOfValues *= 1.1;
	}
}

int main() {
	test(400'000'000, 1000);
	return 0;
}
