/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lverkart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 21:44:08 by lverkart          #+#    #+#             */
/*   Updated: 2021/04/17 21:44:10 by lverkart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*s2;
	size_t	i;

	i = 0;
	s2 = (char *)s;
	while (i < n)
	{
		if (s2[i] == c)
			return (&s2[i]);
		i++;
	}
	return (NULL);
}
