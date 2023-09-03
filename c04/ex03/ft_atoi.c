/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momajdou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 19:55:45 by momajdou          #+#    #+#             */
/*   Updated: 2023/08/26 20:30:34 by momajdou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	skip_space(char str)
{
	if (str == ' ' || (str >= 9 && str <= 13))
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	result = 0;
	sign = 1;
	while (skip_space(str[i]))
		i++;
	if (!str[i])
		return (0);
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (result * sign);
		result = (str[i] - '0') + result * 10;
		i++;
	}
	return (result * sign);
}
