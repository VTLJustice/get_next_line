/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rradules <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 17:20:13 by rradules          #+#    #+#             */
/*   Updated: 2023/10/02 17:01:52 by rradules         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

char	*ft_free(char *result, char *buffer)
{
	char	*temp;

	temp = ft_strjoin(result, buffer);
	if (!temp)
	{
		free(temp);
		free(buffer);
		return (NULL);
	}
	free(result);
	return (temp);
}

char	*ft_discard(char *buffer)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	line = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	i++;
	j = 0;
	while (buffer[i])
		line[j++] = buffer[i++];
	free(buffer);
	return (line);
}

char	*ft_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer)
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*ft_read(int fd, char *result)
{
	char	*buffer;
	int		bytes;

	if (!result)
		result = ft_calloc(1, 1);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	bytes = 1;
	while (bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes] = '\0';
		result = ft_free(result, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		if (buffer)
			free(buffer);
		return (buffer = NULL);
	}
	buffer = ft_read(fd, buffer);
	if (!buffer)
	{
		free(buffer);
		return (NULL);
	}
	line = ft_line(buffer);
	buffer = ft_discard(buffer);
	if (line && line[0] == '\0')
	{
		free(line);
		return (NULL);
	}
	return (line);
}
/*
int	main(void)
{
	int	fd;
	int	lines;
	int	i;

	lines = 6;
	//fd = -1;
	i = 0;
	fd = open("texto2654654.txt", O_RDONLY);
	while (i < lines)
	{
		printf("%s", get_next_line(fd));
		i++;
	}
	return (0);
}*/
