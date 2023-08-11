/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analexan <analexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 15:19:43 by analexan          #+#    #+#             */
/*   Updated: 2023/08/11 10:27:25 by analexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# define same(a, b, c) (a < b && b < c)
typedef struct s_lst
{
	int				data;
	int				above_median;
	int				index;
	int				node_price;
	int				push_price;
	struct s_lst	*next;
}					t_lst;

// ft_split
char	**ft_split_m(char const *s, char c, int *wc);
void	free_all(t_lst *a, t_lst *b);

// operations
void	sa_sb(t_lst **fst_nd, char c);
void	ss(t_lst **a, t_lst **b);
void	pa_pb(t_lst **a, t_lst **b, int mode);
void	ra_rb(t_lst **fst_nd, char c);
void	rr(t_lst **a, t_lst **b);
void	rra_rrb(t_lst **fst_nd, char c);
void	rrr(t_lst **a, t_lst **b);

t_lst	*lstlast(t_lst *head, int mode);
void	addbck(t_lst **head, int n);
int		check_sort(t_lst *lst);

// tool_lib
long	stol(char *str);
int		stoi(char *str);
void	pn(int n);
void	ps(char *str);
void	prt(char *string, ...);

// list_lib
int		is_smallest(int node_data, t_lst *lst);
int		is_biggest(int node_data, t_lst *lst);
void	fill_list(t_lst *lst);
t_lst	*find_target(t_lst *lst, int mode, int node_data);
void	fill_node_price(t_lst *a, t_lst *b, int mode);

// sort_lib
void	lilsort(t_lst **a);

// debug
void	plv(t_lst *a, t_lst *b);
void	plh(t_lst *head);
int		lstlen(t_lst *lst);
void	debugger(t_lst *a, t_lst *b, int *len);

#endif