# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thong-bi <thong-bi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/24 22:55:11 by thong-bi          #+#    #+#              #
#    Updated: 2023/03/27 20:57:31 by thong-bi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
MINIFLAGS = -L mlx_file -lmlx -framework OpenGL -framework AppKit -lz
RM = rm -rf
FSANITIZE = -fsanitize=address -g

LIBFT_PATH = Libft
LIBFT = $(LIBFT_PATH)/libft.a

HEADER = so_long.h

NAME = so_long
SRCS = error.c\
	   img_draw.c\
	   init.c\
	   keys.c\
	   main.c\
	   map.c\
	   player_update.c\
	   updater.c\
	   utils.c\
	   gnl/get_next_line.c\
	   gnl/get_next_line_utils.c
OBJS = $(SRCS:.c=.o)

%.o:	%.c $(HEADER)
			$(CC) $(CFLAGS) -Imlx -c $< -o $@

all: $(LIBFT) $(NAME)

$(NAME):	$(OBJS)
			$(CC) $(OBJS) $(FSANITIZE) $(LIBFT) $(MINIFLAGS) -o $(NAME)

$(LIBFT):
			$(MAKE) -C $(LIBFT_PATH)

clean:
			$(MAKE) -C $(LIBFT_PATH) clean
			$(RM) $(OBJS)

fclean:		clean
			$(MAKE) -C $(LIBFT_PATH) fclean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all re clean fclean
