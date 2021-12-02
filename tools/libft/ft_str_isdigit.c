/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_isdigit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkany <bkany@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 13:37:07 by bkany             #+#    #+#             */
/*   Updated: 2020/07/26 13:44:13 by bkany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_str_isdigit(char *s)
{
	int	i;

	i = 0;
	if (s != NULL)
	{
		while (s[i] != 0)
		{
			if (s[i] != '.' && s[i] != '-' && ft_isdigit(s[i]) == 0)
				return (0);
			else
				i++;
		}
	}
	return (1);
}

int	ft_strstr_isdigit(char **s)
{
	int	i;

	i = 0;
	if (s != NULL)
	{
		while (s[i] != NULL)
		{
			if (ft_str_isdigit(s[i]) == 0)
				return (0);
			else
				i++;
		}
	}
	return (1);
}
