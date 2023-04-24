/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 15:20:09 by lbrochar          #+#    #+#             */
/*   Updated: 2022/07/14 14:06:17 by lbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	swap_str(char *s1, char *s2, int j)
{
	char	temp;

	while (s1[j] != '\0' && s2[j] != '\0')
	{
		temp = s1[j];
		s1[j] = s2[j];
		s2[j] = temp;
		j = j + 1;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	diff;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] == s2[i])
			i++;
		else
		{
			diff = s1[i] - s2[i];
			return (diff);
		}
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < (argc - 1))
	{
		if (ft_strcmp(argv[i], argv[i + 1]) > 0)
		{
			swap_str(argv[i], argv[i + 1], j);
			i = 0;
		}
		else
			i++;
	}
	i = 1;
	while (i <= (argc -1))
	{
		ft_putstr(argv[i]);
		write(1, "\n", 1);
		i++;
	}
}
