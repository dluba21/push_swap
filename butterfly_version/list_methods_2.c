#include "push_swap.h"

t_list	*list_init(int size)
{
	t_list	*list;

	list = (t_list *)malloc(sizeof(t_list));
	if (!list)
		exit (0);
	list->head = NULL;
	list->size = size;
	list->number_of_operations = 0;
	return (list);
}

t_list	*create_list(int size)
{
	t_node	*temp;
	t_list	*list;
	int		i;

	i = 0;
	list = list_init(size);
	list->size = size;
	temp = list->head;
	while (i < list->size)
	{
		add_back_list(list, create_elem(0));
		i++;
	}
	return (list);
}

t_list	*create_list_from_argv(int size, int *sort_ind_array)
{
	t_node	*temp;
	t_list	*list;
	int		i;

	i = 0;
	list = list_init(size);
	temp = list->head;
	while (i < list->size)
		add_back_list(list, create_elem(sort_ind_array[i++]));
	free(sort_ind_array);
	return (list);
}

void	free_list(t_list *list)
{
	t_list	*temp_list;
	t_node	*temp_node;
	t_node	*node;

	temp_list = list;
	node = list->head;
	while (node)
	{
		temp_node = node->next;
		free(node);
		node = temp_node;
	}
	free(temp_list);
}

t_list	*copy_list(t_list *list)
{
	t_list	*new_list;
	t_node	*temp_old_lst;
	t_node	*temp_new_lst;

	if (!list)
		exit(0);
	temp_old_lst = list->head;
	if (!temp_old_lst)
		return (create_list(0));
	new_list = create_list(list->size);
	if (!new_list)
		exit(0);
	temp_new_lst = new_list->head;
	while (temp_old_lst != NULL)
	{
		temp_new_lst->value = temp_old_lst->value;
		temp_new_lst = temp_new_lst->next;
		temp_old_lst = temp_old_lst->next;
	}
	return (new_list);
}
