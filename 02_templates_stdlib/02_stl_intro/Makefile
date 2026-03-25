all: values values_ranges

values: values.cpp
	g++ -g -Wall -pedantic $< -o $@

values_ranges: values_ranges.cpp
	g++ -g -Wall -pedantic -std=c++20 $< -o $@

.PHONY: clean
clean:
	rm -fr values values_ranges
