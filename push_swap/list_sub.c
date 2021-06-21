#include "push_swap.h"

static void	_print_list(char *prefix, int pos)
{
	t_node *node;

	printf("%s", prefix);
	node = st()->n[pos >> 1][pos & 1]->link[next];
	while (node->link[next])
	{
		printf("%d ", node->data);
		node = node->link[next];
	}
	printf("\n");
}

void	print_list(char *prefix)
{
	printf("%s\n", prefix);
	_print_list("a : ", A|head);
	_print_list("b : ", B|head);
}

void	free_list(t_node *node)
{
	if (node->link[next])
		free_list(node->link[next]);
	free(node);
}
