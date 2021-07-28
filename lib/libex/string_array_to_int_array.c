#include "libex.h"

int	*string_array_to_int_array(char **str_array, int len)
{
	int		i;
	int		*arr;

	arr = ft_xcalloc(sizeof(int) * len + 1);
	i = 0;
	while (i < len)
	{
		arr[i] = ft_atoi(str_array[i]);
		i++;
	}
	return (arr);
}
