/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkany <bkany@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 13:37:07 by bkany             #+#    #+#             */
/*   Updated: 2020/07/26 13:44:13 by bkany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

/*
static int		ft_exit(int i)
{
	(void)i;
	return (0);
}
*/

int main(int argc, char **argv)
{
	t_coord	*point1;

	point1 = NULL;
	if (argc == 2)
	{
		if (ft_check_file_name(argv[1]) == 1
			&& ft_read_file_and_fill(argv[1], point1) == 1)
			{
				//lancement du programme
				printf("coucou2");
				ft_free_pt(point1);
				return (0);
			}
		else
		{
			printf("coucou");
			return (1);
			// free des trucs du if à faire
		}
	}
	else
		return (1);
}
