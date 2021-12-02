/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkany <bkany@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 13:37:07 by bkany             #+#    #+#             */
/*   Updated: 2019/12/08 14:00:35 by bkany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	n;

	n = ft_strlen(s);
	if (c == '\0')
		return ((char *)s + n);
	while (n >= 0)
	{
		if (s[n] == (char)c)
			return ((char *)s + n);
		n--;
	}
	return (NULL);
}
