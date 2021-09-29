/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lverkart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 08:39:02 by lverkart          #+#    #+#             */
/*   Updated: 2021/04/18 08:39:05 by lverkart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	const char	*s2;
	size_t		i;

	s2 = src;
	i = dstsize;
	if (!src)
		return (0);
	if (i != 0)
	{
		while (--i != 0)
		{
			*dst = *src;
			if (*dst == '\0')
				break ;
			dst++;
			src++;
		}
	}
	if (dstsize != 0)
		*dst = '\0';
	while (*src)
		src++;
	return (src - s2);
}
