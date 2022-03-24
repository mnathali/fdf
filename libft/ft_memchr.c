/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnathali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 15:34:26 by mnathali          #+#    #+#             */
/*   Updated: 2021/10/25 23:53:24 by mnathali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*str;

	str = (char *)s;
	i = 0;
	if (n == 0)
		return (0);
	while (c >= 256)
		c -= 256;
	while (*str != c && i < n - 1 && str)
	{
		i++;
		str++;
	}
	if (*str == c && i < n)
		return ((void *)str);
	return (0);
}
