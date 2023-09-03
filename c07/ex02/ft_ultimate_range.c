/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momajdou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:27:47 by momajdou          #+#    #+#             */
/*   Updated: 2023/09/02 17:40:21 by momajdou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	val;
	int	i;
	int	*tab;

	i = 0;
	if ((max - min) <= 0)
	{
		*range = NULL;
		return (0);
	}
	val = max - min;
	tab = (int *)malloc(val * sizeof(int));
	if (!tab)
		return (-1);
	while (min < max)
	{
		tab[i] = min;
		i++;
		min++;
	}
	*range = tab;
	return (val);
}
