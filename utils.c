/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamellal <mamellal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 15:14:29 by mamellal          #+#    #+#             */
/*   Updated: 2022/04/10 01:35:56 by mamellal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strcmp(char *s, char *d)
{
	int	i;

	i = 0;
	if (!s || !d)
		return (0);
	while (s[i] && d[i] && s[i] == d[i])
		i++;
	if (i == ft_strlen(s) && ft_strlen(s) == ft_strlen(d))
		return (1);
	return (0);
}

void	ft_putstr(char *s)
{
	int	x;

	x = 0;
	if (!s)
		return ;
	while (s[x])
	{
		write(1, &s[x], 1);
		x++;
	}
	write(1, "\n", 1);
}

void	ft_error(char *str)
{
	ft_putstr(str);
	exit(0);
}

void	ft_checkerrors(char **str)
{
	int	i;
	int	j;
	int	size;

	i = 0;
	j = 0;
	size = ft_strlen(str[i]);
	ft_cn2(str, i, j, size);
}
