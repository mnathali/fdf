/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnathali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:01:33 by mnathali          #+#    #+#             */
/*   Updated: 2021/10/25 21:30:32 by mnathali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_end(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = 0;
	if (s1[i] == 0)
		return (0);
	while (s1[i + 1] != '\0')
		i++;
	while (set[j] != '\0')
	{
		if (s1[i] == set[j])
		{
			k++;
			if (i == 0)
				break ;
			i--;
			j = 0;
			continue ;
		}
		j++;
	}
	return (k);
}

static size_t	ft_begin(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (set[j] != '\0')
	{
		if (s1[i] == set[j])
		{
			i++;
			j = 0;
			continue ;
		}
		j++;
	}
	if (s1[i] == '\0')
		return (0);
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	l;

	if (!s1 || !set)
		return (0);
	l = 0;
	k = 0;
	i = ft_begin(s1, set);
	j = ft_end(s1, set);
	while (s1[k] != '\0')
		k++;
	str = malloc(sizeof(char) * (k - i - j + 1));
	if (!str)
		return (0);
	while (i != k - j)
	{
		str[l] = s1[i];
		i++;
		l++;
	}
	str[l] = '\0';
	return (str);
}
