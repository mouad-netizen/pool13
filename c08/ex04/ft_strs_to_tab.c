/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momajdou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 16:20:21 by momajdou          #+#    #+#             */
/*   Updated: 2023/09/03 17:03:43 by momajdou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

struct s_stock_str	str_copy(char *str, struct s_stock_str obj)
{
	int		size;
	char	*p;
	int		i;

	size = ft_strlen(str);
	p = (char *)malloc((size + 1) * sizeof(char));
	i = 0;
	while (str[i])
	{
		p[i] = str[i];
		i++;
	}
	p[i] = '\0';
	obj.size = size;
	obj.str = str;
	obj.copy = p;
	return (obj);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*tab;

	tab = (t_stock_str *)malloc((ac + 1) * sizeof(t_stock_str));
	i = 0;
	while (av[i])
	{
		tab[i] = str_copy(av[i], tab[i]);
		i++;
	}
	tab[i].str = NULL;
	return (tab);
}
