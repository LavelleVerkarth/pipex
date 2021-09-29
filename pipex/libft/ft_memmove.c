/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lverkart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 21:01:43 by lverkart          #+#    #+#             */
/*   Updated: 2021/04/17 21:01:46 by lverkart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dst2;
	char	*src2;
	int		i;

	dst2 = (char *)dst;
	src2 = (char *)src;
	i = 0;
	if (dst2 > src2)
	{
		while (len > 0)
		{
			len--;
			dst2[len] = src2[len];
		}
	}
	else if (dst2 < src2)
	{
		while (i < (int)len)
		{
			dst2[i] = src2[i];
			i++;
		}
	}
	return (dst);
}
