#include "include/fur.h"
#include "include/lexer.h"
#include "include/parser.h"
#include "include/io.h"
#include <stdlib.h>

void fur_compile(char* src)
{
    lexer_T* lexer = init_lexer(src);
    parser_T* parser = init_parser(lexer);
    AST_T* root = parser_parse(parser);
    printf("%p\n", root);
    token_T* tok = 0;

    while ((tok = lexer_next_token(lexer))->type != TOKEN_EOF)
    {
        printf("%s\n", token_to_str(tok));
    }
}

void fur_compile_file(const char* filename)
{
    char* src = fur_read_file(filename);
    fur_compile(src);
    free (src);
}

 