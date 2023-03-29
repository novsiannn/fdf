/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: novsiann <novsiann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 11:32:40 by novsiann          #+#    #+#             */
/*   Updated: 2023/01/10 15:13:49 by novsiann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_ptr(char *hex, int j, unsigned long long int dec)
{
	char	temp;
	int		i;
	char	string_hex[100];

	i = 0;
	while (dec > 0)
	{
		string_hex[i++] = hex[dec % 16];
		dec /= 16;
	}
	string_hex[i] = '\0';
	i--;
	while (i > j)
	{
		temp = string_hex[i];
		string_hex[i] = string_hex[j];
		string_hex[j] = temp;
		i--;
		j++;
	}
	j = 0;
	while (string_hex[j])
		write(1, &string_hex[j++], 1);
	return (j);
}

int	ptr_area(unsigned long long int dec)
{
	int		j;
	char	*heximal;

	heximal = "0123456789abcdef";
	j = 0;
	if (dec == 0)
	{
		write (1, "0x0", 3);
		return (3);
	}
	write (1, "0x", 2);
	j = print_ptr (heximal, j, dec);
	return (j + 2);
}
