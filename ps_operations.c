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

void rev_rotate_one(t_list *list)
{
	t_node	*temp;
	t_node	*elem;
	int		i;

	i = 1; // '1' tak kak v nachale mi nahodimsya uzhe v headx
	if (!list || !list->head || !list->head->next || !list->size)
	{
		printf("list error(rotate)\n");
		return ;
	}
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



void sa_sb(t_list *list, int stack_flag) // 1 = stack_a, 2 = stack_b
{
	swap_one(list);
	if (stack_flag == 1)
		printf("sa\n");
	else
		printf("sb\n");
}


void ss(t_list *list_1, t_list *list_2)
{
	swap_one(list_1);
	swap_one(list_2);
	printf("ss\n");
}

void pa_pb(t_list *list_a, t_list *list_b, int stack_flag)
{
	push(list_a, list_b);
	if (stack_flag == 1)
	{
		push(list_b, list_a);
		printf("pa\n");
	}
	else
	{
		push(list_a, list_b);
		printf("pb\n");
	}
}

void ra_rb(t_list *list, int stack_flag)
{
	rotate_one(list);
	if (stack_flag == 1)
		printf("ra\n");
	else
		printf("rb\n");
}

void rr(t_list *list_a, t_list *list_b)
{
	rotate_one(list_a);
	rotate_one(list_b);
	printf("rr\n");
}

void rra_rrb(t_list *list, int stack_flag)
{
	rev_rotate_one(list);
	if (stack_flag == 1)
		printf("rra\n");
	else
		printf("rrb\n");
}

void rrr(t_list *list_a, t_list *list_b)
{
	rev_rotate_one(list_a);
	rev_rotate_one(list_b);
	printf("rrr\n");
}
