/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimadela <nimadela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:00:30 by nimadela          #+#    #+#             */
/*   Updated: 2024/11/13 14:00:15 by nimadela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	c1;

	if (n > 0)
	{
		str = (unsigned char *) s;
		while (n > 0)
		{
			c1 = (unsigned char) c;
			if (*str == c1)
				return (str);
			n--;
			str++;
		}
	}
	return (NULL);
}
