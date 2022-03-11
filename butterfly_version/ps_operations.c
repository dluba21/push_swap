#include "push_swap.h"

static void	swap_one(t_list *list)
{
	t_node	*temp_1;
	t_node	*temp_2;

	if (!list || !list->head || !list->head->next)
		return ;
	temp_1 = list->head->next;
	temp_2 = list->head->next->next;
	list->head->next = temp_2;
	temp_1->next = list->head;
	list->head = temp_1;
}

static void	push(t_list *list_src, t_list *list_dest)
{
	t_node	*temp_1;
	t_node	*temp_2;

	if (!list_src || !list_dest || !list_src->head)
		return ;
	temp_1 = list_dest->head;
	temp_2 = list_src->head->next;
	list_dest->head = list_src->head;
	list_dest->head->next = temp_1;
	list_src->head = temp_2;
}

static void	rotate_one(t_list *list)
{
	t_node	*temp;
	t_node	*elem;

	if (!list || !list->head || !list->head->next)
		return ;
	temp = list->head->next;
	elem = get_last_elem(list);
	list->head->next = NULL;
	elem->next = list->head;
	list->head = temp;
}

static void	rev_rotate_one(t_list *list)
{
	t_node	*temp;
	t_node	*elem;
	int		i;

	i = 1;
	if (!list || !list->head || !list->head->next || !list->size)
		return ;
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

void	sa_sb(t_list *list, int stack_flag, int show_flag)
{
	swap_one(list);
	if (show_flag == 1)
	{
		if (stack_flag == 1)
			write(1, "sa\n", 3);
		else
			write(1, "sb\n", 3);
	}
	list->number_of_operations++;
}

void	ss(t_list *list_1, t_list *list_2, int show_flag)
{
	swap_one(list_1);
	swap_one(list_2);
	if (show_flag == 1)
		write(1, "ss\n", 3);
	list_1->number_of_operations++;
}

void	pa_pb(t_list *list_1, t_list *list_2, int stack_flag, int show_flag)
{
	if (stack_flag == 1)
	{
		push(list_2, list_1);
		list_1->size++;
		list_2->size--;
		if (show_flag == 1)
			write(1, "pa\n", 3);
	}
	else
	{
		list_1->size--;
		list_2->size++;
		push(list_1, list_2);
		if (show_flag == 1)
			write(1, "pb\n", 3);
	}
	list_1->number_of_operations++;
}

void	ra_rb(t_list *list, int stack_flag, int show_flag)
{
	rotate_one(list);
	if (show_flag == 1)
	{
		if (stack_flag == 1)
			write(1, "ra\n", 3);
		else
			write(1, "rb\n", 3);
	}
	list->number_of_operations++;
}

void	rr(t_list *list_1, t_list *list_2, int show_flag)
{
	rotate_one(list_1);
	rotate_one(list_2);
	if (show_flag == 1)
		printf("rr\n");
	list_1->number_of_operations++;
}

void	rra_rrb(t_list *list, int stack_flag, int show_flag)
{
	rev_rotate_one(list);
	if (show_flag == 1)
	{
		if (stack_flag == 1)
			write(1, "rra\n", 4);
		else
			write(1, "rrb\n", 4);
	}
	list->number_of_operations++;
}

void	rrr(t_list *list_1, t_list *list_2, int show_flag)
{
	rev_rotate_one(list_1);
	rev_rotate_one(list_2);
	if (show_flag == 1)
		write(1, "rrr\n", 4);
	list_1->number_of_operations++;
}
