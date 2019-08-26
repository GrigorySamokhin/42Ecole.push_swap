/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeizo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 19:16:19 by gmeizo            #+#    #+#             */
/*   Updated: 2019/04/11 19:21:03 by gmeizo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_count_word(char *str, char c)
{
	int word;

	word = 0;
	if (!str)
		return (0);
	while (*str)
	{
		if (((*(str + 1) == c) || (*(str + 1) == '\0')) && *str != c)
			word += 1;
		str++;
	}
	return (word);
}
