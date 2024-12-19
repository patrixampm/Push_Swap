/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check_fts.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppeckham <ppeckham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:22:42 by ppeckham          #+#    #+#             */
/*   Updated: 2024/12/19 10:25:05 by ppeckham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

bool	ft_check_alpha(char **split)
{
	int	i;
	int	j;

	i = 0;
	while (split[i])
	{
		j = 0;
		if ((split[i][j] == '-' || split[i][j] == '+') && (split[i][j + 1]))
			j++;
		while (split[i][j])
		{
			if (split[i][j] < '0' || split[i][j] > '9')
			{
				write(2, "Error\n", 7);
				return (false);
			}
			j++;
		}
		i++;
	}
	return (true);
}

bool	ft_check_if_ordered(t_stack **x)
{
	t_stack	*aux_x;
	t_stack	*aux_y;

	aux_x = *x;
	aux_y = aux_x->next;
	while (aux_x->next != NULL)
	{
		if (aux_x->index > aux_y->index)
			return (false);
		aux_x = aux_x->next;
		aux_y = aux_y->next;
	}
	return (true);
}

int	ft_check_doubles(t_stack **a)
{
	t_stack	*aux;
	t_stack	*temp;

	aux = *a;
	while (aux)
	{
		temp = aux->next;
		while (temp)
		{
			if (aux->value == temp->value)
				return (1);
			temp = temp->next;
		}
		aux = aux->next;
	}
	return (0);
}

bool	ft_check_minmax(t_stack *node, char **split, t_stack **a)
{
	if (node->value > INT_MAX || node->value < INT_MIN)
	{
		ft_free_split(split);
		ft_free_list(a);
		free(node);
		write(2, "Error\n", 7);
		return (false);
	}
	return (true);
}

void	ft_free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}
