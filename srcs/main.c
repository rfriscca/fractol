/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 16:43:00 by rfriscca          #+#    #+#             */
/*   Updated: 2016/04/05 13:50:26 by rfriscca         ###   ########.fr       */
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

void	choose_fractal(int n, t_stock stock)
{
	t_init	data;

	if (n == 1)
	{
		data.width = (X2 - X1) * ZOOM;
		data = ft_init_data(data);
		stock.data = data;
		mlx_mouse_hook(stock.win, mouse_event, &stock);
		mandelbrot(stock, data, 0xffffff);
	}
	else if (n == 2)
	{
		stock.data = ft_init_data_julia(stock.data, 0, 0);
		mlx_hook(stock.win, 6, (1L << 6), mouse_motion, &stock);
		julia(stock, stock.data, 0xffffff);
	}
	else if (n == 3)
	{
		mlx_mouse_hook(stock.win, mouse_event_carpet, &stock);
		sierpinski_carpet(stock, 0, 0, 0);
	}
	else
	{
		ft_putstr("Please enter one parameter\n1 : Mandelbrot\n2 : Julia\n");
		ft_putstr("3 : Sierpinski carpet\n");
		exit(1);
	}
}

int		main(int argc, char **argv)
{
	t_stock	stock;
	int		endian;

	if (argc != 2)
	{
		ft_putstr("Please enter one parameter\n1 : Mandelbrot\n2 : Julia\n");
		ft_putstr("3 : Sierpinski carpet\n");
		exit(1);
	}
	stock.mlx = mlx_init();
	stock.width = (X2 - X1) * ZOOM;
	stock.height = (Y2 - Y1) * ZOOM;
	stock.img = mlx_new_image(stock.mlx, stock.width, stock.height);
	stock.win = mlx_new_window(stock.mlx, stock.width, stock.height, "Fractol");
	mlx_key_hook(stock.win, ft_exit, &stock);
	stock.img_data = mlx_get_data_addr(stock.img, &stock.bits_per_pixel,
		&stock.size_line, &endian);
	choose_fractal(ft_atoi(argv[1]), stock);
	mlx_loop(stock.mlx);
	return (0);
}
