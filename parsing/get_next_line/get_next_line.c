/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkany <bkany@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 16:37:36 by bkany             #+#    #+#             */
/*   Updated: 2020/01/28 17:15:03 by bkany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int					ft_findchar(char *s, char c)
{
	int				i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != 0)
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int					ft_read(int fd, char **tmp)
{
	char			*buf;
	int				ret;
	int				i;

	i = 0;
	if (!(buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	buf[0] = 0;
	while ((ft_findchar(buf, '\n') == 0) &&
			((ret = read(fd, buf, BUFFER_SIZE)) > 0))
	{
		buf[ret] = 0;
		i = ft_strlen_get(*tmp, 0);
		if ((*tmp = ft_strjoin_get(*tmp, buf, i, ret)) == NULL)
			return (-1);
	}
	free(buf);
	return (ret);
}

int					ft_cut(char **tmp, char **line, char c)
{
	int				interm;
	char			*tmp2;

	tmp2 = NULL;
	if ((*line = ft_crop(*tmp, 0, ft_strlen_get(*tmp, c))) == NULL)
		return (-1);
	if (c == '\n')
	{
		interm = ft_strlen_get(*tmp, 0) - ft_strlen_get(*tmp, c) - 1;
		tmp2 = ft_crop(*tmp, (ft_strlen_get(*tmp, c) + 1), interm);
		free(*tmp);
		*tmp = ft_strdup_get(tmp2);
		return (1);
	}
	else if (c == 0)
	{
		free(*tmp);
		*tmp = NULL;
		return (0);
	}
	return (-1);
}

int					ft_emptystr(char **line)
{
	if (!(*line = (char *)malloc(sizeof(char))))
		return (-1);
	(*line)[0] = 0;
	return (0);
}

int					get_next_line(int fd, char **line)
{
	static char		*tmp;
	int				ret;

	if (fd < 0 || fd > 1023 || BUFFER_SIZE <= 0)
		return (-1);
	if (tmp != NULL && (ft_findchar(tmp, '\n') == 1))
		return (ft_cut(&tmp, &*line, '\n'));
	if ((ret = ft_read(fd, &tmp)) < 0)
		return (-1);
	if (ret == BUFFER_SIZE)
		return (ft_cut(&tmp, &*line, '\n'));
	else
	{
		if (tmp != NULL && (ft_findchar(tmp, '\n') == 1))
			return (ft_cut(&tmp, &*line, '\n'));
		else if (tmp != NULL)
			return (ft_cut(&tmp, &*line, 0));
		else
			return (ft_emptystr(&*line));
	}
}
