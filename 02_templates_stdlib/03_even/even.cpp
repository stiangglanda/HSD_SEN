#include <iterator>
#include <fstream>
#include <algorithm>
#include <iostream>

bool even(int const &x) {
	return x % 2 == 0;
}

int main() {
	std::ifstream file{"input"};
	
	std::cout << std::count_if(std::istream_iterator<int>{file}, std::istream_iterator<int>{}, even) << '\n';
	
	return 0;
}

