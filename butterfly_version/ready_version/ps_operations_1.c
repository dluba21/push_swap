/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operations_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrdeysuvorov <anrdeysuvorov@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 03:43:05 by anrdeysuvor       #+#    #+#             */
/*   Updated: 2022/03/12 03:43:33 by anrdeysuvor      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_one(t_list *list)
{
	t_node	*temp_1;
	t_node	*temp_2;

	if (!list || !list->head || !list->head->next)
		return ;
	temp_1 = list->head->next;
	temp_2 = list->head->next->next;
	list->head->next = temp_2;
	temp_1->next = list->head;
	list->head = temp_1;
}

void	push(t_list *list_src, t_list *list_dest)
{
	t_node	*temp_1;
	t_node	*temp_2;

	if (!list_src || !list_dest || !list_src->head)
		return ;
	temp_1 = list_dest->head;
	temp_2 = list_src->head->next;
	list_dest->head = list_src->head;
	list_dest->head->next = temp_1;
	list_src->head = temp_2;
}

void	rotate_one(t_list *list)
{
	t_node	*temp;
	t_node	*elem;

	if (!list || !list->head || !list->head->next)
		return ;
	temp = list->head->next;
	elem = get_last_elem(list);
	list->head->next = NULL;
	elem->next = list->head;
	list->head = temp;
}

void	rev_rotate_one(t_list *list)
{
	t_node	*temp;
	t_node	*elem;
	int		i;

	i = 1;
	if (!list || !list->head || !list->head->next || !list->size)
		return ;
	elem = list->head;
	while (i < list->size - 1)
	{
		elem = elem->next;
		i++;
	}
	temp = elem->next;
	elem->next = NULL;
	temp->next = list->head;
	list->head = temp;
}
