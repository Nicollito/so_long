/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimadela <nimadela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:25:04 by nimadela          #+#    #+#             */
/*   Updated: 2024/11/21 14:51:38 by nimadela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	char	*res;

	if (!s1)
		return ((char *)s2);
	if (!s2)
		return ((char *)s1);
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	res = str;
	while (*s1)
		*str++ = *s1++;
	while (*s2)
		*str++ = *s2++;
	*str = '\0';
	return (res);
}
/* #include <stdio.h>
#include <string.h>
int    main(void)
{

    char *result_ft;

    char *s1 = NULL;
    char *s2 = NULL;

    result_ft = ft_strjoin(s1, s2);
    if (!result_ft)
        printf("ft_strjoin retourne NULL comme attendu ✅\n");
    else
    {
        printf("ft_strjoin ne retourne pas NULL ❌\n");
        //free(result_ft);
    }
	return (0);
} */