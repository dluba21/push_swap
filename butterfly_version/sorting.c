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

void triple_sort(t_list *list, int stack_flag) // 1 = stack_a, 2 = stack_b
{
	t_node	*temp;
	
	if (list->size != 3) //uberu potom, a poka lishnim ne budet
	{
		printf("triple_sort error: not 3 numbers\n");
		exit(0);
	}
	if (is_sort(list) == 1) //case 1 2 3
		return ;
	temp = list->head; //mozhno dobitsa men'shih strok esli snachala sdelat stroki uslovno sortirovannimi (swap), a potom uzhe rabotat s tremya sluchayami)
	find_minmax(list);
	if (temp->value == list->max)
	{
		if (temp->next->value == list->min) //case 3 1 2
		{
			ra_rb(list, stack_flag);
			return ;
		}
		else //case 3 2 1
		{
			ra_rb(list, stack_flag); //oshibka rra
			sa_sb(list, stack_flag);
			return ;
		}
	}
	else if (temp->value == list->min) //case 1 3 2
	{
		sa_sb(list, stack_flag);
		ra_rb(list, stack_flag);
		return ;
	}
	else if (temp->next->value == list->max) //case 2 3 1
	{
		rra_rrb(list, stack_flag); //ohsibka rra
		return ;
	}
	//else{
	sa_sb(list, stack_flag); //case 2 1 3
//	return;}
}

void first_step_of_sort(t_list *list_1, t_list *list_2)
{
	int counter = 1;
	
	while (list_1->head)
	{
		if (list_1->head->value <= counter)
		{
			pa_pb(list_1, list_2, 2);
			ra_rb(list_2, 2);
			counter++;
		}
		else if (list_1->head->value <= counter + UPPER_ITER_LIMIT)
		{
			pa_pb(list_1, list_2, 2);
			counter++;
		}
		else
			ra_rb(list_1, 1);
	}
}

void second_step_of_sort(t_list *list_1, t_list *list_2)
{
	int	maximum;

	maximum = list_2->size;
	while (list_2->head)
	{
		printf("max: %d\tpos: %d\tsize: %d\n", maximum, get_position_of_elem(list_2, maximum), list_2->size);
//		if (get_position_of_elem(list_2, maximum) == -1)
//		{
//			printf("->->->->\n\n");
//			print_list(list_2);
//			printf("<-<-<-<-\n\n");
//		}
		if (get_position_of_elem(list_2, maximum) <= list_2->size / 2)
		{
			while (list_2->head->value != maximum)
				ra_rb(list_2, 2);
			pa_pb(list_1, list_2, 1);
		}
		else
		{
			while (list_2->head->value != maximum)
				rra_rrb(list_2, 2);
			pa_pb(list_1, list_2, 1);
		}
		maximum--;
	}
}


void general_sort(t_list *list_1, t_list *list_2)
{
	if (list_1->size <= 3)
	{
		triple_sort(list_1, 1);
		printf("triple sort ended!\n");
		exit(0);
	}
	else if (list_1->size <= 5)
	{
		printf("five sort\n");
		exit(0);
	}
	first_step_of_sort(list_1, list_2);
	second_step_of_sort(list_1, list_2);
	print_list(list_1);
	if (is_sort(list_1) == 1)
		printf("congratulations! :)\n");
	else
		printf("sorting error :(\n");
	printf("the end! operations: %d\n", list_1->number_of_operations + list_2->number_of_operations);
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
