# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mnathali <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/05 17:30:03 by mnathali          #+#    #+#              #
#    Updated: 2022/03/05 17:30:07 by mnathali         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = fdf

BON_NAME = fdf_bonus

HEADER = fdf.h

LIBFT = libft/libft.a

MLX = mlx_linux/libmlx_Linux.a

SOURCES = main.c gnl.c ft_draw.c arr_functions.c color_atoi.c ft_paint.c\
		hooks.c scale.c long_atoi.c

SOURCES_BONUS = main.c gnl.c ft_draw_bonus.c arr_functions.c color_atoi.c ft_paint.c\
		hooks_bonus.c scale.c long_atoi.c

OBJ = $(patsubst %.c, %.o, $(SOURCES))

OBJ_BON = $(patsubst %.c, %.o, $(SOURCES_BONUS))

BON_HEADER_FUNC = ft_draw_bonus.c hooks_bonus.c

SRC_LFT = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c\
	  ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c\
	  ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c\
	  ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c\
	  ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c\
	  ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c\
	  ft_putendl_fd.c ft_putnbr_fd.c\
	  ft_lstnew.c ft_lstadd_front.c ft_lstsize.c\
	  ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c\
	  ft_lstclear.c ft_lstiter.c ft_lstmap.c

MLX_SRC = mlx_init.c mlx_new_window.c mlx_pixel_put.c mlx_loop.c \
	mlx_mouse_hook.c mlx_key_hook.c mlx_expose_hook.c mlx_loop_hook.c \
	mlx_int_anti_resize_win.c mlx_int_do_nothing.c \
	mlx_int_wait_first_expose.c mlx_int_get_visual.c \
	mlx_flush_event.c mlx_string_put.c mlx_set_font.c \
	mlx_new_image.c mlx_get_data_addr.c \
	mlx_put_image_to_window.c mlx_get_color_value.c mlx_clear_window.c \
	mlx_xpm.c mlx_int_str_to_wordtab.c mlx_destroy_window.c \
	mlx_int_param_event.c mlx_int_set_win_event_mask.c mlx_hook.c \
	mlx_rgb.c mlx_destroy_image.c mlx_mouse.c mlx_screen_size.c \
	mlx_destroy_display.c

all: $(LIBFT) $(MLX) $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(LIBFT): libft/libft.h $(patsubst %.c, libft/%.c, $(SRC_LFT))
	cd libft && $(MAKE)

$(MLX): mlx_linux/mlx.h $(patsubst %.c, mlx_linux/%.c, $(MLX_SRC))
	cd mlx_linux && $(MAKE)

$(OBJ): $(HEADER)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(LIBFT) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $@

bonus: $(LIBFT) $(MLX) $(BON_NAME)

$(patsubst %.c, %.o, $(BON_HEADER_FUNC)): fdf_bonus.h

$(BON_NAME): $(OBJ_BON)
	$(CC) $(OBJ_BON) $(LIBFT) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $@

clean:
	rm -rf $(OBJ) $(OBJ_BON)
	cd libft && $(MAKE) clean
	cd mlx_linux && $(MAKE) clean

fclean: clean
	rm -rf $(NAME) $(BON_NAME)
	cd libft && $(MAKE) fclean

re: fclean all