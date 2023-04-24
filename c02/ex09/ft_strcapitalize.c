/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 15:16:25 by lbrochar          #+#    #+#             */
/*   Updated: 2022/07/12 19:11:54 by lbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_c_is_not_alpha(char c)
{
	int	check;

	check = 1;
	if ((c >= 'a' && c <= 'z')
		|| (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9'))
	{
		check = 0;
	}
	return (check);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	if (str[0] <= 'z' && str[0] >= 'a')
		str[0] = str[0] - 32;
	i++;
	while (str[i] != '\0')
	{
		if ((ft_c_is_not_alpha(str[i - 1]))
			&& (str[i] <= 'z' && str[i] >= 'a'))
		{
			str[i] = str[i] - 32;
		}
		else if ((ft_c_is_not_alpha(str[i - 1]) == 0)
			&& (str[i] <= 'Z' && str[i] >= 'A'))
		{
			str[i] = str[i] + 32;
		}
		i++;
	}
	return (str);
}
