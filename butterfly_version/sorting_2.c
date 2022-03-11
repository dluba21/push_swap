#include "push_swap.h"

void	four_sort(t_list *list_1, t_list *list_2)
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

void	less_six_sort(t_list *list_1, t_list *list_2)
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

void	first_step_of_sort(t_list *list_1, t_list *list_2, \
						int upper_iter_limit, int show_flag)
{
	int	counter;

	counter = 1;
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

void	second_step_of_sort(t_list *list_1, t_list *list_2, int show_flag)
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
