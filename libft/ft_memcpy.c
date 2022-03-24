/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnathali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 21:11:31 by mnathali          #+#    #+#             */
/*   Updated: 2021/10/27 23:39:12 by mnathali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char			*str;
	const char		*btr;

	str = dst;
	btr = src;
	if (!dst && !src)
		return (dst);
	while (n != 0)
	{
		*str = *btr;
		str++;
		btr++;
		n--;
	}
	return (dst);
}
