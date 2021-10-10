#include "core/parse.h"
#include "utils/utils.h"
#include "debug/debug_parse.h"

int parse(char *line, t_list *cmds)
{
    t_list  *tokens;
    char    **strings;

    tokens = init_list();
    tokenizer(line, &strings);
    lexer(strings, tokens);
    parser(tokens, cmds);
    ft_split_free(strings);
    free_list(tokens, NULL);
    return (OK);
}

static t_cmd    *init_cmd()
{
    t_cmd   *cmd;

    cmd = malloc(sizeof(t_cmd));
    if (!cmd)
        exit(12);
    cmd->args = init_list();
    cmd->rd_in = init_list();
    cmd->rd_out = init_list();
    return (cmd);
}

/**
 * cmd 객체를 만든다
 * T_ARG 면, args 에 넣고,
 * T_LEFT_REDIR 면, rd_in 에 넣고,
 * T_RIGHT_REDIR 면, rd_out 에 넣는다.
 * T_PIPE 나오면 cmd 객체 새로 만들고 반복..
 *
 * @example tokens : [
 *  {type: T_ARG, value: 'echo'},
 *  {type: T_ARG, value: 'hello'},
 *  {type: T_RIGHT_REDIR, value: 'abc'},
 *  {type: T_PIPE, value: null},
 *  {type: T_CMD, value: 'cat'},
 *  {type: T_LEFT_REDIR, value: 'abc'},
 * ]
 * @example cmds : [
 *  {
 *    args: [{type: T_ARG, value: 'echo'}, {type: T_ARG, value: 'hello'}]
 *    rd_in: []
 *    rd_out: [{type: T_RIGHT_REDIR, value: 'abc'}]
 *  },
 *  {
 *    args: [{type: T_CMD, value: 'cat'}]
 *    rd_in: [{type: T_LEFT_REDIR, value: 'abc'}]
 *    rd_out: []
 *  }
 * ]
 *
 */
int parser(t_list *tokens, t_list *cmds)
{
    t_list  *node;
    t_cmd   *cmd;
    t_token *token;

    node = tokens->next;
    while (node)
    {
        cmd = init_cmd();
        while (node && ((t_token *)node->data)->type != T_PIPE)
        {
            token = node->data;
            if (token->type == T_ARG)
                push_list(cmd->args, (void *)token);
            else if (token->type == T_LEFT_REDIR || token->type == T_LEFT_DOUBLE_REDIR)
                push_list(cmd->rd_in, (void *)token);
            else
                push_list(cmd->rd_out, (void *)token);
            node = node->next;
        }
        push_list(cmds, (void *)cmd);
        if (node)
            node = node->next;
    }
    return (OK);
}
