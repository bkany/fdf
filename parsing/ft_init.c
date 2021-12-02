/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkany <bkany@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 13:37:07 by bkany             #+#    #+#             */
/*   Updated: 2020/06/26 13:14:13 by bkany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

/*
** Init a point
*/
t_coord					*ft_init_coord(float x, float y, float z)
{
	t_coord				*point;

	if (!(point = (t_coord *)malloc(sizeof(t_coord) * 1)))
		return (NULL);
	point->x = x;
	point->y = y;
	point->z = z;
	point->next = NULL;
	return (point);
}

/*
** Add a new point
*/
void					ft_add_pt(t_coord *point1, t_coord *new_point)
{
	(ft_last_pt(point1))->next = new_point;
}

/*
** Get the last point
*/
t_coord 				*ft_last_pt(t_coord *point)
{
	while (point != NULL && point->next != NULL)
	{
		point = point->next;
	}
	return (point);
} 

/*
** Init a vect
*/
t_vect					*ft_init_vect(float x, float y, float z)
{
	t_vect				*vector;

	if (!(vector = (t_vect *)malloc(sizeof(t_vect) * 1)))
		return (NULL);
	vector->x = x;
	vector->y = y;
	vector->z = z;
	return (vector);
}
