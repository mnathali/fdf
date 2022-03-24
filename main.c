/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnathali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 17:29:27 by mnathali          #+#    #+#             */
/*   Updated: 2022/03/05 17:29:29 by mnathali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	**get_arr(int fd, unsigned int i)
{
	char	**arr;
	char	*str;

	arr = 0;
	str = get_next_line(fd);
	if (str)
		arr = get_arr(fd, i + 1);
	else
		arr = malloc(sizeof(arr) * (i + 1));
	arr[i] = str;
	return (arr);
}

char	***get_map(char **arr)
{
	int		size;
	char	***map;

	size = ft_arrlen(arr);
	map = malloc((size + 1) * sizeof(*map));
	if (!map)
		return (0);
	map[size] = 0;
	while (size)
	{
		size--;
		map[size] = ft_split(arr[size], ' ');
	}
	return (map);
}

short	check_str(char *str)
{
	int		i;

	i = 0;
	if (ft_strlen(str) > 11 && (lg_at(str) > INT_MAX || lg_at(str) < INT_MIN))
		return (1);
	while (str[i] != 0 && str[i] != '\n' && str[i] != ',')
	{
		if ((str[i] == '-' && i != 0) || (!ft_isdigit(str[i]) && str[i] != '-')
			|| (i == 0 && str[i] == '\n'))
			return (1);
		i++;
	}
	if (str[i] == 0 || str[i] == '\n')
		return (0);
	if ((str[i] == ',' && ft_strlen(&str[i]) <= 3 && str[i + 1] != '0'
			&& str[i + 2] != 'x') || i == 0 || i > 11)
		return (1);
	if (str[i] == ',')
		i += 3;
	while (str[i] && (ft_isdigit(str[i]) || (str[i] >= 65 && str[i] <= 70)
			|| (str[i] >= 97 && str[i] <= 102)))
		i++;
	if (str[i] != 0 && str[i] != '\n')
		return (1);
	return (0);
}

short	check_map(char ***map)
{
	int	i;
	int	j;
	int	sz;

	i = 0;
	sz = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (check_str(map[i][j]))
				sz = -1;
			j++;
		}
		if (sz && j != sz && write(2, "Map error\n", 10))
			return (0);
		sz = j;
		i++;
	}
	return (1);
}

int	main(int argc, char const *argv[])
{
	int		fd;
	char	**arr;
	t_data	img;

	fd = -1;
	arr = 0;
	img.map = 0;
	if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	if (fd > 0)
		arr = get_arr(fd, 0);
	if (arr)
		img.map = get_map(arr);
	clean_arr(arr);
	close(fd);
	if (img.map && check_map(img.map))
		ft_draw(&img, (char *)argv[1]);
	clean_map(img.map);
	return (0);
}
