/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkany <bkany@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 10:57:16 by bkany             #+#    #+#             */
/*   Updated: 2019/11/30 16:08:52 by bkany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_chr_in_set(const char *set, char c)
{
	int	i;

	i = 0;
	while (set[i] != 0)
	{
		if (set[i] == c)
			return (1);
		else
			i++;
	}
	return (0);
}

char		*ft_strtrim(const char *s1, const char *set)
{
	size_t	i;
	size_t	j;
	char	*result;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	if (ft_strlen(s1) == 0)
		return (ft_strdup(""));
	j = ft_strlen(s1) - 1;
	while (ft_chr_in_set(set, s1[i]) && s1[i] != 0 && i < ft_strlen(s1) - 1)
		i++;
	while (ft_chr_in_set(set, s1[j]) && s1[j] != 0 && j > 0)
		j--;
	if (i < j)
	{
		if (!(result = (char *)malloc((j - i + 2) * sizeof(char))))
			return (NULL);
		result = ft_substr(s1, i, (j - i + 1));
	}
	else
		result = ft_strdup("");
	return (result);
}
