/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pascal_triangle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 15:04:29 by rfriscca          #+#    #+#             */
/*   Updated: 2016/03/18 16:07:45 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		init_data_pascal(unsigned int *data[16][16])
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (i < 16)
	{
		while (j < i)
		{
			if (i - 1 < 0 || j - 1 < 0 || j > i - 1)
				data[i][j] = 1;
			else
				data[i][j] = data[i - 1][j - 1] + data[i - 1][j];
			++j;
		}
		j = 0;
		++i;
	}
	return (*data);
}

void		pascal_triangle(t_stock stock)
{
	unsigned int	data[16][16];

	init_data_pascal(&data);

}
