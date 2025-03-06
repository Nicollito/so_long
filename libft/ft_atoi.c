/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimadela <nimadela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 10:53:30 by nimadela          #+#    #+#             */
/*   Updated: 2024/11/15 15:07:20 by nimadela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int					sign;
	unsigned long long	res;

	sign = 1;
	res = 0;
	while (*nptr && ((*nptr >= 9 && *nptr <= 13) || *nptr == 32))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign *= -1;
		nptr++;
	}
	while (*nptr && (*nptr >= '0' && *nptr <= '9'))
	{
		res = res * 10 + (*nptr++ - '0');
		if (res > __LONG_LONG_MAX__ && sign < 0)
			return (0);
		if (res > __LONG_LONG_MAX__)
			return (-1);
	}
	return (((int)res) * sign);
}
