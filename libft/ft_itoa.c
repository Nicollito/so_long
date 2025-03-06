/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimadela <nimadela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:20:17 by nimadela          #+#    #+#             */
/*   Updated: 2024/11/20 10:56:51 by nimadela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	int_len(long n)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n / 10 != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		i;
	long	n2;
	int		size;
	char	*res;

	i = 0;
	n2 = (long)n;
	size = int_len(n2);
	res = ft_calloc(size + 1, sizeof(char));
	if (!res)
		return (NULL);
	if (n2 < 0)
	{
		res[0] = '-';
		n2 *= -1;
		i = 1;
	}
	while (size-- > i)
	{
		res[size] = (n2 % 10) + '0';
		n2 /= 10;
	}
	return (res);
}
