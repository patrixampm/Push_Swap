#include "./push_swap.h"

void	ft_free_list(t_stack **lst)
{
	t_stack	*aux;

	aux = *lst;
	while (aux)
	{
		aux = aux->next;
		free(*lst);
		*lst = aux;
	}
	*lst = NULL;
}

static bool	ft_check_for_aplha(char **split)
{
	int	i;

	i = 0;
	if (!(ft_check_alpha(split)))
	{
		ft_free_split(split);
		return (false);
	}
	return (true);
}

bool	ft_create_list(int argc, char **argv, t_stack **a)
{
	int		i;
	int		j;
	char	**split;
	t_stack	*node;

	i = 1;
	split = NULL;
	while (i < argc)
	{
		j = 0;
		split = ft_split(argv[i], ' ');
		if (!(ft_check_for_aplha(split)))
			return (false);
		while (split[j])
		{
			node = ft_lstnew_p(ft_atoll(split[j]));
			if (!(ft_check_minmax(node, split, a)))
				return (false);
			ft_lstadd_back_p(a, node);
			j++;
		}
		ft_free_split(split);
		i++;
	}
	return (true);
}
