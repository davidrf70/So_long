#include "so_long.h"

static int	lst_count_nodes(t_list *lst)
{
	int		i;
	t_list	*node;

	i = 0;
	node = lst;
	while (node)
	{
		i++;
		node = node->next;
	}
	return (i);
}

static t_list	*load_map_in_list(char *map_name)
{
	int		fd;
	t_list	*lst;
	t_list	*node;
	char	*str;

	str = ft_strjoin(MAPS_DIR, map_name);
	fd = open(str, O_RDONLY);
	free(str);
	lst = NULL;
	while (1)
	{
		str = ft_get_next_line(fd);
		if (!str)
			break ;
		node = ft_lstnew(str);
		ft_lstadd_back(&lst, node);
	}
	return (lst);	
}

static char	**load_map_in_array(t_list *lst_map)
{
	int		i;
	t_list	*node;
	char	*str;
	char	**array;
	
	i = lst_count_nodes(lst_map);
	array = malloc((i + 1) * sizeof(char *));
	i = 0;
	node = lst_map;
	while (node)
	{
		str = (char *)node->content;
		array[i] = ft_strjoin(str, "");
		node = node->next;
		i++;
	}
	array[i] = NULL;
	return (array);
}

int	count_map_lines(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

char    **read_map(char *map_name)
{
	int		i;
	t_list	*lst;
	char	**array;

	lst = load_map_in_list(map_name);
	array = load_map_in_array(lst);
	
	ft_lstclear(&lst, free);
	return (array);
}