/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momajdou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 10:28:15 by momajdou          #+#    #+#             */
/*   Updated: 2023/08/19 11:44:57 by momajdou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	temp;
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size - 1)
	{
		j = i;
		while (j < size - 1)
		{
			temp = tab[i];
			tab[i] = tab[j + 1];
			tab[j + 1] = temp;
			j++;
		}
		i++;
	}
}
