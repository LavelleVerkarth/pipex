/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lverkart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 14:34:49 by lverkart          #+#    #+#             */
/*   Updated: 2021/04/19 14:34:51 by lverkart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_chek_str_streim(char s1, char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == s1)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	l;
	size_t	i;
	size_t	n;

	i = 0;
	if (!s1)
		return (NULL);
	l = ft_strlen(s1);
	n = l - 1;
	while (s1[i] && ft_chek_str_streim(s1[i], (char *)set))
		i++;
	if (i == l)
		return (ft_strdup(""));
	while (ft_chek_str_streim(s1[n], (char *)set))
		n--;
	l -= (l - n - 1) + i;
	str = (char *)malloc(sizeof(char) * l + 1);
	if (!str)
		return (NULL);
	ft_memcpy(str, s1 + i, l);
	str[l] = '\0';
	return (str);
}
