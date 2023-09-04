/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momajdou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 10:16:17 by momajdou          #+#    #+#             */
/*   Updated: 2023/09/04 20:32:17 by momajdou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *base)
{
	int	i;

	i = 0;
	while (base[i])
		i++;
	return (i);
}

int	valid_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (base[i])
	{
		j = i + 1;
		if (base[i] == '-' || base[i] == '+' || base[i] <= 32 || base[i] == 127)
		{
			return (0);
		}
		while (base[j])
		{
			if (base[i] == base[j])
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	if (i < 2)
		return (0);
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int			n;
	long long	nb;

	nb = nbr;
	n = ft_strlen(base);
	if (!valid_base(base))
		return ;
	if (nb < 0)
	{
		nb = -nb;
		ft_putchar('-');
	}
	if (nb >= n)
	{
		ft_putnbr_base(nb / n, base);
		ft_putchar(base[nb % n]);
	}
	else
	{
		ft_putchar(base[nb]);
	}
}
