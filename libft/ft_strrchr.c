/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnathali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 14:42:09 by mnathali          #+#    #+#             */
/*   Updated: 2021/10/25 23:56:10 by mnathali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (c >= 256)
		c -= 256;
	while (str[i] != '\0')
		i++;
	while (str[i] != c && i != 0)
		i--;
	if (str[i] != c)
		return (0);
	return (&str[i]);
}
