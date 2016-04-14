# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/16 13:06:21 by rfriscca          #+#    #+#              #
#    Updated: 2016/04/05 15:56:02 by rfriscca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror
FRAMEWORK = -framework OpenGl -framework AppKit
LIBRARY = -Llibft/ -lft -Lminilibx_macos/ -lmlx
INCLUDES = -I libft/
SRCS_DIR = srcs
SRCS = init_data.c          \
       julia.c              \
	   sierpinski_carpet.c	\
	   main.c               \
	   mandelbrot.c         \
	   mlx_pixel_put_img.c  \
	   mouse_event.c
OBJ = $(SRCS:.c=.o)
NAME = fractol
LIBFT_DIR = libft
MLX_DIR = minilibx_macos


all : LIBFT MLX $(NAME)

LIBFT :
	make -C $(LIBFT_DIR) re && make -C $(LIBFT_DIR) clean

MLX :
	make -C $(MLX_DIR) re

$(NAME) : $(OBJ)
	gcc $(FLAGS) -o $(NAME) $(OBJ) $(LIBRARY) $(INCLUDES) $(FRAMEWORK)

%.o : $(SRCS_DIR)/%.c
	gcc $(FLAGS) -c $< $(INCLUDES)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
