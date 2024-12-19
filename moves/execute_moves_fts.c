/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_moves_fts.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppeckham <ppeckham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:23:36 by ppeckham          #+#    #+#             */
/*   Updated: 2024/12/19 10:25:11 by ppeckham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_case_one(t_stack **a, t_stack **b, t_stack *ax, t_stack *bx)
{
	while (bx->pos != 0 && ax->pos != 0)
		rrr(a, b);
	while (bx->pos != 0)
		rrb(b);
	while (ax->pos != 0)
		rra(a);
}

void	ft_case_two(t_stack **a, t_stack **b, t_stack *ax, t_stack *bx)
{
	while (bx->pos != 0)
		rrb(b);
	while (ax->pos != 0)
		ra(a);
}

void	ft_case_three(t_stack **a, t_stack **b, t_stack *ax, t_stack *bx)
{
	while (ax->pos != 0)
		rra(a);
	while (bx->pos != 0)
		rb(b);
}

void	ft_case_four(t_stack **a, t_stack **b, t_stack *ax, t_stack *bx)
{
	while (bx->pos != 0 && ax->pos != 0)
		rr(a, b);
	while (ax->pos != 0)
		ra(a);
	while (bx->pos != 0)
		rb(b);
}

void	ft_rest_cases(t_stack **a, t_stack **b, t_stack *ax, t_stack *bx)
{
	if (bx->cost_b == 0 && bx->cost_a < 0)
		while (ax->pos != 0)
			rra(a);
	if (bx->cost_b == 0 && bx->cost_a > 0)
		while (ax->pos != 0)
			ra(a);
	if (bx->cost_b < 0 && bx->cost_a == 0)
		while (bx->pos != 0)
			rrb(b);
	if (bx->cost_b > 0 && bx->cost_a == 0)
		while (bx->pos != 0)
			rb(b);
}
