/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analexan <analexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 17:04:41 by analexan          #+#    #+#             */
/*   Updated: 2023/08/09 18:32:36 by analexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra_rrb(t_lst **fst_nd, char c)
{
	t_lst	*last;

	if (c)
		prt("rr%c\n", c);
	if (!*fst_nd || !(*fst_nd)->next)
		return ;
	last = lstlast(*fst_nd, 1);
	last->next->next = *fst_nd;
	*fst_nd = last->next;
	last->next = NULL;
	fill_am(*fst_nd);
}

void	rrr(t_lst **a, t_lst **b)
{
	rra_rrb(a, '\0');
	rra_rrb(b, '\0');
	ps("rrr\n");
}

int	is_smallest(int node_data, t_lst *lst)
{
	int	i;

	i = 1;
	while (lst)
	{
		if (lst->data < node_data)
		{
			i = 0;
			break ;
		}
		else
			lst = lst->next;
	}
	return (i);
}

int	is_biggest(int node_data, t_lst *lst)
{
	int	i;

	i = 1;
	while (lst)
	{
		if (lst->data > node_data)
		{
			i = 0;
			break ;
		}
		else
			lst = lst->next;
	}
	return (i);
}

void	fill_am(t_lst *lst)
{
	int		i;
	int		len;
	t_lst	*tmp;

	tmp = lst;
	len = 0;
	i = -1;
	if (!lst)
		return ;
	while (tmp)
	{
		len++;
		if (!tmp->next)
			break ;
		tmp = tmp->next;
	}
	while (++i < len)
	{
		if (i <= len / 2)
			lst->above_median = 1;
		else
			lst->above_median = 0;
		if (lst->next)
			lst = lst->next;
	}
}
