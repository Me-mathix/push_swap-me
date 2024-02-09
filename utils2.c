#include "push_swap.h"

void uni_stack_pos_finder(t_case *stack)
{
	t_case *head;
	int i;

	i = 1;
	head = stack ;
	head->real_pos = i++;
	head = head->next;
	while (head != stack)
	{
		head->real_pos = i++;
		head = head->next;
	}
}

void duo_stack_pos_finder(t_case *s_a, t_case *s_b)
{
	t_case *head;
	int i;

	i = 1;
	head = s_a;
	head->real_pos = i++;
	head = head->next;
	while (head != s_a)
	{
		head->real_pos = i++;
		head = head->next;
	}
	i = 1;
	head = s_b;
	head->real_pos = i++;
	head = head->next;
	while (head != s_b)
	{
		head->real_pos = i++;
		head = head->next;
	}
}

int	ps_lstsize(t_case *lst)
{

	int	count;
	t_case *head;

	if (!lst)
		return (0);
	count = 0;
	head = lst;
	while (head->next != lst)
	{
		count++;
		head = head->next;
	}
	count++;
	return (count);
}
