/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_list_methods_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrdeysuvorov <anrdeysuvorov@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 03:42:41 by anrdeysuvor       #+#    #+#             */
/*   Updated: 2022/03/12 03:43:35 by anrdeysuvor      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_elem(int value)
{
	t_node	*new_elem;

	new_elem = (t_node *)malloc(sizeof(t_node));
	if (!new_elem)
		return (0);
	new_elem->value = value;
	new_elem->next = NULL;
	return (new_elem);
}

int	list_length(t_list *list)
{
	t_node	*temp;
	int		i;

	if (!list || !list->head)
		return (0);
	i = 1;
	temp = list->head;
	while (temp->next)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

t_node	*get_last_elem(t_list *list)
{
	t_node	*temp;

	if (!list || !list->head)
		return (NULL);
	temp = list->head;
	while (temp->next)
		temp = temp->next;
	return (temp);
}

void	add_front_list(t_list *list, t_node *elem)
{
	if (!list || !elem)
		print_error();
	elem->next = list->head;
	list->head = elem;
}

void	add_back_list(t_list *list, t_node *elem)
{
	t_node	*temp;

	if (!list || !elem)
		print_error();
	temp = get_last_elem(list);
	if (!temp)
	{
		list->head = elem;
		return ;
	}
	temp->next = elem;
}
