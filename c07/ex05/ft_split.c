/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momajdou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 10:43:48 by momajdou          #+#    #+#             */
/*   Updated: 2023/09/03 21:34:59 by momajdou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	check_separator(char c, char *charset)
{
	while (*charset)
	{
		if (*charset == c)
			return (1);
		charset++;
	}
	return (0);
}

char	*skip_separators(char *str, char *charset)
{
	while (check_separator(*str, charset))
	{
		str++;
	}
	return (str);
}

int	count_words(char *str, char *charset)
{
	int	count;

	count = 0;
	str = skip_separators(str, charset);
	while (*str)
	{
		if (check_separator(*str, charset))
		{
			count++;
			str = skip_separators(str, charset);
		}
		if (*str)
			str++;
		if (*str == '\0' && !check_separator(*(str - 1), charset))
			return (count + 1);
	}
	return (count);
}

char	*copy_string(char *ptr, char *str)
{
	int		size;
	char	*p;
	int		i;

	i = 0;
	size = (str - ptr + 1);
	p = (char *)malloc(size * sizeof(char *));
	while (ptr != str)
	{
		p[i] = *ptr;
		ptr++;
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	char	**array;
	char	*ptr;

	i = count_words(str, charset);
	array = (char **)malloc((i + 1) * sizeof(char *));
	i = 0;
	str = skip_separators(str, charset);
	ptr = str;
	while (*str)
	{
		if (check_separator(*str, charset) || *(str + 1) == '\0')
		{
			if (*(str + 1) == 0)
				str++;
			array[i] = copy_string(ptr, str);
			str = skip_separators(str, charset);
			ptr = str;
			i++;
		}
		if (*str)
			str++;
	}
	array[i] = 0;
	return (array);
}
