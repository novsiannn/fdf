/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: novsiann <novsiann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 15:41:00 by novsiann          #+#    #+#             */
/*   Updated: 2023/07/08 16:06:09 by novsiann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	isometric(int *x, int *y, int z)
{
	*x = (*x - *y) * cos(0.9);
	*y = (*x + *y) * sin(0.9) - z;
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x < data->win_width && y <= data->win_height && x > 0 && y > 0)
	{
		dst = data->addr + (y * data->line_length + \
					x * (data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

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
	if (data->z)
		data->color = 0x00FFFF;
	else
		data->color = 0xffffff;
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
	if (data->z)
		data->color = 0x00FFFF;
	else
		data->color = 0xffffff;
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

	if (data->img)
	{
		mlx_destroy_image(data->mlx_ptr, data->img);
		data->img = mlx_new_image(data->mlx_ptr, \
		data->win_width, data->win_height);
	}
	y = 0;
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
