#include "push_swap.h"

int	is_sort(t_list *list)
{
	t_node	*temp;

	if (!list || !list->head)
		return (0);
	if (list->size == 1)
		return (1);
	temp = list->head;
	while (temp->next)
	{
		if (temp->value > temp->next->value)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	find_min(t_list *list)
{
	t_node	*temp;
	int		min;

	temp = list->head;
	min = temp->value;
	while (temp)
	{
		if (min > temp->value)
			min = temp->value;
		temp = temp->next;
	}
	return (min);
}

int	find_max(t_list *list)
{
	t_node	*temp;
	int		max;

	temp = list->head;
	max = temp->value;
	while (temp)
	{
		if (max < temp->value)
			max = temp->value;
		temp = temp->next;
	}
	return (max);
}

int	get_position_of_elem(t_list *list, int value)
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
