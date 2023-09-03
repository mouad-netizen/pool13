/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momajdou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 15:59:53 by momajdou          #+#    #+#             */
/*   Updated: 2023/09/03 21:31:34 by momajdou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		str++;
		i++;
	}
	return (i);
}

int	count_size(int nb, int len_base)
{
	long	nbr;
	int		i;

	if (nb == 0)
		return (2);
	i = 0;
	nbr = nb;
	if (nbr < 0)
		nbr = -nbr;
	while (nbr >= len_base)
	{
		i++;
		nbr = nbr / len_base;
	}
	if (nb < 0)
		i += 3;
	else
		i += 2;
	return (i);
}

char	*ft_convert_base2(int nb, char *base)
{
	int		size;
	char	*dest;
	long	nbr;
	int		i;

	i = ft_strlen(base);
	size = count_size(nb, ft_strlen(base));
	dest = (char *)malloc(size * sizeof(char));
	dest[size - 1] = '\0';
	size--;
	nbr = nb;
	if (nb < 0)
		nbr = -nbr;
	while (nbr >= i)
	{
		dest[size - 1] = base[nbr % i];
		size--;
		nbr = nbr / i;
	}
	dest[--size] = base[nbr % i];
	if (nb < 0)
		dest[size - 1] = '-';
	return (dest);
}
