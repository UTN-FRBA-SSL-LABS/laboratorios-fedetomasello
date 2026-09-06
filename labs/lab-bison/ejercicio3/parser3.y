%{
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int  yylex(void);
void yyerror(const char *msg) { fprintf(stderr, "Error: %s\n", msg); }
%}

%token NUM
%token POW
%token UMINUS

/*
 * Sin declaraciones de precedencia, esta gramatica tiene multiples
 * conflictos shift/reduce: Bison no sabe si "2 + 3 * 4" es
 * "(2+3)*4" o "2+(3*4)".
 *
 * Las declaraciones %left / %right resuelven esos conflictos:
 *   - Las que aparecen MAS ABAJO tienen MAYOR precedencia.
 *   - %left  = asociatividad izquierda: a - b - c  se lee  (a-b)-c
 *   - %right = asociatividad derecha:  a ** b ** c se lee  a**(b**c)
 *   - UMINUS es un token ficticio para darle precedencia al menos unario.
 */

%left  '+' '-'
%left  '*' '/'
%right POW
%right UMINUS

%%

input:
    /* vacio */
  | input linea
  ;

linea:
    exp '\n'   { printf("= %d\n", $1); }
  ;

exp:
    exp '+' exp           { $$ = $1 + $3; }
  | exp '-' exp           { $$ = $1 - $3; }
  | exp '*' exp           { $$ = $1 * $3; }
  | exp '/' exp           { $$ = $1 / $3; }
  | exp POW exp           { $$ = (int)pow($1, $3); }
  | '-' exp %prec UMINUS  { $$ = -$2; }
  | '(' exp ')'           { $$ = $2; }
  | NUM                   { $$ = $1; }
  ;

%%

int main(void) {
    return yyparse();
}