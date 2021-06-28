#include "push_swap.h"

void	sort_three()
{
	int num[3];

	num[0] = st()->n[A][HEAD]->link[NEXT]->data;
	num[1] = st()->n[A][HEAD]->link[NEXT]->link[NEXT]->data;
	num[2] = st()->n[A][HEAD]->link[NEXT]->link[NEXT]->link[NEXT]->data;
	if (num[0] < num[1] && num[0] < num[2] && num[1] < num[2])
		return ;
	else if (num[0] < num[1] && num[2] < num[0] && num[2] < num[1])
		rr(A);
	else if (num[1] < num[0] && num[2] < num[0] && num[1] < num[2])
		r(A);
	else
		s(A);
	sort_three();
}

void	sort_five()
{
	int i;

	p(B);
	p(B);
	sort_three();
	if (st()->n[B][HEAD]->link[NEXT]->data >
		st()->n[B][HEAD]->link[NEXT]->link[NEXT]->data)
		s(B);
	i = 0;
	while (i++ < 5)
	{
		if (st()->n[A][HEAD]->link[NEXT]->data < st()->n[B][HEAD]->link[NEXT]->data)
			r(A);
		else
		{
			p(A);
			r(A);
		}
	}
}
