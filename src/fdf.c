/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikitos <nikitos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 14:26:00 by novsiann          #+#    #+#             */
/*   Updated: 2023/04/12 21:53:56 by nikitos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int main(int ac ,char **av)
{	
	t_data *data;

	data = (t_data*)malloc(sizeof(t_data));
	read_file(data);
	ft_printf("%d", ac);
	// data.mlx = mlx_init();
	// data.win = mlx_new_window(data.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "My first window");
	// mlx_key_hook(data.win, close_window, &data);
	// mlx_loop(data.mlx);
	// free(data.mlx);
	return(0);
}