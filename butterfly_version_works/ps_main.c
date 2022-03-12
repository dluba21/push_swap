/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrdeysuvorov <anrdeysuvorov@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 03:43:02 by anrdeysuvor       #+#    #+#             */
/*   Updated: 2022/03/12 03:43:33 by anrdeysuvor      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*list_1;
	t_list	*list_2;
	t_parse	parse;

	if (argc < 2)
		exit(0);
	num_array_dealer(argc, argv, &parse);
	list_1 = create_list_from_argv(parse.size_array, parse.sort_ind_array);
	list_2 = list_init(0);
	general_sort(list_1, list_2);
	return (0);
}
