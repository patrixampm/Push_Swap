/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppeckham <ppeckham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:23:16 by ppeckham          #+#    #+#             */
/*   Updated: 2024/12/19 10:23:17 by ppeckham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdarg.h>
# include <stdio.h>
# include <limits.h>
# include <stdbool.h>

# include "libft/libft.h"

typedef struct s_stack
{
	long long		value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	int				tc;
	struct s_stack	*next;
}	t_stack;

// ARGUMENT CHECKS
bool		ft_check_alpha(char **split);
bool		ft_check_if_ordered(t_stack **x);
int			ft_check_doubles(t_stack **a);
bool		ft_check_minmax(t_stack *node, char **split, t_stack **a);
void		ft_free_split(char **split);

//CONVERSION
long long	ft_atoll(const char *str);

// LISTS
t_stack		*ft_lstnew_p(long long n);
t_stack		*ft_lstlast_p(t_stack *lst);
void		ft_lstadd_back_p(t_stack **lst, t_stack *new);
int			ft_lstsize_p(t_stack **lst);
void		ft_lstadd_front_p(t_stack **lst, t_stack *new);
void		ft_print_list(t_stack **list, char l); //hay que borrar esta
void		ft_free_list(t_stack **lst);
bool		ft_create_list(int argc, char **argv, t_stack **a);

// COMPOSE LIST WITH STRUCT
int			*ft_sort_in_tab(int	*array, int i);
int			*ft_extract_int_list(t_stack **list, int i);
void		ft_set_index(t_stack **list, int i);
void		ft_set_position(t_stack **list);
t_stack		*ft_get_lowest_cost(t_stack **x);
int			ft_find_target_1(t_stack **a, int index);
int			ft_find_target_2(t_stack **a, int b_index, int size);
int			ft_find_target_3(t_stack **a, int index);
void		ft_calculate_cost(t_stack **a, t_stack **b);
void		ft_set_total_cost(t_stack *aux_b);
void		ft_cost(t_stack **a, t_stack **b);

// ORDER
void		ft_order_three(t_stack **a);
void		ft_final_order(t_stack **a);

// ACTIONS
void		push_one(t_stack **src, t_stack **dest);
void		pa(t_stack **b, t_stack **a);
void		pb(t_stack **a, t_stack **b);
void		ft_first_push(t_stack **a, t_stack **b);
void		swap_one(t_stack **lst);
void		swap_both(t_stack **x, t_stack **y);
void		sa(t_stack **a);
void		sb(t_stack **b);
void		ss(t_stack **a, t_stack **b);
void		rotate_one(t_stack **x);
void		rotate_both(t_stack **x, t_stack **y);
void		ra(t_stack **a);
void		rb(t_stack **b);
void		rr(t_stack **a, t_stack **b);
void		reverse_one(t_stack **x);
void		reverse_both(t_stack **x, t_stack **y);
void		rra(t_stack **a);
void		rrb(t_stack **b);
void		rrr(t_stack **a, t_stack **b);

// EXECUTING MOVES
void		ft_case_one(t_stack **a, t_stack **b, t_stack *ax, t_stack *bx);
void		ft_case_two(t_stack **a, t_stack **b, t_stack *ax, t_stack *bx);
void		ft_case_three(t_stack **a, t_stack **b, t_stack *ax, t_stack *bx);
void		ft_case_four(t_stack **a, t_stack **b, t_stack *ax, t_stack *bx);
void		ft_rest_cases(t_stack **a, t_stack **b, t_stack *ax, t_stack *bx);

#endif
