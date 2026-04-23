/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalifa <ahalifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 09:58:51 by ahalifa           #+#    #+#             */
/*   Updated: 2026/04/23 17:03:47 by ahalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H

# include <bsd/string.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t elementCount, size_t elementSize);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int nb);
int		ft_isprint(int c);
char	*ft_itoa(int n);
void	*ft_memchr(const void *memBlock, int searchedChar, size_t size);
int		ft_memcmp(const void *ptr1, const void *ptr2, size_t size);
void	*ft_memcpy(void *dest, const void *src, size_t size);
void	*ft_memmove(void *to, const void *from, size_t size);
void	*ft_memset(void *p, int value, size_t count);
size_t	ft_countword(char const *s, char c);
char	*ft_strchr(const char *str, int searchedChar);
char	*ft_strdup(const char *source);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlen(const char *str);
char    *ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strncmp(const char *first, const char *second, size_t n);
char	*ft_strnstr(const char *str1, const char *str2, size_t len);
char	*ft_strrchr(const char *str, int searchedChar);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_toupper(int c);
int		ft_tolower(int c);

#endif