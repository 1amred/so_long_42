/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamellal <mamellal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 16:43:12 by mamellal          #+#    #+#             */
/*   Updated: 2021/11/30 11:33:07 by mamellal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*fornorm(char *variable, int fd)
{
	int			i;
	char		*buffer;

	i = 1;
	buffer = malloc(sizeof(char ) * (BUFFER_SIZE + 1));
	while (!ft_strchr(variable, '\n') && i != 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i < 0)
		{
			free (buffer);
			return (NULL);
		}
		buffer[i] = '\0';
		variable = ft_strjoin(variable, buffer);
	}
	free (buffer);
	return (variable);
}

char	*gn(char *b)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	while (b[i] && b[i] != '\n')
		i++;
	if (!b[i])
	{
		free (b);
		return (NULL);
	}
	line = (char *)malloc(sizeof(char ) * (ft_strlen(b) - i) + 1);
	if (!line)
		return (NULL);
	i++;
	while (b[i + j])
	{
		line[j] = b[i + j];
		j++;
	}
	line[j] = '\0';
	free (b);
	return (line);
}

char	*gl(char *s)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		line = malloc(sizeof(char ) * i + 2);
	else
		line = malloc(sizeof(char ) * i + 1);
	while (j < i)
	{
		line[j] = s[j];
		j++;
	}
	if (s[j] == '\n')
	{
		line[j] = '\n';
		j++;
	}
	line[j] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*variable[OPEN_MAX];
	char		*dm;

	if (fd < 0 || (fd > OPEN_MAX) || BUFFER_SIZE <= 0)
		return (NULL);
	variable[fd] = fornorm(variable[fd], fd);
	if (!variable[fd])
		return (NULL);
	if (!variable[fd][0])
	{
		free(variable[fd]);
		variable[fd] = NULL;
		return (NULL);
	}
	dm = gl(variable[fd]);
	variable[fd] = gn(variable[fd]);
	return (dm);
}
