#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (x * data->line_length + y * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	ft_paint(float *z, float *z_1, t_data *img, int color)
{
	float	k_x;
	float	k_y;
	float	max;
	float	s[2];
	float	s_1[2];

	s[0] = 200 + (z[0] + z[1]) * cos(0.866) - z[2];
	s_1[0] = 200 + (z_1[0] + z_1[1]) * cos(0.866) - z_1[2];
	s[1] = 200 + (z[1] - z[0]) * sin(0.866);
	s_1[1] = 200 + (z_1[1] - z_1[0]) * sin(0.866);
	k_x = s_1[0] - s[0];
	k_y = s_1[1] - s[1];
	max = k_y;
	if ((k_x > k_y && k_y >= 0) || (k_x < k_y && k_y <= 0))
		max = k_x;
	if (max < 0)
		max *= -1;
	k_x = k_x / max;
	k_y = k_y / max;
	/*if (k_x < 0)
		k_x *= -1;
	if (k_y < 0)
		k_y *= -1;*/
	printf("%f | %f | %f | %f | %f | %f | %f\n", s[0], s_1[0], s[1], s_1[1], k_x, k_y, max);
	while ((int)(s_1[0] - s[0]) || (int)(s_1[1] - s[1]))
	{
		my_mlx_pixel_put(img, s[0], s[1], color);
		s[0] = s[0] + k_x;
		s[1] = s[1] + k_y;
	}
}

void	draw_lines(int i, int j, char ***map, t_data *img)
{
	int 	color;
	float	z[3];
	float	z_1[3];

	z[0] = RATIO * i;
	z[1] = RATIO * j;
	z[2] = ft_atoi(map[i][j]);
	color = 0x00FFFFFF;
	if (ft_atoi(map[i][j]) > 0 || (map[i][j + 1] && ft_atoi(map[i][j + 1]) > 0))
		color = 0x00FF0000;
	else if (ft_atoi(map[i][j]) < 0 || (map[i][j + 1] && ft_atoi(map[i][j + 1]) < 0))
		color = 0x000000FF;
	if (map[i][j + 1])
	{
		z_1[0] = RATIO * i;
		z_1[1] = RATIO * (j + 1);
		z_1[2] = ft_atoi(map[i][j + 1]);
		ft_paint(z, z_1, img, color);
	}
	if (map[i + 1] && ft_atoi(map[i + 1][j]) > 0)
		color = 0x00FF0000;
	else if (map[i + 1] && ft_atoi(map[i + 1][j]) < 0)
		color = 0x000000FF;
	if (map[i + 1])
	{
		z_1[0] = RATIO * (i + 1);
		z_1[1] = RATIO * j;
		z_1[2] = ft_atoi(map[i + 1][j]);
		ft_paint(z, z_1, img, color);
	}
}		

void	put_map_to_image(t_data	*img, char ***map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			draw_lines(i, j, map, img);
			j++;
		}
		i++;
	}
}

void ft_draw(char ***map, char *title)
{
	void	*mlx_win;
	t_data	img;
	void	*mlx;

	mlx = mlx_init();
	img.img = mlx_new_image(mlx, W, H);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
				&img.line_length, &img.endian);
	put_map_to_image(&img, map);
	mlx_win = mlx_new_window(mlx, W, H, title);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
(void)map;
	mlx_loop(mlx);
printf("mlx = %p\nimg = %p\naddr = %p\nwin = %p", mlx, img.img, img.addr, mlx_win);
free(mlx);
free(img.img);
free(img.addr);
free(mlx_win);
}