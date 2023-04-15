/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: novsiann <novsiann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 15:41:00 by novsiann          #+#    #+#             */
/*   Updated: 2023/04/15 19:33:41 by novsiann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

float max_num(float a, float b)
{
	if(a < b)
		return (a);
	return(b);
}

float module(float a)
{
	if(a < 0)
		return (a * -1);
	return (a);
}

void	bresenhem_algorithm(float x, float y,float x1, float y1, t_data *data)
{
	float	x_step;
	float	y_step;
	int		max;

	x_step = x1 - x;
	y_step = y1 - y;

	max = max_num(module(x_step), module(y_step));
	x_step = x_step / max;
	y_step = y_step / max;
	while((int)(x - x1) || (int)(y - y1))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, 0xffffff);
		x += x_step;
		y += y_step;
	}
}