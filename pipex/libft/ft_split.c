/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lverkart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 17:03:05 by lverkart          #+#    #+#             */
/*   Updated: 2021/04/19 17:03:09 by lverkart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_split(char *s, char c)
{
	int	i;
	int	n;
	int	sumword;

	sumword = 0;
	i = 0;
	n = 0;
	while (s[i])
	{
		if (s[i] == c)
			n = 0;
		else if (n == 0)
		{
			sumword++;
			n = 1;
		}
		i++;
	}
	return (sumword);
}

static int	ft_count_two_split(char *s, char c)
{
	int	i;
	int	ret;

	ret = 0;
	i = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i] && s[i] != c)
	{
		ret++;
		i++;
	}
	return (ret);
}

static void	*ft_free_split_fail(char **buf, int i)
{
	int	n;

	n = 0;
	while (n < i)
	{
		free(buf[n]);
		n++;
	}
	free(buf);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**buf;
	int		i;
	int		count;
	int		n[2];

	if (!s)
		return (NULL);
	count = ft_count_split((char *)s, c);
	buf = malloc((count + 1) * sizeof(char *));
	if (buf == NULL)
		return (NULL);
	buf[count] = NULL;
	i = -1;
	n[1] = 0;
	while (++i < count)
	{
		while (s[n[1]] != '\0' && s[n[1]] == c)
			n[1]++;
		n[0] = ft_count_two_split((char *)&s[n[1]], c);
		buf[i] = ft_substr(s, n[1], n[0]);
		if (buf[i] == NULL)
			return (ft_free_split_fail(buf, i));
		n[1] += n[0];
	}
	return (buf);
}
