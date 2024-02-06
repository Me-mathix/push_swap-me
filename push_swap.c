#include "push_swap.h"

int	lst_is_sorted(t_case *stack)
{
	t_case *head;
	
	head = stack;
	while (head->next != stack)
	{
		if (head->nb > head->next->nb)
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

void push_swap(t_case **s_a, t_case **s_b)
{
	int i;
	int j;
	t_case *tmp;

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
