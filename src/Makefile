# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/02 15:12:00 by vpopovyc          #+#    #+#              #
#    Updated: 2017/04/16 14:50:50 by vpopovyc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

SRC = main.c storage_data.c root_path_set.c root_binds.c rooms_spot.c \
		paths_traversal.c path_data_set.c output_addition.c output.c \
		move_lmns.c min_path.c illative_path_2.c illative_path.c \
		get_rooms.c get_input.c fill_mx.c connection_component.c \
		storage_data_addition.c

INC = -I lem_in.h

OBJ = $(SRC:.c=.o)

LIBOBJ = make -C libft/

CFLAGS = -c  -g -Wall -Werror -Wextra

MLXCFLAGS = -lmlx -framework OpenGL -framework AppKit

LIBINC = -L./libft -lft

all: $(NAME)

obj: $(OBJ)

$(NAME) : liball obj
	clang -o $(NAME) $(LIBINC) $(MLXCFLAGS) $(OBJ)

%.o: %.c
	clang $(CFLAGS) -o $@ $<

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

liball:
	@make -C libft/ all

libclean:
	@make -C libft/ clean

libfclean:
	@make -C libft/ fclean

libre: libfclean liball
