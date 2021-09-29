/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lverkart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 14:51:45 by lverkart          #+#    #+#             */
/*   Updated: 2021/04/23 14:51:47 by lverkart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*buf;

	if (!lst || !f)
		return ;
	buf = lst;
	while (buf)
	{
		f(buf->content);
		buf = buf->next;
	}
}
