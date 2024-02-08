#include "push_swap.h"

int	lst_is_sorted(t_case *stack)
{
	t_case *head;
	
	head = stack;
	while (head->next != stack)
	{
		if (head->index > head->next->index)
			return (0);
		head = head->next;
	}
	return (1);
}

void road_to_b(t_case **s_a, t_case **s_b, t_case *node)
{
	while (node->real_pos != 1)
	{
		if ((node->real_pos == 2) && (node->nb < node->prev->nb))
			sa(s_a);
		else if ((ps_lstsize(*s_a) - node->real_pos + 1) < node->real_pos)
			ra_rra(s_a, 1);
		else
			ra_rra(s_a, 0);
	}
	if (!lst_is_sorted(*s_a))
		pb(s_a, s_b);
}

void road_to_a(t_case **s_a, t_case **s_b, t_case *node)
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

void	pre_sort(t_case **s_a, t_case **s_b)
{
	int i;
	int j;
	int perc;
	t_case *tmp;

	i = 1;
	perc = ps_lstsize(*s_a) / 8;
	j = ps_lstsize(*s_a);
	tmp = *s_a;
	while (i < j)
	{
		if (tmp->index < ((perc * j) / j))
		{
			road_to_b(s_a, s_b, tmp);
			i++;
			if (i == perc)
				perc += j / 8;
			tmp = *s_a;
		}
		tmp = tmp->next;
	}
}

void	end_sort(t_case **s_a, t_case **s_b)
{
	t_case *tmp;
	int j;
	int i;

	tmp = *s_b;
	i = 1;
	j = ps_lstsize(*s_b);
	while (i < j)
	{
		while ((*s_a)->index > (*s_a)->prev->index)
			ra_rra(s_a, 1);
		if (tmp->index == (*s_a)->index - 1 || tmp->index == (*s_a)->prev->index + 1)
		{
			road_to_a(s_a, s_b, tmp);
			i++;
			tmp = *s_b;	
		}
		tmp = tmp->next;
	}
}

void push_swap(t_case **s_a, t_case **s_b)
{
	pre_sort(s_a, s_b);
	end_sort(s_a, s_b);
}
