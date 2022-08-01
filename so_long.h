/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamellal <mamellal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:04:02 by mamellal          #+#    #+#             */
/*   Updated: 2022/04/13 02:11:23 by mamellal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <mlx.h>
# include "get_next_line/get_next_line.h"

typedef struct s_long
{
	int		x_p;
	int		y_p;
	void	*mlx;
	void	*wl;
	void	*h;
	void	*ig;
	void	*cn;
	void	*dr;
	void	*ml_w;
	int		p;
	int		c;
	int		e;
	int		m;
	int		w;
	int		collect;
	int		ii;
	char	**map;
}	t_long;

char	**ft_split(char const *s, char c);
int		ft_strcmp(char *s, char *d);
char	*ft_strchr1(const char *str, int c);
void	ft_checkerrors(char **str);
void	ft_error(char *str);
void	move_left(t_long *map);
void	move_right(t_long *map);
void	move_up(t_long *map);
void	move_down(t_long *map);
void	put_in_windows(t_long *m);
void	checkmap(t_long *m);
int		hookmoves(int key, t_long *map);
void	checkerror(char *av);
void	ft_cn(t_long *m, int i, int j);
void	ft_cn2(char **str, int i, int j, int size);
void	ft_norm(t_long *m, int i, int j);
void	ft_putnbr(int nb);
void	print_b(t_long *map);
#endif
