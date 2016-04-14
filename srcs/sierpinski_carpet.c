/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sierpinski_carpet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 13:35:29 by rfriscca          #+#    #+#             */
/*   Updated: 2016/04/14 14:36:04 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_square(t_stock stock, int length, int x, int y)
{
	t_count		i;

	i.x = x;
	i.y = y;
	while (i.y < y + length)
	{
		while (i.x < x + length)
		{
			mlx_pixel_put_img(stock.img_data, i, stock.size_line, 0x000000);
			++i.x;
		}
		i.x = x;
		++i.y;
	}
}

void	draw_first_square(t_stock stock, int length, int x, int y)
{
	t_count		i;

	i.x = x;
	i.y = y;
	while (i.y < y + length)
	{
		while (i.x < x + length)
		{
			mlx_pixel_put_img(stock.img_data, i, stock.size_line, 0xffffff);
			++i.x;
		}
		i.x = x;
		++i.y;
	}
}

void	sierpinski_carpet2(t_stock stock, double save, double count)
{
	double	i;
	double	j;

	i = 0;
	j = 0;
	while (i < sqrt(count))
	{
		while (j < sqrt(count))
		{
			if (j >= 1 && i >= 1)
				draw_square(stock, save, j * 3 * save + save, i * 3 * save
						+ save);
			else if (j >= 1)
				draw_square(stock, save, j * 3 * save + save, (i + 1) * save);
			else if (i >= 1)
				draw_square(stock, save, (j + 1) * save, i * 3 * save + save);
			else
				draw_square(stock, save, (j + 1) * save, (i + 1) * save);
			++j;
		}
		j = 0;
		++i;
	}
}

void	sierpinski_carpet(t_stock stock, int x, int y, int add)
{
	int			n;
	double		count;
	double		save;

	stock.img_data = mlx_get_data_addr(stock.img, &stock.bits_per_pixel,
			&stock.size_line, &n);
	n = 1;
	count = 0;
	draw_first_square(stock, SQUARE_SIZE + add, x, y);
	while ((save = (SQUARE_SIZE + (double)add) / pow(3, (double)n)) > 1)
	{
		count = pow(9, (double)n - 1);
		sierpinski_carpet2(stock, save, count);
		++n;
	}
	mlx_put_image_to_window(stock.mlx, stock.win, stock.img, 0, 0);
}
