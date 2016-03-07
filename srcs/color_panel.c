/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_panel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 14:22:13 by rfriscca          #+#    #+#             */
/*   Updated: 2016/02/22 14:38:43 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_square(t_stock stock, int color, int x, int y)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < 30)
	{
		while (j < 30)
		{
			mlx_pixel_put(stock.mlx, stock.win, x + j, y + i, color);
			++j;
		}
		j = 0;
		++i;
	}
}

void	color_panel(t_stock stock)
{
	draw_square(stock, 0xff0000, 30, 30);
	draw_square(stock, 0x00ff00, 90, 30);	
	draw_square(stock, 0x0000ff, 150, 30);
}
