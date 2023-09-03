/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momajdou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 23:08:40 by momajdou          #+#    #+#             */
/*   Updated: 2023/08/17 16:51:19 by momajdou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_numbers_separated(char a, char b, char c)
{
	ft_putchar(a);
	ft_putchar(b);
	ft_putchar(c);
	if (a < '7')
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_comb(void)
{	
	char	a;
	char	b;
	char	c;

	a = '0';
	while (a <= '7')
	{
	b = a + 1;
		while (b <= '8')
		{
		c = b + 1;
			while (c <= '9')
			{
				print_numbers_separated(a, b, c);
				c++;
			}
		b++;
		}
	a++;
	}
}
