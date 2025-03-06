/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimadela <nimadela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:59:46 by nimadela          #+#    #+#             */
/*   Updated: 2024/11/14 10:13:02 by nimadela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;

	i = 0;
	c = (unsigned char) c;
	while (s[i])
	{
		if ((unsigned char)s[i] == c)
			return (&((char *)s)[i]);
		i++;
	}
	if (c == '\0')
		return (&((char *)s)[i]);
	return (NULL);
}
