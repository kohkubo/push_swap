#include "libbclst.h"

int	bclstsize(t_bclst *lst)
{
	int	len;
	t_bclst	*tmp;

	tmp = bclstsentry(lst);
	tmp = tmp->next;
	len = 0;
	while (tmp->content != NULL)
	{
		tmp = tmp->next;
		printf("%p\n", tmp);
		len++;
	}
	return (len);
}
