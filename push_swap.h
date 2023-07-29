/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analexan <analexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 15:19:43 by analexan          #+#    #+#             */
/*   Updated: 2023/07/29 18:08:11 by analexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct s_lst
{
	int				data;
	struct s_lst	*next;
}					t_lst;

long	stol(char *str);
int		stoi(char *str);
void	pn(int n);
void	ps(char *str);
void	prt(char *string, ...);
char	**ft_split_m(char const *s, char c, int *wc);
void	addfrt(t_lst **head, int n);
void	addbck(t_lst **head, int n);
void	pl(t_lst *head);
void	sa(t_lst *a);
void	sb(t_lst *b);
void	ss(t_lst *a, t_lst *b);
void	pa(t_lst *a, t_lst *b);
void	pb(t_lst *a, t_lst *b);
void	ra(t_lst *a);
void	rb(t_lst *b);
void	rr(t_lst *a, t_lst *b);
void	rra(t_lst *a);
void	rrb(t_lst *b);
void	rrr(t_lst *a, t_lst *b);

#endif