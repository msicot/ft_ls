








#include "ft_ls.h"

void	ft_del_list(t_name **head)
{
	t_name	*tmp;
	t_name	*start;

	start = *head;
	while (start)
	{
		tmp = start;;
//		free(tmp->d_name);
		start = start->next;
		free(tmp);
	}
}

t_name	*ft_create_node(void)
{
	t_name	*node;

	if (!(node = (t_name*)malloc(sizeof(t_name))))
		return (NULL);
	node->next = NULL; 
	return (node);
}
