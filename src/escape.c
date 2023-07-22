/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   escape.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: novsiann <novsiann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 20:31:46 by novsiann          #+#    #+#             */
/*   Updated: 2023/07/22 13:49:37 by novsiann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	escape(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	free_2dstring_int(data->map);
	free(data->addr);
	exit(0);
	return (1);
}

int	esc_invalid_map(t_data *data)
{
	free_2dstring_int(data->map);
	exit(0);
	return (1);
}

int	number_elements_row(char *file_name)
{
	char	*str;
	char	**check;
	int		i;
	int		fd;

	i = 0;
	fd = open(file_name, O_RDONLY);
	str = get_next_line(fd);
	check = ft_split(str, ' ');
	free(str);
	while (check[i] && check[i][0] != '\n')
		i++;
	free_2dstring(check);
	close(fd);
	return (i);
}
