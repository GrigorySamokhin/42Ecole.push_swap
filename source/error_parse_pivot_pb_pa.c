/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_parse_pivot_pb_pa.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeizo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 15:19:27 by gmeizo            #+#    #+#             */
/*   Updated: 2019/07/18 18:23:01 by gmeizo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		pa(t_lstnum *a, t_lstnum *b)
{
	int bt[b->len];
	int at[a->len];
	int temp;
	int i;

	if (b->len == 0 || a->len == 0)
		return ;
	temp = b->arr[0];
	i = -1;
	b->len -= 1;
	a->len += 1;
	while (++i < a->len)
		at[i] = a->arr[i];
	i = -1;
	a->arr[0] = temp;
	while (++i < a->len)
		a->arr[i + 1] = at[i];
	i = -1;
	while (++i <= b->len)
		bt[i] = b->arr[i];
	i = -1;
	while (++i < b->len)
		b->arr[i] = bt[i + 1];
	!a->checker ? ft_putendl("pa") : 0;
}

int			pb(t_lstnum *a, t_lstnum *b)
{
	int bt[b->len];
	int at[a->len];
	int temp;
	int i;

	if (a->len == 0)
		return (1);
	temp = a->arr[0];
	i = -1;
	b->len += 1;
	a->len -= 1;
	while (++i < b->len)
		bt[i] = b->arr[i];
	i = -1;
	b->arr[0] = temp;
	while (++i < b->len)
		b->arr[i + 1] = bt[i];
	i = -1;
	while (++i <= a->len)
		at[i] = a->arr[i];
	i = -1;
	while (++i < a->len)
		a->arr[i] = at[i + 1];
	!a->checker ? ft_putendl("pb") : 0;
	return (0);
}

int			set_pivot(t_lstnum *a, int count)
{
	int i;
	int pivot;

	if (count == 0)
		return (0);
	i = -1;
	pivot = 0;
	while (++i < count)
		pivot += a->arr[i];
	pivot = pivot / count - 0.5;
	return (pivot);
}

int			parse_numb(char **argv, int args, int *arr)
{
	int i;
	int k;
	int add;

	i = 0;
	k = 1;
	while (--args)
	{
		add = ft_atoi_parse(argv[k++], arr, i, i);
		if (add == -1 || ft_isallchar(argv[k - 1]))
		{
			write(1, "Error\n", 6);
			exit(0);
		}
		i += add;
		i++;
	}
	return (i);
}

int			check_error(int *arr, int size)
{
	int i;
	int k;

	i = -1;
	while (++i < size)
	{
		k = i;
		while (++k < size)
			if (arr[i] == arr[k])
			{
				write(1, "Error\n", 6);
				return (1);
			}
	}
	return (0);
}
