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
typedef struct s_index
{
	int	a0;
	int	a1;
	int	a2;
	int	b0;
	int	b1;
	int	b2;
	int am0;
	int am1;
	int am2;
	int bm0;
	int bm1;
	int bm2;
}	t_index;
typedef enum e_order
{
	ASC,
	DESC
}	t_order;

void	resolve_two_asc(t_bclst **lst_a, t_bclst **lst_b);
void	resolve_three_asc(t_bclst **lst_a, t_bclst **lst_b);
void	resolve_two_desc(t_bclst **lst_a, t_bclst **lst_b);
void	resolve_three_desc(t_bclst **lst_a, t_bclst **lst_b);
void	pa_all(t_bclst **lst_a, t_bclst **lst_b);
void	display_array(char **array);
void	display_int_arr(int arr[], int arr_len);
void	print_content(void *p);
void	print_content2(void *p);
void	print_ab(void *a, void *b);
void	ps_print(t_bclst *lst_a, t_bclst *lst_b);
void	ft_ra(t_bclst **lst_a, t_bclst **lst_b);
void	ft_rb(t_bclst **lst_a, t_bclst **lst_b);
void	ft_rr(t_bclst **lst_a, t_bclst **lst_b);
void	ft_pa(t_bclst **lst_a, t_bclst **lst_b);
void	ft_pb(t_bclst **lst_a, t_bclst **lst_b);
void	resolve_6_item(t_bclst **lst_a, t_bclst **lst_b);
void	resolve_three(t_bclst **lst_a, t_bclst **lst_b);
void	ps_destructor(t_bclst **lst_a, t_bclst **lst_b, int *ans_arr);
void	ps_do(t_bclst **lst_a, t_bclst **lst_b);
void	push_swap(int ac, char **av);
int		main(int ac, char **av);
int		*int_arr(int ac, char **av);
int		*ft_sort_arr(int ac, char **av);
void	divide(t_bclst **lst_a, t_bclst **lst_b);
void	divide_3_item(t_bclst **lst_a, t_bclst **lst_b);
void	ft_rra(t_bclst **lst_a, t_bclst **lst_b);
void	ft_rrb(t_bclst **lst_a, t_bclst **lst_b);
void	ft_rrr(t_bclst **lst_a, t_bclst **lst_b);
void	valid_args(int ac, char **av);
void	resolve_only_push(t_bclst **lst_a, t_bclst **lst_b);
bool	ft_isnum(char *s);
void	ft_sa(t_bclst **lst_a, t_bclst **lst_b);
void	ft_sb(t_bclst **lst_a, t_bclst **lst_b);
void	ft_ss(t_bclst **lst_a, t_bclst **lst_b);
int		*ps_constructor(int ac, char **av, t_bclst **lst_a, t_bclst **lst_b);

#endif
