/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 10:05:35 by lbrochar          #+#    #+#             */
/*   Updated: 2022/07/16 10:35:19 by lbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
	{
		dest[i + j] = src[j];
		j++;
	}
	return (dest);
}

int	get_malloc(int size, char **strs, char *sep)
{
	int	res;
	int	i;

	res = 0;
	i = 0;
	if (size == 0)
		return (1);
	while (i < size)
		res = res + str_len(strs[i++]);
	res = res + str_len(sep) * (size - 1);
	return (res + 1);
}

char	*boucle(int size, char *res, char **strs, char *sep)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_strcat(res, strs[i]);
		if (i != size - 1)
			ft_strcat(res, sep);
		i++;
	}
	return (res);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*res;

	res = malloc(get_malloc(size, strs, sep) * sizeof(char));
	if (!res)
		return ('\0');
	res[0] = 0;
	if (size == 0)
		return (res);
	boucle(size, res, strs, sep);
	res[str_len(res)] = 0;
	return (res);
}
