/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimadela <nimadela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:25:08 by nimadela          #+#    #+#             */
/*   Updated: 2024/11/08 15:30:17 by nimadela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
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
	printf("%d\n", isprint(c));
	printf("%d\n", ft_isprint(c));
	return (0);
} */