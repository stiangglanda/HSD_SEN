all: max_subsequence_sum max_subsequence_sum_timing

max_subsequence_sum: max_subsequence_sum.cpp
	g++ -Wall -std=c++17 -pedantic $^ -fsanitize=undefined -fsanitize=address -g -o $@

max_subsequence_sum_timing: max_subsequence_sum_timing.cpp
	g++ -Wall -std=c++17 -pedantic $^ -fsanitize=undefined -fsanitize=address -O3 -o $@

max_subsequence_sum_timing.dat: max_subsequence_sum_timing
	./max_subsequence_sum_timing | tee $@

clean:
	rm -fr max_subsequence_sum max_subsequence_sum_timing

distclean: clean
	rm -fr max_subsequence_sum_timing.dat
