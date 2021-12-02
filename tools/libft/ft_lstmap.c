/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkany <bkany@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 13:13:22 by bkany             #+#    #+#             */
/*   Updated: 2019/11/30 16:03:31 by bkany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst2;
	t_list	*lst2init;

	if (!lst || !f)
		return (NULL);
	if (!(lst2 = ft_lstnew((*f)(lst->content))))
		return (NULL);
	lst2init = lst2;
	while (lst)
	{
		if (lst->next)
		{
			if (!(lst2->next = ft_lstnew((*f)(lst->next->content))))
			{
				ft_lstclear(&lst2init, del);
				return (NULL);
			}
			lst2 = lst2->next;
		}
		lst = lst->next;
	}
	return (lst2init);
}
