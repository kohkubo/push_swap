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
	int index = 0;

	p = ft_xcalloc(sizeof(p));
	p->num = 1;
	p->index = index++;
	t_bclst *lst = bclstinit(bclstnew(p));
	// printf("%p\n", lst);
	// printf("back %p\n", lst->back);
	// printf("next %p\n", lst->next);
	// printf("%p\n", lst->content);

	p = ft_xcalloc(sizeof(p));
	p->num = 2;
	p->index = index++;
	bclstadd_back(&lst, bclstnew(p));
	// print_content(lst->content);
	// print_content(lst->next->content);
	// print_content(lst->next->next->content);
	p = ft_xcalloc(sizeof(p));
	p->num = 3;
	p->index = index++;
	bclstadd_back(&lst, bclstnew(p));


	int num = 4;
	for(int i=0; i<10; i++)
	{
		p = ft_xcalloc(sizeof(p));
		p->num = num++;
		p->index = index++;
		bclstadd_back(&lst, bclstnew(p));
	}

	bclstiter(lst, print_content);
	printf("%d\n", bclstsize(lst));

	bclstclear(&lst, free);
	printf("%d\n", bclstsize(lst));
	// bclstiter(lst, print_content);
	return (0);
}

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

__attribute__((destructor))
void    destructor(void)
{
    int status;
    status = system("leaks a.out &> leaksout");
    if (status)
    {
        write(2, "leak!!!\n", 8);
        system("cat leaksout >/dev/stderr");
        exit(1);
    }
	else
	{
		system("rm leaksout");
		printf("no leaks\n");
	}
}