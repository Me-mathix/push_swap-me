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
}

void rb_rrb(t_case *stack, int i)
{
	if (i == 1)
	{
		printf("rrb\n");
		stack = stack->prev;
	}
	else
	{
		printf("rb\n");
		stack = stack->next;
		printf("%d", stack->nb);
	}
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
		(*s_a)->real_pos = 1;
		return ;
	}
	ft_compactage((*s_b), (*s_a), 2);
	(*s_a)->next->prev = (*s_a)->prev;
	(*s_a)->prev->next = (*s_a)->next;
}

void swapper_value(t_case *first, t_case *second)
{
	t_case *tmp;

	second->next = first->next;
	first->prev = second ->prev;
	tmp = first;
	first = second;
	second = tmp;
	first->next = second;
	second->prev = first;
}