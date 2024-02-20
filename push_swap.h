/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cunh <mda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:48:52 by mda-cunh          #+#    #+#             */
/*   Updated: 2024/02/20 12:58:29 by mda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include "stdlib.h"
# include "stdio.h"

typedef struct s_case
{
	struct s_case	*prev;
	struct s_case	*next;
	int				real_pos;
	int				index;
	int				nb;
}	t_case;

int		ft_tablen(char **tab);
t_case	*init_stack_a(t_case *head, char **tab);
void	ft_compactage(t_case *head, t_case *new_case, int i);
t_case	*ft_newcase(int content);
void	ft_sort_int_tab(int *tab, int size);
void	swapper_value(t_case **stack);

//! MOVEMENT

void	pb(t_case **s_a, t_case **s_b);
void	pa(t_case **s_a, t_case **s_b);
void	rb_rrb(t_case **stack, int i);
void	ra_rra(t_case **stack, int i);
void	sa(t_case **stack);
void	sb(t_case **stack);
void	ss(t_case **s_a, t_case **s_b);

// UTILS 

void	uni_stack_pos_finder(t_case *stack);
void	duo_stack_pos_finder(t_case *s_a, t_case *s_b);
int		ps_lstsize(t_case *lst);
void	free_lst(t_case **s_a, t_case **s_b);

// ALGO

void	push_swap(t_case **s_a, t_case **s_b);
void	road_to_a(t_case **s_a, t_case **s_b, t_case *node);
void	road_to_b(t_case **s_a, t_case **s_b, t_case *node);
int		lst_is_sorted(t_case *stack);

// ALLSORT

void	micro_sort(t_case **s_a, t_case **s_b);
void	little_sort(t_case **s_a, t_case **s_b);
void	pre_sort(t_case **s_a, t_case **s_b, int divider);
void	end_sort(t_case **s_a, t_case **s_b);

#endif