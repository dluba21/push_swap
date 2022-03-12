/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrdeysuvorov <anrdeysuvorov@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 14:16:23 by dluba             #+#    #+#             */
/*   Updated: 2022/03/12 03:43:37 by anrdeysuvor      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	atoi_checker(char *str, int sign)
{
	long	mod;

	mod = 0;
	if (*str < '0' || *str > '9')
		print_error();
	while (*str && *str >= '0' && *str <= '9')
	{
		if (mod * sign > 2147483647 || mod * sign < -2147483648)
			print_error();
		mod = mod * 10 + *str++ - '0';
	}
}

int	ft_atoi_ps(char *str)
{
	int	mod;
	int	sign;

	sign = 1;
	mod = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	atoi_checker(str, sign);
	while (*str && *str >= '0' && *str <= '9')
		mod = mod * 10 + *str++ - '0';
	return (mod * sign);
}
