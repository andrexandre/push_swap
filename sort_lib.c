/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_lib.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analexan <analexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 15:36:25 by analexan          #+#    #+#             */
/*   Updated: 2023/08/16 16:29:15 by analexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// mode = 0: returns smallest; mode = 1: returns biggest;
t_lst	*find_smallest_or_biggest(t_lst *lst, int mode)
{
	t_lst	*temp;

	temp = lst;
	if (!mode || mode == 1)
	{
		while (lst)
		{
			if (!mode && lst->data < temp->data)
				temp = lst;
			else if (mode == 1 && lst->data > temp->data)
				temp = lst;
			lst = lst->next;
		}
	}
	return (temp);
}

// returns 2nd node between node_data from: mode = 0: smallest; = 1: biggest;
t_lst	*find_node_between(t_lst *lst, int mode, int node_data)
{
	if (!mode || mode == 1)
	{
		if (!mode)
		{
			if (lst->data > node_data && node_data > lstlast(lst, 0)->data)
				return (lst);
			while (lst->next && !(lst->data < node_data 
					&& node_data < lst->next->data))
				lst = lst->next;
		}
		else if (mode == 1)
		{
			if (lst->data < node_data && node_data < lstlast(lst, 0)->data)
				return (lst);
			while (lst->next && !(lst->data > node_data 
					&& node_data > lst->next->data))
				lst = lst->next;
		}
	}
	return (lst->next);
}

// fill the node_price of a based on target b
t_lst	*find_and_fill_cheapest(t_lst *a, t_lst *b)
{
	t_lst	*target;
	t_lst	*cheapest;

	if (!a || !b)
		return (a);
	cheapest = a;
	while (a)
	{
		if (is_smallest(a->data, b) || is_biggest(a->data, b))
			target = find_smallest_or_biggest(b, 1);
		else
			target = find_node_between(b, 1, a->data);
		a->target = target;
		a->node_price = a->push_price + target->push_price;
		if (a->node_price < cheapest->node_price)
			cheapest = a;
		a = a->next;
	}
	return (cheapest);
}

// mode = 0: sort to a; mode = 1: sort to b
void	sort_to_list(t_lst **a, t_lst **b, int mode)
{
	t_lst	*target;

	if (is_smallest((*b)->data, *a) || is_biggest((*b)->data, *a))
		target = find_smallest_or_biggest(*a, mode);
	else
		target = find_node_between(*a, mode, (*b)->data);
	while (*a != target)
		if (target->above_median)
			ra_rb(a, 'a' + mode);
	else
		rra_rrb(a, 'a' + mode);
}

// mode = 0: sort to b; mode = 1: sort to a
int	optimize_to_list(t_lst **a, t_lst **b, int mode)
{
	t_lst	*target;

	target = find_and_fill_cheapest(*a, *b);
	while (*a != target)
	{
		if (target->above_median == target->target->above_median
			&& target->push_price && target->target->push_price)
		{
			if (target->above_median)
				rr(a, b);
			else
				rrr(a, b);
		}
		else
		{
			if (target->above_median)
				ra_rb(a, 'a' + mode);
			else
				rra_rrb(a, 'a' + mode);
		}
	}
	sort_to_list(b, a, !mode);
	if (!mode && lstlen(*a) == 3 && lilsort(a))
		return (0);
	return (1);
}
