/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalifa <ahalifa@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 16:10:23 by ahalifa           #+#    #+#             */
/*   Updated: 2026/05/04 12:03:02 by ahalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_line(int fd, char *stash)
{
	char	buf[BUFFER_SIZE + 1];
	char	*temp;
	int		bufread;


	bufread = 1;
	if (!stash)
		stash = ft_strdup("");
	temp = ft_strdup("");
	while (!(ft_strchr(stash, '\n')) && bufread > 0)
	{
		bufread = read(fd, buf, BUFFER_SIZE);
		if (bufread < 0)
		{
			free(temp);
			free(stash);
			// free(buf);
			return (NULL);
		}
		buf[bufread] = '\0';
		temp = stash;
		stash = ft_strjoin(temp, buf);
		free(temp);
	}
	// free(buf);
	return (stash);
}
char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	char		*temp;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	stash = ft_read_line(fd, stash);
	if (!stash || stash[0] == '\0')
	{
		free(stash);
		return (NULL);
	}
	temp = ft_strchr(stash, '\n');
	if (temp)
	{
		line = ft_substr(stash, 0, (temp - stash) + 1);
		temp = ft_strdup(temp + 1);
		free(stash);
		stash = temp;
	}
	else
	{
		line = ft_substr(stash, 0, ft_strlen(stash));
		free(stash);
		stash = NULL;
	}
	return (line);
}

/*
int	main(int ac, char **av)
{
	(void)ac;
	
	int fd = open(av[1], O_RDONLY);
	char *line;
	line = get_next_line(fd);
	while (line)
	{
		printf("ligne :%s\n", line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (0);
}
*/
