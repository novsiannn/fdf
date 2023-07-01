/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikitos <nikitos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 22:20:25 by nikitos           #+#    #+#             */
/*   Updated: 2023/06/14 16:40:31 by nikitos          ###   ########.fr       */
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