/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppeckham <ppeckham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:23:13 by ppeckham          #+#    #+#             */
/*   Updated: 2024/12/19 10:23:14 by ppeckham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_execute_moves(t_stack **a, t_stack **b)
{
	t_stack	*aux_a;
	t_stack	*aux_b;

	aux_a = *a;
	aux_b = ft_get_lowest_cost(b);
	while (aux_a->pos != aux_b->target_pos)
		aux_a = aux_a->next;
	if (aux_b->cost_b < 0 && aux_b->cost_a < 0)
		ft_case_one(a, b, aux_a, aux_b);
	if (aux_b->cost_b < 0 && aux_b->cost_a > 0)
		ft_case_two(a, b, aux_a, aux_b);
	if (aux_b->cost_b > 0 && aux_b->cost_a < 0)
		ft_case_three(a, b, aux_a, aux_b);
	if (aux_b->cost_b > 0 && aux_b->cost_a > 0)
		ft_case_four(a, b, aux_a, aux_b);
	else
		ft_rest_cases(a, b, aux_a, aux_b);
	pa(b, a);
}

static bool	ft_create_stacks(int argc, char **argv, t_stack **a)
{
	if (!(ft_create_list(argc, argv, a)))
	{
		ft_free_list(a);
		return (false);
	}
	if (ft_check_doubles(a))
	{
		write(2, "Error\n", 7);
		ft_free_list(a);
		return (false);
	}
	ft_set_index(a, ft_lstsize_p(a));
	ft_set_position(a);
	if (ft_check_if_ordered(a))
	{
		ft_free_list(a);
		return (false);
	}
	return (true);
}

static void	ft_choose_alg(t_stack **a, t_stack **b)
{
	if (ft_lstsize_p(a) == 2)
		sa(a);
	else if (ft_lstsize_p(a) == 3)
		ft_order_three(a);
	else
	{
		ft_first_push(a, b);
		ft_order_three(a);
	}
}

int	main(int argc, char **argv)
{
	t_stack			*a;
	t_stack			*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (1);
	if (ft_strlen(argv[1]) == 0)
	{
		write(2, "Error\n", 7);
		return (false);
	}
	if (!(ft_create_stacks(argc, argv, &a)))
		return (1);
	else
		ft_choose_alg(&a, &b);
	while (ft_lstsize_p(&b) > 0)
	{
		ft_cost(&a, &b);
		ft_execute_moves(&a, &b);
	}
	ft_final_order(&a);
	ft_free_list(&a);
	ft_free_list(&b);
	return (0);
}
