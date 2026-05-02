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
	while (!(ft_strchr(stash, '\n')) && bufread > 0)
	{
		bufread = read(fd, buf, BUFFER_SIZE);
		buf[bufread] = '\0';
		if (bufread <= 0)
			break ;
		stash = ft_strjoin(stash, buf);
	}
	line = ft_substr(stash,0,(ft_strchr(stash, '\n') - stash) + 1);
	stash = ft_substr(stash,line - stash + 1, ft_strlen(stash) - (line - stash + 1) );
	// printf("je print la stash %s", stash);
	//ne sais pas quand finir le programme
	printf("bufread %d\n", bufread);
	return (line);
}

int	main(int ac, char **av)
{
	int fd = open(av[1], O_RDONLY);
	char *line;
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (0);
}