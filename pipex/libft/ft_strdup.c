/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lverkart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 10:58:53 by lverkart          #+#    #+#             */
/*   Updated: 2021/04/19 10:58:55 by lverkart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*copy;
	int		i;

	i = ft_strlen(s1);
	copy = (char *)malloc(sizeof(char) * i + 1);
	if (!copy)
		return (0);
	copy[i] = '\0';
	while (i >= 0)
	{
		copy[i] = s1[i];
		i--;
	}
	return (copy);
}
