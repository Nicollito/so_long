/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimadela <nimadela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:53:50 by nimadela          #+#    #+#             */
/*   Updated: 2024/11/25 17:49:33 by nimadela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (d == s || n == 0)
		return (dest);
	if (s < d)
	{
		d += n;
		s += n;
		while (n > 0)
		{
			*(--d) = *(--s);
			n--;
		}
		return (dest);
	}
	return (ft_memcpy(d, s, n));
}
/* #include <stdio.h>
#include <string.h>

int	main(void)
{
	char	tab[] = "123456789";
	char	tab2[] = "123456789";

	printf("Ma fonction:\n Before: %s\n", tab);
	ft_memmove(tab + 8, tab, 1);
	printf(" After: %s\n\n", tab);

	printf("Vrai fonction:\n Before: %s\n", tab2);
	memmove(tab2 + 8, tab2, 1);
	printf(" After: %s\n", tab2);
} */