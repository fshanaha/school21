/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_mod.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrella <sbrella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 19:36:50 by sbrella           #+#    #+#             */
/*   Updated: 2019/01/15 19:37:27 by sbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_putstr_mod(char const *s)
{
	int n;

	n = 0;
	if (!s)
		return (0);
	while (s[n])
	{
		ft_putchar(s[n]);
		n++;
	}
	return (0);
}
