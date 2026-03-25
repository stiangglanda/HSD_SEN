#include <iostream>
#include <string>

template <typename T>
class array {
public:
	void print() {
		for (int i=0; i<size; ++i) {
			std::cout << values[i] << " ";
		}
	}
	
	T &operator[](int idx) {
		return values[idx];
	}

private:
	static constexpr int size = 3;
	T values[size] = {};
};

int main() {
	array<int> a1;
	array<std::string> a2;

	a1[0] = 7;
	a1[1] = 4;
	a1[2] = 10;
	a1.print();

	a2[0] = "hello";
	a2[1] = "world";
	a2[2] = "!";
	a2.print();

	return 0;
}

