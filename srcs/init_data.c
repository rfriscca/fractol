/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 15:22:37 by rfriscca          #+#    #+#             */
/*   Updated: 2016/03/07 13:44:22 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

t_init	ft_init_data_zoom(t_init data, double x, double y, double h)
{
	double		x1;
	double		y1;
	static int	it = 0;
	static int	i = 0;

	x1 = data.x1;
	y1 = data.y1;
	data.x1 = x - h + x1;
	data.x2 = x + h + x1;
	data.y1 = y - h + y1;
	data.y2 = y + h + y1;
	printf("%f\n%f\n%f\n%f\n", data.x1, data.x2, data.y1, data.y2);
	data.zoom = (double)data.width / (data.x2 - data.x1);
	++i;
	if (i % 5 == 0)
		it = it + 100;
	data.it_max = IT_MAX + it;
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
	data.width = data.width;
	return (data);
}
