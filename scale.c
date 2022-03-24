#include "fdf.h"

void	calculate_extrem(float *min, float *max, char ***map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if ((i + j) / 2 - ft_atoi(map[i][j]) > *max)
				*max = (i + j) / 2 - ft_atoi(map[i][j]);
			else if ((i + j) / 2 - ft_atoi(map[i][j]) < *min)
				*min = (i + j) / 2 - ft_atoi(map[i][j]);
			j++;
		}
		i++;
	}
}

float	calculate_ratio(char ***map, float *x, float *y)
{
	int		i;
	float	width_y;
	float	min;
	float	max;

	i = ft_arrlen((char **)map);
	min = 0;
	max = 0;
	width_y = ft_arrlen(map[0]) * 0.866 + i * 0.866;
	*y = i * 0.866;
	calculate_extrem(&min, &max, map);
	*x = min * (-1);
	if (max - min <= width_y)
		width_y = (WH - 0.1 * WH) / width_y;
	else
		width_y = (WH - 0.1 * WH) / (max - min);
	*y = *y * width_y + 0.1 * WH / 2;
	*x = *x * width_y + 0.1 * WH / 2;
	return (width_y);
}
