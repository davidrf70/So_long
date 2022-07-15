#include "so_long.h"

/*
*	Return '1' if movement is possible
*/
int	move_up(t_game *g, t_sprite *sp)
{
	int	i;
	int	j;

	i = (sp->y - MOV_INC) / g->map_block->heigth;
	j = sp->x / g->map_block->width;
	if (g->map[i][j] == '1')
		return (0);
	return (1); 

}

int	move_down(t_game *g, t_sprite *sp)
{
	int	i;
	int	j;

	i = (sp->y + MOV_INC) / g->map_block->heigth;
	j = sp->x / g->map_block->width;
	if (g->map[i][j] == '1')
		return (0);
	return (1); 

}

int	move_right(t_game *g, t_sprite *sp)
{
	int	i;
	int	j;

	i = sp->y / g->map_block->heigth;
	j = (sp->x + MOV_INC) / g->map_block->width;
	if (g->map[i][j] == '1')
		return (0);
	return (1); 

}

int	move_left(t_game *g, t_sprite *sp)
{
	int	i;
	int	j;

	i = sp->y / g->map_block->heigth;
	j = (sp->x - MOV_INC) / g->map_block->width;
	if (g->map[i][j] == '1')
		return (0);
	return (1); 

}

int	move_to(t_game *g, t_sprite *sp, int dir)
{
	if (dir == KEY_UP && move_up(g, sp))
	{
		sp->y -= MOV_INC;
		return (1);
	}
	else if (dir == KEY_DOWN && move_down(g, sp))
	{
		sp->y += MOV_INC;
		return (1);
	}
	else if (dir == KEY_RIGHT)
	{
		sp->x += MOV_INC;
		return (1);
	}
	else if (dir == KEY_LEFT)
	{
		sp->x -= MOV_INC;
		return (1);
	}
	return (0);
}