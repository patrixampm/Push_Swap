/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_fts.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppeckham <ppeckham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:24:42 by ppeckham          #+#    #+#             */
/*   Updated: 2024/12/19 10:25:42 by ppeckham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_find_target_1(t_stack **a, int index)
{
	t_stack	*aux_a;
	int		target_index;

	aux_a = *a;
	target_index = index + 1;
	while (aux_a)
	{
		if (aux_a->index == target_index)
			return (aux_a->pos);
		aux_a = aux_a->next;
	}
	return (-1);
}

int	ft_find_target_2(t_stack **a, int b_index, int size)
{
	t_stack	*aux_a;
	int		target_index;

	target_index = b_index + 2;
	while (target_index <= size)
	{
		aux_a = *a;
		while (aux_a)
		{
			if (aux_a->index == target_index)
				return (aux_a->pos);
			aux_a = aux_a->next;
		}
		target_index += 1;
	}
	return (-2);
}

int	ft_find_target_3(t_stack **a, int b_index)
{
	t_stack	*aux_a;
	int		target_index;

	target_index = 1;
	while (target_index < b_index)
	{
		aux_a = *a;
		while (aux_a)
		{
			if (target_index == aux_a->index)
				return (aux_a->pos);
			aux_a = aux_a->next;
		}
		target_index += 1;
	}
	return (-3);
}
