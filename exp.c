#include "lexer.h"
#include "exp.h"

Token *proximo_token() {
  return yylex();
}

void imprime_token( Token *tok) {
  printf("\n");
  switch (tok->tipo) {
    case 0:
      printf("<TOKEN_NUM,%d", tok->valor);
      break;
    case 1:
      switch (tok->valor) {
        case 0:
          printf("<TOKEN_OP,+>");
          break;
        case 1:
          printf("<TOKEN_OP,->");
          break;
        case 2:
          printf("<TOKEN_OP,*>");
          break;
        case 3:
          printf("<TOKEN_OP,/>");
          break;
        default:
          break;
      }
      break;
    case 2:
      switch (tok->valor) {
        case 0:
          printf("<TOKEN_PONT,(>");
          break;
        case 1:
          printf("<TOKEN_PONT,)>");
          break;

        default:
          break;
      }
      break;
    case 3:
      printf("<TOKEN_ERRO,->");
      break;
    
    case 4:
      printf("<TOKEN_ID,%d>",tok->valor);
      break;

    case 5:
      switch (tok->valor){
        case 1:
          printf("<TOKEN_RELOP,>>");
          break;

        case 2:
          printf("<TOKEN_RELOP,<>");
          break;

        case 3:
          printf("<TOKEN_RELOP,>=>");
          break;

        case 4:
          printf("<TOKEN_RELOP,<=>");
          break;

        case 5:
          printf("<TOKEN_RELOP,=>");
          break;

        case 6:
          printf("<TOKEN_RELOP,<>>");
          break;

        default:
          break;
      }
      break;
    case 7:
      printf("<TOKEN_IF,->");
      break;
    case 8:
      printf("<TOKEN_THEN,->");
      break;
    case 9:
      printf("<TOKEN_ELSE,->");
      break;
    
  }
  printf("\n");
}

int main(int argc, char **argv) {
  Token *tok;

  char entrada[50];
  printf("\nAnalise Lexica do arquivo: ");
  fgets(entrada,50,stdin);
  FILE *fp;
  fp = fopen(entrada, "r");
  yyin = fp;

  tok = proximo_token();
  while (tok != NULL) {
    imprime_token(tok);
    tok = proximo_token();
  }

  return 0;

}