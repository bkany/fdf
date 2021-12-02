/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c	                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkany <bkany@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 15:00:53 by bkany             #+#    #+#             */
/*   Updated: 2019/11/30 16:27:40 by bkany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_nb_words(const char *s)
{
	size_t	count;
	int		i;

	count = 0;
	i = 0;
	if (!s)
		return (0);
	while (s[i] != 0)
	{
		while ((s[i] == ' ' || s[i] == '\t' || s[i] == '\r' ||
			s[i] == '\v' || s[i] == '\f') && s[i] != 0)
			i++;
		if (!(s[i] == ' ' || s[i] == '\t' || s[i] == '\r' ||
			s[i] == '\v' || s[i] == '\f') && s[i] != 0)
			count++;
		while (!(s[i] == ' ' || s[i] == '\t' || s[i] == '\r' ||
			s[i] == '\v' || s[i] == '\f') && s[i] != 0)
			i++;
	}
	return (count);
}

static size_t		ft_len_word(const char *s, size_t i)
{
	size_t	count;

	count = 0;
	while ((s[i] == ' ' || s[i] == '\t' || s[i] == '\r' ||
		s[i] == '\v' || s[i] == '\f') && s[i] != 0)
		i++;
	while (!(s[i] == ' ' || s[i] == '\t' || s[i] == '\r' ||
			s[i] == '\v' || s[i] == '\f') && s[i] != 0)
	{
		i++;
		count++;
	}
	return (count);
}

static size_t		ft_next_chr(const char *s, size_t i)
{
	size_t	j;

	j = i;
	while (!(s[j] == ' ' || s[j] == '\t' || s[j] == '\r' ||
			s[j] == '\v' || s[j] == '\f') && s[j])
		j++;
	return (j);
}

static char			**ft_free(char **res, size_t j)
{
	while (j--)
		free(res[j]);
	free(res);
	return (NULL);
}

char				**ft_split_ws(const char *s)
{
	char		**result;
	size_t		i;
	size_t		j;

	j = 0;
	if (!s)
		return (NULL);
	i = ft_next_chr(s, 0);
	i = (i == ft_strlen(s) && ft_nb_words(s) == 0) ? i : 0;
	if (!(result = (char **)malloc(sizeof(char *) * (ft_nb_words(s) + 1))))
		return (NULL);
	while (j <= ft_nb_words(s) && i != ft_strlen(s))
	{
		while (s[i] != 0 && (s[i] == ' ' || s[i] == '\t' || s[i] == '\r' ||
			s[i] == '\v' || s[i] == '\f'))
			i++;
		if (s[i] != 0 && !(s[i] == ' ' || s[i] == '\t' || s[i] == '\r' ||
			s[i] == '\v' || s[i] == '\f'))
		{
			if (!(result[j] = ft_substr(s, i, ft_len_word(s, i))))
				return (ft_free(result, j));
			j++;
		}
		i = ft_next_chr(s, i);
	}
	result[j] = NULL;
	return (result);
}
