all: even even_ranges

even: even.cpp
	g++ -g -Wall -pedantic $< -o $@

even_ranges: even_ranges.cpp
	g++ -g -Wall -pedantic -std=c++20 $< -o $@

.PHONY: clean
clean:
	rm -fr even even_ranges
