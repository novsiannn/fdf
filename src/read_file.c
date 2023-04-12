/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikitos <nikitos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 19:48:11 by nikitos           #+#    #+#             */
/*   Updated: 2023/04/12 21:33:09 by nikitos          ###   ########.fr       */
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

int get_width(char *file_name)
{
	int		width;
	int		fd;
	char	*line;

	fd = open(file_name, O_RDONLY, 0);
	line = get_next_line(fd);
	width = count_words(line, ' ');
	free(line);
	close(fd);
	return (width);
}

void	read_file(char *file_name, t_data *data)
{
	data->height = get_height(file_name);
	data->width = get_width(file_name);
}