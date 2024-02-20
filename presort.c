/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cunh <mda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:39:33 by mda-cunh          #+#    #+#             */
/*   Updated: 2024/02/20 12:42:06 by mda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(int *a, int *b)
{
	int	c;

	c = *b;
	*b = *a;
	*a = c;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	k;

	k = 0;
	while (k < size - 1)
	{
		if (tab[k] > tab[k + 1])
		{
			ft_swap(&tab[k], &tab[k + 1]);
			k = 0;
		}
		else
		{
			k++;
		}
	}
}
