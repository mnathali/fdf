/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnathali <mnathali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 19:26:21 by mnathali          #+#    #+#             */
/*   Updated: 2022/03/25 13:06:12 by mnathali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_strchr_mod(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (-1);
	while (s[i] != c && s[i] != '\0')
		i++;
	if (s[i] != c)
		return (-1);
	return (i);
}

char	*ft_strjoin_mod(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;

	if (!s2)
		return ((char *)s1);
	i = 0;
	j = 0;
	while (s1 && s1[i] != '\0')
		i++;
	while (s2[j] != '\0' && s2[j] != '\n')
		j++;
	if (s2[j] == '\n')
		j++;
	str = malloc(sizeof(char) * (i + j + 1));
	if (!str)
		return (0);
	while (s1 && *s1 != '\0')
		*str++ = *s1++;
	while (*s2 != '\0' && *s2 != '\n')
		*str++ = *s2++;
	if (*s2 == '\n')
		*str++ = *s2++;
	*str++ = '\0';
	return (str - (i + j + 1) * sizeof(char));
}

char	*change_red(char *btr)
{
	int		i;
	int		j;
	char	*red;

	if (!btr)
		return (0);
	j = 0;
	i = ft_strchr_mod(btr, '\n') + 1;
	if (i == 0)
		return (0);
	while (btr[i + j] != 0)
		j++;
	if (j == 0)
		return (0);
	red = malloc(sizeof(char) * (j + 1));
	if (!red)
		return (0);
	j = 0;
	while (btr[i + j] != 0)
	{
		red[j] = btr[i + j];
		j++;
	}
	red[j] = 0;
	return (red);
}

static char	*end_and_free(char **btr, char **red, char **buf, char **str)
{
	if (!*btr && !*str)
	{
		free(*buf);
		return (0);
	}
	*btr = *red;
	if (*buf[0] != 0)
		*red = change_red(*buf);
	else
		*red = change_red(*red);
	free(*btr);
	free(*buf);
	return (*str);
}

char	*get_next_line(int fd)
{
	static char	*red;
	char		*buf;
	char		*str;
	char		*btr;
	int			i;

	if (fd < 0 || SZ <= 0)
		return (0);
	btr = 0;
	buf = malloc(SZ + 1);
	if (!buf)
		return (0);
	buf[0] = 0;
	str = ft_strjoin_mod(0, red);
	while (ft_strchr_mod(str, '\n') < 0)
	{
		i = read(fd, buf, SZ);
		if (i <= 0)
			break ;
		buf[i] = 0;
		btr = ft_strjoin_mod(str, buf);
		free(str);
		str = btr;
	}
	return (end_and_free(&btr, &red, &buf, &str));
}
