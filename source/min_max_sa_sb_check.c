/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_max_sa_sb_check.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeizo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 15:19:27 by gmeizo            #+#    #+#             */
/*   Updated: 2019/07/18 18:23:01 by gmeizo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		min(t_lstnum *a)
{
	int i;
	int min;

	i = 0;
	min = a->arr[0];
	while (i < a->len)
	{
		if (a->arr[i] < min)
			min = a->arr[i];
		i++;
	}
	return (min);
}

int		max(t_lstnum *a)
{
	int i;
	int max;

	i = 0;
	max = a->arr[0];
	while (i < a->len)
	{
		if (a->arr[i] > max)
			max = a->arr[i];
		i++;
	}
	return (max);
}

int		check(t_lstnum *a)
{
	int i;

	i = -1;
	if (a->len <= 0)
		return (0);
	while (++i < a->len - 1)
		if (a->arr[i] >= a->arr[i + 1])
			return (0);
	return (1);
}

int		sa(t_lstnum *a)
{
	int i;

	if (a->len < 1)
		return (0);
	i = a->arr[0];
	a->arr[0] = a->arr[1];
	a->arr[1] = i;
	!a->checker ? ft_putendl("sa") : 0;
	return (0);
}

void	sb(t_lstnum *b)
{
	int i;

	if (b->len < 1)
		return ;
	i = b->arr[0];
	b->arr[0] = b->arr[1];
	b->arr[1] = i;
	!b->checker ? ft_putendl("sb") : 0;
}
