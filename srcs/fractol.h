/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 12:51:05 by rfriscca          #+#    #+#             */
/*   Updated: 2016/02/19 16:08:08 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <mlx.h>
# include "libft.h"
# include <fcntl.h>
# include <math.h>

# define X1 -2.1
# define X2 0.6
# define Y1 -1.2
# define Y2 1.2
# define ZOOM 400
# define IT_MAX 100

typedef struct		s_init
{
	double			x1;
	double			x2;
	double			y1;
	double			y2;
	int				zoom;
	int				it_max;
}					t_init;

typedef struct		s_stock
{
	void			*mlx;
	void			*win;
	int				width;
	int				height;
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

void				mandelbrot(t_stock stock);

#endif
