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

void triple_sort(t_list *list)
{
	t_node	*temp;

	if (list->size != 3) //uberu potom
	{
		printf("triple_sort error: not 3 numbers\n");
		exit(0);
	}
	if (is_sort(list) == 1)
		return ;
	temp = list->head;
	find_minmax(list);
	if (temp-value = list->max)
		
}

int main(int argc, char **argv)
{
	t_list *list;
	t_list *list_2;
	t_node *temp;
	t_parse	parse;

	
	if (argc < 2)
	{
		printf("\ntoo few arguments\n");
		return (0);
	}
	num_array_dealer(argc, argv, &parse);
	list = create_list_from_argv(parse.size_array, parse.sort_ind_array);
	list_2 = list_init(0);
	
	
//
//	printf("%p\n", list->head);
//		printf("%p\n", list->head->next);
	
//		printf("%p\n", list->head->next);
//	printf("%p\n", list->head->next->next);
//	printf("%p\n", list->head->next->next->next);
//		printf("%p\n", list->head->next->next->next->next);
//	printf("\n|\n");
	printf("\nbefore:\n");
	printf("list_one:\n");
	print_list(list);
	printf("list_two:\n");
	print_list(list_2);
	find_minmax(list);
	
	printf("\n%d %d\n", list->min, list->max);
	
//	push(list, list_2);
//	push(list, list_2);
//	push(list, list_2);
//	push(list, list_2);
//	push(list, list_2);
//
//	swap_both(list, list_2);
//	printf("\n");
//	printf("\n|\n");
//	printf("\nafter:\n");
//	printf("list_one:\n");
//	print_list(list);
//	printf("list_two:\n");
//	print_list(list_2);
//
//
//		push(list_2, list);
//	//	printf("\n");
//	//	printf("\n|\n");
//		printf("\nafter:\n");
//		printf("list_one:\n");
//		print_list(list);
//		printf("list_two:\n");
//		print_list(list_2);
//
	
//	swap_ab(list);
//	print_list(list);

//	rev_rotate_one(list);
//	print_list(list);
//	printf("[%d]", ((end - start)));
//	printf("\n{%d}", is_sort(list));
	return (0);
}
