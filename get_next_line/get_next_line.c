/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwafi <kwafi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 15:44:48 by kwafi             #+#    #+#             */
/*   Updated: 2026/02/28 15:44:48 by kwafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stddef.h>

static int	read_loop(int fd, char **stash, char *buf);
static int	do_read(int fd, char **stash);
static char	*free_and_null(char **p);
static char	*cut_line(char **stash);

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	char		tmp;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &tmp, 0) < 0)
	{
		if (stash)
		{
			free(stash);
			stash = NULL;
		}
		return (NULL);
	}
	if (do_read(fd, &stash) == -1)
		return (NULL);
	line = cut_line(&stash);
	if (!line)
		return (NULL);
	return (line);
}

static int	do_read(int fd, char **stash)
{
	char	*buf;
	int		ret;

	buf = (char *)malloc((size_t)BUFFER_SIZE + 1);
	if (!buf)
		return (-1);
	ret = read_loop(fd, stash, buf);
	free(buf);
	if (ret == -1 || ret == -2)
	{
		if (*stash)
		{
			free(*stash);
			*stash = NULL;
		}
		return (-1);
	}
	return (0);
}

static int	read_loop(int fd, char **stash, char *buf)
{
	ssize_t	bytes;
	char	*tmp;

	bytes = 1;
	while (!gn1_strchr(*stash, '\n') && bytes > 0)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes == -1)
			return (-1);
		buf[bytes] = '\0';
		if (!*stash)
			tmp = gn1_strdup(buf);
		else
		{
			tmp = gn1_strjoin(*stash, buf);
			free(*stash);
		}
		*stash = tmp;
		if (!*stash)
			return (-2);
	}
	return (0);
}

static char	*free_and_null(char **p)
{
	if (*p)
		free(*p);
	*p = NULL;
	return (NULL);
}

static char	*cut_line(char **stash)
{
	size_t	i;
	char	*line;
	char	*rest;

	if (!*stash || **stash == '\0')
		return (free_and_null(stash));
	i = 0;
	while ((*stash)[i] && (*stash)[i] != '\n')
		i++;
	if ((*stash)[i] == '\n')
		i++;
	line = gn1_substr(*stash, 0, i);
	if (!line)
		return (free_and_null(stash));
	rest = gn1_substr(*stash, i, gn1_strlen(*stash + i));
	if (!rest)
	{
		free(line);
		return (free_and_null(stash));
	}
	free(*stash);
	*stash = rest;
	return (line);
}
