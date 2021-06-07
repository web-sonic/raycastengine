# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ctragula <ctragula@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/06 09:21:46 by ctragula          #+#    #+#              #
#    Updated: 2021/02/15 21:32:58 by ctragula         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

LIB = libft/libft.a

M_LIB = mlx/libmlx.dlyb

SRCS = main.c \
		error_handler/ft_errors.c \
		error_handler/ft_validations.c \
		error_handler/map_validator.c \
		start.c \
		mlx_controller/controller.c \
		mlx_controller/cub_close.c \
		parser/parser.c \
		gnl/get_next_line.c \
		gnl/get_next_line_utils.c \
		parser/configs.c \
		draw_3d.c \
		my_mlx_pixel_put.c \
		mlx_controller/move_control.c \
		cast_ray.c \
		draw_sprites.c \
		get_pixel_color.c \
		textures.c \
		get_screenshot.c \
		free.c \

INC = cub3d.h \
		error_handler/ft_errors.h

CC = gcc -Wall -Wextra -Werror

FLAGS =  -L libft -lft -L. -lmlx -framework OpenGL -framework AppKit

.PHONY: all clean fclean re bonus

all:	$(NAME)

$(NAME): $(LIB) $(M_LIB) $(INC) $(SRCS)
		cp mlx/libmlx.dylib libmlx.dylib
		$(CC) $(SRCS) $(FLAGS) -o $@

$(LIB):
		$(MAKE) -C libft bonus

$(M_LIB):
		$(MAKE) -C mlx

clean:
	$(MAKE) -C libft clean
	$(RM) mlx/*.o

fclean: clean
	$(MAKE) -C libft fclean
	$(MAKE) -C mlx clean
	$(RM) cub3d libmlx.dylib

re:	fclean all
