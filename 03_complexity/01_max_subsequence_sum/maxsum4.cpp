template <typename T>
int maxsum4(T const &a) {
	int maxSum = 0;
	int currsum = 0;
	for (size_t i=0; i<a.size(); ++i) {
		currsum = currsum + a[i];
		if (currsum < 0)
			currsum = 0;
		if (maxSum < currsum)
			maxSum = currsum;
	}
	return maxSum;
}

