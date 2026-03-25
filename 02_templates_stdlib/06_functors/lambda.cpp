#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

int main() {
	std::vector<int> v = {1, 5, 7};
	
	int sum = 0;
	std::for_each(begin(v), end(v), [&sum](int x) { sum += x; });
	std::cout << sum << "\n";

	std::transform(begin(v), end(v), begin(v), [](int x) -> int { return x+1; });
	std::copy(begin(v), end(v), std::ostream_iterator<int>{std::cout, " "});
	std::cout << "\n";

	return 0;
}

