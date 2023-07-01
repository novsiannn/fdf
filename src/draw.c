/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikitos <nikitos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 15:41:00 by novsiann          #+#    #+#             */
/*   Updated: 2023/06/23 18:00:00 by nikitos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	isometric(float *x, float *y, int z)
{
	*x = (*x - *y) * cos(0.9);
	*y = (*x + *y) * sin(0.9) - z;
}

void	bresenham(float x, float y, float x1, float y1, t_data *data)
{
	float x_step;
	float y_step;
	int max;
	
	int	z;
	int z1;


	z = data->map[(int)y][(int)x];
	z1 = data->map[(int)y1][(int)x1];
	x *= data->zoom;
	y *= data->zoom;
	x1 *= data->zoom;
	y1 *= data->zoom;


	data->color = (z || z1) ? 0xe80c0c : 0xffffff;
	isometric(&x, &y, z);
	isometric(&x1, &y1, z1);

	x += data->shift_x;
	x1 += data->shift_x;
	y += data->shift_y;
	y1 += data->shift_y;
	
	x_step = x1 - x;
	y_step = y1 - y;
	max = get_maxint(mod(x_step), mod(y_step));
	x_step /= max;
	y_step /= max;
	while((int)(x1 - x) || (int)(y1 - y))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, data->color);
		x += x_step;
		y += y_step; 
	}
}

void	draw(t_data *data)
{
	int	x;
	int y;

	y = 0;
	while(y < data->height)
	{
		x = 0;
		while(x < data->width)
		{
			if(x < data->width - 1)
				bresenham(x, y, x + 1, y, data);
			if(y < data->height - 1)
				bresenham(x, y, x, y + 1, data);
			x++;
		}
		y++;
	}
}