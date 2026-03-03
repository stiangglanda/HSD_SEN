#include <algorithm>

class correct_array {
	int size;
	double *data;
public:
	explicit correct_array(int size_) : 
		size{size_}, data{new double[size]} {}

	correct_array(correct_array const &o) :
		size{o.size}, data{new double[size]} {
		std::copy(o.data, o.data+size, data);
	}

	correct_array &operator=(correct_array const &o) {
		if (this != &o) {
			delete[] data;
			size = o.size;
			data = new double[size];
			std::copy(o.data, o.data+size, data);
		}
		return *this;
	}

	~correct_array() {
		delete[] data;
	}
};

int main() {
	correct_array a{1000};
	correct_array b{50};
	a = a;
	a = b;

	return 0;
}

