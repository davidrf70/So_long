# Linux setting for make libmlx.a:
# 	sudo apt-get update && sudo apt-get install xorg libxext-dev zlib1g-dev libbsd-dev

#	https://harm-smits.github.io/42docs/
#	https://github.com/S-LucasSerrano/so_long	so_long implementations with animated sprites
#	https://anyconv.com/es/convertidor-de-png-a-xpm/
#	https://www.deviantart.com/rpg-creation/gallery/34110024/sprites-and-pixel-art?set=34110024&offset=24
#	

NAME			=	so_long

SRC_DIR			=	src/
LIBFT_DIR		=	libft/
MINILIBX_DIR	=	minilibx-linux/
LINUX_LIB		=	/usr/lib/
INCLUDE_DIR		= 	include/

FILES			=	main init_game init_game_map init_game_images movement_mng render utils

SRCS			=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(FILES)))

# To call library 'libft.a', you must remove 'lib' prefix and '.a' suffix from its name
LIBFT			=	ft
MINILIBX		=	mlx
LINUX_LIBS		=	-lXext -lX11 -lm -lz

CC				=	gcc
INCLUDE			=	-I $(INCLUDE_DIR)
#CFLAGS			=	-Werror -Wall -Wextra -g
CFLAGS			=	-g
RM				=	rm -f

# This rule must be over all
all		:	$(NAME)

$(NAME)	: 	
			@make -C $(LIBFT_DIR) --silent
			@make -C $(MINILIBX_DIR) --silent
			$(CC) $(CFLAGS) $(SRCS) $(INCLUDE) \
				-L $(LIBFT_DIR) -l $(LIBFT) \
				-L $(MINILIBX_DIR) -l $(MINILIBX) \
				-L $(LINUX_LIB) $(LINUX_LIBS) \
				-o $(NAME)

clean	:
			@make -C $(LIBFT_DIR) clean --silent
			$(RM) $(OBJS)

fclean	:	clean
			@make -C $(LIBFT_DIR) fclean --silent
			$(RM) $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re
