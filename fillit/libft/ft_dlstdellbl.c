/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdellbl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrella <sbrella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 17:46:08 by sbrella           #+#    #+#             */
/*   Updated: 2018/12/24 20:13:14 by sbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_dlstdellbl(int label, t_dlist **begin)
{
	int		count;
	t_dlist	*here;
	t_dlist	*prev;

	count = 0;
	here = *begin;
	while (*begin && (*begin)->label == label)
	{
		here = (*begin)->next;
		free((*begin)->data);
		free(*begin);
		*begin = here;
		count++;
	}
	prev = here;
	while (here)
	{
		prev = here;
		here = here->next;
		if (here && here->label == label)
			count++ >= 0 ? ft_dlstcut(prev) : ft_dlstcut(prev);
	}
	return (count);
}
