/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_lib.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analexan <analexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 15:36:25 by analexan          #+#    #+#             */
/*   Updated: 2023/08/10 15:36:33 by analexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
