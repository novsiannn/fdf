/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: novsiann <novsiann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 22:20:25 by nikitos           #+#    #+#             */
/*   Updated: 2023/07/07 20:50:43 by novsiann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	free_2dstr(int **matrix, t_data *data)
{
	int	i;

	i = 0;
	while(i < data->height)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

int get_maxint(int a, int b)
{
	if(a > b)
		return (a);
	return (b);
}

float mod(float n)
{
	if(n < 0)
		n *= -1;
	return (n);
}

void	shifting(t_data *data, float *x, float *y, float *x1, float *y1)
{
	*x += data->shift_x;
	*x1 += data->shift_x;
	*y += data->shift_y;
	*y1 += data->shift_y;
}

void	zooming(t_data *data, float *x, float *y, float *x1, float *y1)
{
	*x *= data->zoom;
	*y *= data->zoom;
	*x1 *= data->zoom;
	*y1 *= data->zoom;
}

void drawing(t_data *data,float *x,float *y,float *x1,float *y1)
{
	float x_step;
	float y_step;
	int max;

	x_step = *x1 - *x;
	y_step = *y1 - *y;
	max = get_maxint(mod(x_step), mod(y_step));
	x_step /= max;
	y_step /= max;
	while((int)(*x1 - *x) || (int)(*y1 - *y))
	{
		my_mlx_pixel_put(data, *x, *y, data->color);
		*x += x_step;
		*y += y_step; 
	}
}