#include "push_swap.h"

void swap_one(t_list *list) //sa sb
{
	t_node *temp_1;
	t_node *temp_2;

	if (!list || !list->head)
	{
		printf("list error(swap)\n");
		exit (0);
	}
	if (!list->head->next)
	{
		printf("here is just one elem(swap)\n");
		exit (0);
	}

	temp_1 = list->head->next;
	temp_2 = list->head->next->next;
	list->head->next = temp_2;
	temp_1->next = list->head;
	list->head = temp_1;
}

void swap_both(t_list *list_1, t_list *list_2) //ss
{
	swap_one(list_1);
	swap_one(list_2);
}

void push(t_list *list_src, t_list *list_dest) //pa pb
{
	t_node	*temp_1;
	t_node	*temp_2;

	if (!list_src || !list_dest || !list_src->head)
	{
		printf("list error(push)\n");
		return ;
	}
	temp_1 = list_dest->head; //push front or not free
	temp_2 = list_src->head->next;
	list_dest->head = list_src->head;
	list_dest->head->next = temp_1;
	list_src->head = temp_2;
}

void rotate_one(t_list *list)
{
	t_node	*temp;
	t_node	*elem;

	if (!list || !list->head || !list->head->next)
	{
		printf("list error(rotate)\n");
		return ;
	}
	temp = list->head->next;
	elem = get_last_elem(list);
	list->head->next = NULL;
	elem->next = list->head;
	list->head = temp;
}

void rotate_both(t_list *list_1, t_list *list_2) //rr
{
	rotate_one(list_1);
	rotate_one(list_2);
}

void rev_rotate_one(t_list *list) //ra rb
{
	t_node	*temp;
	t_node	*elem;
	int		i;

	i = 2;
	if (!list || !list->head || !list->head->next || !list->size)
	{
		printf("list error(rotate)\n");
		return ;
	}
	elem = list->head;
	while (i < list->size - 1)
	{
		elem = elem->next;
		i++;
	}
	temp = elem->next;
	elem->next = NULL;
	temp->next = list->head;
	list->head = temp;
}

void rev_rotate_both(t_list *list_1, t_list *list_2) //rrr
{
	rev_rotate_one(list_1);
	rev_rotate_one(list_2);
	
}

