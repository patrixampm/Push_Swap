/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppeckham <ppeckham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:23:57 by ppeckham          #+#    #+#             */
/*   Updated: 2024/12/19 10:25:15 by ppeckham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_one(t_stack **src, t_stack **dest)
{
	t_stack	*aux_x;
	t_stack	*aux_y;

	if (*src == NULL)
		return ;
	aux_x = *src;
	aux_y = aux_x->next;
	aux_x->next = *dest;
	*dest = aux_x;
	*src = aux_y;
}

void	pa(t_stack **b, t_stack **a)
{
	push_one(b, a);
	ft_set_position(a);
	ft_set_position(b);
	write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b)
{
	push_one(a, b);
	ft_set_position(a);
	ft_set_position(b);
	write(1, "pb\n", 3);
}

void	ft_first_push(t_stack **a, t_stack **b)
{
	int			size;
	int			half;

	size = ft_lstsize_p(a);
	half = size / 2;
	if (size % 2 != 0)
		half++;
	while ((size > 3) && (half < size))
	{
		if ((*a)->index <= half)
		{
			pb(a, b);
			size--;
		}
		else
			ra(a);
	}
	while (size > 3)
	{
		pb(a, b);
		size--;
	}
}
