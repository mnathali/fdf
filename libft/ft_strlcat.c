/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnathali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 17:19:56 by mnathali          #+#    #+#             */
/*   Updated: 2021/10/25 23:50:53 by mnathali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dst[i] != '\0' && i < dstsize)
		i++;
	while (i < (dstsize - 1) && src[j] != '\0' && dstsize != 0)
	{
		dst[i] = src[j];
		dst[i + 1] = '\0';
		i++;
		j++;
	}
	i -= j;
	while (src[j] != '\0')
		j++;
	return (i + j);
}
