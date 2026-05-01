/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalifa <ahalifa@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 16:10:23 by ahalifa           #+#    #+#             */
/*   Updated: 2026/05/01 19:37:02 by ahalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	char		buf[BUFFER_SIZE];
	int			bufread;

	if (BUFFER_SIZE <= 0 || read(fd, "", 0) == -1)
		return (NULL);
	bufread = 1;
	if (!stash)
		stash = ft_strdup("");
	// bufread = read(fd, buf, BUFFER_SIZE);
	while (!ft_strchr(stash, '\n') && bufread > 0)
	{
		buf[bufread] = '\0';
		if (bufread <= 0)
			break ;
		stash = ft_strjoin(stash, buf);
		bufread = read(fd, buf, BUFFER_SIZE);
	}
	printf("JE SUIS TEST %s",stash);
	// buffer size a 2, des caracteres sont pas lus.
	// le programme ne s'arrete pas
	// stash a tout mon fichier ?
	// je dois normalement m'arreter a \n
	// j ai meme pas toute ma ligne hmmm
	// je dois m'arreter a \n ou eof
	// line retourne tout mon fichier 
	line = ft_strdup(stash);
	return (line);
}

int	main(int ac, char **av)
{
	int fd = open(av[1], O_RDONLY);
	char *line;
	while (line = get_next_line(fd))
		printf("\n"	);
	// free(line);
	// close(fd);
	return (0);
}