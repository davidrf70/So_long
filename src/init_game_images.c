#include "so_long.h"

char    *get_image_path(char *base_name, int sprite_nb)
{
	char	*path;

	path = ft_strjoin(IMG_DIR, base_name);
	path = ft_strjoin(path, ft_itoa(sprite_nb));
	path = ft_strjoin(path, IMG_EXTENSION);

	return (path);
}

t_player	*load_player(t_game *g)
{
	t_player	*player;
	char		*path;
	int			img_width;
	int			img_height;
	int			i;

	player = malloc(sizeof(t_player));
	player->sprite = malloc(sizeof(t_sprite));
	player->frame_array = malloc(PLAYER_SP_NB * sizeof(void *));
	i = 0;
	while (i < PLAYER_SP_NB)
	{
		path = get_image_path(PLAYER_BASE_NAME, i);
		player->frame_array[i] = mlx_xpm_file_to_image(g->mlx, path, &img_width, &img_height);
		player->sprite->height = img_height;
		player->sprite->width = img_width;
		player->sprite->sp_index = 0;
		i++;
		free(path);
	}
	return (player);
}

void	load_images(t_game *g)
{
	char	*path;
	int		img_width;
	int		img_height;

	path = ft_strjoin(IMG_DIR, WALL_FILE);
	g->img_wall = mlx_xpm_file_to_image(g->mlx, path, &img_width, &img_height);
	g->map_block = malloc(sizeof(t_map_block));
	g->map_block->heigth = img_height;
	g->map_block->width = img_width;
	path = ft_strjoin(IMG_DIR, SPACE_FILE);
	g->img_space = mlx_xpm_file_to_image(g->mlx, path, &img_width, &img_height);
	path = ft_strjoin(IMG_DIR, COLLECT_FILE);
	g->img_collect = mlx_xpm_file_to_image(g->mlx, path, &img_width, &img_height);
	path = ft_strjoin(IMG_DIR, EXIT_FILE);
	g->img_exit = mlx_xpm_file_to_image(g->mlx, path, &img_width, &img_height);
	free(path);
	g->player = load_player(g);
}