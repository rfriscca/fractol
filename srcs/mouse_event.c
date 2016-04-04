/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 15:05:05 by rfriscca          #+#    #+#             */
/*   Updated: 2016/04/04 16:59:56 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_dez	*new_dezoom(t_dez *dezoom, t_stock *param)
{
	t_dez	*n_dezoom;

	if ((n_dezoom = (t_dez*)malloc(sizeof(*n_dezoom))) == NULL)
	{
		ft_putstr("malloc failed");
		exit(0);
	}
	n_dezoom->data = param->data;
	n_dezoom->next = dezoom;
	return (n_dezoom);
}

t_dez	*destroy_dezoom(t_dez *dezoom)
{
	t_dez	*save;

	save = dezoom->next;
	free(dezoom);
	return (save);
}

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
	static double	h = 2;
	static t_dez	*dezoom = NULL;

	x2 = (double)x / (double)param->width * (param->data.x2 - param->data.x1);
	y2 = (double)y / (double)param->height * (param->data.y2 - param->data.y1);
	if (button == 1)
	{
		dezoom = new_dezoom(dezoom, param);
		h = h / 2;
		param->data = ft_init_data_zoom(param->data, x2, y2, h);
		mandelbrot(*(t_stock*)param, param->data, color);
	}
	if (button == 2 && dezoom)
	{
		h = h * 2;
		param->data = dezoom->data;
		dezoom = destroy_dezoom(dezoom);
		mandelbrot(*(t_stock*)param, param->data, color);
	}
	return (0);
}

int		mouse_event_carpet(int button, int x, int y, t_stock *param)
{
	int				x2;
	int				y2;
	static int		add = 0;

	mlx_destroy_image(param->mlx, param->img);
	if (button == 1)
		add = add + 100;
	if (button == 2)
		add = add - 100;
	param->img = mlx_new_image(param->mlx, param->width + add,
			param->height + add);
	x2 = x - param->width / 2 - add;
	y2 = y - param->height / 2 - add;
	sierpinski_carpet(*param, 0, 0, add);
	return (0);
}
