/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkany <bkany@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 16:41:17 by bkany             #+#    #+#             */
/*   Updated: 2021/08/03 20:40:44 by bkany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char		*s2;
	size_t		i;
	size_t		n;

	i = 0;
	n = ft_strlen(s1);
	s2 = (char *)malloc(sizeof(char) * (n + 1));
	if (!s2)
		return (NULL);
	while (s1[i] != 0)
	{
		s2[i] = ((char *)s1)[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
