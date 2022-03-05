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

char **get_map(int fd, unsigned int i)
{
	char **arr;
	char *str;

	arr = 0;
	str = get_next_line(fd);
	if (str)
		arr = get_map(fd, i + 1);
	else
		arr = malloc(sizeof(arr) * i);
	arr[i] = str;
	return (arr);
}

int main(int argc, char const *argv[])
{
	int	fd;
	char **arr;
	int i = 0;
	int j = 0;

	fd = -1;
	if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	if (fd > 0)
		arr = get_map(fd, 0);
	while (arr[i])
	{
		j = 0;
		while (arr[i][j])
		{
			write(1, &arr[i][j], 1);
			j++;
		}
		i++;
	}
	return (0);
}

