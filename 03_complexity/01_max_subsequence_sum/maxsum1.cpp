template <typename T>
int maxsum1(T const &a) {
	int maxSum = 0;
	for (size_t i=0; i<a.size(); ++i) // set begin
		for (size_t j=i; j<a.size(); ++j) { // set end
			int sum = 0;
			for (size_t k=i; k<=j; ++k) // sum values from begin to end
				sum += a[k];

			if (sum > maxSum)
				maxSum = sum;
		}
	return maxSum;
}

