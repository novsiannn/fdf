/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: novsiann <novsiann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:16:33 by novsiann          #+#    #+#             */
/*   Updated: 2023/01/10 15:15:32 by novsiann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	length_un_int(unsigned int num)
{
	int	counter;

	counter = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		num /= 10;
		counter++;
	}
	return (counter);
}

static void	write_unsigned_n(unsigned int n)
{
	n += 48;
	write(1, &n, 1);
}

static void	print_unsigned_n(unsigned int n)
{
	if (n >= 10)
	{
		print_unsigned_n (n / 10);
		write_unsigned_n (n % 10);
	}
	else
		write_unsigned_n (n);
}

int	unsigned_int_area(unsigned int n)
{
	print_unsigned_n (n);
	return (length_un_int(n));
}
