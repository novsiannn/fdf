/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_area.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: novsiann <novsiann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:07:47 by novsiann          #+#    #+#             */
/*   Updated: 2023/01/10 15:11:28 by novsiann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	hex_convert(int j, const char *hex, unsigned int dec)
{
	char	string_hex[100];
	char	temp;
	int		i;

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
		j++;
		i--;
	}
	i = 0;
	while (string_hex[i])
		write (1, &string_hex[i++], 1);
	return (i);
}

static int	hex_convert_lower(unsigned int dec)
{
	char	*heximal;
	int		j;

	j = 0;
	heximal = "0123456789abcdef";
	j = hex_convert (j, heximal, dec);
	return (j);
}

static int	hex_convert_upper(unsigned int dec)
{
	char	*heximal;
	int		j;

	j = 0;
	heximal = "0123456789ABCDEF";
	j = hex_convert (j, heximal, dec);
	return (j);
}

int	hex_main(const char *str, unsigned int arg, int i)
{
	if (arg == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	if (str[i] == 'X')
		return (hex_convert_upper (arg));
	if (str[i] == 'x')
		return (hex_convert_lower (arg));
	return (0);
}
