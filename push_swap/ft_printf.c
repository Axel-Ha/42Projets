/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalifa <ahalifa@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 09:59:58 by ahalifa           #+#    #+#             */
/*   Updated: 2026/05/12 15:22:44 by ahalifa          ###   ########.fr       */
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

int	ft_format(char c, va_list *args)
{
	if (c == 'c')
		return (ft_putchar(va_arg(*args, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(*args, char *)));
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
