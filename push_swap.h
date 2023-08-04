/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analexan <analexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 15:19:43 by analexan          #+#    #+#             */
/*   Updated: 2023/08/04 13:04:11 by analexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# ifndef D
#  define D 0
# endif

typedef struct s_lst
{
	int				data;
	int				above_median;
	struct s_lst	*next;
}					t_lst;

long	stol(char *str);
int		stoi(char *str);
void	pn(int n);
void	ps(char *str);
void	prt(char *string, ...);
char	**ft_split_m(char const *s, char c, int *wc);
t_lst	*lstlast(t_lst *head, int mode);
void	addbck(t_lst **head, int n);
void	plh(t_lst *head);
void	sa_sb(t_lst **fst_nd, char c);
void	ss(t_lst **a, t_lst **b);
void	pa_pb(t_lst **a, t_lst **b, int mode);
void	ra_rb(t_lst **fst_nd, char c);
void	rr(t_lst **a, t_lst **b);
void	rra_rrb(t_lst **fst_nd, char c);
void	rrr(t_lst **a, t_lst **b);
void	freeall(t_lst *a, t_lst *b);
int		check_sort(t_lst *lst);
void	lilsort(t_lst **a);
void	plv(t_lst *a, t_lst *b);
int		smallest(int n, t_lst *lst);
int		biggest(int n, t_lst *lst);
void	fill_am(t_lst *lst, int len);
void	*stoloi(char *str, int mode);


#endif