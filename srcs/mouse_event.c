/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 15:05:05 by rfriscca          #+#    #+#             */
/*   Updated: 2016/06/29 15:42:03 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_motion(int x, int y, t_stock *param)
{
	if (param->stopjulia == 0)
	{
		*param->data = ft_motion_julia(*param->data, (double)x, (double)y);
		julia(*(t_stock*)param, param->color);
	}
	return (0);
}

int		mouse_event(int button, int x, int y, t_stock *param)
{
	double			x2;
	double			y2;

	x2 = (double)x / (double)param->width * (param->data->x2 - param->data->x1);
	y2 = (double)y / (double)param->height *
		(param->data->y2 - param->data->y1);
	if (button == 1 || button == 5)
	{
		param->h = param->h / 2;
		*param->data = ft_init_data_zoom(*param->data, x2, y2, param->h);
		mandelbrot(*(t_stock*)param, param->color);
	}
	if ((button == 2 || button == 4) && param->h < 1)
	{
		param->h = param->h * 2;
		*param->data = ft_init_data_dezoom(*param->data, x2, y2, param->h);
		mandelbrot(*(t_stock*)param, param->color);
	}
	return (0);
}

int		mouse_event_carpet(int button, int x, int y, t_stock *param)
{
	int				x2;
	int				y2;
	static int		add = 0;

	mlx_destroy_image(param->mlx, param->img);
	if (button == 1 || button == 5)
		add = add + 100;
	if ((button == 2 || button == 4) && add > 0)
		add = add - 100;
	param->img = mlx_new_image(param->mlx, param->width + add,
			param->height + add);
	x2 = x - param->width / 2 - add;
	y2 = y - param->height / 2 - add;
	sierpinski_carpet(*param, 0, 0, add);
	return (0);
}
