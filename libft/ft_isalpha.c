/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimadela <nimadela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 09:47:10 by nimadela          #+#    #+#             */
/*   Updated: 2024/11/12 12:37:07 by nimadela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}
/* #include <stdio.h>
#include <ctype.h>

int	main(int ac, char **av)
{
	int	c;

	c = *av[1];
	if (ac != 2)
	{
		printf("NOP\n");
		return (0);
	}
	printf("%d\n", isalpha(c));
	printf("%d\n", ft_isalpha(c));
	return (0);
} */