/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_lib.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analexan <analexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 11:15:51 by analexan          #+#    #+#             */
/*   Updated: 2023/08/16 15:34:21 by analexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_smallest(int node_data, t_lst *lst)
{
	while (lst)
	{
		if (lst->data < node_data)
			return (0);
		lst = lst->next;
	}
	return (1);
}

int	is_biggest(int node_data, t_lst *lst)
{
	while (lst)
	{
		if (lst->data > node_data)
			return (0);
		lst = lst->next;
	}
	return (1);
}

int	lstlen(t_lst *lst)
{
	int	i;

	i = 0;
	if (!lst)
		return (i);
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

int	lilsort(t_lst **lst)
{
	if ((*lst)->data > (*lst)->next->data 
		&& (*lst)->data > (*lst)->next->next->data)
		ra_rb(lst, 'a');
	else if ((*lst)->data < (*lst)->next->data 
		&& (*lst)->next->data > (*lst)->next->next->data)
		rra_rrb(lst, 'a');
	if ((*lst)->data > (*lst)->next->data)
		sa_sb(lst, 'a');
	return (1);
}

// fill the list with the correct index, above_median and push_price
void	fill_list(t_lst *lst)
{
	int	i;
	int	len;

	if (!lst)
		return ;
	len = lstlen(lst);
	i = -1;
	while (++i < len)
	{
		lst->index = i;
		if (i <= len / 2)
			lst->above_median = 1;
		else
			lst->above_median = 0;
		if (lst->above_median)
			lst->push_price = i;
		else
			lst->push_price = len - i;
		if (lst->next)
			lst = lst->next;
	}
}

/*
int	main(void)
{
	t_lst	*lst;
	t_lst	*head;

	head = NULL;
	plh(head);
	while (head)
	{
		lst = head;
		head = head->next;
		free(lst);
	}
	return (0);
}
*/
