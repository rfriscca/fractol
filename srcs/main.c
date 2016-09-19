/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 16:43:00 by rfriscca          #+#    #+#             */
/*   Updated: 2016/09/19 13:56:49 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	choose_fractal2(int n, t_stock *stock)
{
	if (n == 2)
	{
		stock->data->width = (X2 - X1) * ZOOM;
		*stock->data = ft_init_data_julia(*stock->data, 0, 0);
		mlx_mouse_hook(stock->win, mouse_event_julia, stock);
		mlx_key_hook(stock->win, rand_julia, stock);
		mlx_hook(stock->win, 6, (1L << 6), mouse_motion, stock);
		julia(*stock, stock->color);
	}
	else if (n == 3)
	{
		mlx_key_hook(stock->win, key_carpet, stock);
		mlx_mouse_hook(stock->win, mouse_event_carpet, stock);
		sierpinski_carpet(*stock, 0, 0, 0);
	}
	else if (n == 4)
	{
		stock->data->width = (X2 - X1) * ZOOM;
		*stock->data = ft_init_data(*stock->data);
		mlx_mouse_hook(stock->win, mouse_event_custom, stock);
		mlx_key_hook(stock->win, rand_mandel_custom, stock);
		mandelbrot_custom(*stock, stock->color);
	}
}

void	choose_fractal(int n, t_stock *stock)
{
	stock->data = (t_init*)malloc(sizeof(*stock->data));
	if (n == 1)
	{
		stock->data->width = (X2 - X1) * ZOOM;
		*stock->data = ft_init_data(*stock->data);
		mlx_mouse_hook(stock->win, mouse_event, stock);
		mlx_key_hook(stock->win, rand_mandel, stock);
		mandelbrot(*stock, stock->color);
	}
	else if (n == 2 || n == 3 || n == 4)
		choose_fractal2(n, stock);
	else
	{
		ft_putstr("Please enter one parameter\n1 : Mandelbrot\n2 : Julia\n");
		ft_putstr("3 : Sierpinski carpet\n4 : Special Mandelbrot\n");
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
		ft_putstr("3 : Sierpinski carpet\n4 : Special Mandelbrot\n");
		exit(1);
	}
	stock.h = 1;
	stock.color = 0xffffff;
	stock.mlx = mlx_init();
	stock.width = (X2 - X1) * ZOOM;
	stock.height = (Y2 - Y1) * ZOOM;
	stock.img = mlx_new_image(stock.mlx, stock.width, stock.height);
	stock.win = mlx_new_window(stock.mlx, stock.width, stock.height, "Fractol");
	stock.stopjulia = 0;
	stock.img_data = mlx_get_data_addr(stock.img, &stock.bits_per_pixel,
		&stock.size_line, &endian);
	choose_fractal(ft_atoi(argv[1]), &stock);
	mlx_loop(stock.mlx);
	return (0);
}
