/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_lib.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analexan <analexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 11:15:51 by analexan          #+#    #+#             */
/*   Updated: 2023/07/29 19:01:36 by analexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_lst *a, t_lst *b)
{
	rra(a);
	rrb(b);
}

t_lst	*lstlast(t_lst *head)
{
	if (!head)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

void	addfrt(t_lst **head, int n)
{
	t_lst	*node;

	node = malloc(sizeof(t_lst));
	if (!node)
		return ;
	node->data = n;
	if (*head)
		node->next = *head;
	else
		node->next = NULL;
	*head = node;
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
	temp = lstlast(*head);
	if (!*head)
		*head = node;
	else
		temp->next = node;
}

void	pl(t_lst *head)
{
	while (head->next)
	{
		prt("%i ", head->data);
		head = head->next;
	}
	prt("%i\n", head->data);
}
/*
int	main(void)
{
	t_lst	*lst;
	t_lst	*head;

	head = NULL;
	addfrt(&head, 123);
	addfrt(&head, 1);
	pl(head);
	while (head)
	{
		lst = head;
		head = head->next;
		free(lst);
	}
	return (0);
}
*/
