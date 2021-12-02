/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkany <bkany@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 13:37:07 by bkany             #+#    #+#             */
/*   Updated: 2020/06/26 13:14:13 by bkany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_power(int n, int p)
{
	if (p == 0 && n == 0)
		return (0);
	if (p == 1)
		return (n);
	if (p == 0)
		return (1);
	else
		return (n * ft_power(n, p - 1));
}

static int		ft_strlen_tabtab(char **s)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

float			ft_atof(char *s)
{
	float	f;
	char	**tab;

	tab = ft_split(s, '.');
	if (ft_strlen_tabtab(tab) == 2)
	{
		f = ft_atoi(tab[1]) + ft_atoi(tab[0]) * ft_power(10, ft_strlen(tab[1]));
		f = f / ft_power(10, ft_strlen(tab[1]));
		free(tab[0]);
		free(tab[1]);
	}
	else
		f = ft_atoi(tab[0]);
	free(tab);
	return (f);
}
