/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshanaha <fshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 19:22:47 by fshanaha          #+#    #+#             */
/*   Updated: 2018/12/10 17:50:52 by fshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int			flag;
	long int	result;

	flag = 1;
	result = 0;
	while (*str == '\n' || *str == '\t' || *str == '\v' || *str == '\f'
											|| *str == '\r' || *str == ' ')
		str++;
	if (*str == '-')
		flag = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result = (result * 10) + (*str - '0');
		str++;
		if ((result * flag) < 0 && flag > 0)
			return (-1);
		else if ((result * flag) > 0 && flag < 0)
			return (0);
	}
	return (result * flag);
}
