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

void add_front_list(t_list *list, t_node *elem)
{
	if (!list || !elem)
	{
		printf("add_front_lst error");
		exit(0);
	}
	elem->next = list->head;
	list->head = elem;
}


void add_back_list(t_list *list, t_node *elem)
{
	t_node	*temp;
	
	if (!list || !elem)
	{
		printf("add_back_lst error\n");
		exit(0);
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

void print_list_in_line(t_list *list, int stack_flag)
{
	t_node *temp;

	temp = list->head;
	if (stack_flag == 1)
		printf("stack_A: ");
	else if (stack_flag == 2)
		printf("stack_B: ");
	while (temp)
	{
		printf("%d ", temp->value);
		temp = temp->next;
	}
	printf("[next: %d | ", list->next);
	printf("size: %d]", list->size);
	printf("\n");
	
}

t_list *list_init(int size)
{
	t_list	*list;

	list = (t_list *)malloc(sizeof(t_list));
	if (!list)
	{
		printf("init_lst error: malloc\n");
		exit(0);
	}
	list->head = NULL;
	list->size = size;
	return (list);
}

t_list *create_list_from_argv(int size, int *sort_ind_array)
{
	t_node	*temp;
	t_list	*list;
	int		i;

	i = 0;
	list = list_init(size);
	temp = list->head;
	while (i < list->size)
		add_back_list(list, create_elem(sort_ind_array[i++]));
	list->next = 1;
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
	printf("stack is sorted\n");
	return (1);
}
