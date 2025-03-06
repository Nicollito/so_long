/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimadela <nimadela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 11:55:56 by nimadela          #+#    #+#             */
/*   Updated: 2024/11/14 15:54:42 by nimadela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	if (dest == (void *)0 && src == (void *)0)
		return (dest);
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	{
		while (n--)
		{
			*d++ = *s++;
		}
	}
	return (dest);
}
/* #include <stdio.h>
#include <string.h>

int	main(void)
{
	char	dest[] = "0000000000\0";
	char	dest2[] = "0000000000\0";
	char	src[] = "Yo la team\0";
	char	src2[] = "Yo la team\0";

	printf("Ma fonction :\n");
	printf("Before: %s\n", dest);
	ft_memcpy(dest, src, 3);
	printf("After: %s\n", dest);

	printf("Vrai fonction :\n");
	printf("Before: %s\n", dest2);
	memcpy(dest2, src2, 3);
	printf("After: %s\n", dest2);
	return (0);
} */