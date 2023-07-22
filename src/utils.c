/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: novsiann <novsiann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 22:20:25 by nikitos           #+#    #+#             */
/*   Updated: 2023/07/22 16:47:06 by novsiann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	get_maxint(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

float	mod(float n)
{
	if (n < 0)
		n *= -1;
	return (n);
}

void	free_2dstring_int(int **matrix)
{
	int	i;

	i = 0;
	while (matrix[i] != NULL)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

void	free_2dstring(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i] != NULL)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

int	string_check(char *s, int k)
{
	if (((s[k] == '-' && k == 0) || (s[k] == '+' && k == 0)) \
	&& ft_isdigit(s[k + 1]) == 1)
		return (1);
	return (0);
}
