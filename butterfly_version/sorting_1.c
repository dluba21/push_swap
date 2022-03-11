#include "push_swap.h"

int	is_nearly_sort(t_list *list)
{
	int	temp;
	int	flag;

	flag = 0;
	temp = list->head->value;
	ra_rb(list, 1, 0);
	if (is_sort(list) == 1)
		flag = 1;
	while (list->head->value != temp)
	{
		ra_rb(list, 1, 0);
		if (is_sort(list) == 1)
			flag = 1;
	}
	return (flag);
}

void	triple_sort(t_list *list, int stack_flag)
{
	int		min;
	int		max;

	if (is_sort(list) == 1)
		return ;
	if (!is_nearly_sort(list))
		sa_sb(list, stack_flag, 1);
	min = find_min(list);
	max = find_max(list);
	if (list->head->value == max)
		ra_rb(list, stack_flag, 1);
	else if (list->head->value == min)
		return ;
	else
		rra_rrb(list, stack_flag, 1);
}

void	move_elem_on_top(t_list *list, int value, int show_flag)
{
	while (list->head->value != value)
	{
		if (get_position_of_elem(list, value) <= \
			list->size / 2 + list->size % 2)
			ra_rb(list, 1, show_flag);
		else
			rra_rrb(list, 1, show_flag);
	}
}

int	five_sort_best_strategy(t_list *list_a)
{
	int		operations_1;
	int		operations_2;
	t_list	*list_1;
	t_list	*list_2;

	list_1 = copy_list(list_a);
	list_2 = list_init(0);
	move_elem_on_top(list_1, 1, 0);
	pa_pb(list_1, list_2, 2, 0);
	move_elem_on_top(list_1, 2, 0);
	operations_1 = list_1->number_of_operations;
	free_list(list_1);
	list_1 = copy_list(list_a);
	move_elem_on_top(list_1, 2, 0);
	pa_pb(list_1, list_2, 2, 0);
	move_elem_on_top(list_1, 1, 0);
	operations_2 = list_1->number_of_operations;
	free_list(list_1);
	free_list(list_2);
	if (operations_1 <= operations_2 + 1)
		return (0);
	return (1);
}

void	five_sort(t_list *list_1, t_list *list_2)
{
	if (five_sort_best_strategy(list_1) == 0)
	{
		move_elem_on_top(list_1, 1, 1);
		pa_pb(list_1, list_2, 2, 1);
		move_elem_on_top(list_1, 2, 1);
		pa_pb(list_1, list_2, 2, 1);
	}
	else
	{
		move_elem_on_top(list_1, 2, 1);
		pa_pb(list_1, list_2, 2, 1);
		move_elem_on_top(list_1, 1, 1);
		pa_pb(list_1, list_2, 2, 1);
		sa_sb(list_2, 2, 1);
	}
	triple_sort(list_1, 1);
	pa_pb(list_1, list_2, 1, 1);
	pa_pb(list_1, list_2, 1, 1);
	exit(0);
}
