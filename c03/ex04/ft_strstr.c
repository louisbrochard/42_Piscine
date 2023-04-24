/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 13:56:31 by lbrochar          #+#    #+#             */
/*   Updated: 2022/07/16 10:00:19 by lbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdbool.h>

bool	is_same(const char c1, const char c2)
{
	return (((c1 != '\0') || (c1 == '\0' && c2 == '\0')) && (c1 == c2));
}

char	*ft_strstr(char *str, char *to_find)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*to_find == '\0')
		return (str);
	while (str[i])
	{
		j = 0;
		while (is_same(str[i + j], to_find[j]) == true)
		{
			if (to_find[j + 1] == '\0')
				return (str + i);
			++j;
		}
		++i;
	}
	return (NULL);
}
