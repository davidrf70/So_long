#include "so_long.h"
#include <stdio.h>

void	load_sprites_img(t_game *g)
{

}

int	key_hook(int keycode, t_game *game)
{
	int	moved;

	if (keycode == KEY_ESC)
		end_program(game);
	else if (keycode == KEY_Q)
		return (reset(game));
	if (game == NULL)
		return (0);
	if (keycode == KEY_UP || keycode == KEY_W)
		moved = move_to(game, game->player->sprite, KEY_UP);
	else if (keycode == KEY_DOWN || keycode == KEY_S)
		moved = move_to(game, game->player->sprite, KEY_DOWN);
	else if (keycode == KEY_LEFT || keycode == KEY_A)
		moved = move_to(game, game->player->sprite, KEY_LEFT);
	else if (keycode == KEY_RIGHT || keycode == KEY_D)
		moved = move_to(game, game->player->sprite, KEY_RIGHT);
	else
		return (0);
	//if (moved)
	//	printf("Moves -> %02d\n", ++game->moves);
	return (1);
}

t_game *init_game(char *map_name)
{
	t_game	*game;
	char	**map;
	int		win_height;
	int		win_width;

	game = malloc(sizeof(t_game));
	game->mlx = mlx_init();
	map = read_map(map_name);
	load_images(game);
	if (!map)
		return (NULL);
	game->map = map;
	win_width = (ft_strlen(game->map[0]) - 1) * game->map_block->width;
	win_height = count_map_lines(game->map) * game->map_block->heigth;
	game->win = mlx_new_window(game->mlx, win_width, win_height, WIN_TITLE);
	render_map(game); 
	mlx_hook(game->win, 2, 1L<<0, key_hook, game);
	mlx_loop_hook(game->mlx, render_next_frame, game);
	mlx_loop(game->mlx);
	return (game);
}