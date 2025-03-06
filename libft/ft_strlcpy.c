/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimadela <nimadela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:54:23 by nimadela          #+#    #+#             */
/*   Updated: 2024/11/14 10:05:18 by nimadela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned int	i;

	i = 0;
	if (size > 0)
	{
		while (src && src[i] && (i < size - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (src[i])
		i++;
	return (i);
}
/* #include <stdio.h>
#include <bsd/string.h>

int	main(void)
{
	char	src[] = "yo la team !\0";
	char	dst[] = "fffffffffffffffff";
	char	src2[] = "yo la team !\0";
	char	dst2[] = "fffffffffffffffff";

	printf("Ma fonction :\n Before :%s\n", dst);
	printf("return : %i\n", ft_strlcpy(dst, src, 5));
	printf("After : %s\n\n", dst);
	printf("Vrai fonction :\n Before :%s\n", dst2);
	printf("return : %zu\n", strlcpy(dst2, src2, 5));
	printf("After : %s\n\n", dst2);
	return (0);
} */