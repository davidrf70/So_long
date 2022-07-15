#include "so_long.h"

char	**lst2array(t_list *lst)
{
	int		i;
	int		count;
	char	**array;
	t_list	*node;

	if (!lst)
		return ;
	node = lst;
	i = 0;
	while (node)
	{
		count++;
		node = node->next;
	}
	array = malloc((count + 1) * sizeof(char *));
	node = lst;
	i = 0;
	while (node)
	{
		array[i++] = (char *)node->content;
		node = node->next;
	}
	return (array);
}

void	end_program(t_game *g)
{

}

void	reset(t_game *g)
{
	
}
