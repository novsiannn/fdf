/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: novsiann <novsiann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 14:04:05 by novsiann          #+#    #+#             */
/*   Updated: 2023/04/15 18:04:34 by novsiann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WINDOW_WIDTH 1280
# define WINDOW_HEIGHT 1020

#include "../libftPrintf/libft/libft.h"
#include "../libftPrintf/printf/ft_printf.h"
#include "../libftPrintf/libft/get_next_line_bonus.h"
#include "../mlx/mlx.h"
#include <fcntl.h>

typedef struct	s_data{
	int		width;
	int		height;
	int		**z_matrix; //z coordinates

	void	*mlx_ptr;
	void	*win_ptr;
}t_data;

int		close_window(int keycode, t_data *data);
int		get_height(char *file_name);
int		get_width(char *file_name);

void	read_file(char *file_name, t_data *data);
void	bresenhem_algorithm(float x, float y,float x1, float x2, t_data *data);
#endif