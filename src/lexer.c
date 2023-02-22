#include "include/macros.h"
#include "include/lexer.h"
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

lexer_T* init_lexer(char* src)
{
    lexer_T* lexer = calloc(1, sizeof(struct LEXER_STRUCT));
    lexer->src = src;
    lexer->size_src = strlen(src);
    lexer->i = 0;
    lexer->c = lexer->src[lexer->i];

    return lexer;
}

void lexer_advance(lexer_T* lexer)
{
    if (lexer->i < lexer->size_src && lexer->c != '\0')
    {
        lexer->i += 1;
        lexer->c = lexer->src[lexer->i];
    }
}

char lexer_peek(lexer_T* lexer, int offset)
{
    return lexer->src[MIN(lexer->i + offset, lexer->size_src)];
}

token_T* lexer_advance_with(lexer_T* lexer, token_T* token)
{
    lexer_advance(lexer);
    return token;
}

token_T* lexer_advance_current(lexer_T* lexer, int type)
{
    char* value = calloc(2, sizeof(char));
    value[0] = lexer->c;
    value[1] = '\0';

    token_T* token = init_token(type, value);
    lexer_advance(lexer);

    return token;
}

void lexer_skip_whitespace(lexer_T* lexer)
{
    while (lexer->c == 13 || lexer->c == 10 || lexer->c == ' ' || lexer->c == '\t')
    {
        lexer_advance(lexer);
    }   
}

token_T* lexer_parse_id(lexer_T* lexer)
{
    char* value = calloc(1, sizeof(char));
    while (isalnum(lexer->c))
    {
        value = realloc(value, (strlen(value) + 3) * sizeof(char));
        strcat(value, (char[]){lexer->c, 0});
        lexer_advance(lexer);
    }

    return init_token(TOKEN_ID, value);
}

token_T* lexer_parse_number(lexer_T* lexer)
{
    char* value = calloc(1, sizeof(char));
    while (isdigit(lexer->c))
    {
        value = realloc(value, (strlen(value) + 3) * sizeof(char));
        strcat(value, (char[]){lexer->c, 0});
        lexer_advance(lexer);
    }

    return init_token(TOKEN_INT, value);
}

token_T* lexer_next_token(lexer_T* lexer)
{
    while (lexer->c != '\0')
    {
        lexer_skip_whitespace(lexer);
        if(isalpha(lexer->c))
            return lexer_advance_with(lexer, lexer_parse_id(lexer));

        if(isdigit(lexer->c))
            return lexer_advance_with(lexer, lexer_parse_number(lexer));

        switch (lexer->c)
        {
            case '=': {
                if (lexer_peek(lexer, 1) == '>') lexer_advance_with(lexer, init_token(TOKEN_RIGHT_ARROW, "=>"));
                return lexer_advance_with(lexer, init_token(TOKEN_EQUALS, "="));
            } break;
            case '(': return lexer_advance_current(lexer, TOKEN_LPAREN); break;
            case ')': return lexer_advance_current(lexer, TOKEN_RPAREN); break;
            case '{': return lexer_advance_current(lexer, TOKEN_LBRACE); break;
            case '}': return lexer_advance_current(lexer, TOKEN_RBRACE); break;
            case ':': return lexer_advance_current(lexer, TOKEN_COLON); break;
            case ',': return lexer_advance_current(lexer, TOKEN_COMMA); break;
            case '<': return lexer_advance_current(lexer, TOKEN_LT); break;
            case '>': return lexer_advance_current(lexer, TOKEN_GT); break;
            case ';': return lexer_advance_current(lexer, TOKEN_SEMI); break;
            case '\0': break;
            default: printf("[LEXER] Unexpected character `%c`\n", lexer->c); exit(1); break;
        }
    }

    return init_token(TOKEN_EOF, 0);
}



