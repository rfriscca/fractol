/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 13:30:28 by rfriscca          #+#    #+#             */
/*   Updated: 2016/06/24 15:05:54 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		swap_color(int n, int color)
{
	int			red;
	int			green;
	int			blue;

	red = ((color & 0xff0000) >> 16);
	green = ((color & 0x00ff00) >> 8);
	blue = ((color & 0x0000ff));
	if (n % 100 > 0 && n % 100 < 10)
		green = 0;
	else if (n % 100 >= 10 && n % 100 < 50)
		red = 0;
	else if (n % 100 >= 50 && n % 100 < 85)
	{
		green = 0;
		blue = 0;
	}
	return ((red << 16) + (green << 8) + blue);
}

void	mandelbrot_2(t_count i, t_ima z, t_stock stock, int color)
{
	double		save;

	while (z.z_r * z.z_r + z.z_i * z.z_i < 4 && i.i < stock.data->it_max)
	{
		save = z.z_r;
		z.z_r = z.z_r * z.z_r - z.z_i * z.z_i + z.c_r;
		z.z_i = 2 * z.z_i * save + z.c_i;
		++i.i;
	}
	if (i.i < stock.data->it_max)
	{
		mlx_pixel_put_img(stock.img_data, i, stock.size_line,
				swap_color(i.i, color));
	}
}

void	mandelbrot(t_stock stock, int color)
{
	t_ima	z;
	t_count	i;

	mlx_clear_img(stock.img_data, stock.width, stock.height);
	i.x = 0;
	i.y = 0;
	i.i = 0;
	while (i.x < stock.width)
	{
		while (i.y < stock.height)
		{
			z.c_r = (double)i.x / stock.data->zoom + stock.data->x1;
			z.c_i = (double)i.y / stock.data->zoom + stock.data->y1;
			z.z_r = 0;
			z.z_i = 0;
			i.i = 0;
			mandelbrot_2(i, z, stock, color);
			++i.y;
		}
		i.y = 0;
		++i.x;
	}
	mlx_put_image_to_window(stock.mlx, stock.win, stock.img, 0, 0);
}
