/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnathali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 20:17:34 by mnathali          #+#    #+#             */
/*   Updated: 2021/10/19 20:30:06 by mnathali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char			*str;
	const char		*btr;

	str = dst;
	btr = src;
	if (!src && dst)
		str[0] = btr[0];
	if ((src + sizeof(*src) * len > dst) && (dst > src) && src)
	{
		while (len != 0)
		{
			str[len - 1] = btr[len - 1];
			len--;
		}
	}
	else if (src)
	{
		while (len != 0)
		{
			*str++ = *btr++;
			len--;
		}
	}
	return (dst);
}
