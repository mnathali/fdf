/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnathali <mnathali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 13:06:21 by mnathali          #+#    #+#             */
/*   Updated: 2022/03/25 13:06:22 by mnathali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	key_hook(int keycode, t_data *img)
{
	float	bon[3];
	float	max_size;

	max_size = ft_arrlen(img->map[0]);
	if (ft_arrlen((char **)img->map) > max_size)
		max_size = ft_arrlen((char **)img->map);
	put_coord(bon, 0, 0, 0);
	mlx_clear_window(img->mlx, img->win);
	if (keycode == 65307)
	{
		mlx_destroy_window(img->mlx, img->win);
		mlx_destroy_display(img->mlx);
		free(img->mlx);
		clean_map(img->map);
		exit(0);
	}
	if (keycode == 65362 || keycode == 65364)
		bon[1] = (keycode - 65363) * 10 / max_size / max_size;
	if (keycode == 65361 || keycode == 65363)
		bon[2] = (keycode - 65362) * 10 / max_size / max_size;
	put_map_to_image(img, bon);
	return (0);
}

int	expose_hook(t_data	*img)
{
	float	bon[3];

	bon[0] = 0;
	bon[1] = 0;
	bon[2] = 0;
	mlx_clear_window(img->mlx, img->win);
	put_map_to_image(img, bon);
	return (0);
}

int	exit_hook(t_data *img)
{
	mlx_clear_window(img->mlx, img->win);
	mlx_destroy_window(img->mlx, img->win);
	mlx_destroy_display(img->mlx);
	free(img->mlx);
	clean_map(img->map);
	exit(0);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_data *img)
{
	float	bon[3];
	int		max_size;

	max_size = ft_arrlen(img->map[0]);
	if (ft_arrlen((char **)img->map) > max_size)
		max_size = ft_arrlen((char **)img->map);
	put_coord(bon, 0, 0, 0);
	(void)x;
	(void)y;
	mlx_clear_window(img->mlx, img->win);
	if (button == 4)
		bon[0] = 20 / (float)max_size;
	if (button == 5)
		bon[0] = 0 - 20 / (float)max_size;
	put_map_to_image(img, bon);
	return (0);
}
