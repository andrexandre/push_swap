/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analexan <analexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 17:04:41 by analexan          #+#    #+#             */
/*   Updated: 2023/07/31 19:21:01 by analexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra_rrb(t_lst **fst_nd)
{
	t_lst	*last;

	if (!*fst_nd)
		return ;
	last = lstlast(*fst_nd, 1);
	last->next->next = *fst_nd;
	*fst_nd = last->next;
	last->next = NULL;
}

void	rrr(t_lst **a, t_lst **b)
{
	rra_rrb(a);
	rra_rrb(b);
}
