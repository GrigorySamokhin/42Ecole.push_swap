/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeizo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 15:19:27 by gmeizo            #+#    #+#             */
/*   Updated: 2019/07/18 18:23:01 by gmeizo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_checker_disp(t_lstnum *a, t_lstnum *b, char *line)
{
	if (ft_strcmp(line, "sa") == 0)
		sa(a);
	else if (ft_strcmp(line, "ra") == 0)
		ra(a);
	else if (ft_strcmp(line, "pa") == 0)
		pa(a, b);
	else if (ft_strcmp(line, "pb") == 0)
		pb(a, b);
	else if (ft_strcmp(line, "rb") == 0)
		rb(b);
	else if (ft_strcmp(line, "rra") == 0)
		rra(a, 1);
	else if (ft_strcmp(line, "rrb") == 0)
		rrb(b, 1);
	else if (ft_strcmp(line, "rrr") == 0)
		rrr(a, b);
	else
	{
		ft_strdel(&line);
		write(1, "Error", 5);
		exit(0);
	}
	ft_strdel(&line);
	return (1);
}

int			ft_checker(t_lstnum *a, t_lstnum *b)
{
	char	*line;

	if (check_error(a->arr, a->len))
		return (0);
	line = NULL;
	a->checker = 1;
	b->checker = 1;
	while (1)
	{
		if (get_next_line(0, &line) == 0)
			break ;
		if (ft_checker_disp(a, b, line) == -1)
			break ;
	}
	if (check(a) && !b->len)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (1);
}

int			main(int args, char **argv)
{
	t_lstnum *a;
	t_lstnum *b;

	a = (t_lstnum *)malloc(sizeof(t_lstnum));
	b = (t_lstnum *)malloc(sizeof(t_lstnum));
	create_n_fill(a, b, argv, args);
	if (check_error(a->arr, a->len) || args <= 1)
		return (0);
	sort_set(a);
	ft_checker(a, b);
	set_free(a, b);
	return (1);
}
