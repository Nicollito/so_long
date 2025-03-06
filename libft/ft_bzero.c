/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimadela <nimadela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 11:12:16 by nimadela          #+#    #+#             */
/*   Updated: 2024/11/11 15:07:30 by nimadela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;
	unsigned int	i;

	ptr = s;
	i = 0;
	while (i < n)
	{
		ptr[i] = '\0';
		i++;
	}
}
/* #include <string.h>
#include <stdio.h>

int	main(void)
{
	char tab[] = "Yo la team\0";
	char tab2[] = "Yo la team\0";

	printf("Ma fonction :\n");
	printf("Before: %s\n", tab);
	ft_bzero(tab, 5);
	printf("After: %s\n", tab);

	printf("Vrai fonction :\n");
	printf("Before: %s\n", tab2);
	bzero(tab2, 5);
	printf("After: %s\n", tab2);
	return (0);
} */