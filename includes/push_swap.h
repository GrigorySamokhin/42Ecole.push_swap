/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeizo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 15:19:27 by gmeizo            #+#    #+#             */
/*   Updated: 2019/07/18 18:23:01 by gmeizo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct		s_numlist
{
	int				*arr;
	int				len;
	int				pivot;
	int				correct_pos;
	int				checker;
	int				read_length;
	int				to_move_down;
	int				to_move_up;
	int				to_back;
	int				add_length;
	int				flag;
	int				lap;
}					t_lstnum;

void				set_free(t_lstnum *a, t_lstnum *b);
void				sort_return(t_lstnum *a, t_lstnum *b);
int					ft_checker(t_lstnum *a, t_lstnum *b);
int					min(t_lstnum *a);
int					max(t_lstnum *a);
int					check(t_lstnum *a);
int					sa(t_lstnum *a);
int					rra(t_lstnum *a, int pos);
void				rrb(t_lstnum *b, int pos);
int					rrr(t_lstnum *a, t_lstnum *b);
void				rb(t_lstnum *b);
int					ra(t_lstnum *a);
void				pa(t_lstnum *a, t_lstnum *b);
int					pb(t_lstnum *a, t_lstnum *b);
int					set_pivot(t_lstnum *a, int count);
int					check_error(int *arr, int size);
int					parse_numb(char **argv, int args, int *arr);
int					sort_big(t_lstnum *a, t_lstnum *b);
void				fill_half(t_lstnum *a, t_lstnum *b);
void				fill_move(t_lstnum *a, t_lstnum *b);
int					sort_set(t_lstnum *a);
int					create_n_fill(t_lstnum *a, t_lstnum *b,
						char **argv, int args);
void				sort_max(t_lstnum *a, t_lstnum *b, int median, int end);
void				sort_big_1(t_lstnum *a, t_lstnum *b);
void				sort_big_2(t_lstnum *a, t_lstnum *b);
void				sort_big_3(t_lstnum *a, t_lstnum *b);
int					sort_large(t_lstnum *a, t_lstnum *b);
void				sort_one(t_lstnum *a, t_lstnum *b);
int					min_size(t_lstnum *a, int size);
void				sort_two(t_lstnum *a, t_lstnum *b);
int					fill_a_b(t_lstnum *a, t_lstnum *b);

#endif
