#ifndef TMP_H
#define TMP_H

# include "so_long.h"

void	print_matrix(char **mat);
void	*malloc_breaker(size_t size);
void	open_window();
void	affiche_perso();
void	test(void *win, void *mlx);

# define malloc(x) malloc_breaker(x)

#endif