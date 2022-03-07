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

void first_step_general_sort(t_list *list_1, t_list *list_2)
{
	int	i = 0;
	int j = 0; //blokirovka counter

	list_1->mid = list_1->size / 2 + list_1->next; //size / 2 + 1
	while (i < list_1->size)
	{
		if (list_1->head->value == list_1->next && j == 0) //ispravit' koroche chtoby bilo
		{
			list_1->head->flag = -1;
			list_1->next++;
			ra_rb(list_1, 1); //ra
		}
		if (list_1->head->value <= list_1->mid) //vot zdes' bilo bi kruto srazu reverse dealt esli next==value
		{
			pa_pb(list_1, list_2, 2); //pb
			continue;
		}
		else
		{
			ra_rb(list_1, 1); //ra
			j++;
		}
		i++;
	}
	//operations with stack_b
//	while (list_2->size > 3) triple_sort, pb and ra (add it to optimize)
	//mb here not good conidition because there can be 2 or 1 size be left
	while (list_2->head)//repeat recursively while B not empty
	{
		list_1->max = list_1->mid;
		list_1->mid = (list_1->max - list_1->next) / 2 + list_1->next;
		list_1->flag++; //cause init mid in B one more time

		i = 0;
		while (i < list_2->size)
		{
			if (list_2->size == 3)
				triple_sort(list_2, 2);
			if (list_2->head->value == list_1->next) //to optimize change order of 'if'
			{
				//list_2->head->flag = list_1->flag; in pa_pb inserted already
				pa_pb(list_1, list_2, 1); //pa and ra => sorted element
				ra_rb(list_1, 1); //pa and ra => sorted element
				list_1->next++;
				continue;
			}
			else if (list_2->head->value > list_2->mid)
			{
				list_2->head->flag = list_1->flag;
				pa_pb(list_1, list_2, 1); //pa
				continue; //because after this will be i++, but size-- cause push
			}
			
			else
				ra_rb(list_2, 2); //rb
			i++;
		}
	}
}

void other_steps_part_stack_b(t_list *list_1, t_list *list_2) //can be inserted to first_step_sort
{
	int	i;

	while (list_2->head != NULL)//operations with stack_b
	{
		find_minmax(list_2);
		list_1->max = list_2->max;
		list_1->mid = (list_1->max - list_1->next) / 2 + list_1->next;
		list_1->flag++; //cause init mid in B one more time
		
		i = 0;
		while (i < list_2->size)
		{
			if (list_2->size == 3)
				triple_sort(list_2, 2);
			if (list_2->head->value == list_1->next) //to optimize change order of 'if'
			{
				//list_2->head->flag = list_1->flag; in pa_pb inserted already
				pa_pb(list_1, list_2, 1); //pa and ra => sorted element
				ra_rb(list_1, 1); //pa and ra => sorted element
				list_1->next++;
				continue;
			}
			else if (list_2->head->value > list_2->mid)
			{
				pa_pb(list_1, list_2, 1); //pa
				continue; //because after this will be i++, but size-- cause push
			}
			else
				ra_rb(list_2, 2); //rb
			i++;
		}
	}
}

void other_steps_general_sort(t_list *list_1, t_list *list_2)
{
	int	temp_flag;
	int	i;
	temp_flag = list_1->head->flag;
	
	i = 0;
	if (list_1->head->flag == 0)
	{
		find_midmax_with_flag_zero(list_1);
		while (list_1->head->flag == 0)
		{
			//uchet blokirovki i next srazu
			if ((list_1->head->value == list_1->next) && (i == 0)) //zdes' tozhe mozhno dobavit 'ra', esli random==next! sdealt funcioy otdelnuyy
			{
				list_1->head->flag = -1;
				ra_rb(list_1, 1); //tut kak raz i uchel
				list_1->next++;
				continue;
			}
			if (list_1->head->value <= list_1->mid)
				pa_pb(list_1, list_2, 2);
			else
			{
				ra_rb(list_1, 1);
				i++;
			}
		}
		while (i > 0) //prokrutil obratno
		{
			rra_rrb(list_1, 1);
			i--;
		}
		other_steps_part_stack_b(list_1, list_2);
		return ;
	}
	while ((list_1->head->flag == temp_flag) && (list_1->head->flag > 0)) //mb > 0 not good
	{
		if (list_1->head->value == list_1->next) //zdes' tozhe mozhno dobavit 'ra', esli random==next! sdealt funcioy otdelnuyy
		{
			list_1->head->flag = -1;
			ra_rb(list_1, 1); //tut kak raz i uchel
			list_1->next++;
			continue;
		}
		pa_pb(list_1, list_2, 2);
	}
	other_steps_part_stack_b(list_1, list_2);
}


////	while (list_2->size > 3) triple_sort, pb and ra (add it to optimize)
//	//mb here not good conidition because there can be 2 or 1 size be left
//	while (list_2->head)//repeat recursively while B not empty
//	{
//		list_1->max = list_1->mid;
//		list_1->mid = (list_1->max - list_1->next) / 2 + list_1->next;
//		list_1->flag++; //cause init mid in B one more time
//
//		i = 0;
//		while (i < list_2->size)
//		{
//			if (list_2->head->value == list_1->next) //to optimize change order of 'if'
//			{
//				list_2->head->flag = list_1->flag;  //mb not need
//				pa_pb(list_1, list_2, 1); //pa and ra => sorted element
//				ra_rb(list_1, 1); //pa and ra => sorted element
//				list_1->next++;
//				continue;
//			}
//			else if (list_2->head->value > list_2->mid)
//			{
//				list_2->head->flag = list_1->flag;
//				pa_pb(list_1, list_2, 1); //pa
//				continue; //because after this will be i++, but size-- cause push
//			}
//
//			else
//				ra_rb(list_2, 2); //rb
//			i++;
//		}
//	}


void general_sort(t_list *list_1, t_list *list_2) //need init flags, next, size, etc
{
//	if (size >= 3 && size <= 5)
	//	init_lists_values_before_sort();
//	if (list_1->size == 3)
//	{
//		triple_sort(list_1, 1);
//		exit(0);
//	}
	if (is_sort(list_1) == 1) //replace to checking just after parsing
		exit(0);
	first_step_general_sort(list_1, list_2);
	//_and_flag(list_1);
	printf("\n\nfirst step ends...\n\n\n");
	while (is_sort(list_1) != 1)
	{
//		if (list_1->number_of_operations + list_2->number_of_operations > 50)
//			exit(0);
		other_steps_general_sort(list_1, list_2);
		//_and_flag(list_1);
	}
	printf("the end! number of operations: %d\n", list_1->number_of_operations + list_2->number_of_operations);
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
