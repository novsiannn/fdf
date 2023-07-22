/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: novsiann <novsiann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 20:36:11 by novsiann          #+#    #+#             */
/*   Updated: 2023/07/22 13:07:52 by novsiann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	get_color(t_data *data)
{
	if (data->z >= 100 || data->z1 >= 100)
		data->color = 0xbd23a2;
	else if (data->z >= 80 || data->z1 >= 80)
		data->color = 0xb913a9;
	else if (data->z >= 60 || data->z1 >= 60)
		data->color = 0xb500b0;
	else if (data->z >= 40 || data->z1 >= 40)
		data->color = 0xae00b7;
	else if (data->z >= 20 || data->z1 >= 20)
		data->color = 0xa700c0;
	else if (data->z > 0 || data->z1 > 0)
		data->color = 0x9d00c9;
	else if (data->z <= -70 || data->z1 <= -70)
		data->color = 0x020299;
	else if (data->z <= -50 || data->z1 <= -50)
		data->color = 0x0000fb;
	else if (data->z <= -40 || data->z1 <= -40)
		data->color = 0x5000f0;
	else if (data->z <= -20 || data->z1 <= -20)
		data->color = 0x6d00e6;
	else if (data->z <= -1 || data->z1 <= -1)
		data->color = 0x8100dc;
	else
		data->color = 0xffffff;
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x < data->win_width && y < data->win_height && x > 0 && y > 0)
	{
		dst = data->addr + (y * data->line_length + \
					x * (data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

char	**remove_nextline_and_spaces(char *str)
{
	char	**check;
	char	**check2;

	check = ft_split(str, '\n');
	check2 = ft_split(check[0], ' ');
	free_2dstring(check);
	return (check2);
}
