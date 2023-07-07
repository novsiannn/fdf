/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: novsiann <novsiann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 15:41:00 by novsiann          #+#    #+#             */
/*   Updated: 2023/07/07 21:25:18 by novsiann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	isometric(float *x, float *y, int z)
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



void	bresenham(float x, float y, float x1, float y1, t_data *data)
{
	int	z;
	int z1;

	z = data->map[(int)y][(int)x];
	z1 = data->map[(int)y1][(int)x1];
	z *= data->zoom_height;
	z1 *= data->zoom_height;
	zooming(data, &x, &y, &x1, &y1);
	data->color = (z || z1) ? 0x00FFFF : 0xffffff;
	if(data->isometric == 1)
	{
		isometric(&x, &y, z);
		isometric(&x1, &y1, z1);
	}
	shifting(data, &x, &y, &x1, &y1);
	drawing(data, &x, &y, &x1, &y1);
}

void	draw(t_data *data)
{
	int	x;
	int y;

	if (data->img)
	{
		mlx_destroy_image(data->mlx_ptr, data->img);
		data->img = mlx_new_image(data->mlx_ptr, data->win_width, data->win_height);
	}
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
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
}