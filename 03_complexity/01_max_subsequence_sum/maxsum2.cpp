template <typename T>
int maxsum2(T const &a) {
	int maxSum = 0;
	for (size_t i=0; i<a.size(); ++i) { // set begin
		int sum = 0;
		for (size_t j=i; j<a.size(); ++j) { // set end
			sum += a[j]; // sum only next element

			if (sum > maxSum)
				maxSum = sum;
		}
	}
	return maxSum;
}

