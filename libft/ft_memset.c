/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimadela <nimadela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 09:35:35 by nimadela          #+#    #+#             */
/*   Updated: 2024/11/11 15:08:09 by nimadela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int c, size_t count)
{
	unsigned int	i;
	unsigned char	*ptr;

	ptr = dest;
	i = 0;
	while (i < count)
	{
		ptr[i] = c;
		i++;
	}
	return (dest);
}
/* #include <string.h>
#include <stdio.h>

int	main(void)
{
	char tab[] = "Yo la team\0";
	char tab2[] = "Yo la team\0";

	printf("Ma fonction :\n");
	printf("Before: %s\n", tab);
	ft_memset(tab, 'O', 5);
	printf("After: %s\n", tab);

	printf("Vrai fonction :\n");
	printf("Before: %s\n", tab2);
	memset(tab2, 'O', 5);
	printf("After: %s\n", tab2);
	return (0);
} */