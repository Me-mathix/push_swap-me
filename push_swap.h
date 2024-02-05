#include "./libft/libft.h"
#include "stdlib.h"
#include "stdio.h"

typedef struct s_case
{
	struct s_case  *prev;
	struct s_case  *next;
	int		real_pos;
	int     index;
	int		nb;
}	t_case;

int		ft_tablen(char **tab);
t_case	*init_stack_a(t_case *head, char **tab);
void	ft_compactage(t_case *head, t_case *new_case, int i);
t_case	*ft_newcase(int content);
void	mergeSort(int arr[], int l, int r);
void	merge(int arr[], int l, int m, int r);
void	swapper_value(t_case **stack);


//! MOVEMENT

void	pb(t_case **s_a, t_case **s_b);
void	pa(t_case **s_a, t_case **s_b);
void	rb_rrb(t_case **stack, int i);
void	ra_rra(t_case **stack, int i);
void	sa(t_case **stack);
void 	sb(t_case **stack);