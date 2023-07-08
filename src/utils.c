/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: novsiann <novsiann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 22:20:25 by nikitos           #+#    #+#             */
/*   Updated: 2023/07/08 16:07:46 by novsiann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	free_2dstr(int **matrix, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->height)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

int	get_maxint(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

float	mod(float n)
{
	if (n < 0)
		n *= -1;
	return (n);
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
