#include "so_long.h"

void    render_map(t_game *g)
{
	int	i;
	int	j;
	int	width;
	int	height;

	width = g->map_block->width;
	height = g->map_block->heigth;
	i = 0;
	while (g->map[i])
	{
		j = 0;
		while (g->map[i][j] != '\n')
		{
			if (g->map[i][j] == '0')
				mlx_put_image_to_window(g->mlx, g->win, g->img_space,
				j * width, i * height);
			else if (g->map[i][j] == '1')
				mlx_put_image_to_window(g->mlx, g->win, g->img_wall,
				j * width, i * height);
			else if (g->map[i][j] == 'C')
				mlx_put_image_to_window(g->mlx, g->win, g->img_collect,
				j * width, i * height);
			else if (g->map[i][j] == 'E')
				mlx_put_image_to_window(g->mlx, g->win, g->img_exit,
				j * width, i * height);
			else if (g->map[i][j] == 'P')
			{
				g->player->sprite->x = j * width + (width - g->player->sprite->width) / 2;
				g->player->sprite->y = i * height + (height - g->player->sprite->height);
				mlx_put_image_to_window(g->mlx, g->win, g->player->frame_array[0],
				g->player->sprite->x, g->player->sprite->y);
			}
			j++;	
		}
		i++;
	}
}

int	render_next_frame(t_game *g)
{
	// Pendiente de borrado de fondo
	mlx_put_image_to_window(g->mlx, g->win, g->player->frame_array[0],
				g->player->sprite->x, g->player->sprite->y);
}
