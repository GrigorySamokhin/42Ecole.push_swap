/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeizo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 15:19:27 by gmeizo            #+#    #+#             */
/*   Updated: 2019/07/18 18:23:01 by gmeizo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		sort_return(t_lstnum *a, t_lstnum *b)
{
	int temp;

	temp = a->len;
	while (a->to_move_up--)
	{
		if (a->arr[0] == min_size(a, temp - a->correct_pos))
			ra(a);
		else
			pb(a, b);
	}
}

int			sort_medium(t_lstnum *a, t_lstnum *b)
{
	int i;

	i = -1;
	a->lap = 0;
	while (++i < a->read_length)
		(a->arr[0] > a->pivot) ? (ra(a)) : pb(a, b);
	a->pivot = set_pivot(a, a->len - a->correct_pos);
	while (!check(a))
	{
		sort_one(a, b);
		sort_two(a, b);
		fill_a_b(a, b);
		fill_half(a, b);
		fill_move(a, b);
		if (a->lap == 1)
		{
			sort_two(a, b);
			sort_return(a, b);
			sort_two(a, b);
		}
		a->lap++;
	}
	return (1);
}

int			sort_m_m(t_lstnum *a)
{
	while (!check(a))
	{
		if (a->arr[0] == max(a))
			ra(a);
		else if (a->arr[0] > a->arr[1])
			sa(a);
		else if (a->arr[a->len - 1] == min(a))
			rra(a, 0);
		else
			ra(a);
	}
	return (1);
}

int			sort_minimum(t_lstnum *a, t_lstnum *b)
{
	if (a->len < 4)
		sort_m_m(a);
	else
	{
		while (!check(a))
		{
			if (a->arr[0] > a->arr[1] && a->arr[0] > a->arr[a->len - 1])
				ra(a);
			else if (a->arr[0] == min(a))
				pb(a, b);
			else if (a->arr[a->len - 1] == min(a))
			{
				rra(a, 0);
				pb(a, b);
			}
			else if (a->arr[0] > a->arr[1])
				sa(a);
			else
				ra(a);
		}
		while (b->len)
			pa(a, b);
	}
	return (1);
}

int			main(int args, char **argv)
{
	t_lstnum *a;
	t_lstnum *b;

	a = (t_lstnum *)malloc(sizeof(t_lstnum));
	b = (t_lstnum *)malloc(sizeof(t_lstnum));
	create_n_fill(a, b, argv, args);
	if (check_error(a->arr, a->len) || args < 1)
		return (0);
	sort_set(a);
	b->checker = 0;
	if (check(a))
		return (1);
	if (a->len < 30)
		sort_minimum(a, b);
	else if (a->len < 200)
		sort_medium(a, b);
	else
		sort_large(a, b);
	set_free(a, b);
	return (1);
}
