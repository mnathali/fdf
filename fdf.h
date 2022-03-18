/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnathali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 17:29:46 by mnathali          #+#    #+#             */
/*   Updated: 2022/03/05 17:29:50 by mnathali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <fcntl.h>
# include <unistd.h>
# include <sys/errno.h>
# include <stdio.h>
# include <stdlib.h>
# include <mlx.h>
# include <math.h>
# include "libft/libft.h"
# define SZ 42
# define W 1000
# define H 1000
# define RATIO 20

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_tree {
	int		x;
	int		y;
	int		z;
	struct	s_tree *next_x;
	struct	s_tree *next_y;
}				t_tree;

char	*get_next_line(int fd);
void ft_draw(char ***map, char *title);
int	ft_arrlen(char **arr);



#endif
