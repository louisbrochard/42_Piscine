/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:54:21 by lbrochar          #+#    #+#             */
/*   Updated: 2022/07/14 20:56:24 by lbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	ft_is_alpha(char c)
{
	if ((c < 48 || c > 122) || (c < 97 && c > 90)
		|| (c < 65 && c > 57))
		return ('0');
	else
		return ('1');
}

char	*swap(char *str, int i, int j)
{
	char	temp;

	temp = str[i];
	str[i] = str[j];
	str[j] = temp;
	return (str);
}

char	*ft_rev(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
		i++;
	i--;
	while (j < i)
	{
		swap(str, i, j);
		j++;
		i--;
	}
	return (str);
}

char	*boucle(int nb, char *dest, char *base, int *j)
{
	int	a;
	int	i;

	i = 0;
	a = *j;
	while (base[i] != '\0')
		i++;
	while (nb > i)
	{
		dest[a] = base[nb % i];
		nb = nb / i;
		a = a + 1;
	}
	dest[a] = base[nb];
	a = a + 1;
	*j = a;
	return (dest);
}

char	*ft_itoa(int nb, char *base, char *dest)
{
	int	j;
	int	neg;

	neg = 0;
	j = 0;
	if (nb < 0)
		neg = 1;
	if (nb < 0)
		nb = -nb;
	boucle(nb, dest, base, &j);
	if (neg == 1)
		dest[j] = '-';
	if (neg == 1)
		j++;
	dest[j] = '\0';
	ft_rev(dest);
	return (dest);
}
