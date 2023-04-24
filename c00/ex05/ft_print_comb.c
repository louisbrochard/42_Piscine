/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:43:03 by lbrochar          #+#    #+#             */
/*   Updated: 2022/07/06 21:19:13 by lbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void);
void	ft_print_char(int a, int b, int c);

void	ft_print_char(int a, int b, int c)
{
	char	a_c;
	char	b_c;
	char	c_c;

	a_c = a + 48;
	b_c = b + 48;
	c_c = c + 48;
	write(1, &a_c, 1);
	write(1, &b_c, 1);
	write(1, &c_c, 1);
	if (a != 7 || b != 8 || c != 9)
	{
		write(1, ", ", 2);
	}
}

void	ft_print_comb(void)
{
	int	a;
	int	b;
	int	c;

	a = 0;
	while (a < 8)
	{
		b = a + 1;
		while (b < 9)
		{
			c = b + 1;
			while (c < 10)
			{
				ft_print_char(a, b, c);
				c++;
			}
			b++;
		}
		a++;
	}
}
