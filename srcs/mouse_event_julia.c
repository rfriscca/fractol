/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_event_julia.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 16:20:51 by rfriscca          #+#    #+#             */
/*   Updated: 2016/06/23 16:33:55 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int     mouse_event_julia(int button, int x, int y, t_stock *param)
{
    double          x2;
    double          y2;
    static int      color = 0xffffff;
    static double   h = 2;
    static t_dez    *dezoom = NULL;

    x2 = (double)x / (double)param->width * (param->data.x2 - param->data.x1);
    y2 = (double)y / (double)param->height * (param->data.y2 - param->data.y1);
    if (button == 1)
    {
        dezoom = new_dezoom(dezoom, param);
        h = h / 2;
        param->data = ft_init_data_zoom(param->data, x2, y2, h);
        julia(*(t_stock*)param, param->data, color);
    }
    if (button == 2 && dezoom)
    {
        h = h * 2;
        param->data = dezoom->data;
        dezoom = destroy_dezoom(dezoom);
        julia(*(t_stock*)param, param->data, color);
    }
    return (0);
}
