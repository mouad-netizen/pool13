/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momajdou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 15:41:54 by momajdou          #+#    #+#             */
/*   Updated: 2023/09/03 21:34:32 by momajdou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_convert_base2(int nb, char *base);
int		ft_strlen(char *str);

char	*skip_spaces(char *str)
{
	while (*str)
	{
		if (*str == ' ' || (*str >= 9 && *str <= 13))
			str++;
		else
			break ;
	}
	return (str);
}

int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	in_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	base_len;
	int	result;
	int	sign;

	if (!check_base(base))
		return (0);
	base_len = ft_strlen(base);
	result = 0;
	str = skip_spaces(str);
	sign = 1;
	i = 0;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (in_base(*str, base) != -1)
	{
		result = result * base_len + in_base(*str, base);
		str++;
	}
	return (result * sign);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*p;
	int		x;

	if (!check_base(base_from) || !check_base(base_to))
		return (0);
	x = ft_atoi_base(nbr, base_from);
	p = ft_convert_base2(x, base_to);
	return (p);
}
