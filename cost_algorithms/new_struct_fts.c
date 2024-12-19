/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_struct_fts.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppeckham <ppeckham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:24:48 by ppeckham          #+#    #+#             */
/*   Updated: 2024/12/19 10:25:38 by ppeckham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_calculate_cost(t_stack **a, t_stack **b)
{
	t_stack	*aux_b;
	t_stack	*aux_a;

	aux_b = *b;
	while (aux_b)
	{
		aux_a = *a;
		if (aux_b->pos <= ft_lstsize_p(b) / 2)
			aux_b->cost_b = aux_b->pos;
		else
			aux_b->cost_b = (ft_lstsize_p(b) - aux_b->pos) * -1;
		while (aux_a)
		{
			if (aux_b->target_pos == aux_a->pos)
			{
				if (aux_a->pos <= ft_lstsize_p(a) / 2)
					aux_b->cost_a = aux_a->pos;
				else
					aux_b->cost_a = (ft_lstsize_p(a) - aux_a->pos) * -1;
			}
			aux_a = aux_a->next;
		}
		ft_set_total_cost(aux_b);
		aux_b = aux_b->next;
	}
}

void	ft_set_total_cost(t_stack *aux_b)
{
	int	a;
	int	b;

	if (aux_b->cost_b < 0 || aux_b->cost_a < 0)
	{
		a = aux_b->cost_a;
		b = aux_b->cost_b;
		if (aux_b->cost_b < 0)
			b = aux_b->cost_b * -1;
		if (aux_b->cost_a < 0)
			a = aux_b->cost_a * -1;
		aux_b->tc = a + b;
	}
	else
		aux_b->tc = aux_b->cost_a + aux_b->cost_b;
}

void	ft_cost(t_stack **a, t_stack **b)
{
	t_stack	*aux_a;
	t_stack	*aux_b;
	int		b_index;
	int		size;

	aux_a = *a;
	aux_b = *b;
	size = ft_lstsize_p(a) + ft_lstsize_p(b);
	while (aux_b)
	{
		b_index = aux_b->index;
		aux_b->target_pos = ft_find_target_1(a, aux_b->index);
		if (aux_b->target_pos == -1)
			aux_b->target_pos = ft_find_target_2(a, b_index, size);
		if (aux_b->target_pos == -2)
			aux_b->target_pos = ft_find_target_3(a, b_index);
		aux_b = aux_b->next;
	}
	ft_calculate_cost(a, b);
}
