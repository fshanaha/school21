/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshanaha <fshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 18:06:51 by fshanaha          #+#    #+#             */
/*   Updated: 2018/12/10 20:06:30 by fshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	char	*str;
	long	i;
	long	j;

	j = (long)n;
	i = ft_num(j) + 1;
	if (!(str = (char *)malloc(sizeof(char) * i)))
		return (0x0);
	if (j == 0)
	{
		str[0] = '0';
		str[1] = '\0';
	}
	if (j < 0)
	{
		str[0] = '-';
		j = -j;
	}
	str[i-- - 1] = '\0';
	while (j > 0)
	{
		str[i-- - 1] = ((j % 10) + '0');
		j = j / 10;
	}
	return (str);
}
