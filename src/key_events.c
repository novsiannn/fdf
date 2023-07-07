/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: novsiann <novsiann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:37:53 by novsiann          #+#    #+#             */
/*   Updated: 2023/07/07 21:28:27 by novsiann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	deal_key(int key, t_data *data)
{
	if(key == 126)
		data->shift_y -= 30;
	if(key == 125)
		data->shift_y += 30;
	if(key == 123)
		data->shift_x -= 30;
	if(key == 124)
		data->shift_x += 30;
	if (key == 53)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		exit(0);
	}
	if (key == 1 || key == 0 || key == 12 || key == 13)
		zoom_and_isometric(data, key);
	if (key == 2 || key == 3)
		size_map(data, key);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw(data);
	return (1);
}

void size_map(t_data *data,int key)
{
	if(key == 2)
		data->zoom_height += 0.1;
	if(key == 3)
		data->zoom_height -= 0.1;
}

void zoom_and_isometric(t_data *data, int keycode)
{
	if (keycode == 1)
		data->zoom -= 0.9;
	if (keycode == 0)
		data->zoom += 0.9;
	if(keycode == 12)
		data->isometric = 0;
	if(keycode == 13)
		data->isometric = 1;
}