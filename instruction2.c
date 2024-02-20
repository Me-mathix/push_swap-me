/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cunh <mda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:36:06 by mda-cunh          #+#    #+#             */
/*   Updated: 2024/02/20 12:36:23 by mda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h" 

void	sa(t_case **stack)
{
	if (ps_lstsize(*stack) > 2)
		swapper_value(stack);
	else
		*stack = (*stack)->next;
	uni_stack_pos_finder(*stack);
	printf("sa\n");
}

void	sb(t_case **stack)
{
	if (ps_lstsize(*stack) > 2)
		swapper_value(stack);
	else
		*stack = (*stack)->next;
	uni_stack_pos_finder(*stack);
	printf("sb\n");
}

void	ss(t_case **s_a, t_case **s_b)
{
	swapper_value(s_a);
	swapper_value(s_b);
	duo_stack_pos_finder(*s_a, *s_b);
	printf("ss\n");
}
