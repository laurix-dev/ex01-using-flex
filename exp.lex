%option noyywrap
%option nodefault
%option outfile="lexer.c" header-file="lexer.h"

%{
  #include "exp.h"
%}

INTEIRO [0-9]+
LETRA_ [A-Za-z_]
ID {LETRA_}({LETRA_}|{INTEIRO})*
FRACAO (\.{INTEIRO})?
EXPOENTE (E[+-]?{INTEIRO})?
FLOAT {INTEIRO}{FRACAO}{EXPOENTE}
COMENTARIO /\**.\./

%%

if { return token(TOK_IF, NULL); }
then { return token(TOK_THEN, NULL); }
else { return token(TOK_ELSE, NULL); }
[[:space:]] | \t | \n | {COMENTARIO} { } /* ignora espaços, tabulaçóes, nova linha e comentários */
{ID} { return token(TOK_ID, atoi(yytext)); }
{INTEIRO} { return token(TOK_NUM, atoi(yytext)); }
\> { return token(TOK_RELOP, MAIOR); }
\< { return token(TOK_RELOP, MENOR); }
\>= { return token(TOK_RELOP, MAIOR_IGUAL); }
\<= { return token(TOK_RELOP, MENOR_IGUAL); }
\= { return token(TOK_RELOP, IGUAL); }
\<> { return token(TOK_RELOP, DIFERENTE); }
\+ { return token(TOK_OP, SOMA); }
- { return token(TOK_OP, SUB); }
\* { return token(TOK_OP, MULT); }
\/ { return token(TOK_OP, DIV); }
\( { return token(TOK_PONT, PARESQ); }
\) { return token(TOK_PONT, PARDIR); }
<<EOF>> { return NULL; }
. { return token(TOK_ERRO, 0); } 

%%

Token tok;
Token * token (int tipo, int valor) {
  tok.tipo = tipo;
  tok.valor = valor;
  return &tok;
}
