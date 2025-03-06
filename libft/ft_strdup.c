/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimadela <nimadela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:08:56 by nimadela          #+#    #+#             */
/*   Updated: 2024/11/15 16:08:33 by nimadela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	s1len;

	s1len = ft_strlen(s1);
	s2 = malloc(sizeof(char) * s1len + 1);
	if (s2 == NULL)
		return (NULL);
	ft_strlcpy(s2, s1, s1len + 1);
	return (s2);
}
