#ifndef Y_TAB_H
#define Y_TAB_H

typedef struct {
    int posColumna;
    int posFila;
    int intValor;
    char *stringValor;
} YYSTYPE;

#define	ID	                    258
#define COMENTARIO              259
#define TOKEN_INT               260
#define TOKEN_ASIGNACION        261
#define TOKEN_ENTERO            262
#define TOKEN_FINALINSTRUCCION  263
#define TOKEN_MAIN              264
#define TOKEN_VOID              265
#define TOKEN_PARENTESISIZQ     266
#define TOKEN_PARENTESISDER     267
#define TOKEN_CORCHETEIZQ       268
#define TOKEN_CORCHETEDER       269
#define TOKEN_COMA              270
#define TOKEN_RETURN            271
#define TOKEN_IF                272
#define TOKEN_ELSEIF            273
#define TOKEN_ELSE              274
#define TOKEN_WHILE             275
#define TOKEN_DEF               276
#define TOKEN_DOSPUNTOS         277
#define TOKEN_NUEVALINEA        278
#define TOKEN_TABULADOR         279
#define TOKEN_CONTROL           280
#define TOKEN_CODASCII          281
#define TOKEN_COMILLASIMPLE     282
#define TOKEN_DIAGONALINVERSA   283
#define TOKEN_OPMAS             284
#define TOKEN_OPMENOS           285
#define TOKEN_OPMULTI           286
#define TOKEN_OPDIV             287
#define TOKEN_OPIGUAL           288
#define TOKEN_OPMENOR           289
#define TOKEN_OPMAYOR           290
#define TOKEN_OPMAYORIGUAL      291
#define TOKEN_OPMENORIGUAL      292
#define TOKEN_BOOLAND           293
#define TOKEN_BOOLOR            294

extern YYSTYPE yylval;
#endif
