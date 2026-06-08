/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalifa <ahalifa@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 16:10:23 by ahalifa           #+#    #+#             */
/*   Updated: 2026/05/05 13:53:19 by ahalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_free_all(char **stash, char *buf)
{
	if (buf)
		free(buf);
	if (stash && *stash)
	{
		free(*stash);
		*stash = NULL;
	}
	return (NULL);
}

char	*ft_read_line(int fd, char *stash)
{
	char	*buf;
	char	*temp;
	int		bufread;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	bufread = 1;
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	if (!stash)
		stash = ft_strdup("");
	while (!(ft_strchr(stash, '\n')) && bufread > 0)
	{
		bufread = read(fd, buf, BUFFER_SIZE);
		if (bufread < 0)
			return (ft_free_all(&stash, buf));
		buf[bufread] = '\0';
		temp = stash;
		stash = ft_strjoin(temp, buf);
		free(temp);
	}
	ft_free_all(NULL, buf);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	char		*temp;

	stash = ft_read_line(fd, stash);
	if (!stash || stash[0] == '\0')
		return (ft_free_all(&stash, NULL));
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
		ft_free_all(&stash, NULL);
	}
	return (line);
}

/*
int	main(int ac, char **av)
{
	int		fd;
	char	*line;

	(void)ac;
	fd = open(av[1], O_RDONLY);
	// int fd = 0;
	line = get_next_line(fd);
	while (line)
	{
		// printf("ligne :%s\n", line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (0);
}
*/
