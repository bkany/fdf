/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkany <bkany@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 13:13:22 by bkany             #+#    #+#             */
/*   Updated: 2019/12/11 13:38:06 by bkany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*str;

	if (dst == 0 && src == 0)
		return (dst);
	str = dst;
	i = 0;
	while (i < n)
	{
		str[i] = ((char *)src)[i];
		i++;
	}
	return (dst);
}
