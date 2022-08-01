/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lol.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamellal <mamellal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 22:55:42 by mamellal          #+#    #+#             */
/*   Updated: 2022/04/13 02:04:05 by mamellal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strchr1(const char *str, int c)
{
	char	*ptr;

	ptr = (char *)str;
	if (c == 0 && *str == '\0')
		return ((char *)str);
	while (*str)
		str++;
	while (str >= ptr)
	{
		if (*str == (char )c)
		{
			return ((char *)str);
		}
		str--;
	}
	return (NULL);
}

void	checkerror(char *av)
{
	char	*str;

	str = ft_strchr1(av, '.');
	if (!ft_strcmp(str, ".ber"))
		ft_error("error");
}

void	ft_cn(t_long *m, int i, int j)
{
	if (m->map[i][j] == 'C')
		m->c++;
	if (m->map[i][j] == 'E')
		m->e++;
	if (m->map[i][j] != '1'
		&& m->map[i][j] != '0' && m->map[i][j] != 'E'
		&& m->map[i][j] != 'P' && m->map[i][j] != 'C')
		ft_error("Error");
}

void	ft_cn2(char **str, int i, int j, int size)
{
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == ' ' || str[0][j] != '1'
			|| str[i][0] != '1')
				ft_error("error");
			j++;
		}		
		if (str[i][j - 1] != '1' || j > size || j < size)
			ft_error("Error");
		i++;
	}
	if (str[0] == 0)
		ft_error("ERROR");
	j = 0;
	while (str[i - 1][j])
	{
		if (str[i - 1][j] != '1')
			ft_error("ERROR");
		j++;
	}	
}

void	ft_norm(t_long *m, int i, int j)
{
	while (m->map[++i])
	{
		j = 0;
		while (m->map[i][j] && m->map[i][j] != '\n')
		{
			if (m->map[i][j] == '0')
				mlx_put_image_to_window(m->mlx, m->ml_w, m->ig, j * 64, i * 64);
			if (m->map[i][j] == '1')
				mlx_put_image_to_window(m->mlx, m->ml_w, m->wl, j * 64, i * 64);
			if (m->map[i][j] == 'P')
			{
				mlx_put_image_to_window(m->mlx, m->ml_w, m->h, j * 64, i * 64);
				m->x_p = j;
				m->y_p = i;
			}
			if (m->map[i][j] == 'C')
				mlx_put_image_to_window(m->mlx, m->ml_w, m->cn, j * 64, i * 64);
			if (m->map[i][j] == 'E')
			{
				mlx_put_image_to_window(m->mlx, m->ml_w, m->ig, j * 64, i * 64);
				mlx_put_image_to_window(m->mlx, m->ml_w, m->dr, j * 64, i * 64);
			}
			j++;
		}
	}
}
