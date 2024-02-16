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
	while (nptr[i])
	{
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

void ft_compactage(t_case *head, t_case *new_case, int i)
{
	t_case *tmp;

	tmp = head;
	if (!new_case)
	{
		free_lst(&head,NULL);
		return ;
	}
	if (head->next == head && head->prev == head)
	{
		head->next = new_case;
		head->prev = new_case;
		new_case->next = head;
		new_case->prev = head;
		new_case->real_pos = i;
		return ;
	}
	head->prev->next = new_case;
	new_case->prev = head->prev;
	new_case->next = head;
	head->prev = new_case;
	new_case->real_pos = i;
}

int	ft_parse_error(char **tab)
{
	int i;
	int j;
	char *nb_test;

	i = 0;
	j = 0;
	while (tab[i])
	{
		if (tab[i][j] == '-')
			j++;
		while (tab[i][j])
			if (!ft_isdigit(tab[i][j++]))
				return(0);
		nb_test = ft_itoa(ft_atoi(tab[i]));
		if (ft_strncmp(nb_test, tab[i], ft_strlen(tab[i])))
			return(free(nb_test), 0);
		free(nb_test);
		j = i;
		while(tab[++j])
			if (ft_atoi(tab[i]) == ft_atoi(tab[j]))
				return (0);
		j = 0;
		i++;
	}
	return(1);
}

t_case *init_stack_a(t_case *head, char **tab)
{
	int		i;

	i = 1;
	if (!ft_parse_error(tab) || !tab[0])
	{
		ft_free(tab);
		ft_putendl_fd("Error", 2);
		exit(1);
	}	
	head = ft_newcase(ps_atoi(tab[0]));
	head->prev = head;
	head->next = head;
	head->real_pos = 1;
	while (i < ft_tablen(tab))
	{
		ft_compactage(head, ft_newcase(ps_atoi(tab[i])), i + 1);
		if (!head)
			return(NULL);	
		i++;
	}
	return (head);
}
