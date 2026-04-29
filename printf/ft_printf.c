/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalifa <ahalifa@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 09:59:58 by ahalifa           #+#    #+#             */
/*   Updated: 2026/04/29 12:34:48 by ahalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

int	ft_putnbr(int n)
{
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
	{
		return (ft_putchar((n + '0')));
	}
}
int	ft_unsdeci(unsigned int n)
{
	if (n < 0)
		n = n + 4294967296;
	return (ft_putnbr(n));
}
// TODO : 
// Pour u && x && X quand n < 0 
// faire 4294967296 - n pour avoir son chiffre
int	ft_format(char c, va_list *args)
{
	if (c == 'c')
		return (ft_putchar(va_arg(*args, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(*args, char *)));
	// else if (c == 'p')
	// 	ft_pasDeNom3();
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(*args, int)));
	// else if (c == 'u')
	// 	return (ft_unsdeci(va_arg(*args, unsigned int)));
	else if (c == 'x')
		    return (ft_puthexa(va_arg(*args, int),c));
	else if (c == 'X')
	    return (ft_puthexa(va_arg(*args, int),c));
	else if (c == '%')
	    write(1, '%', 1);
	return (-1);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	size_t	i;
	int		current;

	va_start(args, str);
	current = 0;
	i = 0;
	// if(va_start(args, str) == 0)
	//     return (-1);
	while (str[i])
	{
		if (str[i] != '%')
			ft_putchar(str[i]);
		else if (str[i + 1])
		{
			i++;
			ft_format(str[i], &args);
		}
		i++;
	}
	va_end(args);
	return (current);
}

#include <limits.h>

int	main(void)
{
	printf("%x\n", 14);
	ft_printf("%x\n", 14);

	return (0);
}