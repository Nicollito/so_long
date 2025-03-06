/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimadela <nimadela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 13:55:38 by nimadela          #+#    #+#             */
/*   Updated: 2024/11/08 14:05:44 by nimadela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
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
	printf("%d\n", isdigit(c));
	printf("%d\n", ft_isdigit(c));
	return (0);
} */