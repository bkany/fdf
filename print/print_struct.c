/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkany <bkany@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 13:37:07 by bkany             #+#    #+#             */
/*   Updated: 2020/06/26 13:14:13 by bkany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	ft_print_coord(t_coord *coord)
{
	printf("Coordonnees Point\n");
	if (coord != NULL)
		printf("x = %f / y = %f / z = %f\n", coord->x, coord->y, coord->z);
	else
		printf("coord = NULL\n");
}

void	ft_print_vect(t_vect *vect)
{
	printf("Coordonnees Vecteur\n");
	if (vect != NULL)
		printf("x = %f / y = %f / z = %f\n", vect->x, vect->y, vect->z);
	else
		printf("vector = NULL\n");
}
