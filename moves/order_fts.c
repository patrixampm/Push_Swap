/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_fts.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppeckham <ppeckham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:23:53 by ppeckham          #+#    #+#             */
/*   Updated: 2024/12/19 10:25:13 by ppeckham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_order_three(t_stack **a)
{
	t_stack	*aux_x;
	t_stack	*aux_y;
	t_stack	*aux_z;

	aux_x = *a;
	aux_y = aux_x->next;
	aux_z = aux_y->next;
	if (aux_x->index > aux_y->index && aux_x->index > aux_z->index)
		ra(a);
	else if (aux_y->index > aux_x->index && aux_y->index > aux_z->index)
		rra(a);
	if (ft_check_if_ordered(a))
		return ;
	else
		sa(a);
}

void	ft_final_order(t_stack **a)
{
	t_stack	*aux_a;

	aux_a = *a;
	while (aux_a->index != 1)
		aux_a = aux_a->next;
	if (aux_a->pos <= (ft_lstsize_p(a) / 2))
		while (aux_a->pos != 0)
			ra(a);
	else
		while (aux_a->pos != 0)
			rra(a);
}
