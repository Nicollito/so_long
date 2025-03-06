/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimadela <nimadela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:53:59 by nimadela          #+#    #+#             */
/*   Updated: 2024/11/15 19:53:46 by nimadela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_checkset(char const *set, char c)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	len;
	char			*str;
	char			*res;

	len = 0;
	while (ft_checkset(set, *s1))
		s1++;
	while (s1[len])
		len++;
	while (len > 0 && ft_checkset(set, s1[len - 1]))
		len--;
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	res = str;
	while (len--)
		*str++ = *s1++;
	*str = '\0';
	return (res);
}
