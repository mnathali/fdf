#ifndef FDF_BONUS_H
# define FDF_BONUS_H
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>
# include "libft/libft.h"
# include <limits.h>
# define SZ 42
# define WH 2000

typedef struct s_data {
	void	*mlx;
	void	*win;
	char	***map;
}				t_data;

char	*get_next_line(int fd);
void	ft_draw(t_data *img, char *title);
int		ft_arrlen(char **arr);
void	clean_map(char ***map);
void	clean_arr(char **arr);
float	calculate_ratio(char ***map, float *x, float *y);
int		color_atoi(char *str);
void	ft_paint(float *z, float *z_1, t_data *img, int color);
int		exit_hook(t_data *img);
int		expose_hook(t_data	*img);
int		key_hook(int keycode, t_data *img);
int		mouse_hook(int button, int x, int y, t_data *img);
void	put_map_to_image(t_data	*img, float *k);
void	put_coord(float *z, float i, float j, float k);
long	lg_at(const char *str);

#endif
