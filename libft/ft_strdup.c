/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnathali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 13:42:01 by mnathali          #+#    #+#             */
/*   Updated: 2021/10/16 20:14:53 by mnathali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	i;

	i = 0;
	while (s1[i] != '\0')
		i++;
	str = malloc(i + 1);
	if (!str)
		return (0);
	str[i] = s1[i];
	while (i != 0)
	{
		i--;
		str[i] = s1[i];
	}
	return (str);
}
