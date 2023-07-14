# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thong-bi <thong-bi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/24 22:55:11 by thong-bi          #+#    #+#              #
#    Updated: 2023/07/05 17:48:26 by thong-bi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
MINIFLAGS = -L mlx_file -lmlx -framework OpenGL -framework AppKit -lz
RM = rm -rf
FSANITIZE = -fsanitize=address -g

# LIBFT_PATH = Libft
# LIBFT = $(LIBFT_PATH)/libft.a

HEADER = so_long.h

NAME = so_long
SRCS = error.c\
	   image_to_map.c\
	   check_file.c\
	   check_map.c\
	   door_open.c\
	   ft_itoa.c\
	   ft_split.c\
	   key_hook.c\
	   map.c\
	   movement.c\
	   utils.c\
	   main.c\
	   ani_utils.c\
	   animation.c\
	   gnl/get_next_line.c\
	   gnl/get_next_line_utils.c
OBJS = $(SRCS:.c=.o)

%.o:	%.c $(HEADER)
			$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME):	$(OBJS)
			$(CC) $(OBJS) $(FSANITIZE) $(MINIFLAGS) -o $(NAME)

# $(LIBFT):
# 			$(MAKE) -C $(LIBFT_PATH)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all re clean fclean
