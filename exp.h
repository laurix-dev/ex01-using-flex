// constantes booleanas
#define TRUE 1
#define FALSE 0

// constantes para nome de token
#define TOK_NUM 0
#define TOK_OP 1
#define TOK_PONT 2
#define TOK_ERRO 3
#define TOK_ID 4
#define TOK_RELOP 5
#define TOK_EOF 6
#define TOK_IF 7
#define TOK_THEN 8
#define TOK_ELSE 9

// constantes para operadores
#define SOMA 0
#define SUB 1
#define MULT 2
#define DIV 3

// constantes para parenteses
#define PARESQ 0
#define PARDIR 1

// constantes para relacionais
#define MAIOR 1
#define MENOR 2
#define MAIOR_IGUAL 3
#define MENOR_IGUAL 4
#define IGUAL 5
#define DIFERENTE 6

// estrutura de um token
typedef struct {
  int tipo;
  int valor;
} Token;

// funcao para criar um token
extern Token *token();

// funcao do analisador lexico
extern Token *yylex();