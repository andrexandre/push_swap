/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analexan <analexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 15:19:43 by analexan          #+#    #+#             */
/*   Updated: 2023/07/24 15:34:52 by analexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_lst
{
	int				data;
	struct s_lst	*next;
}					t_lst;

long	stol(char *str);
int		stoi(char *str);
void	pn(int n);
void	ps(char *str);
void	push_swap(int *arr);
char	**ft_split_m(char const *s, char c, int *wc);

#endif