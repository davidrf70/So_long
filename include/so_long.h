#ifndef _SO_LONG_H
# define _SO_LONG_H

# include "mlx.h"
# include "libft.h"
# include <fcntl.h>
# include <stdio.h>

# define	WIN_TITLE			"SO LONG"
# define	MAPS_DIR			"./assets/maps/"
# define	IMG_DIR				"./assets/images/"
# define	WALL_FILE			"block01.xpm"
# define	SPACE_FILE			"space01.xpm"
# define	COLLECT_FILE		"collectable.xpm"
# define	EXIT_FILE			"exit.xpm"
# define	PLAYER_BASE_NAME	"mario"
# define	IMG_EXTENSION		".xpm"

# define	PLAYER_SP_NB	1
# define	MOV_INC			3

enum
{
	KEY_ESC = 65307,
	KEY_Q = 113,
	KEY_W = 119,
	KEY_A = 97,
	KEY_S = 115,
	KEY_D = 100,
	KEY_UP = 65362,
	KEY_LEFT = 65361,
	KEY_DOWN = 65364,
	KEY_RIGHT = 65363
};

typedef struct	s_sprite
{
	int				width;
	int				height;
	int				x;
	int				y;
	int				sp_index;
	struct s_sprite	*next;
}	t_sprite;

typedef struct	s_map_block
{
	int	width;
	int	heigth;
}	t_map_block;

typedef struct	s_player
{
	void		**frame_array;
	t_sprite	*sprite;
}	t_player;

typedef struct	s_enemy
{
	void			**frame_array;
	t_sprite		*sprite;
	struct s_enemy	*next;
}	t_enemy;

typedef struct	s_game
{
	void		*mlx;
	void		*win;
	char		**map;
	t_map_block	*map_block;
	void		*img_wall;
	void		*img_space;
	void		*img_exit;
	void		*img_collect;
	t_player	*player;
	t_enemy		*enemy;
}	t_game;

t_game *init_game(char *map_name);
char    **read_map(char *map_name);
int		count_map_lines(char **map);
void    load_images(t_game *g);
void    render_map(t_game *g);
int		render_next_frame(t_game *game);
void    set_sprite_init_pos(t_game *g, t_sprite *sp);
int		move_to(t_game *g, t_sprite *sp, int dir);
void	end_program(t_game *g);

#endif