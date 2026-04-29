/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalifa <ahalifa@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 12:34:46 by ahalifa           #+#    #+#             */
/*   Updated: 2026/04/29 12:34:47 by ahalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_puthexa(int n, char format)
{
    if(n >= 16)
        ft_puthexa(n/16, format);
    if(format == 'X')
        ft_putchar("0123456789ABCDEF"[n%16]); 
    else 
        ft_putchar("0123456789abcdef"[n%16]); 
    return (1);
}