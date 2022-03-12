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

void	print_ok(void)
{
	write(1, "OK\n", 3);
	exit(0);
}

void	print_ko(void)
{
	write(1, "KO\n", 3);
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
	{
		printf("ft_strcmp: no string\n");
		return (0);
	}
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
		print_ok();
	print_ko();
}