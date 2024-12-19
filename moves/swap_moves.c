/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppeckham <ppeckham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:24:05 by ppeckham          #+#    #+#             */
/*   Updated: 2024/12/19 10:25:21 by ppeckham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_one(t_stack **lst)
{
	t_stack	*aux_x;
	t_stack	*aux_y;
	t_stack	*aux_z;

	if (*lst == NULL)
		return ;
	aux_x = *lst;
	aux_y = aux_x->next;
	aux_z = aux_y->next;
	aux_y->next = aux_x;
	aux_x->next = aux_z;
	*lst = aux_y;
}

void	swap_both(t_stack **x, t_stack **y)
{
	if (*x == NULL || *y == NULL)
		return ;
	swap_one(x);
	swap_one(y);
}

void	sa(t_stack **a)
{
	swap_one(a);
	ft_set_position(a);
	write(1, "sa\n", 3);
}

void	sb(t_stack **b)
{
	swap_one(b);
	ft_set_position(b);
	write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b)
{
	swap_both(a, b);
	ft_set_position(a);
	ft_set_position(b);
	write(1, "ss\n", 3);
}
