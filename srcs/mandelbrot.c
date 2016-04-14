/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 13:30:28 by rfriscca          #+#    #+#             */
/*   Updated: 2016/04/14 13:04:52 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		swap_color(int n, int color, t_stock stock)
{
	int			red;
	int			green;
	int			blue;

	if (n % 100 > 0 && n % 100 < 10)
	{
		red = ((color & 0xff0000) >> 16);
		green = ((color & 0x00ff00) >> 8) * 0;
		blue = (color & 0x0000ff);
	}
	else
	{
		red = ((color & 0xff0000) >> 16) * n / stock.data.it_max;
		green = ((color & 0x00ff00) >> 8) * n / stock.data.it_max;
		blue = (color & 0x0000ff) * n / stock.data.it_max;
	}
	return ((red << 16) + (green << 8) + blue);
}

void	mandelbrot_2(t_count i, t_ima z, t_stock stock, int color)
{
	double		save;

	while (z.z_r * z.z_r + z.z_i * z.z_i < 4 && i.i < stock.data.it_max)
	{
		save = z.z_r;
		z.z_r = z.z_r * z.z_r - z.z_i * z.z_i + z.c_r;
		z.z_i = 2 * z.z_i * save + z.c_i;
		++i.i;
	}
	if (i.i < stock.data.it_max)
	{
		mlx_pixel_put_img(stock.img_data, i, stock.size_line,
				swap_color(i.i, color, stock));
	}
}

void	mandelbrot(t_stock stock, t_init data, int color)
{
	t_ima	z;
	t_count	i;

	mlx_clear_img(stock.img_data, stock.width, stock.height);
	i.x = 0;
	i.y = 0;
	i.i = 0;
	stock.data = data;
	while (i.x < stock.width)
	{
		while (i.y < stock.height)
		{
			z.c_r = (double)i.x / stock.data.zoom + stock.data.x1;
			z.c_i = (double)i.y / stock.data.zoom + stock.data.y1;
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
