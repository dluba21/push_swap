/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operations_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrdeysuvorov <anrdeysuvorov@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 03:43:07 by anrdeysuvor       #+#    #+#             */
/*   Updated: 2022/03/12 03:43:32 by anrdeysuvor      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa_sb(t_list *list, int stack_flag, int show_flag)
{
	swap_one(list);
	if (show_flag == 1)
	{
		if (stack_flag == 1)
			write(1, "sa\n", 3);
		else
			write(1, "sb\n", 3);
	}
	list->number_of_operations++;
}

void	ss(t_list *list_1, t_list *list_2, int show_flag)
{
	swap_one(list_1);
	swap_one(list_2);
	if (show_flag == 1)
		write(1, "ss\n", 3);
	list_1->number_of_operations++;
}

void	pa_pb(t_list *list_1, t_list *list_2, int stack_flag, int show_flag)
{
	if (stack_flag == 1)
	{
		push(list_2, list_1);
		list_1->size++;
		list_2->size--;
		if (show_flag == 1)
			write(1, "pa\n", 3);
	}
	else
	{
		list_1->size--;
		list_2->size++;
		push(list_1, list_2);
		if (show_flag == 1)
			write(1, "pb\n", 3);
	}
	list_1->number_of_operations++;
}

void	ra_rb(t_list *list, int stack_flag, int show_flag)
{
	rotate_one(list);
	if (show_flag == 1)
	{
		if (stack_flag == 1)
			write(1, "ra\n", 3);
		else
			write(1, "rb\n", 3);
	}
	list->number_of_operations++;
}

void	rr(t_list *list_1, t_list *list_2, int show_flag)
{
	rotate_one(list_1);
	rotate_one(list_2);
	if (show_flag == 1)
		write(1, "rr\n", 3);
	list_1->number_of_operations++;
}
