/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:42:46 by lbrochar          #+#    #+#             */
/*   Updated: 2022/07/20 09:02:19 by lbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*swap(char *str, int i, int j);
char	*ft_rev(char *str);
char	*ft_itoa(int nb, char *base, char *dest);
char	ft_is_alpha(char c);
char	*boucle(int nb, char *dest, char *base, int *j);

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	else
	{
		return (nb * ft_recursive_power(nb, power - 1));
	}
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
		if ((base[i] == '+' || base[i] == '-')
			|| (base[i] < ' ' || base[i] == 127))
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

int	ft_putnbr_base(char *base, char *temp)
{
	int	j;
	int	k;
	int	l;
	int	i;
	int	res;

	j = 0;
	i = 0;
	l = 0;
	k = 0;
	res = 0;
	while (base[i] != '\0')
		i++;
	while (temp[l] != '\0')
		l++;
	while (temp[j] != '\0')
	{
		while (base[k] != temp[j])
			k++;
		res = res + k * ft_recursive_power(i, (l - 1 - j));
		j++;
		k = 0;
	}
	return (res);
}

int	ft_atoi(char *str, char *base, char *temp)
{
	int	neg;
	int	i;
	int	j;

	neg = 1;
	j = 0;
	i = 0;
	while (str[i] == ' ' || (str[i] > 8 && str[i] < 14))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = neg * (-1);
		i++;
	}
	while (ft_is_alpha(str[i + j]) == '1')
	{
		temp[j] = (str[i + j]);
		j++;
	}
	temp[j] = '\0';
	i = ft_putnbr_base(base, temp);
	return (i * neg);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*dest;
	char	*temp;

	dest = malloc(100 * sizeof(char));
	temp = malloc(100 * sizeof(char));
	if (test_err(base_from) == 1 || test_err(base_to) == 1)
		return (0);
	ft_itoa (ft_atoi(nbr, base_from, temp), base_to, dest);
	return (dest);
}
