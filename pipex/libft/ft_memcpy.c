/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lverkart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 13:57:07 by lverkart          #+#    #+#             */
/*   Updated: 2021/04/17 14:08:01 by lverkart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int		i;
	char	*dst2;
	char	*src2;

	if (dst == 0 && src == 0)
		return (dst);
	dst2 = (char *)dst;
	src2 = (char *)src;
	i = 0;
	while (i != (int)n)
	{
		dst2[i] = src2[i];
		i++;
	}
	return (dst);
}
