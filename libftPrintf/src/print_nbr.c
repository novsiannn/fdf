/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: novsiann <novsiann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 09:56:19 by novsiann          #+#    #+#             */
/*   Updated: 2023/01/10 15:12:57 by novsiann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_length_nbr(int n)
{
	int	counter;

	counter = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		counter++;
	}
	while (n != 0)
	{
		n /= 10;
		counter++;
	}
	return (counter);
}

static void	number_writer(int p)
{
	p += 48;
	write (1, &p, 1);
}

static void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		write (1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		n *= -1;
		write (1, "-", 1);
	}
	if (n >= 10)
	{
		ft_putnbr (n / 10);
		number_writer (n % 10);
	}
	else
		number_writer (n);
}

int	print_nbr(int nbr)
{
	ft_putnbr(nbr);
	return (get_length_nbr(nbr));
}
