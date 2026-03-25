all: print_even print_even_ranges

print_even: print_even.cpp
	g++ -g -Wall -pedantic -std=c++11 $< -o $@

print_even_ranges: print_even_ranges.cpp
	g++ -g -Wall -pedantic -std=c++20 $< -o $@

.PHONY: clean
clean:
	rm -fr print_even print_even_ranges
