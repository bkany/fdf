/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkany <bkany@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 13:13:22 by bkany             #+#    #+#             */
/*   Updated: 2019/11/30 15:43:26 by bkany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *tmp;
	t_list *tmp2;

	tmp = *lst;
	if (*lst != NULL || *del != NULL)
	{
		while (tmp != NULL)
		{
			tmp2 = tmp->next;
			ft_lstdelone(tmp, del);
			tmp = tmp2;
		}
		*lst = NULL;
	}
}
