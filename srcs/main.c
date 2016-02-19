/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 16:43:00 by rfriscca          #+#    #+#             */
/*   Updated: 2016/02/19 14:48:00 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_exit(int n, void *param)
{
	if (n == 53)
		exit(n);
	return (0);
}

int		main(int argc, char **argv)
{
	t_stock	stock;

	stock.mlx = mlx_init();
	stock.width = (X2 - X1) * ZOOM;
	stock.height = (Y2 - Y1) * ZOOM;
	stock.win = mlx_new_window(stock.mlx, stock.width, stock.height, "Fractol");
	mlx_key_hook(stock.win, ft_exit, &stock);
	mandelbrot(stock);
	mlx_loop(stock.mlx);
	return (0);
}
