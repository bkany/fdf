/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkany <bkany@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 16:38:58 by bkany             #+#    #+#             */
/*   Updated: 2020/01/28 16:36:53 by bkany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

# define BUFFER_SIZE 40

int		get_next_line(int fd, char **line);
char	*ft_strjoin_get(char *s1, char *s2, int size1, int size2);
int		ft_strlen_get(char *s, char c);
char	*ft_strcpy_get(char *dst, char *src);
int		ft_read(int fd, char **tmp);
char	*ft_crop(char *s, int start, int size);
int		ft_cut(char **tmp, char **line, char c);
int		ft_emptystr(char **line);
char	*ft_strdup_get(char *s1);
int		ft_findchar(char *s, char c);

#endif
