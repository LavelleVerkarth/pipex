/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lverkart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 21:59:43 by lverkart          #+#    #+#             */
/*   Updated: 2021/04/17 21:59:47 by lverkart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s12;
	unsigned char	*s22;
	size_t			i;

	s12 = (unsigned char *)s1;
	s22 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (s12[i] != s22[i])
			return (s12[i] - s22[i]);
		i++;
	}
	return (0);
}
