#include <stdio.h>
#include <stdlib.h>
#include "util.h"
#include "errormsg.h"
#include "y.tab.h"

YYSTYPE yylval;

int yylex(void); /* prototype for the lexing function */

string toknames[] = {"ID", "COMENTARIO", "INT","ASIGNACION", "ENTERO", 
                    "FININSTRUCCION", "MAIN", "VOID", "PARENTESISIZQ", "PARENTESISDER",
                    "CORCHETEIZQ", "CORCHETEDER", "COMA", "RETURN", "IF", "ELSEIF", "ELSE",
                    "WHILE", "DEF", "INICIOFUNCION", "SALTOLINEA", "TABULADOR", "CARACTERCONTROL", 
                    "CODIDOASCII", "COMILLASIMPLE", "DIAGONALINVERSA", "OPSUMA", "OPRESTA",
                    "OPMULTIPLICACION", "OPDIVISION", "OPIGUAL", "OPMENOR", "OPMAYOR",
                    "OPMAYORIGUAL", "OPMENORIGUAL", "OPBOOLAND", "OPBOOLOR"};

string tokname(int tok) {
    return tok<258 || tok>299 ? "TOKEN NO VALIDO" : toknames[tok-258];
}

int main(int argc, char **argv) {
    //YYSTYPE *yylval_local = &yylval;
    string fname; 
    int tok;

    if (argc != 2) {
        fprintf(stderr,"uso: driver archivo.simple\n"); 
        exit(1);
    }
  
    fname=argv[1];

    EM_reset(fname);

    for(;;) {
        tok=yylex();
        //printf("tok: %d", tok);
        if (tok==0) {
            break;
        } 
        
        else if(tok <= 255) {
            printf("%c \n",tok);
        }
      
        else{
            switch (tok) {
                case ID:
                    printf("Token %s en linea %d posicion %d: %s\n", tokname(tok), yylval.posFila, yylval.posColumna, yylval.stringValor);
                    break;
                case COMENTARIO:
                    break;
                case TOKEN_INT:
                    printf("Token %s en linea %d posicion %d: %s\n", tokname(tok), yylval.posFila, yylval.posColumna, yylval.stringValor);
                    break;
                case TOKEN_ASIGNACION:
                    printf("Token %s en linea %d posicion %d: %s\n", tokname(tok), yylval.posFila, yylval.posColumna, yylval.stringValor);
                    break;
                case TOKEN_ENTERO:
                    printf("Token %s en linea %d posicion %d: %d\n", tokname(tok), yylval.posFila, yylval.posColumna, yylval.intValor);
                    break;
                case TOKEN_FINALINSTRUCCION:
                    printf("Token %s en linea %d posicion %d: %s\n", tokname(tok), yylval.posFila, yylval.posColumna, yylval.stringValor);
                    break;
                case TOKEN_MAIN:
                    printf("Token %s en linea %d posicion %d: %s\n", tokname(tok), yylval.posFila, yylval.posColumna, yylval.stringValor);
                    break;
                case TOKEN_VOID:
                    printf("Token %s en linea %d posicion %d: %s\n", tokname(tok), yylval.posFila, yylval.posColumna, yylval.stringValor);
                    break;
                case TOKEN_PARENTESISIZQ:
                    printf("Token %s en linea %d posicion %d: %s\n", tokname(tok), yylval.posFila, yylval.posColumna, yylval.stringValor);
                    break;
                case TOKEN_PARENTESISDER:
                    printf("Token %s en linea %d posicion %d: %s\n", tokname(tok), yylval.posFila, yylval.posColumna, yylval.stringValor);
                    break;
                case TOKEN_CORCHETEIZQ:
                    printf("Token %s en linea %d posicion %d: %s\n", tokname(tok), yylval.posFila, yylval.posColumna, yylval.stringValor);
                    break;
                case TOKEN_CORCHETEDER:
                    printf("Token %s en linea %d posicion %d: %s\n", tokname(tok), yylval.posFila, yylval.posColumna, yylval.stringValor);
                    break;
                case TOKEN_COMA:
                    printf("Token %s en linea %d posicion %d: %s\n", tokname(tok), yylval.posFila, yylval.posColumna, yylval.stringValor);
                    break;
                case TOKEN_RETURN:
                    printf("Token %s en linea %d posicion %d: %s\n", tokname(tok), yylval.posFila, yylval.posColumna, yylval.stringValor);
                    break;
                case TOKEN_IF:
                    printf("Token %s en linea %d posicion %d: %s\n", tokname(tok), yylval.posFila, yylval.posColumna, yylval.stringValor);
                    break;
                case TOKEN_ELSEIF:
                    printf("Token %s en linea %d posicion %d: %s\n", tokname(tok), yylval.posFila, yylval.posColumna, yylval.stringValor);
                    break;
                case TOKEN_ELSE:
                    printf("Token %s en linea %d posicion %d: %s\n", tokname(tok), yylval.posFila, yylval.posColumna, yylval.stringValor);
                    break;
                case TOKEN_WHILE:
                    printf("Token %s en linea %d posicion %d: %s\n", tokname(tok), yylval.posFila, yylval.posColumna, yylval.stringValor);
                    break;
                case TOKEN_DEF:
                    printf("Token %s en linea %d posicion %d: %s\n", tokname(tok), yylval.posFila, yylval.posColumna, yylval.stringValor);
                    break;
                case TOKEN_DOSPUNTOS:
                    printf("Token %s en linea %d posicion %d: %s\n", tokname(tok), yylval.posFila, yylval.posColumna, yylval.stringValor);
                    break;
                case TOKEN_NUEVALINEA:
                    printf("Token %s en linea %d posicion %d: %s\n", tokname(tok), yylval.posFila, yylval.posColumna, yylval.stringValor);
                    break;
                case TOKEN_TABULADOR:
                    printf("Token %s en linea %d posicion %d: %s\n", tokname(tok), yylval.posFila, yylval.posColumna, yylval.stringValor);
                    break;
                case TOKEN_CONTROL:
                    printf("Token %s en linea %d posicion %d: %s\n", tokname(tok), yylval.posFila, yylval.posColumna, yylval.stringValor);
                    break;
                case TOKEN_CODASCII:
                    printf("Token %s en linea %d posicion %d: %s\n", tokname(tok), yylval.posFila, yylval.posColumna, yylval.stringValor);
                    break;
                case TOKEN_COMILLASIMPLE:
                    printf("Token %s en linea %d posicion %d: %s\n", tokname(tok), yylval.posFila, yylval.posColumna, yylval.stringValor);
                    break;
                case TOKEN_DIAGONALINVERSA:
                    printf("Token %s en linea %d posicion %d: %s\n", tokname(tok), yylval.posFila, yylval.posColumna, yylval.stringValor);
                    break;
                case TOKEN_OPMAS:
                    printf("Token %s en linea %d posicion %d: %s\n", tokname(tok), yylval.posFila, yylval.posColumna, yylval.stringValor);
                    break;
                case TOKEN_OPMENOS:
                    printf("Token %s en linea %d posicion %d: %s\n", tokname(tok), yylval.posFila, yylval.posColumna, yylval.stringValor);
                    break;
                case TOKEN_OPMULTI:
                    printf("Token %s en linea %d posicion %d: %s\n", tokname(tok), yylval.posFila, yylval.posColumna, yylval.stringValor);
                    break;
                case TOKEN_OPDIV:
                    printf("Token %s en linea %d posicion %d: %s\n", tokname(tok), yylval.posFila, yylval.posColumna, yylval.stringValor);
                    break;
                case TOKEN_OPIGUAL:
                    printf("Token %s en linea %d posicion %d: %s\n", tokname(tok), yylval.posFila, yylval.posColumna, yylval.stringValor);
                    break;
                case TOKEN_OPMENOR:
                    printf("Token %s en linea %d posicion %d: %s\n", tokname(tok), yylval.posFila, yylval.posColumna, yylval.stringValor);
                    break;
                case TOKEN_OPMAYOR:
                    printf("Token %s en linea %d posicion %d: %s\n", tokname(tok), yylval.posFila, yylval.posColumna, yylval.stringValor);
                    break;
                case TOKEN_OPMAYORIGUAL:
                    printf("Token %s en linea %d posicion %d: %s\n", tokname(tok), yylval.posFila, yylval.posColumna, yylval.stringValor);
                    break;
                case TOKEN_OPMENORIGUAL:
                    printf("Token %s en linea %d posicion %d: %s\n", tokname(tok), yylval.posFila, yylval.posColumna, yylval.stringValor);
                    break;
                case TOKEN_BOOLAND:
                    printf("Token %s en linea %d posicion %d: %s\n", tokname(tok), yylval.posFila, yylval.posColumna, yylval.stringValor);
                    break;
                case TOKEN_BOOLOR:
                    printf("Token %s en linea %d posicion %d: %s\n", tokname(tok), yylval.posFila, yylval.posColumna, yylval.stringValor);
                    break;
                default:
                    printf("%s \t\t\t en %d\n", tokname(tok), yylval.posFila);
            } 
        }
    }
    
    return 0;
}