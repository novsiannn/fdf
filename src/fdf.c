/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: novsiann <novsiann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 14:26:00 by novsiann          #+#    #+#             */
/*   Updated: 2023/04/15 19:41:49 by novsiann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int main(int ac ,char **av)
{	
	t_data *data;
	char *str;
	int		i;


	data = (t_data*)malloc(sizeof(t_data));
	str = av[0];
	read_file(av[1], data);
	i = ac;
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "FDF");
	mlx_key_hook(data->win_ptr, close_window, &data);
	bresenhem_algorithm(10, 100, 100, 50, data);
	mlx_loop(data->mlx_ptr);
	return(0);
}
