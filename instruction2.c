#include "push_swap.h" 

void sa(t_case **stack)
{
	swapper_value(&*stack);
	uni_stack_pos_finder(*stack);
	printf("sa\n");
}

void sb(t_case **stack)
{
	swapper_value(&*stack);
	uni_stack_pos_finder(*stack);
	printf("sb\n");
}

void ss(t_case **s_a, t_case **s_b)
{
	swapper_value(s_a);
	swapper_value(s_b);
	duo_stack_pos_finder(*s_a, *s_b);
	printf("ss\n");
}