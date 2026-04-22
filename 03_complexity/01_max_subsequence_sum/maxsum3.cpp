inline int max(int const a, int const b) {
	return (a>b) ? a : b;
}

template <typename T>
int maxsub(T const &a, int left, int right) {
	if (left == right)
		return max(a[left], 0);

	int const middle = (left+right)/2;
	int const max_l = maxsub(a, left, middle);
	int const max_r = maxsub(a, middle+1, right);

	int maxpostfix = 0;
	for (int i=left; i<=middle; ++i)
		maxpostfix = max(0, maxpostfix + a[i]);

	int maxprefix = 0;
	for (int i=right; i>middle; --i)
		maxprefix = max(0, maxprefix + a[i]);

	return max(max(max_l, max_r), maxprefix + maxpostfix);
}

template <typename T>
int maxsum3(T const &a) {
	return maxsub(a, 0, a.size()-1);
}

