/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkany <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 13:19:04 by bkany             #+#    #+#             */
/*   Updated: 2019/12/11 15:21:10 by bkany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t		i;
	size_t		len_s2;

	i = 0;
	if (!*s2)
		return ((char *)(s1));
	len_s2 = ft_strlen(s2);
	while (s1[i] != '\0' && i < n)
	{
		if (ft_strncmp(s1 + i, s2, len_s2) == 0 && (i < (n - len_s2 + 1)))
			return ((char *)(s1 + i));
		else
			i++;
	}
	return (NULL);
}
