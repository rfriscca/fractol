/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_event_julia.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 16:20:51 by rfriscca          #+#    #+#             */
/*   Updated: 2016/06/29 15:49:00 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_event_julia(int button, int x, int y, t_stock *param)
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
		julia(*(t_stock*)param, param->color);
	}
	if ((button == 2 || button == 4) && param->h < 1)
	{
		param->h = param->h * 2;
		*param->data = ft_init_data_dezoom(*param->data, x2, y2, param->h);
		julia(*(t_stock*)param, param->color);
	}
	return (0);
}
