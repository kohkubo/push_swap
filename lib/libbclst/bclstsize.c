#include "libbclst.h"

int	bclstsize(t_bclst *lst)
{
	int	len;
	t_bclst	*tmp;

	if (lst == NULL)
		return (0);
	tmp = bclstsentry(lst);
	tmp = tmp->next;
	len = 0;
	while (tmp->content != NULL)
	{
		tmp = tmp->next;
		len++;
	}
	return (len);
}
