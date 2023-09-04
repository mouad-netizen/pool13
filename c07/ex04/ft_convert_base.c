/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momajdou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 18:30:04 by momajdou          #+#    #+#             */
/*   Updated: 2023/09/04 18:53:24 by momajdou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *s);
int	is_base_valid(char *s);
int	ft_atoi_base(char *str, char *base);

int	calc_base_length(long long int nbr, unsigned int length)
{
	if (nbr < length)
		return (1);
	return (1 + calc_base_length(nbr / length, length));
}

void	fill_base_string(char *result, int length, int number, char *base)
{
	int	i;

	i = 0;
	if (number < 0)
	{
		result[i] = '-';
		number *= -1;
		i++;
	}
	while (i < length)
	{
		result[length - 1 - i] = base[number % ft_strlen(base)];
		number /= ft_strlen(base);
		i++;
	}
	result[length] = '\0';
}

void	custom_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char		*result;
	char		*temp_str;
	long int	number;
	int			sign;
	int			length;

	sign = 0;
	if (!is_base_valid(base_from) || !is_base_valid(base_to))
		return (NULL);
	number = ft_atoi_base(nbr, base_from);
	if (number < 0)
	{
		sign = 1;
		number *= -1;
	}
	length = calc_base_length(number, ft_strlen(base_to));
	result = malloc((length + 1) * sizeof(char));
	fill_base_string(result, length, number, base_to);
	if (!sign)
		return (result);
	temp_str = malloc((length + 2) * sizeof(char));
	temp_str[0] = '-';
	custom_strcpy(&temp_str[1], result);
	free(result);
	return (temp_str);
}
