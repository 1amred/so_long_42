/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamellal <mamellal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 02:02:03 by mamellal          #+#    #+#             */
/*   Updated: 2022/04/04 23:12:02 by mamellal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*fornorm(char *variable, int fd)
{
	int			i;
	char		*buffer;

	i = 1;
	buffer = malloc(sizeof(char ) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
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
	while (b[j + i])
	{
		line[j] = b[j + i];
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
	static char	*variable;
	char		*dm;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	variable = fornorm(variable, fd);
	if (!variable)
		return (NULL);
	if (!variable[0])
	{
		free(variable);
		variable = NULL;
		return (NULL);
	}
	dm = gl(variable);
	variable = gn(variable);
	return (dm);
}
