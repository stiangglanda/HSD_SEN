#include <fstream>
#include <algorithm>
#include <iostream>
#include <ranges>

bool even(int const &x) {
	return x % 2 == 0;
}

int main() {
	std::ifstream file{"input"};
	
	std::cout << std::ranges::count_if(std::ranges::istream_view<int>{file}, even) << '\n';
	
	return 0;
}

