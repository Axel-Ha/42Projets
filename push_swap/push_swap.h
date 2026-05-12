/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalifa <ahalifa@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 10:44:16 by ahalifa           #+#    #+#             */
/*   Updated: 2026/05/12 13:48:47 by ahalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include "ft_printf.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct stack
{
	int				nbr;
	// int				pos;
	struct stack	*next;
}					t_stack;

typedef struct flags
{
	int				algo;
	int				bench;
}					t_flags;

void				ft_pa(t_stack **stack_a, t_stack **stack_b);
void				ft_pb(t_stack **stack_a, t_stack **stack_b);
void				ft_swap(t_stack *stack);
void				ft_sa(t_stack **stack_a);
void				ft_sb(t_stack **stack_b);
void				ft_ss(t_stack **stack_a, t_stack **stack_b);
void				ft_rr(t_stack **stack_a, t_stack **stack_b);
void				ft_rb(t_stack **stack_b);
void				ft_ra(t_stack **stack_a);
void				ft_rotate(t_stack **stack);
t_stack				*ft_lstlast(t_stack *lst);
void				ft_rotate_reverse(t_stack **stack);
void				ft_rra(t_stack **stack_a);
void				ft_rrb(t_stack **stack_b);
void				ft_ss(t_stack **stack_a, t_stack **stack_b);
t_stack				*ft_lstnew(int content);
void				ft_stack_clear(t_stack **stack);
int					ft_lst_size(t_stack *stack);
t_stack				*ft_init_stack(char **args);
int					ft_strncmp(const char *first, const char *second, size_t n);
t_flags				ft_get_flags(char **av, int *start);
int					ft_atoi(const char *str);
int					ft_check_args(char **args);
char				**ft_split(char const *s, char c);
void				ft_lstadd_back(t_stack **lst, t_stack *new);
void				ft_bubble_sort(t_stack **stack_a, int size);
int					ft_issign(char c);
int					ft_isdigit(char c);
int					ft_check_duplicate(char **args);
int					ft_check_nbr(char *nbr);
int					ft_check_ranges(char *nbr);

#endif