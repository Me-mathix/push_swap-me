#include "push_swap.h"

void	lst_indexing(t_case *stack_a, int index, int nb)
{
	t_case *head;

	head = stack_a;
	while (head->next != stack_a)
	{
		if (head->nb == nb)
		{
			head->index = index;
			return ;
		}
		head = head->next;		
	}
	if (head->nb == nb)
		head->index = index;	
}

void	looking_for_index(t_case *stack_a, int ac)
{
	int *tab;
	int i;
	t_case *head;

	i = 0;
	head = stack_a;
	tab = malloc((sizeof (int)) * ac);
	while (head->next != stack_a)
	{
		tab[i++] = head->nb;
		head = head->next;
	}
	tab[i] = head->nb;
	mergeSort(tab, 0, i);
	i = -1;
	while (++i < ac)
		lst_indexing(stack_a, i + 1, tab[i]);	
	free(tab);
}

char **parse_arg(int ac, char **av)
{
	char **tmp;

	if (ac < 2)
		exit(1);
	else if (ac == 2)
	{
		tmp = ft_split(av[1], ' ');
		if (!tmp)
			exit(1);
	}
	else
	{
		tmp = malloc((sizeof (char *)) * ac);
		if (!tmp)
			exit(1);
		tmp[ac - 1] = 0;
		while (--ac != 0)
			tmp[ac - 1] = ft_strdup(av[ac]);
	}
	return(tmp);
}

int main(int ac, char **av)
{
	char 	**tmp;
	t_case	*stack_a;
	t_case	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	tmp = NULL;
	tmp = parse_arg(ac, av);
	ac = ft_tablen(tmp);
	stack_a = init_stack_a(stack_a, tmp);
	looking_for_index(stack_a, ac);
	ft_free(tmp);
	// push_swap(stack_a, stack_b);
	t_case *test = stack_a;
	// for (size_t i = 1; i <= 10; i++)
	// {
	// 	printf("nb %d || index %d || real_pos %d\n", test->nb, test->index, test->real_pos);
	// 	test = test->next;
	// }
	ra_rra(&stack_a, 0);
	ra_rra(&stack_a, 0);
	pb(&stack_a, &stack_b);
	test = stack_b;
	for (size_t i = 1; i <= 10; i++)
	{
		printf("nb %d || index %d || real_pos %d\n", test->nb, test->index, test->real_pos);
		test = test->next;
	}
	return (0);
}