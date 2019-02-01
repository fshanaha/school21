/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrella <sbrella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 16:46:48 by sbrella           #+#    #+#             */
/*   Updated: 2018/12/10 15:38:58 by sbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long long int	a;
	int				sign;

	sign = 1;
	a = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v'
			|| *str == '\f' || *str == '\r')
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	if (*str == '+' && sign == 1)
		str++;
	while (*str >= '0' && *str <= '9')
	{
		a = (a * 10) + (long long int)(*str - '0');
		str++;
		if (a > 2147483648)
			return (0);
	}
	return ((int)(a * sign));
}
