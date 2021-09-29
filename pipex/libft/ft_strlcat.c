/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lverkart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 10:16:52 by lverkart          #+#    #+#             */
/*   Updated: 2021/04/18 10:16:59 by lverkart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = 0;
	while (dst[i] && i < dstsize)
		i++;
	while (src[n] && i + 1 < dstsize)
	{
		dst[i] = src[n];
		i++;
		n++;
	}
	if (i < dstsize)
		dst[i] = '\0';
	return (i + ft_strlen(src + n));
}
