#include "push_swap.h"

int	get_optimal_lim_part(t_list *list_a, int upper_iter_limit)
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

int	get_optimal_limit(t_list *list_a)
{
	int	upper_limit;
	int	current_operations;
	int	min_operations;
	int	min_upper_limit;

	min_operations = 10000000;
	upper_limit = 1;
	min_upper_limit = 1;
	while (upper_limit < 60)
	{
		current_operations = get_optimal_lim_part(list_a, upper_limit);
		if (min_operations > current_operations)
		{
			min_operations = current_operations;
			min_upper_limit = upper_limit;
		}
		upper_limit++;
	}
	return (min_upper_limit);
}

void	general_sort(t_list *list_1, t_list *list_2)
{
	int	optimal_limit;

	if (is_sort(list_1) == 1)
		exit(0);
	less_six_sort(list_1, list_2);
	optimal_limit = get_optimal_limit(list_1);
	first_step_of_sort(list_1, list_2, optimal_limit, 1);
	second_step_of_sort(list_1, list_2, 1);
	exit(0);
}
