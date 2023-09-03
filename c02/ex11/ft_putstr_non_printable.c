/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momajdou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 19:53:11 by momajdou          #+#    #+#             */
/*   Updated: 2023/08/21 21:10:37 by momajdou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	if_printable(char c)
{
	if (c > 31 && c < 127)
		return (1);
	return (0);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;
	int	flag;

	i = 0;
	while (str[i] != '\0')
	{
		flag = if_printable(str[i]);
		if (flag == 1)
			ft_putchar(str[i]);
		else
		{
			ft_putchar('\\');
			ft_putchar("0123456789abcdef"[str[i] / 16]);
			ft_putchar("0123456789abcdef"[str[i] % 16]);
		}
		i++;
	}
}
