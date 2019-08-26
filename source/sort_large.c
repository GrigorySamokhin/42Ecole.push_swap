/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeizo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 15:19:27 by gmeizo            #+#    #+#             */
/*   Updated: 2019/07/18 18:23:01 by gmeizo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		sort_max(t_lstnum *a, t_lstnum *b, int median, int end)
{
	while (++median <= end)
	{
		rrb(b, 0);
		if (b->arr[0] == min(b))
		{
			pa(a, b);
			ra(a);
			a->correct_pos++;
		}
	}
	pa(a, b);
	a->to_move_down++;
}

void		sort_big_1(t_lstnum *a, t_lstnum *b)
{
	int i;

	i = -1;
	sort_one(a, b);
	sort_one(a, b);
	sort_one(a, b);
	sort_two(a, b);
	while (a->to_move_up--)
		pb(a, b);
	sort_two(a, b);
	a->add_length = (a->lap == 0) ? a->len / 4 - a->correct_pos
			: a->len - a->len / 4 - a->correct_pos;
	while (++i < a->add_length)
		pb(a, b);
	while (a->arr[0] < max(b))
		pb(a, b);
	sort_one(a, b);
	sort_two(a, b);
	while (a->to_move_up--)
		pb(a, b);
	sort_two(a, b);
}

void		sort_big_2(t_lstnum *a, t_lstnum *b)
{
	int i;

	i = -1;
	a->add_length = (a->lap == 0) ? a->len / 4 : a->len - a->correct_pos;
	while (++i < a->add_length)
		pb(a, b);
	while (a->arr[0] < max(b) && a->lap != 1)
		pb(a, b);
	sort_one(a, b);
	sort_one(a, b);
	sort_two(a, b);
	while (a->to_move_up--)
		pb(a, b);
	sort_two(a, b);
}

void		sort_big_3(t_lstnum *a, t_lstnum *b)
{
	int i;

	i = -1;
	a->add_length = (a->lap == 0) ? a->len / 2 - a->correct_pos
			: a->len - a->correct_pos;
	a->flag == 1 ? a->add_length += 1 : 0;
	while (++i < a->add_length)
		pb(a, b);
	while (a->arr[0] < max(b) && a->lap != 1)
		pb(a, b);
	sort_one(a, b);
	sort_two(a, b);
	while (a->to_move_up--)
		pb(a, b);
	sort_one(a, b);
	sort_two(a, b);
	while (a->to_move_up--)
		pb(a, b);
	sort_two(a, b);
}

int			sort_large(t_lstnum *a, t_lstnum *b)
{
	int i;

	i = -1;
	a->lap = 0;
	(a->len % 2 == 1) ? a->flag = 1 : 0;
	a->pivot = set_pivot(a, a->len) + 1;
	while (++i < a->read_length)
		(a->arr[0] > a->pivot) ? (ra(a)) : pb(a, b);
	while (!check(a))
	{
		if (a->lap == 1)
		{
			a->flag = a->len / 2;
			i = -1;
			while (++i < a->flag)
				pb(a, b);
		}
		sort_big_1(a, b);
		sort_big_2(a, b);
		sort_big_3(a, b);
		a->lap++;
	}
	return (1);
}
