/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_pixel_put_img.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 13:46:23 by rfriscca          #+#    #+#             */
/*   Updated: 2016/03/30 15:00:50 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mlx_clear_img(char *data, int width, int height)
{
	int		i;
	int		length;

	i = 0;
	length = width * 4 * height;
	while (i < length)
	{
		data[i] = 0;
		++i;
	}
}

void	mlx_pixel_put_img(char *data, t_count i, int size_line, int color)
{
	int		goto_pixel;

	goto_pixel = i.y * size_line + i.x * 4;
	data[goto_pixel] = ((color & 0xff0000) >> 16);
	data[goto_pixel + 1] = ((color & 0x00ff00) >> 8);
	data[goto_pixel + 2] = (color & 0x0000ff);
	data[goto_pixel + 3] = 0;
}
