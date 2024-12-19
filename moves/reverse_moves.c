/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppeckham <ppeckham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:24:00 by ppeckham          #+#    #+#             */
/*   Updated: 2024/12/19 10:25:17 by ppeckham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	reverse_one(t_stack **x)
{
	t_stack	*aux_x;
	t_stack	*aux_y;
	t_stack	*aux_z;
	int		i;

	if (*x == NULL)
		return ;
	i = 0;
	aux_z = *x;
	aux_y = *x;
	while (i < (ft_lstsize_p(x) - 2))
	{
		aux_z = aux_z->next;
		i++;
	}
	aux_x = ft_lstlast_p(*x);
	aux_x->next = aux_y;
	*x = aux_x;
	aux_z->next = NULL;
}

void	reverse_both(t_stack **x, t_stack **y)
{
	if (*x == NULL || *y == NULL)
		return ;
	reverse_one(x);
	reverse_one(y);
}

void	rra(t_stack **a)
{
	reverse_one(a);
	ft_set_position(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **b)
{
	reverse_one(b);
	ft_set_position(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse_both(a, b);
	ft_set_position(a);
	ft_set_position(b);
	write(1, "rrr\n", 4);
}
