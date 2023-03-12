Alpha [a-zA-Z]
Digit [0-9]

%{
#include <stdio.h>
#include <string.h>
#include "y.tab.h"
  extern YYSTYPE yylval;
  int yywrap();
  int yyerror(char* s);

  int lineno = 0;
  
  /* Symbol Table*/
  struct sym {
    char *datatype;
    char *nodetype;
    int linenum;
    char *varname;
  } SymTable[128];

  /*EXTERNAL GLOBALS FOR ERROR CHECKING FROM parser.yacc*/
  extern char errarray[15][128];
  extern int errindex;
  extern char keywords[11][10];
  
  int numEntries = 0;

  char currenttype[10];
  //insert into table
  void insert(char n);
  void insert_type(char *type);
  //lookup and return datatype attached to name in symtable
  int lookup(char name[]);
%}

%option yylineno

 //token rules
%%
"int" {strcpy(yylval.node_object.varname,(yytext)); return(INT);}
"char" {strcpy(yylval.node_object.varname,(yytext)); return(CHAR);}
"string" {strcpy(yylval.node_object.varname,(yytext)); return(STRING);}
"bool" {strcpy(yylval.node_object.varname,(yytext)); return(BOOL);}
"real" {strcpy(yylval.node_object.varname,(yytext)); return(REAL);}
"empty" {strcpy(yylval.node_object.varname,(yytext)); return(EMPTY);}
"begin" {strcpy(yylval.node_object.varname,(yytext)); return(BEGINPROG);}
"end" {strcpy(yylval.node_object.varname,(yytext)); return(ENDPROG);}
"start" {strcpy(yylval.node_object.varname,(yytext)); return(START);}
"done" {strcpy(yylval.node_object.varname,(yytext)); return(DONE);}
"if" {strcpy(yylval.node_object.varname,(yytext)); return(IF);}
"else" {strcpy(yylval.node_object.varname,(yytext)); return(ELSE);}
"for" {strcpy(yylval.node_object.varname,(yytext)); return(FOR);}
"print" {strcpy(yylval.node_object.varname,(yytext)); return(PRINT);}
"scan" {strcpy(yylval.node_object.varname,(yytext)); return(SCAN);}
"true" {strcpy(yylval.node_object.varname,(yytext)); return(BOOLTRUE);}
"false" {strcpy(yylval.node_object.varname,(yytext)); return(BOOLFALSE);}
"=" {strcpy(yylval.node_object.varname,(yytext)); return(ASGN);}
"<=" {strcpy(yylval.node_object.varname,(yytext)); return(LTEQ);}
">=" {strcpy(yylval.node_object.varname,(yytext)); return(GTEQ);}
"==" {strcpy(yylval.node_object.varname,(yytext)); return(EQ);}
"!=" {strcpy(yylval.node_object.varname,(yytext)); return(NEQ);}
">" {strcpy(yylval.node_object.varname,(yytext)); return(GT);}
"<" {strcpy(yylval.node_object.varname,(yytext)); return(LT);}
"&&" {strcpy(yylval.node_object.varname,(yytext)); return(AND);}
"||" {strcpy(yylval.node_object.varname,(yytext)); return(OR);}
"+" {strcpy(yylval.node_object.varname,(yytext)); return(PLUS);}
"-" {strcpy(yylval.node_object.varname,(yytext)); return(SUB);}
"/" {strcpy(yylval.node_object.varname,(yytext)); return(DIV);}
"*" {strcpy(yylval.node_object.varname,(yytext)); return(MULT);}
['].['] {strcpy(yylval.node_object.varname,(yytext)); return(CHARLIT);}
["].*["] {strcpy(yylval.node_object.varname,(yytext)); return(STRLIT);}

{Digit}+[.]{Digit}+ {strcpy(yylval.node_object.varname,(yytext)); return(REALLIT);}
{Digit}+ {strcpy(yylval.node_object.varname,(yytext)); return(INTLIT);}
{Alpha}+ {strcpy(yylval.node_object.varname,(yytext)); return(VARNAME);}
[\t\f\v ] {}//skip whitespace
([\n]) {strcpy(yylval.node_object.varname,(yytext)); lineno++; return(NEWLINE);}

. { char errmsg[] = "Unknown char in input on or below line: ";
  errmsg[40] = yytext[0];
  yyerror(errmsg);
  exit(1);
  return(yytext[0]);
  }

%%

  //supporting code
int yywrap()
{
  return(1);
}

int yyerror(char* s){
  fprintf(stderr, "\n ERROR on line: %i:\n %s\n",lineno,s);
  exit(1);
  return 1;
}


void insert(char n){
  //V variable
  //K keyword
  //C conditional
  //L literal

  //ERROR CHECK FOR KEYWORD VARIABLES
    if(n == 'V'){
    for(int i = 0; i < 11; i++){
      if(!strcmp(keywords[i],strdup(yytext))){
	sprintf(errarray[errindex],"ERROR: Line %i: Using keyword (%s) as (or in) variable.\n",lineno+1,yytext);
	errindex++;
	return;
      }
    }
    }
  
  int dupcheck = lookup(yytext);

  if(!dupcheck){
  switch (n){
    //Sets Symtable entries for Vars keywords conditionals and literals
  case 'V':
    SymTable[numEntries].varname=strdup(yytext);
    SymTable[numEntries].datatype=strdup(currenttype);
    SymTable[numEntries].nodetype=strdup("VARIABLE");
    SymTable[numEntries].linenum = lineno;
    numEntries+=1;
    break;
  case 'K':
    SymTable[numEntries].varname=strdup(yytext);
    SymTable[numEntries].datatype=strdup("N/A");
    SymTable[numEntries].nodetype=strdup("KEYWORD");
    SymTable[numEntries].linenum = lineno;
    numEntries+=1;
    break;
  case 'C':
    SymTable[numEntries].varname=strdup(yytext);
    SymTable[numEntries].datatype=strdup("N/A");
    SymTable[numEntries].nodetype=strdup("CONDITIONAL");
    SymTable[numEntries].linenum = lineno;
    numEntries+=1;
    break;
  case 'L':
    SymTable[numEntries].varname=strdup(yytext);
    SymTable[numEntries].datatype=strdup("LITERAL");
    SymTable[numEntries].nodetype=strdup("LITERAL");
    SymTable[numEntries].linenum = lineno;
    numEntries+=1;

  default:
    break;
    
  }
  }

  else if(n == 'V' && !dupcheck){
    sprintf(errarray[errindex],"ERROR: Line %i: Multiple declarations of (%s)\n",lineno+1,yytext);
    errindex++;
  }

  
}

void insert_type(char *type){
  strcpy(currenttype,type);
}

int lookup(char name[]){
  //Iterate through symbol table and check for passed entry
  //if found return -1 else 0
  for(int i = numEntries-1; i>=0; i--){
    if(strcmp(SymTable[i].varname,name)==0){
      return -1;
      break;
    }
  }

  return 0;
  
}

void dumpsymtbl(){
  //Print out symbol table
  printf("-----------------------SYM TABLE START---------------------------\n");
  printf("[SYMBOL]\t[NODETYPE]\t[DATATYPE]\t[LINENO]\n");
  for(int i = 0; i <= numEntries-1; i++){
      printf("[%s]\t[%s]\t[%s]\t[%i]\t\n",SymTable[i].varname,SymTable[i].nodetype,
    	   SymTable[i].datatype,SymTable[i].linenum);
 
  }

  for(int i = 0; i <= numEntries-1; i++){
    free(SymTable[i].varname);
    free(SymTable[i].datatype);
    free(SymTable[i].nodetype);
  }

  printf("-------------------------SYM TABLE END----------------------------\n");
  
}
