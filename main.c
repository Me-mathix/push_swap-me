/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cunh <mda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:37:23 by mda-cunh          #+#    #+#             */
/*   Updated: 2024/02/20 12:44:13 by mda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_lst(t_case **s_a, t_case **s_b)
{
	t_case	*actual;
	t_case	*sav;
	int		i;

	i = ps_lstsize(*s_a);
	actual = *s_a;
	while (i--)
	{
		sav = actual->next;
		free(actual);
		actual = sav;
	}
	*s_a = NULL;
	i = ps_lstsize(*s_b);
	actual = *s_b;
	while (i--)
	{
		sav = actual->next;
		free(actual);
		actual = sav;
	}
	*s_b = NULL;
	exit(1);
}

void	lst_indexing(t_case *stack_a, int index, int nb)
{
	t_case	*head;

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
	int		*tab;
	int		i;
	t_case	*head;

	i = 0;
	head = stack_a;
	tab = malloc((sizeof (int)) * ac);
	if (!tab)
		return ;
	while (head->next != stack_a)
	{
		tab[i++] = head->nb;
		head = head->next;
	}
	tab[i] = head->nb;
	ft_sort_int_tab(tab, i + 1);
	i = -1;
	while (++i < ac)
		lst_indexing(stack_a, i + 1, tab[i]);
	free(tab);
}

char	**parse_arg(int ac, char **av)
{
	char	**tmp;

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
		{
			tmp[ac - 1] = ft_strdup(av[ac]);
			if (!tmp[ac - 1])
				ft_free(tmp);
		}
	}
	return (tmp);
}

int	main(int ac, char **av)
{
	char	**tmp;
	t_case	*stack_a;
	t_case	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	tmp = NULL;
	tmp = parse_arg(ac, av);
	ac = ft_tablen(tmp);
	stack_a = init_stack_a(stack_a, tmp);
	if (!stack_a)
		return (ft_free(tmp), 0);
	looking_for_index(stack_a, ac);
	ft_free(tmp);
	push_swap(&stack_a, &stack_b);
	free_lst(&stack_a, &stack_b);
}
