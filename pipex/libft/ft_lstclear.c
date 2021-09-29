/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lverkart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 12:27:07 by lverkart          #+#    #+#             */
/*   Updated: 2021/04/23 12:27:08 by lverkart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_recurs_lstclear(t_list *lst, void (*del)(void*))
{
	if (lst->next != NULL)
		ft_recurs_lstclear(lst->next, del);
	del(lst->content);
	free(lst);
}

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	if (!*lst)
		return ;
	ft_recurs_lstclear(*lst, del);
	*lst = NULL;
}
