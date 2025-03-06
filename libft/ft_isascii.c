/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimadela <nimadela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:16:20 by nimadela          #+#    #+#             */
/*   Updated: 2024/11/08 15:23:15 by nimadela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
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
	printf("%d\n", isascii(c));
	printf("%d\n", ft_isascii(c));
	return (0);
} */