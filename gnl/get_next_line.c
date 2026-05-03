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
	char 		*temp;

	if (BUFFER_SIZE <= 0 || read(fd, "", 0) == -1)
		return (NULL);
	bufread = 1;
	if (!stash)
		stash = ft_strdup("");
	while (!(ft_strchr(stash, '\n')) && bufread > 0)
	{
		bufread = read(fd, buf, BUFFER_SIZE);
		if (bufread <= 0)
			break ;
		buf[bufread] = '\0';
		temp = stash;
		stash = ft_strjoin(temp, buf);
		free(temp);
	}
	temp = ft_strchr(stash, '\n');
	line = ft_substr(stash,0,(temp - stash) + 1);
	temp = ft_strdup(temp + 1);
	free(stash);
	stash = temp;
	printf("je test %s", stash);
	return (line);
}

int	main(int ac, char **av)
{
	int fd = open(av[1], O_RDONLY);
	char *line;
	line = get_next_line(fd);
	// while (line)
	// {
	// 	printf("%s", line);
	// 	free(line);
	// 	line = get_next_line(fd);
	// }
	free(line);
	close(fd);
	return (0);
}