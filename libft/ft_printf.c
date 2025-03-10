/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimadela <nimadela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:46:39 by nimadela          #+#    #+#             */
/*   Updated: 2024/12/10 10:16:10 by nimadela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putstr(const char *str)
{
	if (!str)
		return ((int)write(1, "(null)", 6));
	return ((int)write(1, str, ft_strlen(str)));
}

static int	ft_putnbr_base(long int nbr, char *base)
{
	int	bsize;
	int	len;

	bsize = (int)ft_strlen(base);
	len = 0;
	if (nbr < 0 && bsize == 10)
	{
		len += ft_putstr("-");
		nbr *= -1;
	}
	if (nbr / bsize != 0)
		len += ft_putnbr_base(nbr / bsize, base);
	len += (int)write(1, &base[nbr % bsize], 1);
	return (len);
}

static int	ft_putnbr_base_ptr(unsigned long int nbr, char *base)
{
	int	bsize;
	int	len;

	if (nbr == 0)
		return (write(1, "(nil)", 5));
	len = 0;
	len += ft_putstr("0x");
	bsize = (int)ft_strlen(base);
	if (nbr < 0 && bsize == 10)
	{
		len += ft_putstr("-");
		nbr *= -1;
	}
	if (nbr / bsize != 0)
		len += ft_putnbr_base(nbr / bsize, base);
	len += (int)write(1, &base[nbr % bsize], 1);
	return (len);
}

static int	sort_format(const char format, va_list ap)
{
	int	len;

	len = 0;
	if (format == 'c')
		len += write(1, &(char){(char)va_arg(ap, int)}, 1);
	else if (format == 's')
		len += ft_putstr(va_arg(ap, char *));
	else if (format == 'i' || format == 'd')
		len += ft_putnbr_base(va_arg(ap, int), "0123456789");
	else if (format == 'p')
		len += ft_putnbr_base_ptr(va_arg(ap, unsigned long int),
				"0123456789abcdef");
	else if (format == 'u')
		len += ft_putnbr_base(va_arg(ap, unsigned int), "0123456789");
	else if (format == 'x')
		len += ft_putnbr_base(va_arg(ap, unsigned int), "0123456789abcdef");
	else if (format == 'X')
		len += ft_putnbr_base(va_arg(ap, unsigned int), "0123456789ABCDEF");
	else if (format == '%')
		len += (int)write(1, "%", 1);
	else
		return (-1);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		len;
	int		i;

	len = 0;
	i = 0;
	if (!format)
		return (-1);
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (!format[i])
				return (-1);
			len += sort_format(format[i], ap);
		}
		else if (format[i - 1] != '%' || format[i - 2] == '%')
			len += write(1, &format[i], 1);
		i++;
	}
	va_end(ap);
	return (len);
}
