/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkany <bkany@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 16:38:13 by bkany             #+#    #+#             */
/*   Updated: 2020/01/28 16:51:43 by bkany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int				ft_strlen_get(char *s, char c)
{
	int			i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != 0 && s[i] != c)
		i++;
	return (i);
}

char			*ft_strcpy_get(char *dst, char *src)
{
	int			i;
	int			n;

	i = 0;
	n = ft_strlen_get(src, 0);
	if (dst == NULL)
		return (NULL);
	while (i < n && src[i] != 0)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (dst);
}

char			*ft_strjoin_get(char *s1, char *s2, int si1, int si2)
{
	int			i;
	int			j;
	char		*result;

	i = 0;
	j = 0;
	if (!(result = (char *)malloc(sizeof(char) * (si1 + si2 + 1))))
		return (NULL);
	while (s1 && s1[i] != 0 && i < si1)
	{
		result[i] = s1[i];
		i++;
	}
	free(s1);
	s1 = NULL;
	while (s2 && s2[j] != 0 && (j < si2))
		result[i++] = s2[j++];
	result[i] = '\0';
	return (result);
}

char			*ft_crop(char *s, int start, int size)
{
	int			i;
	int			j;
	char		*result;

	i = 0;
	j = start;
	if (!(result = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (s && s[j] != 0 && (j < (start + size)))
		result[i++] = s[j++];
	result[i] = '\0';
	return (result);
}

char			*ft_strdup_get(char *s1)
{
	char		*s2;
	size_t		i;
	size_t		n;

	i = 0;
	n = ft_strlen_get(s1, 0);
	if (!(s2 = (char *)malloc(sizeof(char) * (n + 1))))
		return (NULL);
	while (s1[i] != 0)
	{
		s2[i] = ((char *)s1)[i];
		i++;
	}
	s2[i] = '\0';
	free(s1);
	return (s2);
}
