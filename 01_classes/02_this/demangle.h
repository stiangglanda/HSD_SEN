// Warning: This will only work on recent versions of gcc, and certainly
// NOT on MSVC or other compilers.

#ifndef DEMANGLE_H
#define DEMANGLE_H

#include <cxxabi.h>
#include <stdlib.h>

std::string dem(char const *x) {
	char *s = abi::__cxa_demangle(x, 0, 0, 0);
	std::string ret(s);
	free(s);
	return ret;
}

#endif /* DEMANGLE_H */

