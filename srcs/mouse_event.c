/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 15:05:05 by rfriscca          #+#    #+#             */
/*   Updated: 2016/03/11 13:34:45 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_motion(int x, int y, t_stock *param)
{
	param->data = ft_init_data_julia(param->data, (double)x, (double)y);
	julia(*(t_stock*)param, param->data, 0xffffff);
	return (0);
}

int		mouse_event(int button, int x, int y, t_stock *param)
{
	double			x2;
	double			y2;
	static int		color = 0xffffff;
	static double	h = 1;

	x2 = (double)x / (double)param->width * (param->data.x2 - param->data.x1);
	y2 = (double)y / (double)param->height * (param->data.y2 - param->data.y1);
	if (button == 1)
	{
		param->data = ft_init_data_zoom(param->data, x2, y2, h);
		mandelbrot(*(t_stock*)param, param->data, color);
		h = h / 2;
	}
	if (button == 2)
	{
		param->data = ft_init_data_dezoom(param->data, x2, y2, h);
		mandelbrot(*(t_stock*)param, param->data, color);
		h = h * 2;
	}
	return (0);
}
