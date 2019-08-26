/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeizo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 12:19:40 by gmeizo            #+#    #+#             */
/*   Updated: 2019/04/10 18:07:59 by gmeizo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int			ft_count_chr(const char *temp, char c)
{
	int i;
	int k;

	k = -1;
	i = 0;
	while (temp[++k])
	{
		if (temp[k] == c)
			i++;
	}
	return (i);
}