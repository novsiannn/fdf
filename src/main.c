/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikitos <nikitos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 14:26:00 by novsiann          #+#    #+#             */
/*   Updated: 2023/06/23 17:23:20 by nikitos          ###   ########.fr       */
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
    data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "FDF");
	read_file(av[1], data);
	data->zoom = 20;
	draw(data);
	mlx_key_hook(data->win_ptr, deal_key, data);
	mlx_loop(data->mlx_ptr);
	return (1);
}
