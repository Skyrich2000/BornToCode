#include "debug/debug_parse.h"

void    print_token(t_token *token)
{
    char *c;

    if (token->type == T_ARG)
        c = "T_ARG";
    else if (token->type == T_LEFT_REDIR)
        c = "T_LEFT_REDIR";
    else if (token->type == T_RIGHT_REDIR)
        c = "T_RIGHT_REDIR";
    else if (token->type == T_LEFT_DOUBLE_REDIR)
        c = "T_LEFT_DOUBLE_REDIR";
    else if (token->type == T_RIGHT_DOUBLE_REDIR)
        c = "T_RIGHT_DOUBLE_REDIR";
    else
        c = "T_PIPE";
    printf("    {type: %s, value: %s}\n", c, token->value);
}

void    print_token_list(t_list *tokens)
{
    t_list  *node;

    node = tokens->next;
    printf("[\n");
    while (node)
    {
        print_token(node->data);
        node = node->next;
    }
    printf("]\n");
}

void	print_pp(char **arr)
{
	int idx;

	idx = -1;
	while (arr[++idx])
	{
		printf("{line[%d] : %s}\n", idx, arr[idx]);
	}
}
