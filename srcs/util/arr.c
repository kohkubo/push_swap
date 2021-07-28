#include "push_swap.h"

static int64_t	ps_atol(const char *s)
{
	uint64_t	n;
	int			neg;
	uint64_t	tmp;

	n = 0;
	neg = 1;
	while (ft_isspace(*s))
		s++;
	if (*s == '-' || *s == '+')
		if (*s++ == '-')
			neg = -1;
	while (ft_isdigit(*s))
	{
		tmp = n;
		n = n * 10 + *s++ - '0';
		if (tmp >> 60 || n >> 63)
		{
			errno = EINVAL;
			if (neg == 1)
				return (LONG_MAX);
			else
				return (LONG_MIN);
		}
	}
	return (n * neg);
}

int	*int_arr(int ac, char **av)
{
	int		i;
	int		*arr;
	int64_t	tmp;

	arr = ft_xcalloc(sizeof(int) * ac - 1);
	i = 1;
	while (i < ac)
	{
		tmp = ps_atol(av[i]);
		if (tmp > INT_MAX || tmp < INT_MIN)
		{
			ft_error_exit("Error\n");
		}
		arr[i - 1] = tmp;
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
