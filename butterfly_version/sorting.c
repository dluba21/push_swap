#include "push_swap.h"

//ya ne uzhel peremesheniye naverch kogda prihozhu k neotsortirovannomu kusku
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
	{
		printf("get position error\n");
		exit (0);
	}
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


//void tetra_sort(t_list *list_1, t_list *list_2, int stack_flag)
//{
//
//}

int triple_sort(t_list *list, int stack_flag) // 1 = stack_a, 2 = stack_b
{
	t_node	*temp;
	
	if (list->size != 3) //uberu potom, a poka lishnim ne budet
	{
		printf("triple_sort error: not 3 numbers\n");
		exit(0);
	}
	if (is_sort(list) == 1) //case 1 2 3
		return (0);
	temp = list->head; //mozhno dobitsa men'shih strok esli snachala sdelat stroki uslovno sortirovannimi (swap), a potom uzhe rabotat s tremya sluchayami)
	find_minmax(list);
	if (temp->value == list->max)
	{
		if (temp->next->value == list->min) //case 3 1 2
		{
			ra_rb(list, stack_flag, 1);
			return (0);
		}
		else //case 3 2 1
		{
			ra_rb(list, stack_flag, 1); //oshibka rra
			sa_sb(list, stack_flag, 1);
			return (0);
		}
	}
	else if (temp->value == list->min) //case 1 3 2
	{
		sa_sb(list, stack_flag, 1);
		ra_rb(list, stack_flag, 1);
		return (0);
	}
	else if (temp->next->value == list->max) //case 2 3 1
	{
		rra_rrb(list, stack_flag, 1); //ohsibka rra
		return (0);
	}
	//else{
	sa_sb(list, stack_flag, 1); //case 2 1 3
	return (0);
//	return;}
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
	printf("operation_1 = %d\toperation_1 = %d\n", operations_1, operations_2 + 1);
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
//		printf("max: %d\tpos: %d\tsize: %d\n", maximum, get_position_of_elem(list_2, maximum), list_2->size);
//		if (get_position_of_elem(list_2, maximum) == -1)
//		{
//			printf("->->->->\n\n");
//			print_list(list_2);
//			printf("<-<-<-<-\n\n");
//		}
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
	{
		printf("error: get_optimal_sort_step\n");
		exit (0);
	}
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
//		printf("min_limit = %d\tmin_oper = %d\tcurr_oper = %d\n", min_upper_limit, min_operations, current_operations);
		if (min_operations > current_operations)
		{
			min_operations = current_operations;
			min_upper_limit = upper_limit;
		}
//		if (list_a->size == 100 && current_operations <= 700)
//			return (upper_limit);
//		else if (list_a->size == 500 && current_operations <= 7000)
//			return (upper_limit);
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
//	optimal_limit = 19;
	first_step_of_sort(list_1, list_2, optimal_limit, 1);
	second_step_of_sort(list_1, list_2, 1);
//	print_list(list_1);
	
//	if (is_sort(list_1) == 1)
//		printf("congratulations! :)\n");
//	else
//		printf("sorting error :(\n");
//	printf("the end! operations: %d\n", list_1->number_of_operations + list_2->number_of_operations);
}



int main(int argc, char **argv)
{
	t_list *list_1;
	t_list *list_2;
	t_node *temp;
	t_parse	parse;

//	if (argc == 1)
//	{
//		printf("\n");
//		exit(0);
//	}
	if (argc < 2)
	{
		printf("\ntoo few arguments\n");
		return (0);
	}
	num_array_dealer(argc, argv, &parse);
	list_1 = create_list_from_argv(parse.size_array, parse.sort_ind_array);
	list_2 = list_init(0);
	
	//_in_line(list_1, 1);
	//_in_line(list_2, 1);

	general_sort(list_1, list_2);
//	//_and_flag(list_1);
	
// pointers_check_start
//	printf("%p\n", list->head);
//	printf("%p\n", list->head->next);
//
//		printf("%p\n", list->head->next);
//	printf("%p\n", list->head->next->next);
//	printf("%p\n", list->head->next->next->next);
//		printf("%p\n", list->head->next->next->next->next);
// pointers_check_end
	
	
	
//operation_check_start
//	printf("\nbefore:\n");
//	printf("list_one:\n");
//	//(list);
//	printf("list_two:\n");
//	//(list_2);
//	rra(list); //operation need to be checked
//	printf("\nafter:\n");
//	printf("list_one:\n");
//	//(list);
//	printf("list_two:\n");
//	//(list_2);
//operation_check_end

	
	
	
	
	
	
	
//triple_sort_check_start
//	printf("\nbefore:\n");
//	//(list);
//	printf("\n");
//	triple_sort(list, 1);
//	printf("\nafter:\n");
//	//(list);
//triple_sort_check_end
	
	
//	push(list, list_2);
//	push(list, list_2);
//	push(list, list_2);
//	push(list, list_2);
//	push(list, list_2);
//

//
//
//		push(list_2, list);
//	//	printf("\n");
//	//	printf("\n|\n");
//		printf("\nafter:\n");
//		printf("list_one:\n");
//		//(list);
//		printf("list_two:\n");
//		//(list_2);
//
	
//	swap_ab(list);
//	//(list);

//	rev_rotate_one(list);
//	//(list);
//	printf("[%d]", ((end - start)));
//	printf("\n{%d}", is_sort(list));
	return (0);
}
