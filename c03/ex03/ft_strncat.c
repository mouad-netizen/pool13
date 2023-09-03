/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momajdou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 21:42:08 by momajdou          #+#    #+#             */
/*   Updated: 2023/08/26 12:00:42 by momajdou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	j;

	{
		i = 0;
		j = 0;
		while (dest[i])
		{
			i++;
		}
		while (src[j] && j < nb)
		{
			dest[i + j] = src[j];
			j++;
		}
		dest[i + j] = '\0';
		return (dest);
	}
}
