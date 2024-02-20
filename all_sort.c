/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cunh <mda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:54:49 by mda-cunh          #+#    #+#             */
/*   Updated: 2024/02/20 13:08:10 by mda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	micro_sort(t_case **s_a)
{
	while (!lst_is_sorted(*s_a))
	{
		if ((*s_a)->index < (*s_a)->next->index)
			sa(s_a);
		else if ((*s_a)->index > (*s_a)->prev->index)
			ra_rra(s_a, 0);
		else if ((*s_a)->index > (*s_a)->next->index)
			sa(s_a);
	}
}

void	little_sort(t_case **s_a, t_case **s_b)
{
	int		i;
	int		j;
	t_case	*tmp;

	i = 1;
	j = ps_lstsize(*s_a);
	tmp = *s_a;
	while (i <= j)
	{
		if (lst_is_sorted(*s_a))
			break ;
		if (tmp->index == i)
		{
			road_to_b(s_a, s_b, tmp);
			i++;
			tmp = *s_a;
		}
		tmp = tmp->next;
	}
	while (ps_lstsize(*s_b))
		pa(s_a, s_b);
}

void	pre_sort(t_case **s_a, t_case **s_b, int divider)
{
	int		i;
	int		j;
	int		perc;
	t_case	*tmp;

	i = 1;
	perc = ps_lstsize(*s_a) / divider;
	j = ps_lstsize(*s_a);
	tmp = *s_a;
	while (i <= j + 2)
	{
		if (tmp->index < perc)
		{
			road_to_b(s_a, s_b, tmp);
			i++;
			if (i == perc)
				perc += j / (divider + divider);
			tmp = *s_a;
		}
		tmp = tmp->next;
	}
}

void	end_sort(t_case **s_a, t_case **s_b)
{
	int		j;
	t_case	*tmp;

	j = ps_lstsize(*s_b);
	tmp = *s_b;
	while (j != 1)
	{
		if ((tmp->index - 1) == (*s_a)->prev->index)
		{
			road_to_a(s_a, s_b, tmp);
			ra_rra(s_a, 0);
			j--;
			tmp = *s_b;
		}
		else if ((tmp->index + 1) == (*s_a)->index)
		{
			road_to_a(s_a, s_b, tmp);
			j--;
			tmp = *s_b;
		}
		tmp = tmp->next;
	}
	pa(s_a, s_b);
}
