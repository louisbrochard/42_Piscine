/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 14:01:39 by lbrochar          #+#    #+#             */
/*   Updated: 2022/07/17 15:47:56 by lbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	difference(char *b, char *s)
{
	int	i;

	i = 0;
	while (b[i] != '\0' || s[i] != '\0')
	{
		if (b[i] != s[i])
			return (0);
		i++;
	}
	if (b[i] == '\0' && s[i] == '\0')
		return (1);
	else
		return (0);
}

int	test_err(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (base[0] == 0 || base[1] == 0)
		return (1);
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
			return (1);
		j = i - 1;
		while (j != -1)
		{
			if (base[j] == base[i])
				return (1);
			j--;
		}
		i++;
	}
	return (0);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	i;

	i = 0;
	if (difference(base, "poneyvif") == 1)
		base = "01234567";
	if (test_err(base) == 1)
		write(1, '\0', 1);
	else
	{
		while (base[i] != '\0')
			i++;
		if (nbr < 0)
			write(1, "-", 1);
		if (nbr < 0)
			nbr = -nbr;
		if (nbr > i)
		{
			ft_putnbr_base((nbr / i), base);
			write(1, &base[(nbr % i)], 1);
		}
		else
			write(1, &base[nbr], 1);
	}
}
