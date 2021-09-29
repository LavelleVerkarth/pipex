/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lverkart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 13:01:21 by lverkart          #+#    #+#             */
/*   Updated: 2021/04/18 13:01:23 by lverkart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	n;

	if (needle[0] == '\0')
		return ((char *)haystack);
	if (len == 0)
		return (NULL);
	i = 0;
	while (haystack[i] && i < len)
	{
		n = 0;
		if (haystack[i] == needle[n])
		{
			while (needle[n] && haystack[n + i] && haystack[n + i] == needle[n]
				&& (n + i) < len)
				n++;
			if (!needle[n])
				return ((char *)(haystack + i));
		}
		i++;
	}
	return (NULL);
}
