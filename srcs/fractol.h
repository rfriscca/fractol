/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 12:51:05 by rfriscca          #+#    #+#             */
/*   Updated: 2016/03/30 15:01:56 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <mlx.h>
# include "libft.h"
# include <fcntl.h>
# include <math.h>

# define X1J -1.4
# define X2J 1
# define X1 -2.1
# define X2 0.6
# define Y1 -1.2
# define Y2 1.2
# define ZOOM 400
# define IT_MAX 100
# define SQUARE_SIZE 800

typedef struct		s_init
{
	double			x;
	double			y;
	double			x1;
	double			x2;
	double			y1;
	double			y2;
	int				zoom;
	int				width;
	int				it_max;
	int				it;
}					t_init;

typedef struct		s_stock
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*img_data;
	int				width;
	int				height;
	int				bits_per_pixel;
	int				size_line;
	t_init			data;
}					t_stock;

typedef struct		s_ima
{
	double			c_r;
	double			c_i;
	double			z_r;
	double			z_i;
}					t_ima;

typedef struct		s_count
{
	int				i;
	int				x;
	int				y;
}					t_count;

void				mandelbrot(t_stock stock, t_init data, int color);
void				burnship(t_stock stock, t_init data, int color);
void				Sierpinski_carpet(t_stock stock);
void				julia(t_stock stock, t_init data, int color);
void				color_panel(t_stock stock);
t_init				ft_init_data(t_init data);
t_init				ft_init_data_julia(t_init data, double x, double y);
int					mouse_event(int button, int x, int y, t_stock *param);
int					mouse_motion(int x, int y, t_stock *param);
int					swap_color(int n, int color, t_stock stock);
t_init				ft_init_data_zoom(t_init data, double x, double y, double h);
t_init				ft_init_data_dezoom(t_init data, double x, double y, double h);
void				mlx_pixel_put_img(char *data, t_count i, int size_line, int color);
void				mlx_clear_img(char *data, int width, int height);

#endif
