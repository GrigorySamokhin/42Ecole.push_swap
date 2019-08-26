/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_one_two.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeizo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 15:19:27 by gmeizo            #+#    #+#             */
/*   Updated: 2019/07/18 18:23:01 by gmeizo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		sort_one(t_lstnum *a, t_lstnum *b)
{
	b->pivot = set_pivot(b, b->len) + 1;
	a->to_move_up = 0;
	while (b->len && max(b) > b->pivot)
	{
		if (b->arr[0] > b->pivot)
		{
			pa(a, b);
			a->to_move_up++;
		}
		else if (b->arr[0] == min(b))
		{
			pa(a, b);
			ra(a);
			a->correct_pos++;
		}
		else
			rb(b);
	}
}

int			min_size(t_lstnum *a, int size)
{
	int i;
	int min;

	i = 0;
	min = a->arr[0];
	while (i < size)
	{
		if (a->arr[i] < min)
			min = a->arr[i];
		i++;
	}
	return (min);
}

void		sort_two(t_lstnum *a, t_lstnum *b)
{
	a->to_move_down = 0;
	while (b->len)
	{
		if (b->arr[0] == min(b))
		{
			pa(a, b);
			ra(a);
			a->correct_pos++;
		}
		else if (b->arr[0] == max(b))
		{
			pa(a, b);
			a->to_move_down++;
		}
		else if (sort_big(a, b))
			a->lap = a->lap;
		else
			rb(b);
	}
	while (a->to_move_down--)
	{
		ra(a);
		a->correct_pos++;
	}
}

void		fill_a_b_set(t_lstnum *a, t_lstnum *b)
{
	int i;
	int step;

	i = -1;
	step = a->to_move_up;
	a->pivot = set_pivot(a, a->to_move_up) + 1;
	a->to_move_up = 0;
	a->to_back = 0;
	while (++i < step)
		if (a->arr[0] > a->pivot)
		{
			ra(a);
			a->to_back++;
		}
		else
			pb(a, b);
}

int			fill_a_b(t_lstnum *a, t_lstnum *b)
{
	fill_a_b_set(a, b);
	while (a->to_back-- > 0)
	{
		if (b->arr[0] != max(b))
			rrr(a, b);
		else
			rra(a, 0);
		a->to_move_up++;
	}
	sort_two(a, b);
	while (a->to_move_up--)
		pb(a, b);
	sort_two(a, b);
	return (1);
}
