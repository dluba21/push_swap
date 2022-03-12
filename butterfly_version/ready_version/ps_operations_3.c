/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operations_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrdeysuvorov <anrdeysuvorov@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 03:43:09 by anrdeysuvor       #+#    #+#             */
/*   Updated: 2022/03/12 03:43:32 by anrdeysuvor      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra_rrb(t_list *list, int stack_flag, int show_flag)
{
	rev_rotate_one(list);
	if (show_flag == 1)
	{
		if (stack_flag == 1)
			write(1, "rra\n", 4);
		else
			write(1, "rrb\n", 4);
	}
	list->number_of_operations++;
}

void	rrr(t_list *list_1, t_list *list_2, int show_flag)
{
	rev_rotate_one(list_1);
	rev_rotate_one(list_2);
	if (show_flag == 1)
		write(1, "rrr\n", 4);
	list_1->number_of_operations++;
}
