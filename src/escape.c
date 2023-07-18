/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   escape.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: novsiann <novsiann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 20:31:46 by novsiann          #+#    #+#             */
/*   Updated: 2023/07/18 20:42:42 by novsiann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	escape(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	free_2dstring(data->map, data);
	free(data->addr);
	exit(0);
	return (1);
}
