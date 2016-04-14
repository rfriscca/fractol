# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/16 13:06:21 by rfriscca          #+#    #+#              #
#    Updated: 2016/04/14 13:11:49 by rfriscca         ###   ########.fr        #
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
	make -C $(LIBFT_DIR)

MLX :
	make -C $(MLX_DIR)

$(NAME) : $(OBJ)
	gcc $(FLAGS) -o $(NAME) $(OBJ) $(LIBRARY) $(INCLUDES) $(FRAMEWORK)

%.o : $(SRCS_DIR)/%.c
	gcc $(FLAGS) -c $< $(INCLUDES)

clean :
	rm -f $(OBJ)
	make -C $(LIBFT_DIR) clean

fclean : clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re : fclean all

.PHONY : all clean fclean re
