/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momajdou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 18:32:00 by momajdou          #+#    #+#             */
/*   Updated: 2023/09/02 19:51:49 by momajdou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *sep)
{
	int	i;

	i = 0;
	while (sep[i])
		i++;
	return (i);
}

int	count_size_strings(int size, char **strs, char *sep)
{
	int	i;
	int	j;
	int	count;
	int	size_sep;

	size_sep = ft_strlen(sep);
	count = 0;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
		{
			count++;
			j++;
		}
		if (i < size - 1)
			count += size_sep;
		i++;
	}
	return (count + 1);
}

void	put_values(char **strs, char *s, char *sep, int size)
{
	int	i;
	int	j;
	int	k;
	int	l;

	i = 0;
	k = 0;
	while (i < size)
	{
		l = 0;
		j = 0;
		while (strs[i][j])
		{
			s[k++] = strs[i][j++];
		}
		if (i < size - 1)
		{
			while (sep[l])
			{
				s[k++] = sep[l++];
			}
		}
		i++;
	}
	s[k] = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		count;
	char	*s;

	if (size <= 0)
	{
		s = (char *)malloc(sizeof(char));
		*s = '\0';
		return (s);
	}
	count = count_size_strings(size, strs, sep);
	s = (char *)malloc(count * sizeof(char));
	if (!s)
		return (NULL);
	put_values(strs, s, sep, size);
	return (s);
}
