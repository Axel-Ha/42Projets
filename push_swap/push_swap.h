/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalifa <ahalifa@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 10:44:16 by ahalifa           #+#    #+#             */
/*   Updated: 2026/05/27 11:08:54 by ahalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct stack
{
	int				nbr;
	int				index;
	struct stack	*next;
}					t_stack;

typedef struct flags
{
	int				algo;
	int				bench;
}					t_flags;

typedef struct stats
{
	float			disorder_metric;
	int				bench;
	int				total_ops;
	int				sa;
	int				sb;
	int				ss;
	int				pa;
	int				pb;
	int				ra;
	int				rb;
	int				rr;
	int				rra;
	int				rrb;
	int				rrr;
}					t_stats;

void				ft_pa(t_stack **stack_a, t_stack **stack_b, t_stats *stats);
void				ft_pb(t_stack **stack_a, t_stack **stack_b, t_stats *stats);
void				ft_sa(t_stack **stack_a, t_stats *stats);
void				ft_sb(t_stack **stack_b, t_stats *stats);
void				ft_ss(t_stack **stack_a, t_stack **stack_b, t_stats *stats);
void				ft_ra(t_stack **stack_a, t_stats *stats);
void				ft_rb(t_stack **stack_b, t_stats *stats);
void				ft_rr(t_stack **stack_a, t_stack **stack_b, t_stats *stats);
t_stack				*ft_listlast(t_stack *lst);
t_stack				*ft_listnew(int content);
int					ft_list_size(t_stack *stack);
void				ft_add_back(t_stack **lst, t_stack *new);
void				ft_rra(t_stack **stack_a, t_stats *stats);
void				ft_rrb(t_stack **stack_b, t_stats *stats);
void				ft_stack_clear(t_stack **stack);
t_stack				*ft_init_stack(char **args);
t_flags				*ft_init_flags(void);
int					ft_strncmp(const char *first, const char *second, size_t n);
t_flags				*ft_get_flags(char **args, int *start, t_flags *flag);
int					ft_atoi(const char *str);
int					ft_check_args(char **args);
void				ft_select_sort(t_stack **stack_a, t_stack **stack_b,
						int size, t_stats *stats);
int					ft_issign(char c);
int					ft_check_duplicate(char **args);
int					ft_check_nbr(char *nbr);
int					ft_check_ranges(char *nbr);
float				ft_compute_disorder(t_stack **stack_a);
int					ft_free_stacks(t_stack **stack_a, t_stats *stats,
						t_flags *flags);
void				*ft_freearr(char **arr, int count);
int					ft_countword(char const *s, char c);
t_stats				*ft_init_stats(t_flags *flag);
void				ft_init_index(t_stack *stack, int stack_size);
int					find_max_digits(t_stack *stack_a);
void				ft_chunk_sort(t_stack **stack_a, t_stack **stack_b,
						int list_size, t_stats *stats);
int					ft_sqrt(int n);
void				ft_radix_sort(t_stack **stack_a, t_stack **stack_b,
						t_stats *stats, int size);
void				ft_print_bench(t_flags *flags, t_stats *stats);
void				ft_select_algo(t_stack **stack_a, t_flags *flags,
						t_stats *stats);

#endif