/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lverkart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 20:18:48 by lverkart          #+#    #+#             */
/*   Updated: 2021/04/19 20:18:50 by lverkart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_itoa_part_two(int minus, int i, int n)
{
	char	*ret;

	ret = malloc((i + 1 + minus) * sizeof(char));
	if (!ret)
		return (NULL);
	ret[i + minus] = '\0';
	while (--i >= 0)
	{
		ret[i + minus] = n % 10 + 48;
		n = n / 10;
	}
	if (minus)
		ret[0] = '-';
	return (ret);
}

char	*ft_itoa(int n)
{
	int		i;
	int		del;
	int		minus;

	minus = 0;
	i = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	if (n < 0)
	{
		n = -n;
		minus++;
	}
	del = n;
	while (del)
	{
		del = del / 10;
		i++;
	}
	return (ft_itoa_part_two(minus, i, n));
}
