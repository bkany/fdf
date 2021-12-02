/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkany <bkany@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 15:10:29 by bkany             #+#    #+#             */
/*   Updated: 2019/12/08 12:33:25 by bkany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t		i;
	size_t		n;

	i = 0;
	n = ft_strlen(s);
	if (!s)
		return (NULL);
	if (c == '\0')
		return ((char *)s + n);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)(s) + i);
		i++;
	}
	return (NULL);
}
