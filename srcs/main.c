/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 16:43:00 by rfriscca          #+#    #+#             */
/*   Updated: 2016/03/30 14:58:38 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int		ft_exit(int n)
{
	if (n == 53)
		exit(n);
	return (0);
}

void	choose_fractal(int n)
{
}

int		main(int argc, char **argv)
{
	t_stock	stock;
	t_init	data;
	int		endian;

	data.width = (X2 - X1) * ZOOM;
	data = ft_init_data(data);
	stock.mlx = mlx_init();
	stock.width = (X2 - X1) * ZOOM;
	stock.height = (Y2 - Y1) * ZOOM;
	stock.img = mlx_new_image(stock.mlx, stock.width, stock.height);
	stock.win = mlx_new_window(stock.mlx, stock.width, stock.height, "Fractol");
	mlx_key_hook(stock.win, ft_exit, &stock);
	stock.data = data;
	stock.img_data = mlx_get_data_addr(stock.img, &stock.bits_per_pixel,
		&stock.size_line, &endian);
	Sierpinski_carpet(stock);
	//burnship(stock, data, 0x00ffff);
	//mlx_hook(stock.win, 6, (1L<<6), mouse_motion, &stock);
	mlx_mouse_hook(stock.win, mouse_event, &stock);
	mlx_loop(stock.mlx);
	return (0);
}
