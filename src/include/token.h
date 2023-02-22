#ifndef FUR_TOKEN_H
#define FUR_TOKEN_H

typedef struct TOKEN_STRUCT
{
    char* value;
    enum 
    {
        TOKEN_ID,
        TOKEN_EQUALS,
        TOKEN_RPAREN,
        TOKEN_LBRACE,
        TOKEN_RBRACE, 
        TOKEN_LPAREN,
        TOKEN_COLON,
        TOKEN_COMMA,
        TOKEN_LT,
        TOKEN_GT, 
        TOKEN_RIGHT_ARROW,
        TOKEN_INT,
        TOKEN_SEMI,
        TOKEN_EOF,
    } type;
} token_T;

token_T* init_token(int type, char* value);

const char* token_type_to_string(int type);

char* token_to_str(token_T* token);

#endif