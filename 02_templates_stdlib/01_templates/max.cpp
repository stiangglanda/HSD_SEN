#include <iostream>

template <typename T>
T max(T const &a, T const &b) {
        return (a>b) ? a : b;
}

int main() {
	std::cout << max(10, 20) << "\n";     // 20
	std::cout << max('a', 'b') << "\n";   // b
	std::cout << max(1.3, 1.7) << "\n";   // 1.7
	
	// error: no matching function for call to ‘max(int, double)’
	//std::cout << max(1, 1.7) << "\n";
	std::cout << max<double>(1, 1.7) << "\n";	// 1.7
	std::cout << max<int>(1, 1.7) << "\n"; 	// 1

	// error: no matching function for call to 'max(const char [2], const char [2])'
	//std::cout << max<int>("a", "b") << "\n";

	return 0;
}

