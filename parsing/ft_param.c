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

int	ft_read_file_and_fill(char *file_name, t_coord *point1)
{
	int		fd;
	int		error;
	int		error2;
	char	*line;
	char	**tab_line;
	int		nb_col;
	int		nb_row;
	int		z;
	int		x;
	t_coord	*point;

	error = 1;
	error2 = 1;
	tab_line = NULL;
	line = NULL;
	nb_col = 0;
	nb_row = 0;
	z = 0;
	x = 0;
	point = NULL;
	fd = open(file_name, O_RDONLY);
	
	// on lit le fichier ligne par ligne si aucun problème ne se présente
	while ((error = get_next_line(fd, &line)) > 0 && error2 == 1)
	{
		printf("tab_line = %s\n",line);
		
		tab_line = ft_split(line, ' ');
		// traitement de la ligne si elle n'est constituée que de nombres
		if (ft_strstr_isdigit(tab_line) == 1)
		{
			nb_row++;
			while (tab_line[z] != NULL)
			{
				
				//remplissage du point 1;
				if (point1 == NULL)
				{
					point1 = ft_init_coord(x, ft_atoi(tab_line[z]), z);
					if (point1 == NULL)
						error2 = -1;
				}
				// Remplissage de la suite de point
				else
				{
					point = ft_init_coord(x, ft_atoi(tab_line[z]), z);
					if (point != NULL)
						ft_last_pt(point1)->next = point;
					else
						error2 = -1;
				}
				z++;
			}
			x++;
			printf("x = %i\n", x);
		}
		else
		{
			error2 = -1;
		}
	}
	if (fd == -1)
		error2 = -1;
	free(line);
	close(fd);
	
	// On affecte le next du dernier point à NULL
	if (point1 != NULL)
	{
		ft_last_pt(point1)->next = NULL;
	}
	return (error2);
}
