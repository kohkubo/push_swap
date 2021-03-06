#include "push_swap.h"

void	display_array(char **array)
{
	while (*array)
		printf("%s ", *array++);
	printf("\n");
}

void	display_int_arr(int arr[], int arr_len)
{
	printf("%d", arr[0]);
	for (int i = 1; i < arr_len; i++)
		printf(" %d", arr[i]);
	printf("\n");
}

void	print_content(void *p)
{
	if (p != NULL)
		printf("index %d : num %d\n", ((t_content *)p)->index, ((t_content *)p)->n);
	else
		printf("(null)\n");
}

void	print_content2(void *p)
{
	if (p != NULL)
		printf("%d\n", ((t_content *)p)->n);
	else
		printf("(null)\n");
}

void	print_ab(void *a, void *b)
{
	t_content *acon = (t_content *)a;
	t_content *bcon = (t_content *)b;
	if (!a)
		printf("%5s[  ]g[  ]gc[ ] | %5d[%2d]g[%2d]gc[%d]\n", " ", bcon->n, bcon->index, bcon->group, bcon->gcount);
	else if (!b)
		printf("%5d[%2d]g[%2d]gc[%d] | %5s[  ]g[  ]gc[ ]\n", acon->n, acon->index, acon->group, acon->gcount, " ");
	else
		printf("%5d[%2d]g[%2d]gc[%d] | %5d[%2d]g[%2d]gc[%d]\n", acon->n, acon->index, acon->group, acon->gcount, bcon->n, bcon->index, bcon->group, bcon->gcount);
}

void	ps_print(t_bclst *lst_a, t_bclst *lst_b)
{
	t_bclst *tmp_a;
	t_bclst *tmp_b;

	tmp_a = bclstfirst(lst_a);
	tmp_b = bclstfirst(lst_b);

	printf("=================\n");
	printf("%9s | %s\n", "a", "b");
	printf("-----------------\n");
	while (tmp_a->content != NULL || tmp_b->content != NULL)
	{
		print_ab(tmp_a->content, tmp_b->content);
		if (tmp_a->content != NULL)
			tmp_a = tmp_a->next;
		if (tmp_b->content != NULL)
			tmp_b = tmp_b->next;
	}
	printf("=================\n");
}
