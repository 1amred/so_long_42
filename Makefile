# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mamellal <mamellal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/15 11:11:06 by mamellal          #+#    #+#              #
#    Updated: 2022/04/13 01:42:55 by mamellal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =  so_long.c lib.c utils2.c utils.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c moves.c lol.c
		
NAME = so_long


OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
XFLAGS = -lmlx -framework OpenGL -framework Appkit

all : $(NAME)
	
$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(XFLAGS) $(OBJS) -o $(NAME)
clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all
