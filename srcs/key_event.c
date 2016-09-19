/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 14:29:33 by rfriscca          #+#    #+#             */
/*   Updated: 2016/09/19 11:56:06 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		key_carpet(int n, t_stock *param)
{
	if (n == 53)
	{
		free(param->data);
		exit(1);
	}
	return (0);
}

int		rand_mandel(int n, t_stock *param)
{
	if (n == 53)
	{
		free(param->data);
		exit(1);
	}
	else if (n == 15)
	{
		*param->data = ft_init_data(*param->data);
		param->h = 1;
		mandelbrot(*param, param->color);
	}
	else if (n == 8)
	{
		param->color = rand();
		mandelbrot(*param, param->color);
	}
	return (0);
}

int		rand_julia(int n, t_stock *param)
{
	if (n == 53)
	{
		free(param->data);
		exit(1);
	}
	else if (n == 1 && param->stopjulia == 1)
		param->stopjulia = 0;
	else if (n == 1 && param->stopjulia == 0)
		param->stopjulia = 1;
	else if (n == 15)
	{
		*param->data = ft_init_data_julia(*param->data, 0, 0);
		param->h = 1;
		julia(*param, param->color);
	}
	else if (n == 8)
	{
		param->color = rand();
		julia(*param, param->color);
	}
	return (0);
}
