/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikitos <nikitos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 14:42:14 by nikitos           #+#    #+#             */
/*   Updated: 2023/01/07 13:06:02 by nikitos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t dstsize)
{	
	size_t	i;
	size_t	k;
	size_t	res;

	i = 0;
	k = 0;
	res = ft_strlen (dst) + ft_strlen (src);
	if (ft_strlen (dst) >= dstsize)
		return (ft_strlen (src) + dstsize);
	while (dst[k])
		k++;
	while (src[i] && k < dstsize - 1)
	{
		dst[k] = src[i];
		k++;
		i++;
	}
	dst[k] = '\0';
	return (res);
}
