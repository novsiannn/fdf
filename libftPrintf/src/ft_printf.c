/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: novsiann <novsiann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 17:12:17 by novsiann          #+#    #+#             */
/*   Updated: 2023/01/10 15:07:13 by novsiann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	checking_percent(const char *str, int i, va_list arg)
{
	int	num;

	num = 0;
	if (str[i] == 'X' || str[i] == 'x')
		num += hex_main (str, va_arg(arg, unsigned int), i);
	if (str[i] == 'u')
		num += unsigned_int_area (va_arg(arg, unsigned int));
	if (str[i] == 'p')
		num += ptr_area (va_arg(arg, unsigned long long int));
	if ((str[i] == 'd' || str[i] == 'i'))
		num += print_nbr (va_arg(arg, int));
	if (str[i] == 's')
		num += print_str (va_arg(arg, char *));
	if (str[i] == 'c')
		num += print_char (va_arg(arg, int));
	if (str[i] == '%')
		num += print_char ('%');
	return (num);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		i;
	int		letters;

	va_start (arg, format);
	i = 0;
	letters = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			letters += checking_percent (format, i + 1, arg);
			i += 2;
		}
		else
		{
			write(1, &format[i], 1);
			i++;
			letters++;
		}
	}
	va_end (arg);
	return (letters);
}
