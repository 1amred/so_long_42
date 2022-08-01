/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamellal <mamellal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 00:06:43 by mamellal          #+#    #+#             */
/*   Updated: 2022/04/13 02:14:51 by mamellal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_left(t_long *map)
{
	if (map->map[map->y_p][map->x_p - 1] != '1'
		|| map->map[map->y_p][map->x_p - 1] == 'C')
	{
		if (map->map[map->y_p][map->x_p - 1] == 'C')
			map->c--;
		if (map->map[map->y_p][map->x_p - 1] == 'E' && map->c == 0)
			ft_error("YOU WIN");
		else if (map->map[map->y_p][map->x_p - 1] != 'E')
		{
			map->map[map->y_p][map->x_p] = '0';
			map->map[map->y_p][map->x_p - 1] = 'P';
			put_in_windows(map);
		}
	}
	if (map->map[map->y_p][map->x_p - 1] != '1'
		&& map->map[map->y_p][map->x_p - 1] != 'E')
	{
		write(1, "moves : ", 8);
		ft_putnbr(map->ii++);
		write(1, "\n", 1);
	}
}

void	move_right(t_long *map)
{
	if (map->map[map->y_p][map->x_p + 1] != '1'
		|| map->map[map->y_p][map->x_p + 1] == 'C')
	{
		if (map->map[map->y_p][map->x_p + 1] == 'C')
			map->c--;
		if (map->map[map->y_p][map->x_p + 1] == 'E' && map->c == 0)
			ft_error("YOU WIN");
		else if (map->map[map->y_p][map->x_p + 1] != 'E')
		{
			map->map[map->y_p][map->x_p] = '0';
			map->map[map->y_p][map->x_p + 1] = 'P';
			put_in_windows(map);
		}
	}
	if (map->map[map->y_p][map->x_p + 1] != '1'
		&& map->map[map->y_p][map->x_p + 1] != 'E')
	{
		write(1, "moves : ", 8);
		ft_putnbr(map->ii++);
		write(1, "\n", 1);
	}
}

void	move_up(t_long *map)
{
	if (map->map[map->y_p - 1][map->x_p] != '1'
		|| map->map[map->y_p - 1][map->x_p] == 'C')
	{
		if (map->map[map->y_p - 1][map->x_p] == 'C')
			map->c--;
		if (map->map[map->y_p - 1][map->x_p] == 'E' && map->c == 0)
			ft_error("YOU WIN");
		else if (map->map[map->y_p - 1][map->x_p] != 'E')
		{
			map->map[map->y_p][map->x_p] = '0';
			map->map[map->y_p - 1][map->x_p] = 'P';
			put_in_windows(map);
		}
	}
	if (map->map[map->y_p - 1][map->x_p] != '1'
		&& map->map[map->y_p - 1][map->x_p] != 'E')
	{
		write(1, "moves : ", 8);
		ft_putnbr(map->ii++);
		write(1, "\n", 1);
	}
}

void	move_down(t_long *map)
{
	if (map->map[map->y_p + 1][map->x_p] != '1'
		|| map->map[map->y_p + 1][map->x_p] == 'C')
	{
		if (map->map[map->y_p + 1][map->x_p] == 'C')
			map->c--;
		if (map->map[map->y_p + 1][map->x_p] == 'E' && map->c == 0)
			ft_error("YOU WIN");
		else if (map->map[map->y_p + 1][map->x_p] != 'E')
		{
			map->map[map->y_p][map->x_p] = '0';
			map->map[map->y_p + 1][map->x_p] = 'P';
			put_in_windows(map);
		}
	}
	if (map->map[map->y_p + 1][map->x_p] != '1'
		&& map->map[map->y_p + 1][map->x_p] != 'E')
	{
		write(1, "moves : ", 8);
		ft_putnbr(map->ii++);
		write(1, "\n", 1);
	}
}

void	checkmap(t_long *m)
{
	int	i;
	int	j;

	i = 0;
	while (m->map[i])
	{
		j = 0;
		while (m->map[i][j])
		{
			if (m->map[i][j] == 'P')
			{
				m->p++;
				if (m->p > 1)
					ft_error("error");
			}
			ft_cn(m, i, j);
			j++;
		}
		i++;
	}
	if (m->c == 0 || m->e == 0 || m->p == 0)
		ft_error("error");
}
