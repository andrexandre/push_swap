/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_lib.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analexan <analexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 11:15:51 by analexan          #+#    #+#             */
/*   Updated: 2023/08/09 15:38:43 by analexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// mode = 0: last one, mode = 1: one before last
t_lst	*lstlast(t_lst *head, int mode)
{
	if (!head)
		return (NULL);
	if (!mode)
		while (head->next)
			head = head->next;
	else
		while (head->next->next)
			head = head->next;
	return (head);
}

void	addbck(t_lst **head, int n)
{
	t_lst	*node;
	t_lst	*temp;

	node = malloc(sizeof(t_lst));
	if (!node)
		return ;
	node->data = n;
	node->next = NULL;
	temp = lstlast(*head, 0);
	if (!*head)
		*head = node;
	else
		temp->next = node;
}

int	check_sort(t_lst *lst)
{
	int	i;

	i = 1;
	if (!lst)
		return (i);
	while (lst->next)
	{
		if (lst->data > lst->next->data)
		{
			i = 0;
			break ;
		}
		lst = lst->next;
	}
	return (i);
}

void	lilsort(t_lst **lst)
{
	if ((*lst)->data > (*lst)->next->data 
		&& (*lst)->data > (*lst)->next->next->data)
		ra_rb(lst, 'a');
	else if ((*lst)->data < (*lst)->next->data 
		&& (*lst)->next->data > (*lst)->next->next->data)
		rra_rrb(lst, 'a');
	if ((*lst)->data > (*lst)->next->data)
		sa_sb(lst, 'a');
}

// mode = 0: smallest; = 1: biggest; = 2: between node_data;
t_lst	*find_target(t_lst *lst, int mode, int node_data)
{
	t_lst	*target;

	target = lst;
	if (!mode)
	{
		while (lst->next)
		{
			if (lst->data < target->data)
				target = lst;
			lst = lst->next;
		}
		if (lst->data < target->data)
			target = lst;
	}
	else if (mode == 1)
	{
		while (lst->next)
		{
			if (lst->data > target->data)
				target = lst;
			lst = lst->next;
		}
		if (lst->data > target->data)
			target = lst;
	}
	else
	{
		if (lstlast(lst, 0)->data < node_data && node_data < lst->data)
			return (lstlast(lst, 0));
		while (lst->next && !(lst->data < node_data 
				&& node_data < lst->next->data))
			lst = lst->next;
		return (lst);
	}
	return (target);
}
/*
int	main(void)
{
	t_lst	*lst;
	t_lst	*head;

	head = NULL;
	addfrt(&head, 123);
	addfrt(&head, 1);
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
