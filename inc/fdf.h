/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikitos <nikitos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 14:04:05 by novsiann          #+#    #+#             */
/*   Updated: 2023/06/23 19:15:04 by nikitos          ###   ########.fr       */
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
#include <stdio.h>
#include <fcntl.h>
#include <math.h>

// red color = 0xe80c0c
// white = 0xffffff

typedef struct	s_data{
	int		width;
	int		height;
	int		**map; // my already read map.
	int		zoom;
	int		color;
	int		shift_x;
	int		shift_y;

	void	*mlx_ptr;
	void	*win_ptr;
}t_data;

int		get_height(char *file_name);
int		get_width(char *file_name);
int		get_maxint(int a, int b);
int		deal_key(int keycode, t_data *data);

void	read_file(char *file_name, t_data *data);
void	bresenham(float x, float y,float x1, float x2, t_data *data);
void	free_2dstr(int **matrix, t_data *data);
void	draw(t_data *data);
void	zoom_map(t_data *data, int keycode);
void	size_map(t_data *data, int key);

float	mod(float n);
#endif