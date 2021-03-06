/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnathali <mnathali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 13:05:38 by mnathali          #+#    #+#             */
/*   Updated: 2022/03/25 13:05:39 by mnathali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	check_ratio(float rt, t_data *img)
{
	if (rt > 1)
		return ;
	if (write(2, "map too big for this window\n", 28))
		key_hook(65307, img);
}

void	put_coord(float *z, float i, float j, float k)
{
	z[0] = i;
	z[1] = j;
	z[2] = k;
}

void	draw_lines(int i, int j, t_data	*img)
{
	int				color;
	static float	z[4];
	static float	z_1[4];
	static float	rt;

	if (!rt)
		rt = calculate_ratio(img->map, &z[3], &z_1[3]);
	check_ratio(rt, img);
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

void	put_map_to_image(t_data	*img)
{
	int	i;
	int	j;

	i = 0;
	while (img->map[i])
	{
		j = 0;
		while (img->map[i][j])
		{
			draw_lines(i, j, img);
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
	mlx_hook(img->win, 17, 0, &exit_hook, img);
	mlx_key_hook(img->win, &key_hook, img);
	mlx_expose_hook(img->win, &expose_hook, img);
	mlx_loop(img->mlx);
}
