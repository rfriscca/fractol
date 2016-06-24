/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 15:22:37 by rfriscca          #+#    #+#             */
/*   Updated: 2016/06/24 13:34:23 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_init	ft_init_data_julia(t_init data, double x, double y)
{
	data.x = x / 1000;
	data.y = y / 2000;
	data.x1 = X1J;
	data.x2 = X2J;
	data.y1 = Y1;
	data.y2 = Y2;
	data.zoom = ZOOM;
	data.it_max = IT_MAX;
	data.width = data.width;
	return (data);
}

t_init	ft_init_data_dezoom(t_init data, double x, double y, double h)
{
	double		x1;
	double		y1;

	x1 = data.x1;
	y1 = data.y1;
	data.x1 = x - h + x1;
	data.x2 = x + h + x1;
	data.y1 = y - h + y1;
	data.y2 = y + h + y1;
	data.zoom = (double)data.width / (data.x2 - data.x1);
	data.it = data.it - 100;
	data.it_max = IT_MAX + data.it;
	data.width = data.width;
	return (data);
}

t_init	ft_init_data_zoom(t_init data, double x, double y, double h)
{
	double		x1;
	double		y1;

	x1 = data.x1;
	y1 = data.y1;
	data.x1 = x - h + x1;
	data.x2 = x + h + x1;
	data.y1 = y - h + y1;
	data.y2 = y + h + y1;
	data.zoom = (double)data.width / (data.x2 - data.x1);
	data.it_max = IT_MAX + data.it;
	data.it = data.it + 100;
	data.width = data.width;
	return (data);
}

t_init	ft_init_data(t_init data)
{
	data.x1 = X1;
	data.x2 = X2;
	data.y1 = Y1;
	data.y2 = Y2;
	data.zoom = ZOOM;
	data.it_max = IT_MAX;
	data.it = 0;
	data.width = data.width;
	return (data);
}
