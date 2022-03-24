/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnathali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 17:57:37 by mnathali          #+#    #+#             */
/*   Updated: 2021/10/26 00:23:18 by mnathali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static short	ft_lenght(int n)
{
	short	j;

	j = 0;
	if (n < 0 || n == 0)
		j = j + 1;
	while (n != 0)
	{
		j++;
		n = n / 10;
	}
	return (j);
}

char	*ft_itoa(int n)
{
	char	*str;
	short	j;

	j = ft_lenght(n);
	str = malloc(sizeof(char) * (j + 1));
	if (!str)
		return (0);
	str[j] = '\0';
	if (n < 0)
		str[0] = '-';
	if (n == 0)
		str[0] = '0';
	while (n != 0)
	{
		j--;
		if (n % 10 < 0)
			str[j] = ((-1) * (n % 10)) + '0';
		else
			str[j] = (n % 10) + '0';
		n = n / 10;
	}
	return (str);
}
