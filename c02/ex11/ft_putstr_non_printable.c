/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 17:33:01 by lbrochar          #+#    #+#             */
/*   Updated: 2022/07/13 20:40:23 by lbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	put_char_base(int mod)
{
	char	*base;

	base = "0123456789abcdef";
	write(1, &base[mod], 1);
}

void	put_char(char c)
{
	write(1, &c, 1);
}

void	conv(int x)
{
	int	mod;
	int	div;

	div = x / 16;
	mod = x % 16;
	div = div + 48;
	put_char(div);
	put_char_base(mod);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] <= 31 || str[i] == 127)
		{
			write(1, "\\", 1);
			conv(str[i]);
		}
		else
			write(1, &str[i], 1);
	}
}
