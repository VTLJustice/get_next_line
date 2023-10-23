/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rradules <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 17:25:27 by rradules          #+#    #+#             */
/*   Updated: 2023/10/02 17:32:37 by rradules         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		length;
	char	*result;
	int		i;
	int		j;

	i = 0;
	length = ft_strlen(s1) + ft_strlen(s2);
	result = malloc(sizeof(char) * (length + 1));
	if (!result || !s1 || !s2)
		return (NULL);
	while (s1[i] != '\0')
	{
		result[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		result[i] = s2[j];
		i++;
		j++;
	}
	result[length] = '\0';
	return (result);
}

char	*ft_strchr(const char *string, int c)
{
	char	*str;

	str = (char *)string;
	while (*str != c && *str != '\0')
		str++;
	if (*str == c)
		return (str);
	else
		return (NULL);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_bzero(void *str, size_t n)
{
	size_t	i;
	char	*temp_str;

	i = 0;
	temp_str = (char *)str;
	while (i < n)
	{
		temp_str[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*pointr;

	pointr = malloc(count * size);
	if (!pointr)
	{
		free(pointr);
		return (NULL);
	}
	ft_bzero(pointr, size * count);
	return (pointr);
}
