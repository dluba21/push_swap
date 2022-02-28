/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluba <dluba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 14:16:23 by dluba             #+#    #+#             */
/*   Updated: 2021/10/17 14:38:39 by dluba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int atoi_checker(char *str, int sign, t_errors *error)
{
	long	mod;
	
	mod = 0;
	if (*str < '0' || *str > '9')
	{
		error->atoi_flag = 1;
		return (1);
	}
//	printf("[%c]", *str);
	while (*str && *str >= '0' && *str <= '9')
	{
		if (mod * sign > 2147483647 || mod * sign < -2147483648)
		{
			error->atoi_flag = 1;
			return (1);
		}
		mod = mod * 10 + *str++ - '0';
	}
	return (0);
}

int	ft_atoi(char *str, t_errors *error)
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
	if (atoi_checker(str, sign, error) == 1)
		return (0);
	while (*str && *str >= '0' && *str <= '9')
		mod = mod * 10 + *str++ - '0';
	return (mod * sign);
}

//int main()
//{
//	t_errors error;
//	printf("%d", ft_atoi("   a", &error));
//}
