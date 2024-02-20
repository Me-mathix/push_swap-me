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

void micro_sort(t_case **s_a, t_case **s_b)
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

void little_sort(t_case **s_a, t_case **s_b)
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

void	pre_sort(t_case **s_a, t_case **s_b, int divider)
{
	int i;
	int j;
	int perc;
	t_case *tmp;

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
	int j;
	t_case *tmp;

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

void push_swap(t_case **s_a, t_case **s_b)
{
	if (ps_lstsize(*s_a) >= 80)
	{
		if (ps_lstsize(*s_a) > 100)
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
