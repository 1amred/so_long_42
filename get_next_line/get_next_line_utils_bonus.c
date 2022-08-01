/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamellal <mamellal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 15:36:07 by mamellal          #+#    #+#             */
/*   Updated: 2021/11/30 11:33:21 by mamellal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(char *str)
{
	int	b;

	b = 0;
	while (str[b])
		b++;
	return (b);
}

int	ft_strchr(char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != (char )c && str[i])
		i++;
	if (str[i] == (char ) c)
		return (1);
	else
		return (0);
}

char	*ft_strdup(char *src)
{
	int		a;
	char	*b;

	a = 0;
	b = (char *)malloc(sizeof(char ) * (ft_strlen(src) + 1));
	if (b == 0)
		return (0);
	while (src [a])
	{
		b[a] = src[a];
		a++;
	}
	b[a] = 0;
	return (b);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ptr;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1)
		s1 = ft_strdup("");
	ptr = (char *)malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen (s2)) + 1));
	if (!ptr)
		return (NULL);
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		ptr[i] = s2[j];
		i++;
		j++;
	}
	ptr[i] = '\0';
	free(s1);
	return (ptr);
}
