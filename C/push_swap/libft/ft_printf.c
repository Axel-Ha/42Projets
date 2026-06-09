/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctu <ctu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 09:59:58 by ahalifa           #+#    #+#             */
/*   Updated: 2026/06/09 16:13:36 by ctu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar(char c, int fd)
{
	return (write(fd, &c, 1));
}

int	ft_putstr(char *str, int fd)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (str == NULL)
		return (write(fd, "(null)", 6));
	while (str[i])
	{
		count += ft_putchar(str[i], fd);
		i++;
	}
	return (count);
}

int	ft_putfloat(double n, int fd)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	count += ft_putnbr_printf((int) n, fd);
	count += ft_putchar('.', fd);
	if (n < 0)
	{
		count += ft_putchar('-', fd);
		n = -n;
	}
	while (i < 2)
	{
		n = ((((n + 0.005) - (double)(int)n) * 10));
		count += ft_putnbr_printf((int)n, fd);
		i++;
	}
	return (count);
}

int	ft_format(char c, va_list *args, int fd)
{
	if (c == 'c')
		return (ft_putchar(va_arg(*args, int), fd));
	else if (c == 's')
		return (ft_putstr(va_arg(*args, char *), fd));
	else if (c == 'p')
		return (ft_putvoid(va_arg(*args, uintptr_t)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr_printf(va_arg(*args, int), fd));
	else if (c == 'u')
		return (ft_unsdeci(va_arg(*args, unsigned int)));
	else if (c == 'x')
		return (ft_puthexa(va_arg(*args, unsigned int), c));
	else if (c == 'X')
		return (ft_puthexa(va_arg(*args, unsigned int), c));
	else if (c == '%')
		return (ft_putchar('%', fd));
	else if (c == 'f')
		return (ft_putfloat(va_arg(*args, double), fd));
	return (0);
}

int	ft_printf(int fd, const char *str, ...)
{
	va_list	args;
	size_t	i;
	int		current;

	va_start(args, str);
	current = 0;
	i = 0;
	if (str == NULL)
	{
		va_end(args);
		return (write(fd, "(null)", 6));
	}
	while (str[i])
	{
		if (str[i] != '%')
			current += ft_putchar(str[i], fd);
		else if (str[i + 1])
		{
			i++;
			current += ft_format(str[i], &args, fd);
		}
		i++;
	}
	va_end(args);
	return (current);
}

// int	main(void)
// {
// 	double	n;

// 	n = 61.121;
// 	ft_printf("%f\n", n);
// 	return (0);
// }
