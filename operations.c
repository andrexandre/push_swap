/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analexan <analexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 17:04:41 by analexan          #+#    #+#             */
/*   Updated: 2023/07/29 17:28:38 by analexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_lst *a)
{
	t_lst	*tmp;

	tmp = a->next->next;
	a->next = a;
}

void	sb(t_lst *b)
{
	(void)b;
}

void	ss(t_lst *a, t_lst *b)
{
	sa(a);
	sb(b);
}

void	pa(t_lst *a, t_lst *b)
{
	(void)a;
	(void)b;
}

void	pb(t_lst *a, t_lst *b)
{
	(void)a;
	(void)b;
}
