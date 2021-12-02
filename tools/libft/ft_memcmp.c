/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkany <bkany@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 17:24:15 by bkany             #+#    #+#             */
/*   Updated: 2019/12/08 14:05:51 by bkany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int		ft_memcmp(const void *dst, const void *src, size_t n)
{
	size_t		i;
	int			result;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)dst)[i] != ((unsigned char *)src)[i])
		{
			result = ((unsigned char *)dst)[i] - ((unsigned char *)src)[i];
			return (result);
		}
		i++;
	}
	return (0);
}
