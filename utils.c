#include "push_swap.h"

int ft_tablen(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		i++;
	return(i);
}

int	ps_atoi(const char *nptr)
{
	long	nbr;
	long	neg;
	int		i;

	nbr = 0;
	neg = 1;
	i = 0;
	while ((nptr[i] <= 13 && nptr[i] >= 9) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
		if (nptr[i++] == '-')
			neg *= -1;
	if ((nptr[i] < '0') && (nptr[i] > '9'))
		exit(12);
	while (nptr[i])
	{
		if ((nptr[i] < '0') && (nptr[i] > '9'))
			exit(12);
		nbr = nbr * 10 + nptr[i] - 48;
		i++;
	}
	return (nbr * neg);
}

t_case	*ft_newcase(int content)
{
	t_case	*newlst;

	newlst = malloc(sizeof (t_case));
	if (!newlst)
		return (NULL);
	newlst->nb = content;
	return (newlst);
}
void ft_compactage(t_case *head, t_case *new_case)
{
	t_case *tmp;

	tmp = head;
	while (tmp->next != head)
	{
		if (tmp->nb == tmp->next->nb)
			exit(111);
		tmp = tmp->next;
	}
	if (tmp->next == head && tmp->prev == head)
	{
		tmp->next = new_case;
		tmp->prev = new_case;
		new_case->next = head;
		new_case->prev = head;
		return ;
	}
	head->prev->next = new_case;
	new_case->prev = head->prev;
	new_case->next = head;
	head->prev = new_case;
}

t_case *init_stack_a(t_case *head, char **tab)
{
	int		i;

	i = 1;
	head = ft_newcase(ps_atoi(tab[0]));
	head->prev = head;
	head->next = head;
	while (i < ft_tablen(tab))
		ft_compactage(head, ft_newcase(ps_atoi(tab[i++])));
	return (head);
}
