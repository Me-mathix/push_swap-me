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