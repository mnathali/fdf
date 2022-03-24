#include "fdf.h"

int	ft_arrlen(char **arr)
{
	int	i;

	i = 0;
	while (arr && arr[i])
		i++;
	return (i);
}

void	clean_arr(char **arr)
{
	int	i;

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

void	clean_map(char ***map)
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
