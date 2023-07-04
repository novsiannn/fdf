/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: novsiann <novsiann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 14:26:00 by novsiann          #+#    #+#             */
/*   Updated: 2023/07/04 20:46:04 by novsiann         ###   ########.fr       */
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
	data->win_width = 1920;
	data->win_height = 1080;
	data->constant = 1;
    data->win_ptr = mlx_new_window(data->mlx_ptr, data->win_width, data->win_height, "FDF");
	data->img = mlx_new_image(data->mlx_ptr, data->win_width, data->win_height);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length,&data->endian);
	read_file(av[1], data);
	if(data->win_width > data->win_height)
		data->constant = data->win_width / data->win_height;
	data->zoom = data->win_width / data->width / 2 / data->constant;
	data->shift_x = data->win_width / 2 - data->win_width / 3;
	data->shift_y = data->win_height / 2 - data->height / 3 * data->zoom;
	draw(data);
	mlx_key_hook(data->win_ptr, deal_key, data);
	mlx_loop(data->mlx_ptr);
	return (1);
}
