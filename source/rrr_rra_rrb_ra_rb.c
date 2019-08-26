/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr_rra_rrb_ra_rb.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeizo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 15:19:27 by gmeizo            #+#    #+#             */
/*   Updated: 2019/07/18 18:23:01 by gmeizo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		rra(t_lstnum *a, int pos)
{
	int i;
	int temp;
	int arr[a->len];

	if (a->len == 0)
		return (0);
	i = -1;
	while (++i < a->len)
		arr[i] = a->arr[i];
	temp = a->arr[a->len - 1];
	i = 0;
	while (i < a->len)
	{
		a->arr[i + 1] = arr[i];
		i++;
	}
	a->arr[0] = temp;
	if (pos == 0)
		ft_putendl("rra");
	return (0);
}

void	rrb(t_lstnum *b, int pos)
{
	int i;
	int temp;
	int arr[b->len];

	if (b->len == 0)
		return ;
	i = -1;
	while (++i < b->len)
		arr[i] = b->arr[i];
	temp = b->arr[b->len - 1];
	i = 0;
	while (i < b->len)
	{
		b->arr[i + 1] = arr[i];
		i++;
	}
	b->arr[0] = temp;
	if (pos == 0)
		ft_putendl("rrb");
}

int		rrr(t_lstnum *a, t_lstnum *b)
{
	rra(a, 1);
	rrb(b, 1);
	!a->checker ? ft_putendl("rrr") : 0;
	return (1);
}

int		ra(t_lstnum *a)
{
	int i;
	int temp;
	int arr[a->len];
	int end;

	if (a->len == 0)
		return (0);
	i = -1;
	end = a->len;
	while (++i < a->len)
		arr[i] = a->arr[i];
	temp = a->arr[0];
	i = 0;
	while (end--)
	{
		a->arr[i] = arr[i + 1];
		i++;
	}
	a->arr[a->len - 1] = temp;
	!a->checker ? ft_putendl("ra") : 0;
	return (0);
}

void	rb(t_lstnum *b)
{
	int i;
	int temp;
	int arr[b->len];
	int end;

	if (b->len == 0)
		return ;
	i = -1;
	end = b->len;
	while (++i < b->len)
		arr[i] = b->arr[i];
	temp = b->arr[0];
	i = 0;
	while (end--)
	{
		b->arr[i] = arr[i + 1];
		i++;
	}
	b->arr[b->len - 1] = temp;
	!b->checker ? ft_putendl("rb") : 0;
}
