/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momajdou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 11:46:01 by momajdou          #+#    #+#             */
/*   Updated: 2023/08/20 09:39:27 by momajdou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	min;

	i = 0;
	while (i < size - 1)
	{
		j = i;
		min = tab[i];
		while (j < size - 1)
		{
			if (min > tab[j + 1])
			{	
				min = tab[j + 1];
				tab[j + 1] = tab[i];
				tab[i] = min;
			}
		j++;
		}
	i++;
	}
}
