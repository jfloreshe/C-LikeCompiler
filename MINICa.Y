/* Dise�o de las reglas de un MINIC */

%{

#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

int yylex();
typedef union { int entero;
		float real;
		char cadena[30];
		} tipovalor;
void IS(int , int);
void IBP(int );
void asignarParametros(int);
char lexema[80];
typedef struct {char nombre[30];
		int a1,a2,a4,a5,a6;  	// a1: INT/FLOAT	a2: FUN/VAR		a4: inicio de FUN a5:fin de FUN a6:nro parametros en FUN
		tipovalor a3; 	// guarda valor
	} tipoTablaSimbolo;

tipoTablaSimbolo TS[100], *pTS;
int nTS = 0;
int bufferParametros[100];
int iBP = -1;//indiceactual del buffer de parametros
int insertaSimbolo(char *, int);
int localizaSimbolo(char *);
void muestraSimbolo();
void imprimirCadena(char *);
int encontrarFuncionAsociada();
int tipoVar;

// Definici�n de la tabla de c�digo

typedef struct { int op,a1,a2,a3;}
	tipoCodigo;

tipoCodigo TABCOD[100];
int cx = -1; 		// indice de c�digo actual
int indicevartemp = 0;  	//n�mero de variables temporales
void genCodigo(int ,int ,int ,int );
int genvartemp();
void muestraCodigo();

void interprete();

// Definici�n de las operaciones de lenguaje intermedio

#define MOVER	1
#define SUMAR	2
#define SALTAR	3
#define SALTARV	4
#define SALTARF	5
#define MENOR	6
#define RESTAR       7 
#define MULTIPLICAR  8
#define DIVIDIR      9
#define MAYOR 		10
#define SALTARYREGRESAR 11

%}

%token INT FLOAT STRING FORMATO ID IF ELSE NUM REAL CADENA WHILE DO FOR FUNCION RETURN
%token LEER IMPRIMIR
%token CENTERO	
%token CFLOAT	
%token VAR
%right '='
%left '?'
%left OR	
%left AND	
%right NOT
%left IGUAL NOIGUAL MENORIGUAL MAYORIGUAL '<' '>'
%left '+' '-'
%left '*' '/'

%%

	programaC : listaDeclC ;
	listaDeclC : listaDeclC declC | ;
	declC : Tipo listaVar ';';
/*  declC : Tipo ID '('                     listaPar ')' bloque; */
	declC : Tipo ID '(' { IS($1,FUNCION); $$=localizaSimbolo(lexema);} listaPar ')' {genCodigo(SALTARV,$4,0,0);} 
	 {TS[$4].a4=cx+1;TS[$4].a6 = nTS - $4 -1;;$$=cx+1;} bloque{ TS[$4].a5=cx;$$=cx;};
	Tipo : INT  | FLOAT | STRING;
	
/*  listaVar : ID ','                       listaVar | ID ; */
	listaVar : ID ',' { IS(tipoVar,VAR); }	listaVar | ID { IS(tipoVar,VAR); };
	listaPar : Tipo ID { IS($1,VAR); }',' listaPar   | Tipo ID { IS($1,VAR); } | /* Nada */;
	listaParCall : expr{IBP($1);}',' listaParCall | expr {IBP($1);IBP(-1);} | /*Nada*/;
	bloque : '{' listaVarLoc listaProp '}';
	listaVarLoc : /* Nada */ | Tipo listaVar ';' listaVarLoc ;
	listaProp : /* Nada */ | listaProp prop | listaProp listaVarLoc;
	prop : ';' ;
	prop : bloque ;

/*  prop : IF '(' expr ')' prop ;  */
    prop : IF '(' expr  ')'  {genCodigo(SALTARF,$3,0,-1); 
								$$ = cx; 
								} 
								prop 
								{ TABCOD[$5].a3 = cx + 1;
									genCodigo(SALTARV,$3,0,-1);
									$$ = cx;
								} 																
								propif { TABCOD[$7].a3 = cx + 1;};

								
	propif : /* nada */ | ELSE bloque {$$=cx;};
	
/*  prop : WHILE '('               EXPRESION ')' prop;  */
	prop : WHILE '(' {$$ = cx + 1;}  expr    ')' 	{genCodigo(SALTARF,$4,0,-1); /* Destino no resuelto */
	   						                         $$ = cx; /* Falta llenar cuarto componente de este salto */} 
				                                 prop	
				                                 	{genCodigo(SALTAR,0,0,$3); /* Ir al comienzo de la expresi�n */
							                         TABCOD[$6].a3 = cx + 1; /* Llenando destino de sltar falso */
				                                    } ;

/*	prop : FOR '(' expr ';' expr ';' expr ')' prop ;	*/
	prop : FOR '(' expr ';' {$$ = cx + 1;} expr {genCodigo(SALTARV,$6,0,-1); $$ =cx;} 
												{genCodigo(SALTARF,$6,0,-1); $$=cx;} ';' 
												{$$ = cx + 1;} expr {genCodigo(SALTAR,0,0,$5); $$ =cx;} ')' 
																			
																			{TABCOD[$7].a3 = cx +1;}
																			 prop { 
																				 	TABCOD[$8].a3 = cx + 2;
																				 	genCodigo(SALTAR,0,0,$10);
																				};
	;
/*  prop : IMPRIMIR '(' expr ')' ;  */	
	prop : IMPRIMIR '(' /*FORMATO	{ $$ = nTS; IS(FORMATO,0);} ','*/  expr ')'	{genCodigo(IMPRIMIR,$3,0,0);};
	prop : LEER '('ID {$$ = localizaSimbolo(lexema);} ')' {genCodigo(LEER,$4,0,0);} ;
	prop : expr ;
	expr : expr OR expr ;
	expr : expr AND expr ;
	expr : NOT expr ;
	expr : expr IGUAL expr {int n = genvartemp();	
							genCodigo(IGUAL,n,$1,$3);
							  $$=n;} ;  /* n = $1 == $3   */;
	expr : expr NOIGUAL expr {int n = genvartemp();	genCodigo(NOIGUAL,n,$1,$3);  $$=n;} ;  /* n = $1 != $3   */;
	expr : expr '<' expr   {int n = genvartemp();	genCodigo(MENOR,n,$1,$3);  $$=n;} ;  /* n = $1 < $3   */
	expr : expr '>' expr   {int n = genvartemp();   genCodigo(MAYOR,n,$1,$3);  $$=n;};		/*  n = $1 > $3  */
	expr : expr MENORIGUAL expr {int n = genvartemp();	genCodigo(MENORIGUAL,n,$1,$3);  $$=n;} ;  /* n = $1 <= $3   */
	expr : expr MAYORIGUAL expr {int n = genvartemp();	genCodigo(MAYORIGUAL,n,$1,$3);  $$=n;} ;  /* n = $1 >= $3   */
	expr : expr '+' expr  	{int n = genvartemp();	genCodigo(SUMAR,n,$1,$3);  $$=n;};
    expr : expr '-' expr {int n = genvartemp(); genCodigo(RESTAR,n,$1,$3);$$=n;} ; /*  restar,a-b,a,b   */;
	expr : expr '*' expr {int n = genvartemp(); genCodigo(MULTIPLICAR,n,$1,$3);$$=n;}; /*multiplicar,a*b,a,b*/;
	expr : expr '/' expr {int n = genvartemp(); genCodigo(DIVIDIR,n,$1,$3);$$=n;} ; /*  dividir,a/b,a,b   */;

	
	expr : expr {genCodigo(SALTARF,$1,0,-1); $$=cx; } 
			'?' expr {TABCOD[$2].a3 = cx +1; genCodigo(SALTARV,$1,0,-1); $$=cx;}
			':' expr {TABCOD[$5].a3 = cx + 1;};
	expr : ID {$$ = localizaSimbolo(lexema);};
	expr : NUM  {int v; IS(INT,VAR);$$ = localizaSimbolo(lexema);sscanf(lexema,"%d",&v);TS[$$].a3.entero = v;};	/* Codigo 1 */
	expr : REAL	{float v; IS(FLOAT,VAR);$$ = localizaSimbolo(lexema);	sscanf(lexema,"%f",&v);TS[$$].a3.real = v;};	/* Codigo 2 */
	expr : CADENA {IS(STRING,VAR); 
					$$ = localizaSimbolo(lexema);					
					strcpy(TS[$$].a3.cadena,lexema);
					};
	expr : FUNCION {$$ = localizaSimbolo(lexema);} '('listaParCall')' {asignarParametros($2);}
	
		{genCodigo(SALTARYREGRESAR, TS[$2].a4,TS[$2].a5,cx+2); $$=$2;};
	expr : RETURN expr {int n,n2; n=encontrarFuncionAsociada(); n2 = localizaSimbolo(lexema);genCodigo(MOVER,n,n2,0); genCodigo(RETURN,0,0,0);};
	expr : ID '=' { $$ = localizaSimbolo(lexema); }	expr {genCodigo(MOVER,$3,$4,0);};	/* Codigo 3 */
	expr : ID '[' expr ']' ;
	expr : ID '[' expr ']' '=' expr;

%%

void genCodigo(int op,int a1,int a2,int a3)
{
	tipoCodigo *p;

	cx++;
	p = &TABCOD[cx];
	p->op = op;
	p->a1 = a1;
	p->a2 = a2;
	p->a3 = a3;
}

int genvartemp()
{
	char t[30];
	sprintf(t,"_T%d",nTS);
	strcpy(TS[nTS].nombre,t);
	TS[nTS].a1 = FLOAT;
	TS[nTS].a2 = VAR;
	return nTS++;
}

void muestraCodigo()
{
	int i,op,a1,a2,a3;
	for(i=0;i<=cx;i++) {
		op = TABCOD[i].op; a1 = TABCOD[i].a1;
		a2 = TABCOD[i].a2; a3 = TABCOD[i].a3;
		printf("%2d) ",i);
		switch(op)
		{		
		case MENOR: printf("MENOR %s = %s < %s\n",TS[a1].nombre,TS[a2].nombre,TS[a3].nombre);break;
		case MENORIGUAL: printf("MENORIGUAL %s = %s <= %s\n",TS[a1].nombre,TS[a2].nombre,TS[a3].nombre);break;
		case MAYOR: printf("MAYOR %s = %s > %s\n",TS[a1].nombre,TS[a2].nombre,TS[a3].nombre);break;
		case MAYORIGUAL: printf("MAYORIGUAL %s = %s >= %s\n",TS[a1].nombre,TS[a2].nombre,TS[a3].nombre);break;
		case IGUAL: printf("IGUAL %s = %s == %s\n",TS[a1].nombre,TS[a2].nombre,TS[a3].nombre);break;
		case NOIGUAL: printf("NOIGUAL %s = %s != %s\n",TS[a1].nombre,TS[a2].nombre,TS[a3].nombre);break;
		case SALTARYREGRESAR: printf("SALTARYREGRESAR inicio %d, final %d, regresar a %d\n",a1,a2,a3);break;
		case SALTAR: printf("SALTAR %d\n",a3);break;
		case SALTARV: printf("SALTARV %s %d \n",TS[a1].nombre,a3);break;
		case SALTARF: printf("SALTARF %s %d \n",TS[a1].nombre,a3);break;
		case MOVER: printf("MOVER %s %s \n",TS[a1].nombre,TS[a2].nombre);break;
		case IMPRIMIR: printf("IMPRIMIR %s \n",TS[a1].nombre);break;
		case LEER: printf("LEER %s \n",TS[a1].nombre);break;
		case SUMAR: printf("SUMAR %s = %s + %s\n",TS[a1].nombre,TS[a2].nombre,TS[a3].nombre);break;
		case RESTAR      : printf("RESTAR %s = %s - %s\n",TS[a1].nombre,TS[a2].nombre,TS[a3].nombre);break;
		case MULTIPLICAR : printf("MULTIPLICAR %s = %s * %s\n", TS[a1].nombre,TS[a2].nombre,TS[a3].nombre); break;
		case DIVIDIR     : printf("DIVIDIR %s = %s / %s\n",TS[a1].nombre,TS[a2].nombre,TS[a3].nombre);break;
		case RETURN		 : printf("RETURN\n");
		
		// Los dem�s casos
		}
	}
	return;
}

int localizaSimbolo(char *n)
{
	int i;
	for(i=0;i<nTS;i++) if(strcmp(n,TS[i].nombre) == 0) return i;
	return -1;
}
int insertaSimbolo(char *n, int t)
{
	if(localizaSimbolo(n)>=0) return -1;
	strcpy(TS[nTS].nombre,n);
	TS[nTS].a1 = t;
	TS[nTS].a2 = TS[nTS].a3.real = TS[nTS].a4 = 0;
	return nTS++;	
}
void IBP(int isimbolo){
	bufferParametros[++iBP] = isimbolo;
}
void asignarParametros(int ifuncion){
	
	if(TS[ifuncion].a6 != iBP){
		yyerror("parametros fuera de rango");
	}
	int iParametro = ifuncion + 1;
	for(int i = 0; i < iBP; ++i){
		int simboloEnBuffer = bufferParametros[i];
		genCodigo(MOVER,iParametro,simboloEnBuffer,0);
		iParametro++;
	}
	iBP = -1;
}
void IS(int tipo,int clase)
{
	int i;
	i = insertaSimbolo(lexema, tipo); TS[i].a2=clase;
	//printf("*** %d %s\n",tipo,TS[i].nombre);
	//if(i<0) yyerror("Identifiador ya declarado.");
}

void muestraSimbolo()
{
	int i;
	printf("int=%d,float=%d,string=%d\n",INT,FLOAT,STRING);
	for(i=0,pTS=TS;i<nTS;i++,pTS++)
		printf("%20s %d %d %g\n",pTS->nombre,pTS->a1,pTS->a2,pTS->a3.real);
} 

int encontrarFuncionAsociada(){
	int i;
	for(i=nTS-1; i>=0 ; --i){
		if(TS[i].a2 == FUNCION)
			break;
	}
	return i;
}
void imprimirCadena(char *str){
	char *character;
	character = str;
	char value;
	int i =0;
	while(*character != '\0'){
		if(str[i] == '\\'){
			++i;
			if(str[i] == 'n'){
				printf("\n");
			}
			else if(str[i] == 't'){
				printf("\t");
			}
			else
				printf("%c",str[--i]);
		}
		else
			printf("%c",str[i]);
		i++;
		character++;
	}
}


int yylex()
//TODO FIX HOW IT gets everything
{
  int c;  char *p;
  do c=getchar();while(isspace(c));
  if (isalpha(c))
    { p=lexema;
      do  { 
		  *p++=c; 
		  c=getchar();
	  } 
	  while (isalpha(c));
	  ungetc(c,stdin);
	  *p=0;
	  int simboloPos = localizaSimbolo(lexema);
	  if(simboloPos >= 0){
		  if(TS[simboloPos].a2 == FUNCION){
		  	return FUNCION;
		  }	
	  }
      if (strcmp(lexema,"if")==0) return IF;
      if (strcmp(lexema,"else")==0) return ELSE;
      if (strcmp(lexema,"int")==0) return tipoVar=yylval=INT;
      if (strcmp(lexema,"float")==0) return tipoVar=yylval=FLOAT;
	  if (strcmp(lexema,"string")==0) return tipoVar=yylval=STRING;
      if (strcmp(lexema,"while")==0) return WHILE;
      if (strcmp(lexema,"for")==0) return FOR;
      if (strcmp(lexema,"do")==0) return DO;
      if (strcmp(lexema,"print")==0) return IMPRIMIR;
	  if (strcmp(lexema,"read")==0) return LEER;
	  if (strcmp(lexema,"return")==0) return RETURN;
      if (strcmp(lexema,"chao")==0) {		  
		  return EOF;							
	  }
      
      /* van otras palabras reservadas */
      
      return yylval=ID;
    }
/*    if (c=='\"') {
      p=lexema;
      do  { *p++=c; c=getchar(); } while (c!='\"');
      ungetc(c,stdin); *p=0;
      return yylval=FORMATO;
    }*/
  
    if ( c=='(' || c==')' || c==';' || c==',' || c=='{' || c=='}' ||
         c==',' || c=='*' || c=='/' || c=='+' || c=='-' || c=='?' ||
         c=='[' || c==']' || c==':') return yylval=c;
	
    if ( c=='!') { 
    	c=getchar();
    	if(c=='=') return NOIGUAL;
    	ungetc(c,stdin); return NOT;
    	}
    	
    if ( c=='=' ) {
    	c=getchar();
    	if(c=='=') return IGUAL;
    	ungetc(c,stdin); return '=';
    	}
    	
    if ( c=='>' ) {
    	c=getchar();
    	if(c=='=') return MAYORIGUAL;
    	ungetc(c,stdin); return '>';
    	}
    	
    if ( c=='<' ) {
    	c=getchar();
    	if(c=='=') return MENORIGUAL;
    	ungetc(c,stdin); return '<';
    	}

    if ( c=='&' ) {
    	c=getchar();
    	if(c=='&') return AND;
    	ungetc(c,stdin); return '&';
    	}

	if ( c=='|' ) {
    	c=getchar();
    	if(c=='|') return OR;
    	ungetc(c,stdin); return '|';
    	}

    if (isdigit(c)) { 
    	p=lexema;
      	do  { *p++=c; c=getchar(); } while (isdigit(c));
      	if(c=='.') { do  { *p++=c; c=getchar(); } while (isdigit(c));
      			 ungetc(c,stdin); *p=0; return yylval=REAL;}
      	ungetc(c,stdin); *p=0;
    	return yylval=NUM;
    	}
    if ( c == '"') {
		p=lexema;
		do {c=getchar(); *p++=c;} while(c!='"');
		*(p-1)=0;
		return yylval = CADENA;
	}	
    yyerror("��� caracter ilegal !!!");
}

yyerror(char *m)  { 
	fprintf(stderr,"error de sintaxis %s\n",m); 
	getchar(); 
	exit(0);
	}

void interprete(){
	int icx,op,a1,a2,a3;
	tipovalor entrada;
	int enSaltarRegresar = 0;
	//usar como un stack para poder utilizar con funciones nested 
	int numeroOperacionesParaRegresar = 0;
	int regresarA = -1;
	FILE *tty;	
	tty = freopen("/dev/tty", "r", stdin);
	if (tty == NULL) {
		perror("Unable to open terminal for reading");
	}
	printf("Programa en ejecuci�n: \n");
	icx = 0;
	while(1){
		if(icx==cx+1) break;
		op = TABCOD[icx].op;
		a1 = TABCOD[icx].a1;
		a2 = TABCOD[icx].a2;
		a3 = TABCOD[icx].a3;

		switch(op)
		{
		case RETURN :
			if(enSaltarRegresar){
				numeroOperacionesParaRegresar = 0;
				icx = regresarA;
				regresarA = -1;
				enSaltarRegresar = 0;
				continue;
			}
			break;
		case SALTARYREGRESAR :
			enSaltarRegresar = 1;
			numeroOperacionesParaRegresar = a2 - a1 
			+1;
			regresarA = a3;
			icx = a1;
			continue;
		case SALTAR :	
						icx = a3; 
						continue;
		case SALTARF : if(!TS[a1].a3.entero) { icx = a3; continue;}
				else break;
		case SALTARV : 
				if(TS[a1].a2 == VAR){
					if(TS[a1].a3.entero) { 
						icx = a3; continue;
					}
					else break;
				}
				else if(TS[a1].a2 == FUNCION){
					if(strcmp(TS[a1].nombre,"main")!=0){
						icx = TS[a1].a5 +1;
						continue;
					}
					else if (strcmp(TS[a1].nombre,"main")==0){
						break;
					}
				}
		case IMPRIMIR : if(TS[a1].a1==INT){
							printf("%d\n",TS[a1].a3.entero);
						}
						else if(TS[a1].a1==FLOAT){
							printf("%f\n",TS[a1].a3.real);
						}
						else if(TS[a1].a1==STRING){
							imprimirCadena(TS[a1].a3.cadena);
						}
			 break;
		case LEER :   
						if(TS[a1].a1 == INT){
							scanf(" %d", &entrada.entero);
							TS[a1].a3.entero = entrada.entero;
						}
						else if(TS[a1].a1 == FLOAT){
							scanf(" %f", &entrada.real);
							TS[a1].a3.real = entrada.real;
						}					
						else if(TS[a1].a1 == STRING){
							scanf("%s",&entrada.cadena);
							strcpy(TS[a1].a3.cadena,&entrada.cadena);
						}
						break;
		case MOVER : 
					if(TS[a1].a1 == INT){
						if(TS[a2].a1 == INT)
							TS[a1].a3.entero = TS[a2].a3.entero;
						else if(TS[a2].a1 == FLOAT)
							TS[a1].a3.entero = TS[a2].a3.real;
					}
					else if(TS[a1].a1 == FLOAT){
						if(TS[a2].a1 == INT)
							TS[a1].a3.real = TS[a2].a3.entero;
						else if(TS[a2].a1 == FLOAT)
							TS[a1].a3.real = TS[a2].a3.real;
					}
					else if(TS[a1].a1 == STRING){
						if(TS[a2].a1 == STRING)
							strcpy(TS[a1].a3.cadena,TS[a2].a3.cadena);
						else if(TS[a2].a1 == INT)
							snprintf(TS[a1].a3.cadena,30,"%d",TS[a2].a3.entero);
						else if(TS[a2].a1 == FLOAT)
							snprintf(TS[a1].a3.cadena,30,"%f",TS[a2].a3.real);
					}
					break;
		case SUMAR : 
					if(TS[a1].a1 == INT){
						if(TS[a2].a1==INT && TS[a3].a1==FLOAT){
							TS[a1].a3.entero = (TS[a2].a3.entero + TS[a3].a3.real);	
						}
						else if(TS[a2].a1==INT && TS[a3].a1==INT){
							TS[a1].a3.entero = (TS[a2].a3.entero + TS[a3].a3.entero);
						} 
						else if(TS[a2].a1==FLOAT && TS[a3].a1==FLOAT){
							TS[a1].a3.entero = (TS[a2].a3.real + TS[a3].a3.real);
						}
						else if(TS[a2].a1==FLOAT && TS[a3].a1==INT){
							TS[a1].a3.entero = (TS[a2].a3.real + TS[a3].a3.entero);
						}
					}
					else if(TS[a1].a1 == FLOAT){
						if(TS[a2].a1==INT && TS[a3].a1==FLOAT){
							TS[a1].a3.real = (TS[a2].a3.entero + TS[a3].a3.real);	
						}
						else if(TS[a2].a1==INT && TS[a3].a1==INT){
							TS[a1].a3.real = (TS[a2].a3.entero + TS[a3].a3.entero);
						} 
						else if(TS[a2].a1==FLOAT && TS[a3].a1==FLOAT){
							TS[a1].a3.real = (TS[a2].a3.real + TS[a3].a3.real);
						}
						else if(TS[a2].a1==FLOAT && TS[a3].a1==INT){
							TS[a1].a3.real = (TS[a2].a3.real + TS[a3].a3.entero);
						}
					}
					break;
		case RESTAR      : 
					if(TS[a1].a1 == INT){
						if(TS[a2].a1==INT && TS[a3].a1==FLOAT){
							TS[a1].a3.entero = (TS[a2].a3.entero - TS[a3].a3.real);	
						}
						else if(TS[a2].a1==INT && TS[a3].a1==INT){
							TS[a1].a3.entero = (TS[a2].a3.entero - TS[a3].a3.entero);
						} 
						else if(TS[a2].a1==FLOAT && TS[a3].a1==FLOAT){
							TS[a1].a3.entero = (TS[a2].a3.real - TS[a3].a3.real);
						}
						else if(TS[a2].a1==FLOAT && TS[a3].a1==INT){
							TS[a1].a3.entero = (TS[a2].a3.real - TS[a3].a3.entero);
						}
					}
					else if(TS[a1].a1 == FLOAT){
						if(TS[a2].a1==INT && TS[a3].a1==FLOAT){
							TS[a1].a3.real = (TS[a2].a3.entero - TS[a3].a3.real);	
						}
						else if(TS[a2].a1==INT && TS[a3].a1==INT){
							TS[a1].a3.real = (TS[a2].a3.entero - TS[a3].a3.entero);
						} 
						else if(TS[a2].a1==FLOAT && TS[a3].a1==FLOAT){
							TS[a1].a3.real = (TS[a2].a3.real - TS[a3].a3.real);
						}
						else if(TS[a2].a1==FLOAT && TS[a3].a1==INT){
							TS[a1].a3.real = (TS[a2].a3.real - TS[a3].a3.entero);
						}
					}
					break;
		case MULTIPLICAR : 
					if(TS[a1].a1 == INT){
						if(TS[a2].a1==INT && TS[a3].a1==FLOAT){
							TS[a1].a3.entero = (TS[a2].a3.entero * TS[a3].a3.real);	
						}
						else if(TS[a2].a1==INT && TS[a3].a1==INT){
							TS[a1].a3.entero = (TS[a2].a3.entero * TS[a3].a3.entero);
						} 
						else if(TS[a2].a1==FLOAT && TS[a3].a1==FLOAT){
							TS[a1].a3.entero = (TS[a2].a3.real * TS[a3].a3.real);
						}
						else if(TS[a2].a1==FLOAT && TS[a3].a1==INT){
							TS[a1].a3.entero = (TS[a2].a3.real * TS[a3].a3.entero);
						}
					}
					else if(TS[a1].a1 == FLOAT){
						if(TS[a2].a1==INT && TS[a3].a1==FLOAT){
							TS[a1].a3.real = (TS[a2].a3.entero * TS[a3].a3.real);	
						}
						else if(TS[a2].a1==INT && TS[a3].a1==INT){
							TS[a1].a3.real = (TS[a2].a3.entero * TS[a3].a3.entero);
						} 
						else if(TS[a2].a1==FLOAT && TS[a3].a1==FLOAT){
							TS[a1].a3.real = (TS[a2].a3.real * TS[a3].a3.real);
						}
						else if(TS[a2].a1==FLOAT && TS[a3].a1==INT){
							TS[a1].a3.real = (TS[a2].a3.real * TS[a3].a3.entero);
						}
					}
					break;
		case DIVIDIR :
					if(TS[a1].a1 == INT){
						if(TS[a2].a1==INT && TS[a3].a1==FLOAT){
							TS[a1].a3.entero = (TS[a2].a3.entero / TS[a3].a3.real);	
						}
						else if(TS[a2].a1==INT && TS[a3].a1==INT){
							TS[a1].a3.entero = (TS[a2].a3.entero / TS[a3].a3.entero);
						} 
						else if(TS[a2].a1==FLOAT && TS[a3].a1==FLOAT){
							TS[a1].a3.entero = (TS[a2].a3.real / TS[a3].a3.real);
						}
						else if(TS[a2].a1==FLOAT && TS[a3].a1==INT){
							TS[a1].a3.entero = (TS[a2].a3.real / TS[a3].a3.entero);
						}
					}
					else if(TS[a1].a1 == FLOAT){
						if(TS[a2].a1==INT && TS[a3].a1==FLOAT){
							TS[a1].a3.real = (TS[a2].a3.entero / TS[a3].a3.real);	
						}
						else if(TS[a2].a1==INT && TS[a3].a1==INT){
							TS[a1].a3.real = (TS[a2].a3.entero / TS[a3].a3.entero);
						} 
						else if(TS[a2].a1==FLOAT && TS[a3].a1==FLOAT){
							TS[a1].a3.real = (TS[a2].a3.real / TS[a3].a3.real);
						}
						else if(TS[a2].a1==FLOAT && TS[a3].a1==INT){
							TS[a1].a3.real = (TS[a2].a3.real / TS[a3].a3.entero);
						}
					}
					break; 
		case MENOR : 
					if(TS[a2].a1==INT && TS[a3].a1==FLOAT){
						TS[a1].a3.entero = (TS[a2].a3.entero < TS[a3].a3.real);	
					}
					else if(TS[a2].a1==INT && TS[a3].a1==INT){
						TS[a1].a3.entero = (TS[a2].a3.entero < TS[a3].a3.entero);
					} 
					else if(TS[a2].a1==FLOAT && TS[a3].a1==FLOAT){
						TS[a1].a3.entero = (TS[a2].a3.real < TS[a3].a3.real);
					}
					else if(TS[a2].a1==FLOAT && TS[a3].a1==INT){
						TS[a1].a3.entero = (TS[a2].a3.real < TS[a3].a3.entero);
					}
					break;
		case MENORIGUAL : 
					if(TS[a2].a1==INT && TS[a3].a1==FLOAT){
						TS[a1].a3.entero = (TS[a2].a3.entero <= TS[a3].a3.real);	
					}
					else if(TS[a2].a1==INT && TS[a3].a1==INT){
						TS[a1].a3.entero = (TS[a2].a3.entero <= TS[a3].a3.entero);
					} 
					else if(TS[a2].a1==FLOAT && TS[a3].a1==FLOAT){
						TS[a1].a3.entero = (TS[a2].a3.real <= TS[a3].a3.real);
					}
					else if(TS[a2].a1==FLOAT && TS[a3].a1==INT){
						TS[a1].a3.entero = (TS[a2].a3.real < TS[a3].a3.entero);
					}
					break;
		case MAYOR :
					if(TS[a2].a1==INT && TS[a3].a1==FLOAT){
						TS[a1].a3.entero = (TS[a2].a3.entero > TS[a3].a3.real);	
					}
					else if(TS[a2].a1==INT && TS[a3].a1==INT){
						TS[a1].a3.entero = (TS[a2].a3.entero > TS[a3].a3.entero);
					} 
					else if(TS[a2].a1==FLOAT && TS[a3].a1==FLOAT){
						TS[a1].a3.entero = (TS[a2].a3.real > TS[a3].a3.real);
					}
					else if(TS[a2].a1==FLOAT && TS[a3].a1==INT){
						TS[a1].a3.entero = (TS[a2].a3.real > TS[a3].a3.entero);
					}
					break;
		case MAYORIGUAL : 
					if(TS[a2].a1==INT && TS[a3].a1==FLOAT){
						TS[a1].a3.entero = (TS[a2].a3.entero >= TS[a3].a3.real);	
					}
					else if(TS[a2].a1==INT && TS[a3].a1==INT){
						TS[a1].a3.entero = (TS[a2].a3.entero >= TS[a3].a3.entero);
					} 
					else if(TS[a2].a1==FLOAT && TS[a3].a1==FLOAT){
						TS[a1].a3.entero = (TS[a2].a3.real >= TS[a3].a3.real);
					}
					else if(TS[a2].a1==FLOAT && TS[a3].a1==INT){
						TS[a1].a3.entero = (TS[a2].a3.real >= TS[a3].a3.entero);
					}
					break;
		case IGUAL : 
					if(TS[a2].a1==INT && TS[a3].a1==FLOAT){
						TS[a1].a3.entero = (TS[a2].a3.entero == TS[a3].a3.real);	
					}
					else if(TS[a2].a1==INT && TS[a3].a1==INT){
						TS[a1].a3.entero = (TS[a2].a3.entero == TS[a3].a3.entero);
					} 
					else if(TS[a2].a1==FLOAT && TS[a3].a1==FLOAT){
						TS[a1].a3.entero = (TS[a2].a3.real == TS[a3].a3.real);
					}
					else if(TS[a2].a1==FLOAT && TS[a3].a1==INT){
						TS[a1].a3.entero = (TS[a2].a3.real == TS[a3].a3.entero);
					}
					break;
		case NOIGUAL : 
					if(TS[a2].a1==INT && TS[a3].a1==FLOAT){
						TS[a1].a3.entero = (TS[a2].a3.entero != TS[a3].a3.real);	
					}
					else if(TS[a2].a1==INT && TS[a3].a1==INT){
						TS[a1].a3.entero = (TS[a2].a3.entero != TS[a3].a3.entero);
					} 
					else if(TS[a2].a1==FLOAT && TS[a3].a1==FLOAT){
						TS[a1].a3.entero = (TS[a2].a3.real != TS[a3].a3.real);
					}
					else if(TS[a2].a1==FLOAT && TS[a3].a1==INT){
						TS[a1].a3.entero = (TS[a2].a3.real != TS[a3].a3.entero);
					}
					break;
		}
	icx++;
	}  //Fin de 'while'
	}  //Fin de funcion
	
main(int argc, char *argv[])  {
	yyparse();
	muestraSimbolo();
	muestraCodigo();
	interprete();
	}
