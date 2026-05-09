/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalifa <ahalifa@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 12:34:46 by ahalifa           #+#    #+#             */
/*   Updated: 2026/04/30 10:15:13 by ahalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexa(unsigned int n, char format)
{
	int	count;

	count = 0;
	if (n >= 16)
		count += ft_puthexa(n / 16, format);
	if (format == 'X')
		count += ft_putchar("0123456789ABCDEF"[n % 16]);
	else
		count += ft_putchar("0123456789abcdef"[n % 16]);
	return (count);
}

int	ft_putaddr(uintptr_t n)
{
	int	count;

	count = 0;
	if (n >= 16)
		count += ft_putaddr(n / 16);
	count += ft_putchar("0123456789abcdef"[n % 16]);
	return (count);
}

int	ft_putvoid(uintptr_t p)
{
	int	count;

	count = 0;
	if (p == 0)
		return (write(1, "(nil)", 5));
	count += ft_putstr("0x");
	count += ft_putaddr(p);
	return (count);
}

int	ft_unsdeci(unsigned int n)
{
	int	count;

	count = 0;
	if (n > 9)
	{
		count += ft_unsdeci(n / 10);
		count += ft_unsdeci(n % 10);
	}
	else
		count += ft_putchar(n + '0');
	return (count);
}

int	ft_putnbr(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	if (n < 0)
	{
		count += (ft_putchar('-'));
		n *= -1;
	}
	if (n > 9)
	{
		count += ft_putnbr(n / 10);
		count += ft_putnbr(n % 10);
	}
	else
		count += ft_putchar(n + '0');
	return (count);
}
