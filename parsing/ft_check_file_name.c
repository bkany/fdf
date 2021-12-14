/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file_name.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkany <bkany@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 13:37:07 by bkany             #+#    #+#             */
/*   Updated: 2020/07/26 13:44:13 by bkany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

/*
** Retourne 1 si tout va bien, 0 sinon
*/
int		ft_check_file_name(char *name)
{
	int	error;
	int	i;

	error = 0;
	i = 0;
	if (name != NULL)
	{
		while (name[i] != 0)
			i++;
		if (name[i - 1] == 'f' && name[i - 2] == 'd' && name[i - 3] == 'f' && name[i - 4] == '.')
			error = 1;
	}
	return (error);
}
