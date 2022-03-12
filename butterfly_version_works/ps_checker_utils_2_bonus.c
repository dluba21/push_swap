/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_checker_utils_2_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrdeysuvorov <anrdeysuvorov@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 03:42:36 by anrdeysuvor       #+#    #+#             */
/*   Updated: 2022/03/12 03:43:36 by anrdeysuvor      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	first_arg_parser(char *str)
{
	int	flag;

	flag = 1;
	if (!str[0])
		print_error();
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			flag = 0;
		str++;
	}
	return (flag);
}

void	print_result(char *str)
{
	while (*str)
		write(1, str++, 1);
	exit(0);
}

int	ft_strlen_ps(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strcmp(char *str_1, char *str_2)
{
	int	i;

	i = 0;
	if (!str_1 || !str_2)
		return (0);
	if (ft_strlen_ps(str_1) == ft_strlen_ps(str_2))
	{
		while (str_1[i] == str_2[i])
			i++;
		i--;
		if (i == ft_strlen_ps(str_1))
			return (1);
	}
	return (0);
}

void	check_is_sort_at_end(t_list *list_1, t_list *list_2)
{
	if (is_sort(list_1) && list_2->head == NULL)
		print_result("OK\n");
	print_result("KO\n");
}
