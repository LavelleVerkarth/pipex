/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lverkart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 22:15:30 by lverkart          #+#    #+#             */
/*   Updated: 2021/04/22 22:15:31 by lverkart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*buf;

	if (!new || !lst)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		buf = *lst;
		while (buf->next != NULL)
		{
			buf = buf->next;
		}
		buf->next = new;
	}
}
