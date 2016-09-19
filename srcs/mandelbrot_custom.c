/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 13:30:28 by rfriscca          #+#    #+#             */
/*   Updated: 2016/09/19 13:28:23 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot_2_custom(t_count i, t_ima z, t_stock stock, int color)
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

void	mandelbrot_custom(t_stock stock, int color)
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
			z.c_r = fabs((double)i.x / stock.data->zoom + stock.data->x1);
			z.c_i = (double)i.y / stock.data->zoom + stock.data->y1;
			z.z_r = 0;
			z.z_i = 0;
			i.i = 0;
			mandelbrot_2_custom(i, z, stock, color);
			++i.y;
		}
		i.y = 0;
		++i.x;
	}
	mlx_put_image_to_window(stock.mlx, stock.win, stock.img, 0, 0);
}
