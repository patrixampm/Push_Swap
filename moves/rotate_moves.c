#include "./push_swap.h"

void	rotate_one(t_stack **x)
{
	t_stack	*aux_x;
	t_stack	*aux_y;
	t_stack	*aux_z;

	if (*x == NULL)
		return ;
	aux_z = ft_lstlast_p(*x);
	aux_x = *x;
	aux_y = aux_x->next;
	aux_z->next = aux_x;
	aux_x->next = NULL;
	*x = aux_y;
}

void	rotate_both(t_stack **x, t_stack **y)
{
	if (*x == NULL || *y == NULL)
		return ;
	rotate_one(x);
	rotate_one(y);
}

void	ra(t_stack **a)
{
	rotate_one(a);
	ft_set_position(a);
	write(1, "ra\n", 3);
}

void	rb(t_stack **b)
{
	rotate_one(b);
	ft_set_position(b);
	write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b)
{
	rotate_both(a, b);
	ft_set_position(a);
	ft_set_position(b);
	write(1, "rr\n", 3);
}
