#include "push_swap.h"

void swap_one(t_list *list) //sa sb
{
	t_node *temp_1;
	t_node *temp_2;

	if (!list || !list->head || !list->head->next)
		return ;
	temp_1 = list->head->next;
	temp_2 = list->head->next->next;
	list->head->next = temp_2;
	temp_1->next = list->head;
	list->head = temp_1;
}

void push(t_list *list_src, t_list *list_dest) //pa pb
{
	t_node	*temp_1;
	t_node	*temp_2;

	if (!list_src || !list_dest || !list_src->head)
		return ;
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
		return ;
	temp = list->head->next;
	elem = get_last_elem(list);
	list->head->next = NULL;
	elem->next = list->head;
	list->head = temp;
}

void rev_rotate_one(t_list *list)
{
	t_node	*temp;
	t_node	*elem;
	int		i;

	i = 1; // '1' tak kak v nachale mi nahodimsya uzhe v headx
	if (!list || !list->head || !list->head->next || !list->size)
		return ;
	elem = list->head;
	while (i < list->size - 1) // '-1' tak kak predposledniy element nuzhen
	{
		elem = elem->next;
		i++;
	}
	temp = elem->next;
	elem->next = NULL;
	temp->next = list->head;
	list->head = temp;
}



void sa_sb(t_list *list, int stack_flag, int show_flag) // 1 = stack_a, 2 = stack_b
{
	swap_one(list);
	if (show_flag == 1)
	{
		if (stack_flag == 1)
			write(1, "sa\n", 3);
		else
			write(1, "sb\n", 3);
	}
	
	
	//_in_line(list, stack_flag);
	list->number_of_operations++; //just for check, delete it
}


void ss(t_list *list_1, t_list *list_2, int show_flag)
{
	swap_one(list_1);
	swap_one(list_2);
	if (show_flag == 1)
		write(1, "ss\n", 3);
	
	//_in_line(list_1, 1);
	//_in_line(list_2, 2);
	
	list_1->number_of_operations++; //just for check, delete it
}

void pa_pb(t_list *list_1, t_list *list_2, int stack_flag, int show_flag) //'1' = 'pa';'2' = 'pb'
{
	if (stack_flag == 1)
	{
		if (list_2->head->value == list_1->next)
			list_2->head->flag = -1; // '-1' lishnee, vezde ubrat'
		else
			list_2->head->flag = list_1->flag; //flag prisvoit pri pushe
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
	
	//_in_line(list_1, 1);
	//_in_line(list_2, 2);
	
	list_1->number_of_operations++; //just for check, delete it
}

void ra_rb(t_list *list, int stack_flag, int show_flag)
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

void rr(t_list *list_1, t_list *list_2, int show_flag)
{
	rotate_one(list_1);
	rotate_one(list_2);
	if (show_flag == 1)
		printf("rr\n");
	list_1->number_of_operations++;
}

void rra_rrb(t_list *list, int stack_flag, int show_flag)
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

void rrr(t_list *list_1, t_list *list_2, int show_flag)
{
	rev_rotate_one(list_1);
	rev_rotate_one(list_2);
	if (show_flag == 1)
		write(1, "rrr\n", 4);
	list_1->number_of_operations++;
}
