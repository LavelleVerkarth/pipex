/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lverkart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 13:49:02 by lverkart          #+#    #+#             */
/*   Updated: 2021/04/18 13:49:07 by lverkart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i] && n > 0)
	{
		i++;
		n--;
		if (n == 0)
			return (0);
	}
	if (!n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
