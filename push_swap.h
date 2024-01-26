#include "./libft/libft.h"
#include "stdlib.h"
#include "stdio.h"

typedef struct s_case
{
	struct s_case  *prev;
	struct s_case  *next;
	int     index;
	int		nb;
}	t_case;

int		ft_tablen(char **tab);
t_case	*init_stack_a(t_case *head, char **tab);
void	ft_compactage(t_case *head, t_case *new_case);
t_case	*ft_newcase(int content);