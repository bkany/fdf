/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkany <bkany@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 13:37:07 by bkany             #+#    #+#             */
/*   Updated: 2020/07/26 13:44:13 by bkany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

/*
** Free a serie of points
*/
void		ft_free_pt(t_coord *point1)
{
	t_coord		*tmp;
	t_coord		*tmp2;

	tmp = NULL;
	tmp2 = NULL;
	if (point1 != NULL)
	{
		tmp = point1;
		while (tmp)
		{
			tmp2 = tmp->next;
			tmp->next = NULL;
			free(tmp);
			tmp = tmp2;
		}
		tmp = NULL;
	}
}

void		ft_free_tabtab(char **tab)
{
	int				i;

	i = 0;
	if (tab != NULL)
	{
		if (tab[0] != NULL)
		{
			while (tab[i] != NULL)
			{
				free(tab[i]);
				i++;
			}
		}
		free(tab);
		tab = NULL;
	}
}