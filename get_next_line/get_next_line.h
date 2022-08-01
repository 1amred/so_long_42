/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamellal <mamellal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 16:15:43 by mamellal          #+#    #+#             */
/*   Updated: 2022/04/08 00:56:35 by mamellal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE  42
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

int		ft_strlen(char *str);
int		ft_strchr(char *str, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);
char	*ft_strdup(char	*src);

#endif