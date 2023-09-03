/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momajdou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 16:27:59 by momajdou          #+#    #+#             */
/*   Updated: 2023/09/03 17:04:26 by momajdou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <unistd.h>

void	putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	putnbr(int nb)
{
	long	nbr;
	char	c;

	nbr = nb;
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr = -nbr;
	}
	if (nbr <= 9)
	{
		c = nbr + '0';
		ft_putchar(c);
	}
	else
	{
		putnbr(nbr / 10);
		c = (nbr % 10) + '0';
		ft_putchar(c);
	}
}

void	ft_show_tab(struct s_stock_str *par)
{
	while (par->str)
	{
		putstr(par->str);
		ft_putchar('\n');
		putnbr(par->size);
		ft_putchar('\n');
		putstr(par->copy);
		ft_putchar('\n');
		par++;
	}
}
