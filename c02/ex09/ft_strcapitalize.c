/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momajdou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 11:30:03 by momajdou          #+#    #+#             */
/*   Updated: 2023/08/21 21:10:14 by momajdou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	lower(char c)
{
	if (c >= 'A' && c <= 'Z')
		c += 'a' - 'A';
	return (c);
}

char	upper(char c)
{
	if (c >= 'a' && c <= 'z')
		c -= 'a' - 'A';
	return (c);
}

int	can_upper(char c)
{
	if ((c > 31 && c < 48))
		return (1);
	else if (c > 57 && c < 65)
		return (1);
	else if (c > 'Z' && c < 'a')
		return (1);
	else if (c > 'z' && c < 127)
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	flag;

	i = 1;
	if (str[0] != '\0')
		str[0] = upper(str[0]);
	while (str[i] != '\0')
	{
		flag = can_upper(str[i - 1]);
		if (flag == 1)
			str[i] = upper(str[i]);
		else
			str[i] = lower(str[i]);
		i++;
	}
	return (str);
}
