#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../lib/libft/libft.h"
# include "../lib/libex/libex.h"
# include "../lib/libbclst/libbclst.h"
typedef struct s_content
{
	int	n;
	int	index;
}	t_content;

void	ft_ra(t_bclst **lst_a, t_bclst **lst_b);
void	ft_rb(t_bclst **lst_a, t_bclst **lst_b);
void	ft_rr(t_bclst **lst_a, t_bclst **lst_b);
void	ft_pa(t_bclst **lst_a, t_bclst **lst_b);
void	ft_pb(t_bclst **lst_a, t_bclst **lst_b);
void	display_int_arr(int arr[], int arr_len);
void	print_content(void *p);
t_bclst	*ps_lst(int ac, char **av);
int		*int_arr(int ac, char **av);
int		*ft_sort_arr(int ac, char **av);
void	take_index(t_bclst *lst, int *arr, int len);
void	push_swap(int ac, char **av);
int		main(int ac, char **av);
void	ft_rra(t_bclst **lst_a, t_bclst **lst_b);
void	ft_rrb(t_bclst **lst_a, t_bclst **lst_b);
void	ft_rrr(t_bclst **lst_a, t_bclst **lst_b);
void	valid_args(int ac, char **av);
bool	ft_isnum(char *s);
void	ft_sa(t_bclst **lst_a, t_bclst **lst_b);
void	ft_sb(t_bclst **lst_a, t_bclst **lst_b);
void	ft_ss(t_bclst **lst_a, t_bclst **lst_b);

#endif
