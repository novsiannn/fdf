/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: novsiann <novsiann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 22:20:25 by nikitos           #+#    #+#             */
/*   Updated: 2023/07/18 20:45:54 by novsiann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

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

void	free_2dstring(int **matrix, t_data *data)
{
	int	y;

	y = 0;
	while (y < data->height)
	{
		free(matrix[y]);
		y++;
	}
	free(matrix);
}

void	isometric(int *x, int *y, int z)
{
	*x = (*x - *y) * cos(0.9);
	*y = (*x + *y) * sin(0.9) - z;
}
