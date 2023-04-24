/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 11:14:03 by lbrochar          #+#    #+#             */
/*   Updated: 2022/07/14 11:28:42 by lbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_alpha(char c)
{
	if ((c < 48 || c > 122) || (c < 97 && c > 90)
		|| (c < 65 && c > 57))
		return (0);
	else
		return (1);
}

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

int	ft_putnbr_base(char *base, char un, char deux)
{
	int	j;
	int	num;
	int	res;
	int	let;

	j = 0;
	let = 0;
	if (difference(base, "poneyvif") == 1)
		base = "01234567";
	if (test_err(base) == 1)
		return (0);
	else
	{
		while (base[j] != '\0')
			j++;
		num = un - 48;
		while (base[let] != deux)
			let++;
		res = num * j + let;
		return (res);
	}
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	neg;
	int	num;

	i = 0;
	neg = 1;
	num = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == '\t')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = neg * (-1);
		i++;
	}
	if (str[i] < 48 || str[i] > 57)
		return (0);
	if (ft_is_alpha(str[i + 1]) == 0)
		return (0);
	num = ft_putnbr_base(base, str[i], str[i + 1]);
	return (num * neg);
}
