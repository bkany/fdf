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

/*
static int		ft_exit(int i)
{
	(void)i;
	return (0);
}
*/

int main(int argc, char **argv)
{
	t_env	env;

	env = (t_env){0};
	if (argc == 2)
	{
		if (ft_check_file_name(argv[1]) == 1
			&& ft_read_file_and_fill(argv[1], &env) == 1)
			{
				//lancement du programme
				ft_free_pt(env.point1);
				return (0);
			}
		else
		{
			ft_free_pt(env.point1);
			return (1);
			// free des trucs du if à faire
		}
	}
	else
		return (1);
}
