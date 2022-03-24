#include "fdf.h"

static void	normalize_coeff(float *k_x, float *k_y)
{
	float	max;

	max = *k_x;
	if (*k_y != 0)
		max = *k_y;
	if (*k_x != 0 && ((*k_y / *k_x > 0 && *k_y / *k_x < 1)
			|| (*k_y / *k_x < 0 && *k_y / *k_x > -1)))
		max = *k_x;
	if (max < 0)
		max *= -1;
	*k_x = *k_x / max;
	*k_y = *k_y / max;
}

void	ft_paint(float *z, float *z_1, t_data *img, int color)
{
	float	k_x;
	float	k_y;
	float	s[2];
	float	s_1[2];

	s[0] = (z[0] + z[1]) / 2 - z[2];
	s_1[0] = (z_1[0] + z_1[1]) / 2 - z_1[2];
	s[1] = (z[1] - z[0]) * 0.866;
	s_1[1] = (z_1[1] - z_1[0]) * 0.866;
	k_x = s_1[0] - s[0];
	k_y = s_1[1] - s[1];
	normalize_coeff(&k_x, &k_y);
	while ((int)(s_1[0] - s[0]) || (int)(s_1[1] - s[1]))
	{
		mlx_pixel_put(img->mlx, img->win, z_1[3] + s[1], z[3] + s[0], color);
		s[0] = s[0] + k_x;
		s[1] = s[1] + k_y;
	}
}
