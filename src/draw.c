/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikitos <nikitos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 15:41:00 by novsiann          #+#    #+#             */
/*   Updated: 2023/07/19 16:33:05 by nikitos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	x_line(int x, int y, t_data *data)
{
	data->x = x;
	data->y = y;
	data->x1 = x + 1;
	data->y1 = y;
	data->z = data->map[(int)data->y][(int)data->x];
	data->z1 = data->map[(int)data->y1][(int)data->x1];
	data->z *= data->zoom_height;
	data->z1 *= data->zoom_height;
	data->x *= data->zoom;
	data->y *= data->zoom;
	data->x1 *= data->zoom;
	data->y1 *= data->zoom;
	get_color(data);
	if (data->isometric == 1)
	{
		isometric(&data->x, &data->y, data->z);
		isometric(&data->x1, &data->y1, data->z1);
	}
	drawing_line(data);
}

void	y_line(int x, int y, t_data *data)
{
	data->x = x;
	data->y = y;
	data->x1 = x;
	data->y1 = y + 1;
	data->z = data->map[(int)data->y][(int)data->x];
	data->z1 = data->map[(int)data->y1][(int)data->x1];
	data->z *= data->zoom_height;
	data->z1 *= data->zoom_height;
	data->x *= data->zoom;
	data->y *= data->zoom;
	data->x1 *= data->zoom;
	data->y1 *= data->zoom;
	get_color(data);
	if (data->isometric == 1)
	{
		isometric(&data->x, &data->y, data->z);
		isometric(&data->x1, &data->y1, data->z1);
	}
	drawing_line(data);
}

void	draw_map(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	draw_background(data);
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
				x_line(x, y, data);
			if (y < data->height - 1)
				y_line(x, y, data);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
}
