/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikitos <nikitos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 20:36:47 by novsiann          #+#    #+#             */
/*   Updated: 2023/07/19 16:47:38 by nikitos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	draw_background(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->win_height)
	{
		x = 0;
		while (x < data->win_width)
		{
			my_mlx_pixel_put(data, x, y, 0xA4A4A4);
			x++;
		}
		y++;
	}
}

void	drawing_line(t_data *data)
{
	float	x_step;
	float	y_step;
	float	x;
	float	y;
	int		max;

	x = data->x;
	y = data->y;
	x_step = (int)data->x1 - x;
	y_step = (int)data->y1 - y;
	max = get_maxint(mod(x_step), mod(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(x - data->x1) || (int)(y - data->y1))
	{
		my_mlx_pixel_put(data, x + data->shift_x, \
		y + data->shift_y, data->color);
		x += x_step;
		y += y_step;
	}
}
