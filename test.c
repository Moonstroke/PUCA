#include <stdio.h> /* for printf, puts */
#include <stdlib.h> /* for exit, EXIT_FAILURE, malloc, free */

#include "funcattrs.h"
#include "varattrs.h"


CONSTEXPR int return73(void) {
	return 73;
}


INLINE void print_int(int i) {
	printf("%d", i);
}

NODISCARD int important_value(void) {
	puts("This function returns a very important value.");
	return 42;
}

NORETURN void die(void) {
	exit(EXIT_FAILURE);
}

HOTSPOT int hot_function(unsigned int u) {
	printf("Iteration %u of the hot function.\n", u);
	return u - return73();
}

MALLOC void *allocate(size_t n) {
	char *p = malloc(n);
	if(p) {
		for(size_t i = 0; i < n; ++i) {
			p[i] = (i % 26) + 'a';
		}
	}
	return p;
}

// TODO

int main(void) {
	// TODO
}


#include "end_funcattrs.h"
#include "end_varattrs.h"
