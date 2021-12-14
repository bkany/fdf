/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkany <bkany@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 13:37:07 by bkany             #+#    #+#             */
/*   Updated: 2020/06/25 13:14:13 by bkany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFDF_H
# define LIBFDF_H

# include "tools/libft/libft.h"
# include "parsing/get_next_line/get_next_line.h"
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <mlx.h>
# include <math.h>

#include <stdio.h>

# define PARAM 		11

/*
** STRUCTURES
*/

typedef struct			s_coord
{
	float				x;
	float				y;
	float				z;
	struct s_coord		*next;
}						t_coord;


typedef struct			s_vect
{
	float				x;
	float				y;
	float				z;
}						t_vect;

typedef struct			s_data
{
	void				*img;
	char				*addr;
	int					bits_per_pixel;
	int					line_length;
	int					endian;
}						t_data;

typedef struct 			s_env
{
	struct s_coord		*point1;
	int					nb_col;
	int					nb_row;
}						t_env;
/*
** INITIALISATION DES STRUCTURES
*/
t_coord					*ft_init_coord(float x, float y, float z);
t_vect					*ft_init_vect(float x, float y, float z);

/*
** PRINT DES STRUCTURES
*/
void					ft_print_coord(t_coord *coord);
void					ft_print_vect(t_vect *vect);

/*
** TOOLS
*/
t_coord 				*ft_last_pt(t_coord *point1);
void					ft_add_pt(t_coord *point1, t_coord *new_point);

/*
** FREE DES STRUCTURES
*/
void					ft_free_pt(t_coord *point);

/*
** REMPLISSAGE DE LA STRUCTURE SET
*/
int						ft_check_file_name(char *name);
int						ft_read_file_and_fill(char *file_name, t_env *env);

#endif
