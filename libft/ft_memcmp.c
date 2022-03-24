/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnathali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 16:38:14 by mnathali          #+#    #+#             */
/*   Updated: 2021/10/17 13:11:42 by mnathali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*str;
	const unsigned char	*btr;

	i = 0;
	str = s1;
	btr = s2;
	if (n == 0)
		return (0);
	while (*str == *btr && i < n)
	{
		i++;
		if (i == n)
			break ;
		str++;
		btr++;
	}
	return (*str - *btr);
}
