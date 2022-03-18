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

void	clean_arr(char **arr)
{
	int i;

	i = 0;
	while (arr && arr[i])
	{
		free(arr[i]);
		i++;
	}
	if (arr)
		free(arr);
	return ;
}

char **get_arr(int fd, unsigned int i)
{
	char **arr;
	char *str;

	arr = 0;
	str = get_next_line(fd);
	if (str)
		arr = get_arr(fd, i + 1);
	else
		arr = malloc(sizeof(arr) * (i + 1));
	arr[i] = str;
	return (arr);
}

int	ft_arrlen(char **arr)
{
	int	i;

	i = 0;
	while (arr && arr[i])
		i++;
	return (i);
}

void clean_map(char ***map)
{
	int	i;

	i = 0;
	while (map && map[i])
	{
		clean_arr(map[i]);
		i++;
	}
	if (map)
		free(map);
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
	return(map);
}

int main(int argc, char const *argv[])
{
	int		fd;
	char	**arr;
	char	***map;

	fd = -1;
	arr = 0;
	map = 0;
	if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	if (fd > 0)
		arr = get_arr(fd, 0);
	if (arr)
		map = get_map(arr);
	clean_arr(arr);
	if (map)
		ft_draw(map, (char *)argv[1]);
	clean_map(map);
	close(fd);
	return (0);
}

