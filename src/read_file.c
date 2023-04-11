/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikitos <nikitos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 19:48:11 by nikitos           #+#    #+#             */
/*   Updated: 2023/04/10 20:15:04 by nikitos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int		get_height(char *file_name)
{
	int		height;
	int		fd;

	fd = open(file_name, O_RDONLY, 0);
	height = 0;
	while(get_next_line(fd))
	{
		height++;
	}
	close(fd);
	return (height);
}

void	read_file(char *file_name, t_data *data)
{
	data->height = get_height(file_name);
}