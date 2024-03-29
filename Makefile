# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: haachtch <haachtch@student.codam.n>          +#+                      #
#                                                    +#+                       #
#    Created: 2020/06/28 20:22:26 by haachtch      #+#    #+#                  #
#    Updated: 2020/06/28 22:07:45 by haachtch      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	= cub3D

MINILIBX_D = ./libx
MINILIBX = libmlx.dylib

LIBFT_D = ./libft

SRC_D  = src
INC_D = inc
OBJ_D = obj

SRC =	$(SRC_D)/get_next_line.c\
		$(SRC_D)/get_next_line_utils.c\
		$(SRC_D)/calculation.c\
		$(SRC_D)/color.c\
		$(SRC_D)/config.c\
		$(SRC_D)/draw.c\
		$(SRC_D)/events.c\
		$(SRC_D)/flood_fill.c\
		$(SRC_D)/ft_copy_file.c\
		$(SRC_D)/ft_get_resolution.c\
		$(SRC_D)/ft_print_file.c\
		$(SRC_D)/get_color.c\
		$(SRC_D)/images.c\
		$(SRC_D)/init_game.c\
		$(SRC_D)/parse_textures.c\
		$(SRC_D)/set_position.c\
		$(SRC_D)/is_map_valid.c\
		$(SRC_D)/main.c\
		$(SRC_D)/movements.c\
		$(SRC_D)/new_parser.c\
		$(SRC_D)/save.c\
		$(SRC_D)/sprite.c\
		$(SRC_D)/textures.c\
		$(SRC_D)/parser_utils.c\
		$(SRC_D)/raycaster_utils.c\
		$(SRC_D)/vec2.c\
		$(SRC_D)/sprites_utils.c


INC = $(INC_D)/cub3d.h\
	  $(INC_D)/bmp.h\
	  ./libft/libft.h

OBJ := $(SRC:$(SRC_D)/%.c=$(OBJ_D)/%.o)

LIBFT = ./libft/libft.a
CC = clang

CC_FLAGS = -g -Wall -Werror -Wextra -Ofast -march=native
#CC_FLAGS = -Wall -Werror -Wextra -g -fsanitize=address

all: $(NAME)

$(NAME): $(MINILIBX) $(LIBFT) $(OBJ_D) $(OBJ) $(INC_D) $(INC)
	$(CC) $(CC_FLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(MINILIBX)

$(OBJ_D):
	mkdir -p $(OBJ_D)

$(OBJ): $(OBJ_D)/%.o: $(SRC_D)/%.c
	@$(CC) $(CC_FLAGS) -I$(INC_D) -I./libft -c $< -o $@

$(MINILIBX) :
	$(MAKE) -C $(MINILIBX_D)
	@ln -s $(MINILIBX_D)/$(MINILIBX) ./

$(LIBFT):
	@$(MAKE) -C ./libft

clean:
	rm -rf $(OBJ_D)
	$(MAKE) -C $(MINILIBX_D) clean
	@$(MAKE) -C ./libft clean
	rm	-rf *.dSYM
	rm -f screenshot.bmp

fclean: clean
	rm -f $(NAME)
	rm -f $(MINILIBX)
	@$(MAKE) -C ./libft fclean

re: fclean all
