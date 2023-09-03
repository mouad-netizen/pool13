/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momajdou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 12:20:25 by momajdou          #+#    #+#             */
/*   Updated: 2023/09/02 19:46:29 by momajdou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	val;
	int	i;
	int	*tab;

	i = 0;
	val = max - min;
	if (min >= max)
		return (NULL);
	tab = (int *)malloc(val * sizeof(int));
	if (!tab)
		return (NULL);
	while (min < max)
	{
		tab[i] = min;
		i++;
		min++;
	}
	return (tab);
}
