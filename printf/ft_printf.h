/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalifa <ahalifa@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 09:52:58 by ahalifa           #+#    #+#             */
/*   Updated: 2026/04/30 11:03:24 by ahalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *type, ...) __attribute__((format(printf, 1, 2)));
int	ft_puthexa(unsigned int n, char format);
int	ft_putchar(char c);
int	ft_putvoid(uintptr_t p);
int	ft_putstr(char *str);
int	ft_putnbr(int n);
int	ft_unsdeci(unsigned int n);

#endif