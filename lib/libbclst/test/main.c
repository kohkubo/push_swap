#include "./../libbclst.h"

#include <stdio.h>

typedef struct s_content
{
	int num;
	int index;
}	t_content;


void	print_content(void *p)
{
	if (p != NULL)
		printf("%d : %d\n", ((t_content *)p)->index, ((t_content *)p)->num);
	else
		printf("(null)\n");
}

int main()
{
	t_content *p;

	p = ft_xcalloc(sizeof(p));
	p->num = 1;
	p->index = 0;
	t_bclst *lst = bclstinit(bclstnew(p));
	// printf("%p\n", lst);
	// printf("back %p\n", lst->back);
	// printf("next %p\n", lst->next);
	// printf("%p\n", lst->content);

	p = ft_xcalloc(sizeof(p));
	p->num = 2;
	p->index = 1;
	bclstadd_back(&lst, bclstnew(p));
	// print_content(lst->content);
	// print_content(lst->next->content);
	// print_content(lst->next->next->content);
	p = ft_xcalloc(sizeof(p));
	p->num = 3;
	p->index = 2;
	bclstadd_back(&lst, bclstnew(p));

	bclstiter(lst, print_content);
	printf("%d\n", bclstsize(lst));
	return (0);
}