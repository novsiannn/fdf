/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: novsiann <novsiann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:37:53 by novsiann          #+#    #+#             */
/*   Updated: 2023/07/01 16:34:47 by novsiann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	deal_key(int key, t_data *data)
{
	if(key == 126)
		data->shift_y -= 50;
	if(key == 125)
		data->shift_y += 50;
	if(key == 123)
		data->shift_x -= 50;
	if(key == 124)
		data->shift_x += 50;
	if (key == 53)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		exit(0);
	}
	if(key == 1 || key == 0)
		zoom_map(data, key);
	if(key == 2 || key == 3)
		size_map(data, key);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw(data);
	return (1);
}

void size_map(t_data *data,int key)
{
	int	x;
	int	y;
	y = 0;
	while(y < data->height)
	{
		x = 0;
		while(x < data->width)
		{
			if(data->map[y][x] > 0 && key == 2)
				data->map[y][x] += 5;
			if(data->map[y][x] > 0 && key == 3)
				data->map[y][x] -= 5;
			x++;
		}
		y++;
	}
}

void zoom_map(t_data *data, int keycode)
{
	if (keycode == 1)
		data->zoom -= 1;
	if (keycode == 0)
		data->zoom += 1;
}