all: print_even_squared print_even_squared_ranges

print_even_squared: print_even_squared.cpp
	g++ -g -Wall -pedantic $< -o $@

print_even_squared_ranges: print_even_squared_ranges.cpp
	g++ -g -Wall -pedantic -std=c++20 $< -o $@

.PHONY: clean
clean:
	rm -fr print_even_squared print_even_squared_ranges
