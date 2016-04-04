/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sierpinski_carpet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 13:35:29 by rfriscca          #+#    #+#             */
/*   Updated: 2016/04/01 16:49:13 by rfriscca         ###   ########.fr       */
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

void	sierpinski_carpet(t_stock stock)
{
	double		i;
	double		j;
	int			n;
	double	 	count;
	double		save;

	n = 1;
	count = 0;
	i = 0;
	j = 0;
	draw_first_square(stock, SQUARE_SIZE, 100, 100);
	while ((save = SQUARE_SIZE / pow(3, (double)n)) > 1)
	{
		count = pow(9, (double)n - 1);
		while (i < sqrt(count))
		{
			while (j < sqrt(count))
			{
				if (j >= 1 && i >= 1)
					draw_square(stock, save, j * 3 * save + save + 100, i * 3 * save + save + 100);
				else if (j >= 1)
					draw_square(stock, save, j * 3 * save + save + 100, (i + 1) * save + 100);
				else if (i >= 1)
					draw_square(stock, save, (j + 1) * save + 100, i * 3 * save + save + 100);
				else
					draw_square(stock, save, (j + 1) * save + 100, (i + 1) * save + 100);
				++j;
			}
			j = 0;
			++i;
		}
		i = 0;
		++n;
	}
	mlx_put_image_to_window(stock.mlx, stock.win, stock.img, 0, 0);
}
