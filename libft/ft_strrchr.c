/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimadela <nimadela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:56:21 by nimadela          #+#    #+#             */
/*   Updated: 2024/11/14 16:17:12 by nimadela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;
	int				j;

	i = 0;
	j = -1;
	s = (char *)s;
	c = (char)c;
	while (s[i])
	{
		if (s[i] == c)
			j = i;
		i++;
	}
	if (s[i] == c)
		j = i;
	if (j == -1)
		return (NULL);
	return (&((char *)s)[j]);
}
