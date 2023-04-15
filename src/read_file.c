/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: novsiann <novsiann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 19:48:11 by nikitos           #+#    #+#             */
/*   Updated: 2023/04/15 15:30:47 by novsiann         ###   ########.fr       */
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

void	fill_matrix(int *z_line, char *line)
{
	char	**nums;
	int		i;

	nums = ft_split(line, ' ');
	i = 0;
	while(nums[i])
	{
		z_line[i] =  ft_atoi(nums[i]);
		free(nums[i]);
		i++;
	}
	free(nums);
}

void	read_file(char *file_name, t_data *data)
{
	int fd;
	int i;
	char *line;

	data->height = get_height(file_name);
	data->width = get_width(file_name);

	data->z_matrix = (int **)malloc(sizeof(int *) * (data->height + 1));
	i = 0;
	while (i <= data->height)
		data->z_matrix[i++] = (int *)malloc(sizeof(int) * (data->width + 1));
	fd = open(file_name, O_RDONLY, 0);
	i = 0;
	while((line = get_next_line(fd)))
	{
		fill_matrix(data->z_matrix[i], line);
		free(line);
		i++;
	}
	data->z_matrix[i] = NULL;
}