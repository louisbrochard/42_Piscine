/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 18:16:29 by lbrochar          #+#    #+#             */
/*   Updated: 2022/07/07 09:25:12 by lbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	set_b(int a_d, int a_u, int *b_d, int *b_u)
{
	if (a_u != 9)
	{
		*b_u = a_u + 1;
		*b_d = a_d;
	}
	else
	{
		*b_u = 0;
		*b_d = a_d + 1;
	}	
}

void	ft_print_char(int a_d, int a_u, int b_d, int b_u)
{
	char	a_1;
	char	a_2;
	char	b_1;
	char	b_2;

	a_1 = a_d + 48;
	a_2 = a_u + 48;
	b_1 = b_d + 48;
	b_2 = b_u + 48;
	write(1, &a_1, 1);
	write(1, &a_2, 1);
	write(1, " ", 1);
	write(1, &b_1, 1);
	write(1, &b_2, 1);
	if (a_d != 9 || a_u != 8 || b_d != 9 || b_u != 9)
	{
		write(1, ", ", 2);
	}
}

int	bouclewhile(int a_d, int a_u, int b_d, int b_u)

{
	while (b_u < 10)
	{
		ft_print_char(a_d, a_u, b_d, b_u);
		b_u++;
	}
	return (b_u);
}

void	ft_print_comb2(void)
{
	int	a_d;
	int	a_u;
	int	b_d;
	int	b_u;

	a_d = 0;
	while (a_d < 10)
	{
		a_u = 0;
		while (a_u < 10)
		{
			set_b(a_d, a_u, &b_d, &b_u);
			while (b_d < 10)
			{
				bouclewhile(a_d, a_u, b_d, b_u);
				b_d++;
				b_u = 0;
			}
			a_u++;
		}
		a_d++;
	}
}
