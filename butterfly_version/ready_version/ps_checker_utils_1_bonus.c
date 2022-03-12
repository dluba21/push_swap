/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_checker_utils_1_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrdeysuvorov <anrdeysuvorov@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 03:42:31 by anrdeysuvor       #+#    #+#             */
/*   Updated: 2022/03/12 03:42:32 by anrdeysuvor      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_command(t_list *list_1, t_list *list_2, int command)
{
	if (command == 1)
		sa_sb(list_1, 1, 0);
	else if (command == 2)
		sa_sb(list_2, 2, 0);
	else if (command == 3)
		ss(list_1, list_2, 0);
	else if (command == 4)
		pa_pb(list_1, list_2, 1, 0);
	else if (command == 5)
		pa_pb(list_1, list_2, 2, 0);
	else if (command == 6)
		ra_rb(list_1, 1, 0);
	else if (command == 7)
		ra_rb(list_2, 2, 0);
	else if (command == 8)
		rr(list_1, list_2, 0);
	else if (command == 9)
		rra_rrb(list_1, 1, 0);
	else if (command == 10)
		rra_rrb(list_2, 2, 0);
	else if (command == 11)
		rrr(list_1, list_2, 0);
}

int	choose_command(char *str)
{
	if (ft_strcmp(str, "sa\n"))
		return (1);
	if (ft_strcmp(str, "sb\n"))
		return (2);
	if (ft_strcmp(str, "ss\n"))
		return (3);
	if (ft_strcmp(str, "pa\n"))
		return (4);
	if (ft_strcmp(str, "pb\n"))
		return (5);
	if (ft_strcmp(str, "ra\n"))
		return (6);
	if (ft_strcmp(str, "rb\n"))
		return (7);
	if (ft_strcmp(str, "rr\n"))
		return (8);
	if (ft_strcmp(str, "rra\n"))
		return (9);
	if (ft_strcmp(str, "rrb\n"))
		return (10);
	if (ft_strcmp(str, "rrr\n"))
		return (11);
	return (-1);
}

int	command_parser(void)
{
	int		command;
	char	*line;

	line = get_next_line(0);
	if (!line)
		return (0);
	command = choose_command(line);
	free(line);
	return (command);
}

int	main(int argc, char **argv)
{
	int		command;
	t_list	*list_1;
	t_list	*list_2;
	t_parse	parse;

	if (argc == 1)
		print_error();
	num_array_dealer(argc, argv, &parse);
	list_1 = create_list_from_argv(parse.size_array, parse.sort_ind_array);
	list_2 = list_init(0);
	while (1)
	{
		command = command_parser();
		if (command == -1)
			print_error();
		if (command == 0)
			break ;
		do_command(list_1, list_2, command);
	}
	check_is_sort_at_end(list_1, list_2);
	exit(0);
}
