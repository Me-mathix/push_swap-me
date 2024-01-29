#include "push_swap.h"

void	find_near_route(h_a)
{
	
}


void push_swap(t_case *s_a, t_case *s_b)
{
	t_case *h_a;
	t_case *h_b;

	h_a = s_a;
	h_b = s_b;
	while (h_a->next != s_a)
	{
		find_near_route(h_a);
		h_a = h_a->next;
	}

}
