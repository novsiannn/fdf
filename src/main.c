/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: novsiann <novsiann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 14:26:00 by novsiann          #+#    #+#             */
/*   Updated: 2023/07/01 16:46:42 by novsiann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int main(int ac ,char **av)
{
	t_data	*data;

	if (ac != 2)
	{
		ft_printf("Error");
		exit(0);
	}
	data = (t_data*)malloc(sizeof(t_data));
	if(!data)
		return (0);
	data->mlx_ptr = mlx_init();
	data->shift_x = 250;
	data->shift_y = 250;
    data->win_ptr = mlx_new_window(data->mlx_ptr, 1650, 1000, "FDF");
	data->img = mlx_new_image(data->mlx_ptr, 1650, 1000);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length,&data->endian);
	read_file(av[1], data);
	data->zoom = 5;
	draw(data);
	mlx_key_hook(data->win_ptr, deal_key, data);
	mlx_loop(data->mlx_ptr);
	return (1);
}
