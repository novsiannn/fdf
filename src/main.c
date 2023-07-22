/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: novsiann <novsiann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 14:26:00 by novsiann          #+#    #+#             */
/*   Updated: 2023/07/22 12:17:13 by novsiann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	mlx_inizialization(t_data *data)
{
	data->win_width = 1500;
	data->win_height = 1000;
	data->constant = 1;
	data->isometric = 1;
	data->zoom_height = 1;
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, \
	data->win_width, data->win_height, "FDF");
	data->img = mlx_new_image(data->mlx_ptr, data->win_width, data->win_height);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, \
	&data->line_length, &data->endian);
	if (data->win_width > data->win_height)
		data->constant = data->win_width / data->win_height;
	data->zoom = data->win_width / data->width / 2 / data->constant;
	data->shift_x = data->win_width / 2 - data->width / 3;
	data->shift_y = data->win_height / 2 - data->height / 3 * data->zoom;
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
	{
		ft_printf("Error");
		exit(0);
	}
	read_file(av[1], &data);
	// is_map_valid(av[1], &data);
	mlx_inizialization(&data);
	draw_map(&data);
	mlx_hook(data.win_ptr, 2, 0, deal_key, &data);
	mlx_hook(data.win_ptr, 17, 0, escape, &data);
	mlx_loop(data.mlx_ptr);
	return (1);
}
