/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 13:30:28 by rfriscca          #+#    #+#             */
/*   Updated: 2016/03/07 13:53:26 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		swap_color(int n, int color, t_stock stock)
{
	int		red;
	int 	green;
	int		blue;

	red = ((color & 0xff0000) >> 16) * n / stock.data.it_max;
	green = ((color & 0x00ff00) >> 8) * n / stock.data.it_max;
	blue = (color & 0x0000ff) * n / stock.data.it_max;
	return ((red << 16) + (green << 8) + blue);
}

void	mandelbrot_2(t_count i, t_ima z, t_stock stock, int n)
{
	double	save;

	while (z.z_r * z.z_r + z.z_i * z.z_i < 4 && i.i < stock.data.it_max)
	{
		save = z.z_r;
		z.z_r = z.z_r * z.z_r - z.z_i * z.z_i + z.c_r;
		z.z_i = 2 * z.z_i * save + z.c_i;
		++i.i;
	}
	mlx_pixel_put(stock.mlx, stock.win, i.x, i.y, swap_color(i.i, n, stock) + i.i);
	/*if (i.i < stock.data.it_max)
	{
		mlx_pixel_put(stock.mlx, stock.win, i.x, i.y, swap_color(i.i, n, stock));
	}*/
}

void	mandelbrot(t_stock stock, t_init data, int color)
{
	t_ima	z;
	t_count	i;

	mlx_clear_window(stock.mlx, stock.win);
	i.x = 0;
	i.y = 0;
	i.i = 0;
	stock.data = data;
	while (i.x < stock.width)
	{
		while (i.y < stock.height)
		{
			z.c_r = (double)i.x / data.zoom + data.x1;
			z.c_i = (double)i.y / data.zoom + data.y1;
			z.z_r = 0;
			z.z_i = 0;
			i.i = 0;
			mandelbrot_2(i, z, stock, color);
			++i.y;
		}
		i.y = 0;
		++i.x;
	}
	color_panel(stock);
}
