/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshanaha <fshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 16:45:45 by fshanaha          #+#    #+#             */
/*   Updated: 2018/12/06 17:24:29 by fshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	if (s1 && s2)
	{
		if ((ft_strcmp(s1, s2)) == 0)
			return (1);
		else
			return (0);
	}
	return (0);
}
