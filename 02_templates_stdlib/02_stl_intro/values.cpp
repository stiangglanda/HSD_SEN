#include <vector>
#include <iterator>
#include <fstream>
#include <algorithm>
#include <iostream>
#include <numeric>

int main() {
	std::ifstream file{"input"};
	std::vector<int> v;
	
	std::copy(std::istream_iterator<int>{file}, std::istream_iterator<int>{}, std::back_inserter(v));
	
	std::sort(begin(v), end(v));
	
	std::cout << "min: " << v.front() << '\n';
	std::cout << "med: " << *(begin(v) + v.size()/2) << '\n';
	std::cout << "max: " << v.back() << '\n';
	std::cout << "avg: " << accumulate(begin(v), end(v), 0.0) / v.size() << '\n';
	
	return 0;
}

