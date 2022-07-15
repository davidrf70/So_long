#include	"libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*node;

	if (!lst || !(*lst))
		return ;
	while (*lst)
	{
		node = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		(*lst) = node;
	}
}
