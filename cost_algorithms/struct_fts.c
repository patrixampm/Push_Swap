/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_fts.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppeckham <ppeckham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:24:45 by ppeckham          #+#    #+#             */
/*   Updated: 2024/12/19 10:25:41 by ppeckham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	*ft_sort_in_tab(int	*array, int i)
{
	int	j;
	int	temp;

	j = 0;
	while (j < i - 1)
	{
		if (array[j] > array[j + 1])
		{
			temp = array[j];
			array[j] = array[j + 1];
			array[j + 1] = temp;
			j = 0;
		}
		else
			j++;
	}
	return (array);
}

int	*ft_extract_int_list(t_stack **list, int i)
{
	t_stack	*aux;
	int		*array;
	int		j;

	array = malloc((i + 1) * sizeof(int));
	aux = *list;
	j = 0;
	while (aux)
	{
		array[j] = aux->value;
		j++;
		aux = aux->next;
	}
	return (array);
}

void	ft_set_index(t_stack **list, int i)
{
	t_stack	*aux;
	int		*array;
	int		j;

	j = 0;
	aux = *list;
	array = ft_extract_int_list(list, i);
	array = ft_sort_in_tab(array, i);
	while (j < i)
	{
		if (array[j] == aux->value)
		{
			aux->index = j + 1;
			j++;
			aux = *list;
		}
		else
			aux = aux->next;
	}
	free(array);
}

void	ft_set_position(t_stack **list)
{
	t_stack	*aux;
	int		c;

	aux = *list;
	c = 0;
	while (aux)
	{
		aux->pos = c;
		aux = aux->next;
		c++;
	}
}

t_stack	*ft_get_lowest_cost(t_stack **x)
{
	t_stack	*aux_x;
	t_stack	*aux_y;
	t_stack	*lowest;

	aux_x = *x;
	aux_y = aux_x->next;
	lowest = *x;
	while (aux_x && aux_y)
	{
		if (aux_y->tc < lowest->tc)
			lowest = aux_y;
		aux_x = aux_x->next;
		aux_y = aux_x->next;
	}
	return (lowest);
}
