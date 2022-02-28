#include "push_swap.h"


t_node *create_elem(int value)
{
	t_node	*new_elem;

	new_elem = (t_node *)malloc(sizeof(t_node));
	if (!new_elem)
		return (0);
	new_elem->value = value;
	new_elem->next = NULL;
	return (new_elem);
}

int list_length(t_list *list)
{
	t_node *temp;
	int		i;

	if (!list || !list->head)
		return (0);
	i = 1;
	temp = list->head;
	while (temp->next)
	{
		temp = temp->next;
		i++;
	}
	return (i);
	
}

t_node *get_last_elem(t_list *list)
{
	t_node *temp;

	if (!list || !list->head)
		return (NULL);
	temp = list->head;
	while (temp->next)
		temp = temp->next;
	return (temp);
}

void add_front_list(t_list *list, t_node *elem, t_errors *error)
{
	if (!list || !elem)
	{
		error->list_create_flag = 1;
		return ;
	}
	elem->next = list->head;
	list->head = elem;
}


void add_back_list(t_list *list, t_node *elem, t_errors *error)
{
	t_node	*temp;
	
	if (!list || !elem)
	{
		error->list_create_flag = 1;
		return ;
	}
	temp = get_last_elem(list);
	if (!temp)
	{
		list->head = elem;
		return ;
	}
	temp->next = elem;
}

void print_list(t_list *list)
{
	t_node *temp;

	temp = list->head;
	while (temp)
	{
		printf("%d\n", temp->value);
		temp = temp->next;
	}
	
}

t_list *create_list(int size, char **argv, t_errors *error)
{
	t_node	*temp;
	t_list	*list;
	int		i;

	i = 1;
	list = (t_list *)malloc(sizeof(t_list));
	list->size = size;
	temp = list->head;
	while (i < list->size)
		add_back_list(list, create_elem(ft_atoi(argv[i++], error)), error);
	return (list);
}

int is_sort(t_list *list)
{
	t_node	*temp;

	if (!list || !list->head)
		return (0);
	if (list->size == 1)
		return (1);
	temp = list->head;
	while (temp->next)
	{
		if (temp->value > temp->next->value)
			return (0);
		temp = temp->next;
	}
	return (1);
}
