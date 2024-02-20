/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cunh <mda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:53:19 by mda-cunh          #+#    #+#             */
/*   Updated: 2024/02/20 12:54:07 by mda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	uni_stack_pos_finder(t_case *stack)
{
	t_case	*head;
	int		i;

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

void	duo_stack_pos_finder(t_case *s_a, t_case *s_b)
{
	t_case	*head;
	int		i;

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
	int		count;
	t_case	*head;

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

int	ft_tablen(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}
