/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikitos <nikitos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 19:48:11 by nikitos           #+#    #+#             */
/*   Updated: 2023/06/22 21:38:32 by nikitos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	get_height(char *file_name)
{
	int	height;
	int fd = open(file_name, O_RDONLY);

	if (fd == -1)
	{
		ft_printf("Error file.");
		exit (0);
	}
	height = 0;
	while(get_next_line(fd))
		height++;
	close(fd);
	return (height);
}

int	get_width(char *file_name)
{
	char	*line;
	int		width;
	int		fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error file.");
		exit (0);
	}
	line = get_next_line(fd);
	if(!line)
	{
		ft_printf("Can't read file");
		exit(0);	
	}
	width = count_words(line, ' ');
	free(line);
	close(fd);
	return (width);
}

void fill_map(int *map_line, char *line)
{
	char	**nums;
	int		i;

	nums = ft_split(line, ' ');
	i = 0;
	while(nums[i])
	{
		map_line[i] = ft_atoi(nums[i]);
		free(nums[i]);
		i++;
	}
	free(nums);
}

void	read_file(char *file_name, t_data *data)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	data->height = get_height(file_name);
	data->width = get_width(file_name);
	data->map = (int **)malloc(sizeof(int *) * (data->height + 1));
	while(i <= data->height)
		data->map[i++] = (int *)malloc(sizeof(int) * (data->width + 1));
	 i = 0;
	 fd = open(file_name, O_RDONLY);
	 while((line = get_next_line(fd)))
	 {
	 	fill_map(data->map[i], line);
		free(line);
		i++;
	 }
	 data->map[i] = NULL;
	 close(fd);
}