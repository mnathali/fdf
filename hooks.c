/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnathali <mnathali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 13:06:24 by mnathali          #+#    #+#             */
/*   Updated: 2022/03/25 13:06:25 by mnathali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_hook(int keycode, t_data *img)
{
	if (keycode == 65307)
	{
		mlx_clear_window(img->mlx, img->win);
		mlx_destroy_window(img->mlx, img->win);
		mlx_destroy_display(img->mlx);
		clean_map(img->map);
		free(img->mlx);
		exit(0);
	}
	return (0);
}

int	expose_hook(t_data	*img)
{
	mlx_clear_window(img->mlx, img->win);
	put_map_to_image(img);
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
