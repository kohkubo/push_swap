#include "push_swap.h"

int	*int_arr(int ac, char **av)
{
	int	i;
	int	*arr;

	arr = ft_xcalloc(sizeof(int) * ac - 1);
	i = 1;
	while (i < ac)
	{
		arr[i - 1] = ft_atoi(av[i]);
		i++;
	}
	return (arr);
}

int	*ft_sort_arr(int ac, char **av)
{
	int	*arr;

	arr = int_arr(ac, av);
	ft_quick_sort(arr, 0, ac - 2);
	return (arr);
}