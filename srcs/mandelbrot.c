/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 13:30:28 by rfriscca          #+#    #+#             */
/*   Updated: 2016/02/19 15:46:26 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int		swap_color(int n)
{
	int		red;
	int 	green;
	int		blue;

	red = n * 255 / IT_MAX;
	green = 0;
	blue = 0;
	if (n > 25)
	{
		red = n * 220 / IT_MAX;
		green = n * 95 / IT_MAX;
		blue = n * 20 / IT_MAX;
	}
	if (n > 48)
	{
		red = n * 255 / IT_MAX;
		green = n * 255 / IT_MAX;
		blue = 0;
	}
	return ((red << 16) + (green << 8) + blue);
}

void	mandelbrot_2(t_count i, t_ima z, t_stock stock)
{
	double	save;

	while (z.z_r * z.z_r + z.z_i * z.z_i < 4 && i.i < IT_MAX)
	{
		save = z.z_r;
		z.z_r = z.z_r * z.z_r - z.z_i * z.z_i + z.c_r;
		z.z_i = 2 * z.z_i * save + z.c_i;
		++i.i;
	}
	if (i.i < IT_MAX)
	{
		mlx_pixel_put(stock.mlx, stock.win, i.x, i.y, swap_color(i.i));
	}
}

void	mandelbrot(t_stock stock)
{
	t_ima	z;
	t_count	i;

	i.x = 0;
	i.y = 0;
	i.i = 0;
	while (i.x < stock.width)
	{
		while (i.y < stock.height)
		{
			z.c_r = (double)i.x / ZOOM + X1;
			z.c_i = (double)i.y / ZOOM + Y1;
			z.z_r = 0;
			z.z_i = 0;
			i.i = 0;
			mandelbrot_2(i, z, stock);
			++i.y;
		}
		i.y = 0;
		++i.x;
	}
}
