/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_fill.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeizo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 15:19:27 by gmeizo            #+#    #+#             */
/*   Updated: 2019/07/18 18:23:01 by gmeizo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			sort_big(t_lstnum *a, t_lstnum *b)
{
	int end;
	int median;

	end = b->len;
	median = b->len / 2 + 1;
	while (++median < end)
	{
		if (b->arr[median] == max(b))
		{
			sort_max(a, b, median, end);
			break ;
		}
	}
	return (0);
}

void		fill_half(t_lstnum *a, t_lstnum *b)
{
	int i;
	int range;

	i = 0;
	range = a->len - a->correct_pos;
	a->pivot = set_pivot(a, range) + 7;
	a->to_back = 0;
	while (i++ < range)
		if (a->arr[0] >= a->pivot)
		{
			ra(a);
			a->to_back++;
		}
		else
			pb(a, b);
}

void		fill_move(t_lstnum *a, t_lstnum *b)
{
	a->to_move_up = 0;
	while (a->to_back--)
	{
		if (b->arr[0] != max(b))
			rrr(a, b);
		else
			rra(a, 0);
		a->to_move_up++;
	}
}

int			sort_set(t_lstnum *a)
{
	a->pivot = set_pivot(a, a->len);
	a->add_length = 0;
	a->correct_pos = 0;
	a->to_move_down = 0;
	a->to_move_up = 0;
	a->checker = 0;
	a->to_back = 0;
	a->flag = 0;
	a->lap = 0;
	a->read_length = a->len;
	return (1);
}

int			create_n_fill(t_lstnum *a, t_lstnum *b, char **argv, int args)
{
	int		*arr_buff;
	int		i;

	i = -1;
	arr_buff = (int *)malloc(sizeof(int) * (1000000));
	a->len = parse_numb(argv, args, arr_buff);
	a->arr = (int *)malloc(sizeof(int) * (a->len + 1));
	b->arr = (int *)malloc(sizeof(int) * (a->len / 2 + 1));
	b->len = 0;
	while (++i < a->len)
		a->arr[i] = arr_buff[i];
	free(arr_buff);
	return (1);
}
