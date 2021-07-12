#include "../includes/push_swap.h"

void	resolve_2_item(t_bclst **lst_a, t_bclst **lst_b)
{
	int	index0;
	int	index1;

	index0 = ((t_content *)((*lst_a)->content))->index;
	index1 = ((t_content *)((*lst_a)->next->content))->index;
	if (index0 > index1)
		ft_sa(lst_a, lst_b);
}

void	pa_all(t_bclst **lst_a, t_bclst **lst_b)
{
	while ((*lst_b)->content != NULL)
		ft_pb(lst_a, lst_b);
}

void	resolve_6_item(t_bclst **lst_a, t_bclst **lst_b)
{
	divide_3_item(lst_a, lst_b);
	resolve_3_item_a(lst_a, lst_b);
	printf("-------------------\n");
	// ps_print(*lst_a, *lst_b);
	resolve_3_item_b(lst_b, lst_a);
	pa_all(lst_a, lst_b);
	// ps_print(*lst_a, *lst_b);
}

void	resolve_3_item_b(t_bclst **lst_a, t_bclst **lst_b)
{
	int	index0;
	int	index1;
	int	index2;

	index0 = ((t_content *)((*lst_a)->content))->index;
	index1 = ((t_content *)((*lst_a)->next->content))->index;
	index2 = ((t_content *)((*lst_a)->next->next->content))->index;
	if (index0 < index1 && index1 < index2)
	{
		ft_sa(lst_a, lst_b);
		ft_rra(lst_a, lst_b);
	}
	else if (index0 < index1 && index1 > index2 && index0 < index2)
		ft_ra(lst_a, lst_b);
	else if (index0 > index1 && index1 < index2 && index0 < index2)
		ft_rra(lst_a, lst_b);
	else if (index0 < index1)
		ft_sa(lst_a, lst_b);
	else if (index0 > index1 && index1 < index2)
	{
		ft_rra(lst_a, lst_b);
		ft_sa(lst_a, lst_b);
	}
}

void	resolve_3_item_a(t_bclst **lst_a, t_bclst **lst_b)
{
	int	index0;
	int	index1;
	int	index2;

	index0 = ((t_content *)((*lst_a)->content))->index;
	index1 = ((t_content *)((*lst_a)->next->content))->index;
	index2 = ((t_content *)((*lst_a)->next->next->content))->index;
	if (index0 > index1 && index1 > index2)
	{
		ft_sa(lst_a, lst_b);
		ft_rra(lst_a, lst_b);
	}
	else if (index0 > index1 && index1 < index2 && index0 > index2)
		ft_ra(lst_a, lst_b);
	else if (index0 < index1 && index1 > index2 && index0 > index2)
		ft_rra(lst_a, lst_b);
	else if (index0 > index1)
		ft_sa(lst_a, lst_b);
	else if (index0 < index1 && index1 > index2)
	{
		ft_rra(lst_a, lst_b);
		ft_sa(lst_a, lst_b);
	}
}

// void	resolve_3_item(t_bclst **lst_a, t_bclst **lst_b)
// {
// 	int	index0;
// 	int	index1;
// 	int	index2;

// 	index0 = ((t_content *)((*lst_a)->content))->index;
// 	index1 = ((t_content *)((*lst_a)->next->content))->index;
// 	index2 = ((t_content *)((*lst_a)->next->next->content))->index;
// 	if (index0 == 2 && index1 == 1)
// 	{
// 		ft_sa(lst_a, lst_b);
// 		ft_rra(lst_a, lst_b);
// 	}
// 	else if (index0 == 2 && index1 == 0)
// 		ft_ra(lst_a, lst_b);
// 	else if (index0 == 1 && index1 == 2)
// 		ft_rra(lst_a, lst_b);
// 	else if (index0 == 1 && index1 == 0)
// 		ft_sa(lst_a, lst_b);
// 	else if (index0 == 0 && index1 == 2)
// 	{
// 		ft_rra(lst_a, lst_b);
// 		ft_sa(lst_a, lst_b);
// 	}
// }

void	resolve_only_push(t_bclst **lst_a, t_bclst **lst_b)
{
	t_content	*c;
	int	max;
	int	i;

	i = 0;
	max = bclstsize(*lst_a);
	while (i < max)
	{
		c = (t_content *)((*lst_a)->content);
		if (c->index == i)
		{
			ft_pa(lst_a, lst_b);
			i++;
			continue ;
		}
		if ((*lst_a)->next->content == NULL)
			*lst_a = (*lst_a)->next->next;
		else
			*lst_a = (*lst_a)->next;
	}
	while ((*lst_b)->content != NULL)
	{
		ft_pb(lst_a, lst_b);
	}
}
