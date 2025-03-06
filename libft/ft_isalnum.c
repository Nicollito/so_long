/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimadela <nimadela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:11:54 by nimadela          #+#    #+#             */
/*   Updated: 2024/11/14 13:11:32 by nimadela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int c)
{
	return ((c >= '0' && c <= '9')
		|| (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
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
	printf("%d\n", isalnum(c));
	printf("%d\n", ft_isalnum(c));
	return (0);
} */