#include "push_swap.h"

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
	return (0);
}