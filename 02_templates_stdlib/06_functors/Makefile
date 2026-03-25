TARGETS=functors lambda

all: $(TARGETS)

%: %.cpp
	g++ -Wall $< -g -std=c++11 -o $@

.PHONY: clean
clean:
	rm -fr $(TARGETS)
