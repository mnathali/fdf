#include "fdf_bonus.h"

void	put_coord(float *z, float i, float j, float k)
{
	z[0] = i;
	z[1] = j;
	z[2] = k;
}

void	zoom_transverse(float *z, float *z_1, float *rt, float *k)
{
	if (*rt > 0 || (*rt < 0 && k[0] > 0))
		*rt += k[0];
	z_1[3] += k[2];
	z[3] += k[1];
	return ;
}

void	draw_lines(int i, int j, t_data	*img, float *k)
{
	int				color;
	static float	z[4];
	static float	z_1[4];
	static float	rt;

	if (!rt)
		rt = calculate_ratio(img->map, &z[3], &z_1[3]);
	zoom_transverse(z, z_1, &rt, k);
	put_coord(z, rt * i, rt * j, rt * ft_atoi(img->map[i][j]));
	color = color_atoi(ft_strchr(img->map[i][j], ','));
	if (img->map[i][j + 1] && ft_strchr(img->map[i][j + 1], ','))
		color = color_atoi(ft_strchr(img->map[i][j + 1], ','));
	if (img->map[i][j + 1])
	{
		put_coord(z_1, rt * i, rt * (j + 1), rt * ft_atoi(img->map[i][j + 1]));
		ft_paint(z, z_1, img, color);
	}
	if (img->map[i + 1] && ft_strchr(img->map[i + 1][j], ','))
		color = color_atoi(ft_strchr(img->map[i + 1][j], ','));
	if (img->map[i + 1])
	{
		put_coord(z_1, rt * (i + 1), rt * j, rt * ft_atoi(img->map[i + 1][j]));
		ft_paint(z, z_1, img, color);
	}
}

void	put_map_to_image(t_data	*img, float *k)
{
	int	i;
	int	j;

	i = 0;
	while (img->map[i])
	{
		j = 0;
		while (img->map[i][j])
		{
			draw_lines(i, j, img, k);
			k[0] = 0;
			j++;
		}
		i++;
	}
}

void	ft_draw(t_data *img, char *title)
{
	img->mlx = mlx_init();
	if (!img->mlx)
		return ;
	img->win = mlx_new_window(img->mlx, WH, WH, title);
	if (!img->win)
		return ;
	mlx_mouse_hook(img->win, &mouse_hook, img);
	mlx_hook(img->win, 17, 0, &exit_hook, img);
	mlx_key_hook(img->win, &key_hook, img);
	mlx_expose_hook(img->win, &expose_hook, img);
	mlx_loop(img->mlx);
}
