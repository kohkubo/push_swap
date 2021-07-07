#include "libbclst.h"

void	bclstclear(t_bclst **lst, void (*del)(void *))
{
	t_bclst	*sentry;
	t_bclst	*tmp;

	if (!del || !lst || !*lst)
		return ;
	sentry = bclstsentry(*lst);
	while (sentry->next->content != NULL)
	{
		tmp = sentry->next->next;
		bclstdelone(sentry->next, del);
		free(sentry->next);
		sentry->next = tmp;
	}
	free(sentry);
}
