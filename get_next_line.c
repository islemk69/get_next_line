/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikaismou <ikaismou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 10:31:27 by ikaismou          #+#    #+#             */
/*   Updated: 2022/12/11 11:08:57 by ikaismou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_newtmp(char *tmp)
{
	int		i;
	int		j;
	char	*str;
	int		size;

	i = 0;
	while (tmp[i] && tmp[i] != '\n')
		i++;
	if (!tmp[i] || !tmp)
		return (free(tmp), NULL);
	size = (ft_strlen(tmp) - i);
	str = malloc(sizeof(char) * size);
	if (!str)
		return (free(tmp), NULL);
	i++;
	j = 0;
	while (tmp[i])
		str[j++] = tmp[i++];
	str[j] = '\0';
	return (free(tmp), str);
}

char	*ft_line(char *tmp)
{
	int		i;
	char	*line;

	i = 0;
	if (!tmp[i])
		return (NULL);
	while (tmp[i] != '\n' && tmp[i] != '\0')
		i++;
	if (tmp[i] == '\0')
		line = malloc(sizeof(char) * (i + 1));
	else
		line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (tmp[i] && tmp[i] != '\n')
	{
		line[i] = tmp[i];
		i++;
	}
	if (tmp[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_tmp(int fd, char *tmp)
{
	char	*str;
	int		rd;

	str = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!str)
		return (free(tmp), NULL);
	rd = 1;
	while (!ft_strchr(tmp, '\n') && rd != 0)
	{
		rd = read(fd, str, BUFFER_SIZE);
		if (rd == -1)
		{
			free(str);
			free(tmp);
			return (0);
		}
		str[rd] = '\0';
		tmp = ft_strjoin(tmp, str);
	}
	free(str);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*tmp;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (read(fd, NULL, 0) == -1)
		return (free(tmp), tmp = NULL, NULL);
	tmp = ft_tmp(fd, tmp);
	if (!tmp)
	{
		free(tmp);
		return (NULL);
	}
	line = ft_line(tmp);
	if (line)
		tmp = ft_newtmp(tmp);
	else
	{
		free(tmp);
		tmp = NULL;
	}
	return (line);
}
