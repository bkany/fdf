/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkany <bkany@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 13:37:07 by bkany             #+#    #+#             */
/*   Updated: 2020/07/26 13:44:13 by bkany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static int ft_check_file(char *file_name, t_env *env, int fd)
{
	int		error;
	int		error2;
	char	*line;
	char	**tab_line;

	error = 1;
	tab_line = NULL;
	line = NULL;
	error2 = ft_check_file_name(file_name);
	while ((error = get_next_line(fd, &line)) > 0 && error2 == 1)
	{
		tab_line = ft_split(line, ' ');
		if (ft_strstr_isdigit(tab_line) != 1)
			error2 = -1;
		env->nb_row++;
		ft_free_tabtab(tab_line);
		free(line);
	}
	free(line);
	return (error2);
}

static int	ft_fill(t_env *env, int fd)
{
	int		error;
	int		error2;
	char	*line;
	char	**tab_line;
	int		z;
	int		x;
	t_coord	*point;

	error = 1;
	error2 = 1;
	tab_line = NULL;
	line = NULL;
	z = 0;
	x = 0;
	point = NULL;
	while ((error = get_next_line(fd, &line)) > 0 && error2 == 1)
	{
		tab_line = ft_split(line, ' ');
		while (tab_line[z] != NULL)
		{
			if (env->point1 == NULL)
			{
				env->point1 = ft_init_coord(x, ft_atoi(tab_line[z]), z);
				env->nb_col++;
				if (env->point1 == NULL)
					error2 = -1;
			}
			else
			{
				point = ft_init_coord(x, ft_atoi(tab_line[z]), z);
				if (point != NULL)
					ft_last_pt(env->point1)->next = point;
				else
					error2 = -1;
			}
			z++;
		}
		z = 0;
		x++;
		ft_free_tabtab(tab_line);
		free(line);
	}
	free(line);
	if (env->point1 != NULL)
		ft_last_pt(env->point1)->next = NULL;
	return (error2);
}

/*
** Retourne 0 si ça se passe mal
** 1 sinon
*/
int		ft_read_file_and_fill(char *file_name, t_env *env)
{
	int fd;
	int result;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		result = 0;
	else
		result = ft_check_file(file_name, env, fd) * ft_fill(env, fd);
	close(fd);
	return (result);

}
