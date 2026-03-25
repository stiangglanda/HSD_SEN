#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

template <typename T>
class sum {
public:
	T val = 0;
	
	void operator()(T const &x) {
		val += x;
	}
};

int main() {
	std::vector<int> v = {1, 5, 7};
	sum<int> s;
	
	s = for_each(begin(v), end(v), s);
	std::cout << s.val << "\n";
	
	s = for_each(begin(v), end(v), s);
	std::cout << s.val << "\n";
	
	s.val = 0;
	s = for_each(begin(v), end(v), s);
	std::cout << s.val << "\n";
	
	return 0;
}

