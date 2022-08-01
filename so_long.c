/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamellal <mamellal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:16:51 by mamellal          #+#    #+#             */
/*   Updated: 2022/04/13 23:04:23 by mamellal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close(void)
{
	write(1, "Exit", 5);
	exit(0);
}

void	put_in_windows(t_long *m)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = -1;
	j = 0;
	m->x_p = 0;
	m->y_p = 0;
	m->ig = mlx_xpm_file_to_image(m->mlx, "pics/img.xpm", &x, &y);
	m->wl = mlx_xpm_file_to_image(m->mlx, "pics/wall.xpm", &x, &y);
	m->h = mlx_xpm_file_to_image(m->mlx, "pics/hero.xpm", &x, &y);
	m->cn = mlx_xpm_file_to_image(m->mlx, "pics/coin.xpm", &x, &y);
	m->dr = mlx_xpm_file_to_image(m->mlx, "pics/door.xpm", &x, &y);
	ft_norm(m, i, j);
}

char	**read_map(char *av1)
{
	int		fd;
	char	*line;
	char	*all_line;
	char	**string;

	fd = open(av1, 'r');
	if (fd < 0)
		ft_error("Error");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
		{
			free(line);
			break ;
		}
		if (line[0] == '\n')
			ft_error("Error");
		all_line = ft_strjoin(all_line, line);
		free(line);
	}
	string = ft_split(all_line, '\n');
	free(all_line);
	return (string);
}

int	hookmoves(int key, t_long *map)
{
	if (key == 0)
		move_left(map);
	else if (key == 2)
		move_right(map);
	else if (key == 13)
		move_up(map);
	else if (key == 1)
		move_down(map);
	else if (key == 53)
		ft_error("Exit");
	return (0);
}

int	main(int ac, char **av)
{
	int		x;
	t_long	m;
	int		y;

	y = 0;
	m.p = 0;
	m.c = 0;
	m.ii = 1;
	if (ac < 2)
		exit(1);
	checkerror(av[1]);
	m.mlx = mlx_init();
	m.map = read_map(av[1]);
	ft_checkerrors(m.map);
	checkmap(&m);
	x = ft_strlen(m.map[0]) * 64;
	while (m.map[y])
		y++;
	y *= 64;
	m.ml_w = mlx_new_window(m.mlx, x, y, "so_long");
	put_in_windows(&m);
	mlx_key_hook(m.ml_w, hookmoves, &m);
	mlx_hook(m.ml_w, 17, 0, ft_close, NULL);
	mlx_loop(m.mlx);
}
