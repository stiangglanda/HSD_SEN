TARGETS=max array

all: $(TARGETS)

%: %.cpp
	g++ -Wall $< -g -o $@

.PHONY: clean
clean:
	rm -fr $(TARGETS)

