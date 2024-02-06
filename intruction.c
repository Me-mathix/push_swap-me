#include "push_swap.h"

void ra_rra(t_case **stack, int i)
{
	if (i == 1)
	{
		printf("rra\n");
		*stack = (*stack)->prev;
	}
	else
	{
		printf("ra\n");
		*stack = (*stack)->next;
	}
	uni_stack_pos_finder(*stack);
}

void rb_rrb(t_case **stack, int i)
{
	if (i == 1)
	{
		printf("rrb\n");
		*stack = (*stack)->prev;
	}
	else
	{
		printf("rb\n");
		*stack = (*stack)->next;
	}
	uni_stack_pos_finder(*stack);
}

void pb(t_case **s_a, t_case **s_b)
{
	t_case *tmp;

	if (!*s_b)
	{
		(*s_a)->next->prev = (*s_a)->prev;
		(*s_a)->prev->next = (*s_a)->next;
		tmp = (*s_a)->next;
		*s_b = *s_a;
		(*s_a)->prev = *s_b;
		(*s_a)->next = *s_b;
		*s_a = tmp;
		duo_stack_pos_finder(*s_a, *s_b);
		printf("pb\n");
		return ;
	}
	tmp = (*s_a)->next;
	(*s_a)->next->prev = (*s_a)->prev;
	(*s_a)->prev->next = (*s_a)->next;
	ft_compactage((*s_b), (*s_a), 2);
	*s_b = *s_a;
	*s_a = tmp;
	duo_stack_pos_finder(*s_a, *s_b);
	if ((*s_a)->next == (*s_b)->next && (*s_a)->prev == (*s_b)->prev)
		*s_a = NULL;
	printf("pb\n");
}

void pa(t_case **s_a, t_case **s_b)
{
	t_case *tmp;

	if (!*s_a)
	{
		(*s_b)->next->prev = (*s_b)->prev;
		(*s_b)->prev->next = (*s_b)->next;
		tmp = (*s_b)->next;
		*s_a = *s_b;
		(*s_b)->prev = *s_a;
		(*s_b)->next = *s_a;
		*s_b = tmp;
		duo_stack_pos_finder(*s_a, *s_b);
		printf("pa\n");
		return ;
	}
	tmp = (*s_b)->next;
	(*s_b)->next->prev = (*s_b)->prev;
	(*s_b)->prev->next = (*s_b)->next;
	ft_compactage((*s_a), (*s_b), 2);
	*s_a = *s_b;
	*s_b = tmp;
	duo_stack_pos_finder(*s_a, *s_b);
	if ((*s_b)->next == (*s_a)->next && (*s_b)->prev == (*s_a)->prev)
		*s_b = NULL;
	printf("pa\n");
}

void swapper_value(t_case **stack)
{
	(*stack)->prev->next = (*stack)->next;
	(*stack)->next->next->prev = *stack;
	(*stack)->next->prev = (*stack)->prev;
	(*stack)->prev = (*stack)->next;
	(*stack)->next = (*stack)->prev->next;
	(*stack)->prev->next = *stack;
	*stack = (*stack)->prev; 
}