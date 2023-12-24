%option yylineno

%{
    #include <string.h>
    #include "util.h"
    #include "y.tab.h"
    #include "errormsg.h"

    int charPos = 1;
    int columna = 1;
    int fila = 0;

    extern YYSTYPE yylval;

    char* captureComment(char* text) {
        text[strlen(text) - 3] = '\0';  // Elimina los caracteres "---"
        return strdup(text + 3);
    }

    int yywrap(void) {
        charPos=1;
        return 1;
    }

    #define MAX_STR_CONST   256
    char string_buf[MAX_STR_CONST];
    char *string_buf_ptr;

    void adjust(void) {
        EM_tokPos = charPos;
        charPos += yyleng;
    }
    
    char bufer[256];char *apbufer;
%}

ID      	        [_]*[a-zA-Z][a-zA-Z0-9_]*
TIPOINT             "int"
ASIGNACION          "="
ENTERO              "-"[0-9]+|"+"[0-9]+|[0-9]+
FINALINSTRUCCION    ";"
MAIN                "main"
TIPOVACIO           "void"
PARENTESISIZQ       "("
PARENTESISDER       ")"
CORCHETEIZQ         "{"
CORCHETEDER         "}"
COMA                ","
RETURN              "return"
IF                  "if"
ELSEIF              "elseif"
ELSE                "else"
WHILE               "while"
DEF                 "def"
INICIOFUNCION       ":"
NUEVALINEA          "\\n"
TABULADOR           "\\t"
CONTROL             "\\^c"
ASCII               "\\"[0-7][0-7][0-7]
COMILLASIM          "\\'"
DIAGINVERSA         "\\"
OPMAS               "+"
OPMENOS             "-"
OPMULTI             "*"
OPDIV               "/"
OPIGUAL             "=="
OPMENOR             "<"
OPMAYOR             ">"
OPMAYORIGUAL        ">="
OPMENORIGUAL        "<="
BOOLAND             "&"
BOOLOR              "|"


%%
{TIPOINT}       {
                    columna += yyleng;
                    yylval.posColumna = columna;
                    yylval.posFila = yylineno;
					yylval.stringValor = strdup(yytext);
					return TOKEN_INT;
				}

{ASIGNACION}    {
                    columna += yyleng;
                    yylval.posColumna = columna;
                    yylval.posFila = yylineno;
					yylval.stringValor = strdup(yytext);
					return TOKEN_ASIGNACION;
				}

{ENTERO}       {
                    columna += yyleng;
                    yylval.posColumna = columna;
                    yylval.posFila = yylineno;
					yylval.intValor = atoi(yytext);
					return TOKEN_ENTERO;
				}

{FINALINSTRUCCION} {
                    columna += yyleng;
                    yylval.posColumna = columna;
                    yylval.posFila = yylineno;
					yylval.stringValor = strdup(yytext);
					return TOKEN_FINALINSTRUCCION;
				}

{MAIN}          {
                    columna += yyleng;
                    yylval.posColumna = columna;
                    yylval.posFila = yylineno;
					yylval.stringValor = strdup(yytext);
					return TOKEN_MAIN;
				}

{TIPOVACIO}     {
                    columna += yyleng;
                    yylval.posColumna = columna;
                    yylval.posFila = yylineno;
					yylval.stringValor = strdup(yytext);
					return TOKEN_VOID;
				}

{PARENTESISIZQ} {
                    columna += yyleng;
                    yylval.posColumna = columna;
                    yylval.posFila = yylineno;
					yylval.stringValor = strdup(yytext);
					return TOKEN_PARENTESISIZQ;
				}

{PARENTESISDER} {
                    columna += yyleng;
                    yylval.posColumna = columna;
                    yylval.posFila = yylineno;
					yylval.stringValor = strdup(yytext);
					return TOKEN_PARENTESISDER;
				}

{CORCHETEIZQ}   {
                    columna += yyleng;
                    yylval.posColumna = columna;
                    yylval.posFila = yylineno;
					yylval.stringValor = strdup(yytext);
					return TOKEN_CORCHETEIZQ;
				}

{CORCHETEDER}   {
                    columna += yyleng;
                    yylval.posColumna = columna;
                    yylval.posFila = yylineno;
					yylval.stringValor = strdup(yytext);
					return TOKEN_CORCHETEDER;
				}

{COMA}          {
                    columna += yyleng;
                    yylval.posColumna = columna;
                    yylval.posFila = yylineno;
					yylval.stringValor = strdup(yytext);
					return TOKEN_COMA;
				}

{RETURN}        {
                    columna += yyleng;
                    yylval.posColumna = columna;
                    yylval.posFila = yylineno;
					yylval.stringValor = strdup(yytext);
					return TOKEN_RETURN;
				}

{IF}            {
                    columna += yyleng;
                    yylval.posColumna = columna;
                    yylval.posFila = yylineno;
					yylval.stringValor = strdup(yytext);
					return TOKEN_IF;
				}

{ELSEIF}        {
                    columna += yyleng;
                    yylval.posColumna = columna;
                    yylval.posFila = yylineno;
					yylval.stringValor = strdup(yytext);
					return TOKEN_ELSEIF;
				}

{ELSE}          {
                    columna += yyleng;
                    yylval.posColumna = columna;
                    yylval.posFila = yylineno;
					yylval.stringValor = strdup(yytext);
					return TOKEN_ELSE;
				}

{WHILE}         {
                    columna += yyleng;
                    yylval.posColumna = columna;
                    yylval.posFila = yylineno;
					yylval.stringValor = strdup(yytext);
					return TOKEN_WHILE;
				}

{DEF}          {
                    columna += yyleng;
                    yylval.posColumna = columna;
                    yylval.posFila = yylineno;
					yylval.stringValor = strdup(yytext);
					return TOKEN_DEF;
				}

{INICIOFUNCION} {
                    columna += yyleng;
                    yylval.posColumna = columna;
                    yylval.posFila = yylineno;
					yylval.stringValor = strdup(yytext);
					return TOKEN_DOSPUNTOS;
				}

{NUEVALINEA}    {
                    columna += yyleng;
                    yylval.posColumna = columna;
                    yylval.posFila = yylineno;
					yylval.stringValor = strdup(yytext);
					return TOKEN_NUEVALINEA;
				}

{TABULADOR}     {
                    columna += yyleng;
                    yylval.posColumna = columna;
                    yylval.posFila = yylineno;
					yylval.stringValor = strdup(yytext);
					return TOKEN_TABULADOR;
				}

{CONTROL}       {
                    columna += yyleng;
                    yylval.posColumna = columna;
                    yylval.posFila = yylineno;
					yylval.stringValor = strdup(yytext);
					return TOKEN_CONTROL;
				}

{ASCII}         {
                    columna += yyleng;
                    yylval.posColumna = columna;
                    yylval.posFila = yylineno;
					yylval.stringValor = strdup(yytext);
					return TOKEN_CODASCII;
				}

{COMILLASIM}    {
                    columna += yyleng;
                    yylval.posColumna = columna;
                    yylval.posFila = yylineno;
					yylval.stringValor = strdup(yytext);
					return TOKEN_COMILLASIMPLE;
				}

{DIAGINVERSA}   {
                    columna += yyleng;
                    yylval.posColumna = columna;
                    yylval.posFila = yylineno;
					yylval.stringValor = strdup(yytext);
					return TOKEN_DIAGONALINVERSA;
				}

{OPMAS}         {
                    columna += yyleng;
                    yylval.posColumna = columna;
                    yylval.posFila = yylineno;
					yylval.stringValor = strdup(yytext);
					return TOKEN_OPMAS;
				}

{OPMENOS}       {
                    columna += yyleng;
                    yylval.posColumna = columna;
                    yylval.posFila = yylineno;
					yylval.stringValor = strdup(yytext);
					return TOKEN_OPMENOS;
				}

{OPMULTI}       {
                    columna += yyleng;
                    yylval.posColumna = columna;
                    yylval.posFila = yylineno;
					yylval.stringValor = strdup(yytext);
					return TOKEN_OPMULTI;
				}

{OPDIV}         {
                    columna += yyleng;
                    yylval.posColumna = columna;
                    yylval.posFila = yylineno;
					yylval.stringValor = strdup(yytext);
					return TOKEN_OPDIV;
				}

{OPIGUAL}       {
                    columna += yyleng;
                    yylval.posColumna = columna;
                    yylval.posFila = yylineno;
					yylval.stringValor = strdup(yytext);
					return TOKEN_OPIGUAL;
				}

{OPMENOR}       {
                    columna += yyleng;
                    yylval.posColumna = columna;
                    yylval.posFila = yylineno;
					yylval.stringValor = strdup(yytext);
					return TOKEN_OPMENOR;
				}

{OPMAYOR}       {
                    columna += yyleng;
                    yylval.posColumna = columna;
                    yylval.posFila = yylineno;
					yylval.stringValor = strdup(yytext);
					return TOKEN_OPMAYOR;
				}

{OPMAYORIGUAL}  {
                    columna += yyleng;
                    yylval.posColumna = columna;
                    yylval.posFila = yylineno;
					yylval.stringValor = strdup(yytext);
					return TOKEN_OPMAYORIGUAL;
				}

{OPMENORIGUAL}  {
                    columna += yyleng;
                    yylval.posColumna = columna;
                    yylval.posFila = yylineno;
					yylval.stringValor = strdup(yytext);
					return TOKEN_OPMENORIGUAL;
				}

{BOOLAND}       {
                    columna += yyleng;
                    yylval.posColumna = columna;
                    yylval.posFila = yylineno;
					yylval.stringValor = strdup(yytext);
					return TOKEN_BOOLAND;
				}

{BOOLOR}        {
                    columna += yyleng;
                    yylval.posColumna = columna;
                    yylval.posFila = yylineno;
					yylval.stringValor = strdup(yytext);
					return TOKEN_BOOLOR;
				}

{ID} 			{
                    columna += yyleng;
                    yylval.posColumna = columna;
                    yylval.posFila = yylineno;
					yylval.stringValor = strdup(yytext);
					return ID;
				}
                
"---"([^-]|-[^-]|--[^-])*"---" {
                    char* comment = captureComment(yytext);
                    printf("Comentario:\n%s\n", comment); // Imprime el comentario capturado
                    yylval.stringValor = comment;
                    return COMENTARIO;  // Devuelve el token COMENTARIO  
                }

" "             {
                    columna += yyleng;
                    continue;
                }

\n              {
                    columna = 1;
                    fila = 0;
                    continue;
                }
    

.               {
                    printf("Token ilegal encontrado en linea %d posición %d: %s\n",yylineno, columna, yytext);
                    columna += yyleng;
                }
