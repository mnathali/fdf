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


NAME = fdfd

LIBFT = libft/libft.a

SOURCES = main.c gnl.c draw.c

OBJ = $(patsubst %.c, %.o, $(SOURCES))

all: $(LIBFT) $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(LIBFT):
	cd libft && $(MAKE)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(LIBFT) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)


clean:
	rm -rf $(OBJ)
	cd libft && $(MAKE) clean

fclean: clean
	rm -rf $(NAME)
	cd libft && $(MAKE) fclean

re: fclean all