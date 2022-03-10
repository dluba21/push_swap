#include "push_swap.h"

void find_minmax(t_list *list)
{
	t_node	*temp;

	temp = list->head;
	list->max = temp->value;
	list->min = temp->value;
	while (temp)
	{
		if (list->max < temp->value)
			list->max = temp->value;
		if (list->min > temp->value)
			list->min = temp->value;
		temp = temp->next;
	}
}



int get_position_of_elem(t_list *list, int value)
{
	t_node	*temp;
	int		position;

	position = 1;
	temp = list->head;
	if (!temp)
		exit (0);
	while (temp->next)
	{
		if (temp->value == value)
			return (position);
		temp = temp->next;
		position++;
	}
	return (position);
}

void find_midmax_with_flag_zero(t_list *list)
{
	t_node	*temp;

	temp = list->head;
	list->max = temp->value;
	list->min = temp->value;
	while (temp && temp->flag == 0)
	{
		if (list->max < temp->value)
			list->max = temp->value;
		if (list->min > temp->value)
			list->min = temp->value;
		temp = temp->next;
	}
	list->mid = (list->max - list->next) / 2 + list->next;
}


int is_nearly_sort(t_list *list)
{
	int	temp;
	int flag;

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

void triple_sort(t_list *list, int stack_flag) // 1 = stack_a, 2 = stack_b
{
	t_node	*temp;
	
	if (is_sort(list) == 1) //case 1 2 3
		return ;
	if (!is_nearly_sort(list))
		sa_sb(list, stack_flag, 1);
	find_minmax(list);
	if (list->head->value == list->max)
		ra_rb(list, stack_flag, 1);
	else if (list->head->value == list->min)
		return ;
	else
		rra_rrb(list, stack_flag, 1);
}

void get_elem_on_top(t_list *list, int value, int show_flag)
{
	while (list->head->value != value)
	{
		if (get_position_of_elem(list, value) <= list->size / 2 + list->size % 2)
			ra_rb(list, 1, show_flag);
		else
			rra_rrb(list, 1, show_flag);
	}
}

int five_sort_best_strategy(t_list *list_a)
{
	int		operations_1;
	int		operations_2;
	t_list	*list_1;
	t_list	*list_2;

	list_1 = copy_list(list_a);
	list_2 = list_init(0);
	get_elem_on_top(list_1, 1, 0);
	pa_pb(list_1, list_2, 2, 0);
	get_elem_on_top(list_1, 2, 0);
	operations_1 = list_1->number_of_operations;
	free_list(list_1);
	list_1 = copy_list(list_a);
	get_elem_on_top(list_1, 2, 0);
	pa_pb(list_1, list_2, 2, 0);
	get_elem_on_top(list_1, 1, 0);
	operations_2 = list_1->number_of_operations;
	free_list(list_1);
	free_list(list_2);
	if (operations_1 <= operations_2 + 1)
		return (0);
	return (1);
}

void five_sort(t_list *list_1, t_list *list_2)
{
	if (five_sort_best_strategy(list_1) == 0)
	{
		get_elem_on_top(list_1, 1, 1);
		pa_pb(list_1, list_2, 2, 1);
		get_elem_on_top(list_1, 2, 1);
		pa_pb(list_1, list_2, 2, 1);
	}
	else
	{
		get_elem_on_top(list_1, 2, 1);
		pa_pb(list_1, list_2, 2, 1);
		get_elem_on_top(list_1, 1, 1);
		pa_pb(list_1, list_2, 2, 1);
		sa_sb(list_2, 2, 1);
	}
	triple_sort(list_1, 1);
	pa_pb(list_1, list_2, 1, 1);;
	pa_pb(list_1, list_2, 1, 1);
	exit(0);
}

//find_min_sort

void four_sort(t_list *list_1, t_list *list_2)
{
	while (list_1->head->value != 4)
	{
		if (get_position_of_elem(list_1, 4) <= 2)
			ra_rb(list_1, 1, 1);
		else
			rra_rrb(list_1, 1, 1);
	}
	pa_pb(list_1, list_2, 2, 1);
	triple_sort(list_1, 1);
	pa_pb(list_1, list_2, 1, 1);
	ra_rb(list_1, 1, 1);
	exit(0);
}

void less_six_sort(t_list *list_1, t_list *list_2)
{
	if (list_1->size == 5)
		five_sort(list_1, list_2);
	if (list_1->size == 4)
		four_sort(list_1, list_2);
	if (list_1->size == 3)
	{
		triple_sort(list_1, 1);
		exit(0);
	}
	if (list_1->size == 2)
	{
		sa_sb(list_1, 1, 1);
		exit(0);
	}
	if (list_1->size == 1)
		exit(0);
}

void first_step_of_sort(t_list *list_1, t_list *list_2, int upper_iter_limit, int show_flag)
{
	int counter = 1;
	
	while (list_1->head)
	{
		if (list_1->head->value <= counter)
		{
			pa_pb(list_1, list_2, 2, show_flag);
			ra_rb(list_2, 2, show_flag);
			counter++;
		}
		else if (list_1->head->value <= counter + upper_iter_limit)
		{
			pa_pb(list_1, list_2, 2, show_flag);
			counter++;
		}
		else
			ra_rb(list_1, 1, show_flag);
	}
}

void second_step_of_sort(t_list *list_1, t_list *list_2, int show_flag)
{
	int	maximum;

	maximum = list_2->size;
	while (list_2->head)
	{
		if (get_position_of_elem(list_2, maximum) <= list_2->size / 2)
		{
			while (list_2->head->value != maximum)
				ra_rb(list_2, 2, show_flag);
			pa_pb(list_1, list_2, 1, show_flag);
		}
		else
		{
			while (list_2->head->value != maximum)
				rra_rrb(list_2, 2, show_flag);
			pa_pb(list_1, list_2, 1, show_flag);
		}
		maximum--;
	}
}


int get_optimal_limit_one_step(t_list *list_a, t_list *list_b, int upper_iter_limit)
{
	t_list	*list_1;
	t_list	*list_2;
	int		oper_numb;

	list_1 = copy_list(list_a);
	list_2 = list_init(0);

	first_step_of_sort(list_1, list_2, upper_iter_limit, 0);
	second_step_of_sort(list_1, list_2, 0);
	if (!is_sort(list_1))
		exit (0);
	oper_numb = list_1->number_of_operations + list_2->number_of_operations;
	free_list(list_1);
	free_list(list_2);
	return (oper_numb);
}

int get_optimal_limit(t_list *list_a, t_list *list_b)
{
	
	int	upper_limit;
	int current_operations;
	int min_operations;
	int min_upper_limit;

	min_operations = 10000000;
	upper_limit = 1;
	min_upper_limit = 1;
	while (upper_limit < 60)
	{
		current_operations = get_optimal_limit_one_step(list_a, list_b, upper_limit);
		if (min_operations > current_operations)
		{
			min_operations = current_operations;
			min_upper_limit = upper_limit;
		}
		upper_limit++;
	}
	return (min_upper_limit);
}

void general_sort(t_list *list_1, t_list *list_2)
{
	int	optimal_limit;

	if (is_sort(list_1) == 1)
		exit(0);
	less_six_sort(list_1, list_2);
	optimal_limit = get_optimal_limit(list_1, list_2);
	first_step_of_sort(list_1, list_2, optimal_limit, 1);
	second_step_of_sort(list_1, list_2, 1);
	exit(0);
}



int main(int argc, char **argv)
{
	t_list *list_1;
	t_list *list_2;
	t_node *temp;
	t_parse	parse;

	if (argc == 1)
	{
		write(1, "\n", 1); //?????
		exit(0);
	}
	num_array_dealer(argc, argv, &parse);
	list_1 = create_list_from_argv(parse.size_array, parse.sort_ind_array);
	list_2 = list_init(0);
	general_sort(list_1, list_2);
	return (0);
}
