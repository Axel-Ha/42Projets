/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctu <ctu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 12:34:46 by ahalifa           #+#    #+#             */
/*   Updated: 2026/05/25 10:49:27 by ctu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_puthexa(unsigned int n, char format)
{
	int	count;

	count = 0;
	if (n >= 16)
		count += ft_puthexa(n / 16, format);
	if (format == 'X')
		count += ft_putchar("0123456789ABCDEF"[n % 16], 1);
	else
		count += ft_putchar("0123456789abcdef"[n % 16], 1);
	return (count);
}

int	ft_putaddr(uintptr_t n)
{
	int	count;

	count = 0;
	if (n >= 16)
		count += ft_putaddr(n / 16);
	count += ft_putchar("0123456789abcdef"[n % 16], 1);
	return (count);
}

int	ft_putvoid(uintptr_t p)
{
	int	count;

	count = 0;
	if (p == 0)
		return (write(1, "(nil)", 5));
	count += ft_putstr("0x", 1);
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
		count += ft_putchar(n + '0', 1);
	return (count);
}

int	ft_putnbr_printf(int n, int fd)
{
	int	count;

	count = 0;
	if (n == -2147483648)
		return (write(fd, "-2147483648", 11));
	if (n < 0)
	{
		count += (ft_putchar('-', fd));
		n *= -1;
	}
	if (n > 9)
	{
		count += ft_putnbr_printf(n / 10, fd);
		count += ft_putnbr_printf(n % 10, fd);
	}
	else
		count += ft_putchar(n + '0', fd);
	return (count);
}
