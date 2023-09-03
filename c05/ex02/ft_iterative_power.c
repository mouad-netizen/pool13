/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momajdou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 18:59:34 by momajdou          #+#    #+#             */
/*   Updated: 2023/08/28 11:27:38 by momajdou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	i;
	int	result;

	i = power;
	result = nb;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	while (i > 1)
	{
		result = result * nb;
		i--;
	}
	return (result);
}
