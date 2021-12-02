/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkany <bkany@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 15:00:53 by bkany             #+#    #+#             */
/*   Updated: 2021/08/03 20:38:33 by bkany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_size(int n)
{
	int	i;

	i = 1;
	if (n == -2147483648)
		return (10);
	while (n >= 10 || n <= -10)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

char	*ft_itoa(int nb)
{
	int			size;
	char		*result;
	long int	n;

	n = nb;
	size = ft_count_size(n);
	if (n < 0)
		size = ft_count_size(n) + 1;
	result = (char *)malloc(sizeof(char) * (size + 1));
	if (!result)
		return (NULL);
	if (n < 0)
	{
		n = n * (-1);
		result[0] = '-';
	}
	result[size] = '\0';
	while (n >= 10)
	{
		result[size - 1] = n % 10 + '0';
		size--;
		n = n / 10;
	}
	result[size - 1] = n + '0';
	return (result);
}
