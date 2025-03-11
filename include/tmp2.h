#ifndef TMP2_H
#define TMP2_H

# include <stdlib.h>

void	*malloc_breaker(size_t size);

# define malloc(x) malloc_breaker(x)

#endif