/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cunh <mda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:54:52 by mda-cunh          #+#    #+#             */
/*   Updated: 2024/02/20 12:59:45 by mda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lst_is_sorted(t_case *stack)
{
	t_case	*head;

	head = stack;
	while (head->next != stack)
	{
		if (head->index > head->next->index)
			return (0);
		head = head->next;
	}
	return (1);
}

void	road_to_b(t_case **s_a, t_case **s_b, t_case *node)
{
	while (node->real_pos != 1)
	{
		if (ps_lstsize(*s_b) > 2)
			if (((node->real_pos == 2) && (node->nb < node->prev->nb))
				&& ((*s_b)->index < (*s_b)->next->index))
				ss(s_a, s_b);
		if (node->real_pos == 1)
			break ;
		if (ps_lstsize(*s_a) == 2)
			sa(s_a);
		else if ((node->real_pos == 2) && (node->nb < node->prev->nb))
			sa(s_a);
		else if ((ps_lstsize(*s_a) - node->real_pos + 1) < node->real_pos)
			ra_rra(s_a, 1);
		else
			ra_rra(s_a, 0);
	}
	if (!lst_is_sorted(*s_a))
		pb(s_a, s_b);
}

void	road_to_a(t_case **s_a, t_case **s_b, t_case *node)
{
	while (node->real_pos != 1)
	{
		if ((node->real_pos == 2) && (node->nb < node->prev->nb))
			sb(s_b);
		else if ((ps_lstsize(*s_b) - node->real_pos + 1) < node->real_pos)
			rb_rrb(s_b, 1);
		else
			rb_rrb(s_b, 0);
	}
	pa(s_a, s_b);
}

void	push_swap(t_case **s_a, t_case **s_b)
{
	if (ps_lstsize(*s_a) >= 80)
	{
		if (ps_lstsize(*s_a) > 300)
			pre_sort(s_a, s_b, 8);
		else if (ps_lstsize(*s_a) <= 100)
			pre_sort(s_a, s_b, 4);
		end_sort(s_a, s_b);
	}
	else if (ps_lstsize(*s_a) >= 4)
		little_sort(s_a, s_b);
	else
		micro_sort(s_a, s_b);
}
