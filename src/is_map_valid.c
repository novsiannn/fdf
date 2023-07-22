/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: novsiann <novsiann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 13:02:31 by novsiann          #+#    #+#             */
/*   Updated: 2023/07/22 14:25:10 by novsiann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	check_arr(char **str, int elem)
{
	int	j;
	int	k;

	j = 0;
	while (str[j])
	{
		k = 0;
		while (str[j][k] && str[j][k] != '\n' && str[j][k] != ',')
		{
			if (ft_isdigit(str[j][k]) == 0 && string_check(str[j], k) == 0)
			{
				free_2dstring(str);
				return (1);
			}
			k++;
		}
		j++;
	}
	if (j != elem)
		return (1);
	return (0);
}

int	check_map(char *file_name, t_data *data)
{
	int		fd;
	int		i;
	char	*line;
	char	**str;
	int		elem;

	fd = open(file_name, O_RDONLY);
	elem = number_elements_row(file_name);
	i = 0;
	while (i < data->height)
	{
		line = get_next_line(fd);
		str = remove_nextline_and_spaces(line);
		free(line);
		if (check_arr(str, elem) == 1)
			return (1);
		free_2dstring(str);
		i++;
	}
	close(fd);
	return (0);
}

void	is_map_valid(char *file_name, t_data *data)
{
	if (check_map(file_name, data) == 1)
	{
		printf("error invalid map\n");
		esc_invalid_map(data);
	}
}
