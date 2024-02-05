#include "push_swap.h"

void	find_near_route(h_a)
{
	
}


void push_swap(t_case *s_a, t_case *s_b)
{
	while (s_a->next != s_a)
	{
		find_near_route(s_a);
		s_a = s_a->next;
	}

}
