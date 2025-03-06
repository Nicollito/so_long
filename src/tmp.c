/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimadela <nimadela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 16:20:14 by nimadela          #+#    #+#             */
/*   Updated: 2025/03/06 11:19:52 by nimadela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include <stdio.h>

static int	count_malloc = 0;

void	print_matrix(char **mat)
{
	int	i;

	i = 0;
	while (mat[i])
	{
		printf("%s", mat[i]);
		i++;
	}
	printf("\n");
}

void	*malloc_breaker(size_t size)
{
	if (--count_malloc == 0)
		return (NULL);
	return ((malloc)(size));
}
