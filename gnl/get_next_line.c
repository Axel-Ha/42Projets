/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalifa <ahalifa@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 16:10:23 by ahalifa           #+#    #+#             */
/*   Updated: 2026/05/01 14:07:06 by ahalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static	char *s;
	char	*line;
	char		buf[BUFFER_SIZE];
	int		bufread;
	bufread = 0;
	s = "";
	while (!(ft_strchr(s, '\n')) && (bufread = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[bufread + 1] = '\0';
		s = ft_strjoin(s, buf);
	}
	//s contient toute ma phrase avant ma fin de ligne
	// la derniere phrase n'est pas donner
	// buffer size a 2, des caracteres sont pas lus.
	// le programme ne s'arrete pas 
	//bufread ne donnes pas -1 ?
	//j'ai une boucle infini
	line = ft_strdup(s);
	printf("test");
	if (bufread == -1)
	{
		return (NULL);
	}

	return (line);
}

int	main(int ac, char **av)
{
	int fd = open(av[1], O_RDONLY);
	char *line;
	while( line = get_next_line(fd))
		printf("%s",line);
	// free(line);
	// close(fd);
	return (0);
}