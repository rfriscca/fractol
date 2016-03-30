/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 13:30:28 by rfriscca          #+#    #+#             */
/*   Updated: 2016/03/30 13:06:48 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	burnship2(t_count i, t_ima z, t_stock *stock, int color)
{
	double		save;

	while (z.z_r * z.z_r + z.z_i * z.z_i < 4 && i.i < stock->data.it_max)
	{
		save = z.z_r;
		z.z_r = fabs(z.z_r * z.z_r - z.z_i * z.z_i + z.c_r);
		z.z_i = fabs(2 * z.z_i * save + z.c_i);
		++i.i;
	}
	if (i.i < stock->data.it_max)
	{
		mlx_pixel_put_img(stock->img_data, i,
				stock->size_line, swap_color(i.i, color, *stock));
	}
}

void	burnship(t_stock stock, t_init data, int color)
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
			z.c_r = (double)i.x / data.zoom + data.x1;
			z.c_i = (double)i.y / data.zoom + data.y1;
			z.z_r = 0;
			z.z_i = 0;
			i.i = 0;
			burnship2(i, z, &stock, color);
			++i.y;
		}
		i.y = 0;
		++i.x;
	}
	mlx_put_image_to_window(stock.mlx, stock.win, stock.img, 0, 0);
}
