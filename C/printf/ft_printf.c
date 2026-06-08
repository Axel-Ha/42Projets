/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalifa <ahalifa@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 09:59:58 by ahalifa           #+#    #+#             */
/*   Updated: 2026/05/21 11:46:25 by ahalifa          ###   ########.fr       */
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
	int	count;

	i = 0;
	count = 0;
	if (str == NULL)
		return (write(1, "(null)", 6));
	while (str[i])
	{
		count += ft_putchar(str[i]);
		i++;
	}
	return (count);
}


int	ft_putfloat(double n)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	count += ft_putnbr_printf((int)n);
	count += ft_putchar('.');
	n += 0.005;
	if(n < 0)
	{
		count += ft_putchar('-');
		n = -n;
	}
	while (i < 2)
	{
		n = (((n - (double)(int)n) * 10));
		count += ft_putnbr_printf((int)n);
		i++;
	}
	return (count);
}

int	ft_format(char c, va_list *args)
{
	if (c == 'c')
		return (ft_putchar(va_arg(*args, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(*args, char *)));
	else if (c == 'p')
		return (ft_putvoid(va_arg(*args, uintptr_t)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(*args, int)));
	else if (c == 'u')
		return (ft_unsdeci(va_arg(*args, unsigned int)));
	else if (c == 'x')
		return (ft_puthexa(va_arg(*args, unsigned int), c));
	else if (c == 'X')
		return (ft_puthexa(va_arg(*args, unsigned int), c));
	else if (c == '%')
		return (ft_putchar('%'));
	else if (c == 'f')
		return (ft_putfloat(va_arg(*args, double)));
	return (0);
}

int	ft_printf(const char *str, ...)
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
		return (write(1, "(null)", 6));
	}
	while (str[i])
	{
		if (str[i] != '%')
			current += ft_putchar(str[i]);
		else if (str[i + 1])
		{
			i++;
			current += ft_format(str[i], &args);
		}
		i++;
	}
	va_end(args);
	return (current);
}

int	main(void)
{
	double n = 0.12;
	
	ft_printf("%f\n", n);
	// printf("%p\n", &a);
	// ft_printf("%p", NULL);
	// ft_printf("%s",NULL);
	// ft_printf("blabla %s\n test %d ", "Je suis un test", 20);
	// printf("%p\n", &a);
	return (0);
}
