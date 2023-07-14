/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: novsiann <novsiann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 14:04:05 by novsiann          #+#    #+#             */
/*   Updated: 2023/07/14 21:56:17 by novsiann         ###   ########.fr       */
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
	int		**map;
	float	zoom;
	float	zoom_height;
	int		color;
	int		shift_x;
	int		shift_y;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		win_width;
	int		win_height;
	int		constant;
	int		isometric;
	int		x;
	int		y;
	int		x1;
	int		y1;
	int		z;
	int		z1;

	char	*addr;
	void	*img;
	void	*mlx_ptr;
	void	*win_ptr;
}t_data;

int		get_height(char *file_name);
int		get_width(char *file_name);
int		get_maxint(int a, int b);
int		deal_key(int keycode, t_data *data);
int		test(int keycode, t_data *data);

void	read_file(char *file_name, t_data *data);
void	drawing_line(t_data *data);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	free_2dstr(int **matrix, t_data *data);
void	draw_map(t_data *data);
void	zoom_and_isometric(t_data *data, int keycode);
void	size_map(t_data *data, int key);
void	isometric(int *x, int *y, int z);
void	get_color(t_data *data);
void	free_2dstring(int **matrix, t_data *data);

float	mod(float n);
#endif