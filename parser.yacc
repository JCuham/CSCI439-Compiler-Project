%{
  //initial setup
  #include <stdio.h>
  #include <string.h>
  #include <stdlib.h>
  #include <ctype.h>
  #include "lex.yy.c"
  int yylex();
  int yywrap();

  /*SYNTAX TREE FUNCTIONS*/
  void printSynTree(struct node*n);
  void cleanup(struct node*n);
  /*CODE GENERATION FUNCTIONS*/
  void gencode(struct node*n);
  void gencodevars(struct node*n);
  void gencodestrings(struct node*n);
  void gencodeblock(struct node*n);
  void ifcodeblock(struct node*n);
  /*ERROR GENERATION FUNCTIONS*/
  void no_declaration(char *s);
  void keyword_var(char *s);
  int type_checker(char *s1, char *s2);
  char *get_current_type(char *s);
  /*ERROR CHECKING GLOBAL VARS*/
  int status;
  extern int lineno;
  char errarray[15][128];
  int errindex = 0;
  char keywords[11][10] = {"int","real","string","char","else","if","for","begin","end","start","done"};
  /*CODE GENERATION GLOBAL VARS*/
  char codeblock_array[128][128];
  int codeblockindex = 0;
  char codevar_array[40][40];
  int codevarindex = 0;
  char string_array[40][128];
  int stringindex = 0;
  int numdefinedstr = 0;
  int numdefinedvar = 0;
  int pstmtcounter = 0;
  int loopcounter = 0;
  int scanstmtcounter=0;
  int ifstmtcounter=0;
  int totalifstmt = 0;
  /*SYNTAX TREE NODE CREATION FUNCTION*/
  struct node* createNode(struct node *L, struct node *R, char *tok);
  /*SYNTAX TREE ROOT NODE GLOBAL*/
  struct node *root;
  /*SYNTAX TREE NODE STRUCTURE*/
  struct node {
    struct node *L;
    struct node *R;
    char *token;
  };


 %}

%union {
  struct variable {
    char varname[128];
    struct node *n;
  } node_object;
}
 //tokens
 %token EMPTY
 %token <node_object> INT CHAR STRING BOOL REAL BEGINPROG ENDPROG START DONE IF ELSE FOR
 PRINT SCAN BOOLTRUE BOOLFALSE ASGN LTEQ GTEQ EQ NEQ GT LT AND OR PLUS
 SUB DIV MULT CHARLIT STRLIT REALLIT INTLIT VARNAME NEWLINE
  //grammar rules
 %type <node_object> prog codeblock code elsestmt printstmt scanstmt cond value condop
 declare assign condstmt type boolop mathop
 %%

 prog: BEGINPROG codeblock ENDPROG
 {
   struct node *temp1 = createNode($1.n,$2.n,"BEGIN");
   struct node *temp2 = createNode(NULL,$3.n,"END");
   $$.n = createNode(temp1,temp2,"codeblock");
   root = $$.n;
 }
;

codeblock: code
{
  $$.n = createNode($1.n,NULL,"codeblock");
}
;

codeblock: code codeblock
{
  $$.n = createNode($1.n,$2.n,"codeblock");
}
;

code: FOR {insert('K');} condstmt cond condstmt NEWLINE START codeblock DONE
{
  //Create temp nodes to store conditions and condition statements
  //Root points to conditions as left child and right child is the codeblock inside the loop
  struct node *temp1 = createNode($4.n,$5.n,"CONDITION");
   struct node *temp2 = createNode($3.n,temp1,"CONDITION");
   $$.n = createNode(temp2,$8.n,"FORLOOP");
 
}
| IF {insert('K');} cond NEWLINE START NEWLINE codeblock DONE NEWLINE elsestmt
{
  //Constructs a node to store condtitions and sets root to point to conditions and codeblock
  //as left child
  //right child is the else condition if it exists
  struct node *elif = createNode($3.n,$7.n,$1.varname);
  $$.n = createNode(elif,$9.n,"elif");
  totalifstmt++;
}
| declare
| printstmt
| scanstmt 
| assign 
| NEWLINE
;

elsestmt: ELSE {insert('K');} NEWLINE START NEWLINE codeblock DONE NEWLINE
{
  $$.n = createNode(NULL,$6.n,$1.varname);
}
|{$$.n = NULL;}
;

printstmt: PRINT {insert('K');} value NEWLINE
{
  $$.n = createNode($1.n,$3.n,"PRINTSTMT");
}
;

scanstmt: SCAN {insert('K');} value value NEWLINE
{
  struct node *scan = createNode($3.n,$4.n,"SCANVARS");
  $$.n = createNode($1.n,scan,"SCANSTMT");
}
;

cond: BOOLTRUE {$$.n = createNode(NULL,NULL,$1.varname);}
| BOOLFALSE {$$.n = createNode(NULL,NULL,$1.varname);}
| value condop value {$1.n = createNode(NULL,NULL,$1.varname); $$.n = createNode($1.n,$3.n,$2.varname);}
;

value: REALLIT {insert_type("real"); insert('L'); $$.n = createNode(NULL,NULL,$1.varname);}
| INTLIT {insert_type("int"); insert('L'); $$.n = createNode(NULL,NULL,$1.varname);}
| CHARLIT {insert_type("char"); insert('L'); $$.n = createNode(NULL,NULL,$1.varname);}
| STRLIT {insert_type("string"); insert('L'); $$.n = createNode(NULL,NULL,$1.varname);}
| VARNAME {insert_type(yytext); insert('V'); $$.n = createNode(NULL,NULL,$1.varname);}
;

condop: LTEQ
| GTEQ
| EQ
| NEQ
| GT
| LT
;


declare: type VARNAME {insert('V');} ASGN value NEWLINE
{
  //Creates a child node with the variable name and sets root to have it as leftmost child
  //rightmost child is the value
  $2.n = createNode(NULL,NULL,$2.varname);
  $$.n = createNode($2.n,$5.n,"DECLARATION");
}
;

assign: VARNAME { no_declaration($1.varname); insert('V');} ASGN value NEWLINE
{
  $$.n = createNode($1.n,$3.n,"ASSIGNMENT");
}
;

condstmt: type VARNAME { insert('V');} ASGN value
{
  $2.n = createNode(NULL,NULL,$2.varname);
  $$.n = createNode($2.n,$5.n,$4.varname);
}
| value boolop value
{
  no_declaration($1.varname);
  $$.n = createNode($1.n,$3.n,$2.varname);
}
| value mathop value
{
  no_declaration($1.varname);
  $$.n = createNode($1.n,$3.n,$2.varname);
}
;

type: INT {insert_type("int");}
| CHAR {insert_type("char");}
| STRING {insert_type("string");}
| BOOL {insert_type("bool");}
| REAL {insert_type("real");}
| EMPTY {insert_type("empty");}
;

boolop: AND
| OR
;

mathop: PLUS
| SUB
| DIV
| MULT
;

%%

void printSynTree(struct node*n){

  if(n->L){
    printSynTree(n->L);
  }
  printf("%s | ",n->token);

  if(n->R){
    printSynTree(n->R);
  }
  
  
}

void gencodevars(struct node*n){

  //traverse SynTree in order and store declared variables in var array
  if(n->L){
    gencodevars(n->L);
  }
  //Variable Declaration
  if(strcmp(n->token,"DECLARATION")==0){
    //grab l child varaible and r child value convert to asm and store in array with newline
    //check for string declaration
    if((memcmp(n->R->token,"\"",1))){
    snprintf(codevar_array[codevarindex],39,"%s DQ %s\n",n->L->token,n->R->token);
    codevarindex++;
    numdefinedvar++;
    }else if(!(memcmp(n->R->token,"\"",1))){
      //is a string declaration need to place in string vars array
      //need to store string number for determining right string and length
      int strnum = stringindex;
      snprintf(string_array[stringindex],127,"msg%i DQ %s, 0 \nlen%i equ $ - %s\n",stringindex,n->R->token,stringindex,n->L->token);
      stringindex++;
      numdefinedstr++;
    }
    
  }

  //Scan variable declaration scanstmtcounter
  if(strcmp(n->token,"SCANSTMT")==0){
    
  }
  
  if(n->R){
    gencodevars(n->R);
  }
  
}

void gencodestrings(struct node*n){
  //traverse SynTree in order and store declared strings in var array
  //and print stmt strings
}

void ifcodeblock(struct node*n){

  //iterate tree recursively in order
  if(n->L){
    ifcodeblock(n->L);
  }

  //IF PRINTSTMT is current node
   if(strcmp(n->token,"PRINTSTMT")==0){
  
    //PRINT LITERAL DECLARED INLINE
    if(!(memcmp(n->R->token,"\"",1))){
      // snprintf(codeblock_array[codeblockindex],127,"")
      //print stmt R node is literal
      snprintf(codeblock_array[codeblockindex],127,"mov ecx, %s\t;store string to print in ecx\nint 0x80\t;print value stored in ecx\n",n->R->token);
      codeblockindex++;
	}else{
      //print predefined string
      if(pstmtcounter < numdefinedstr){
	snprintf(codeblock_array[codeblockindex],127,"mov edx,len%i\nmov dx,msg%i\nmov ebx,1\nmov dx,4\nint 0x80\n\n",
		 pstmtcounter,pstmtcounter);
	pstmtcounter++;
	codeblockindex++;
      }
    }
  }

   //right node iteration
  if(n->R){
    ifcodeblock(n->R);
  }
  
}

void gencodeblock(struct node*n){

  if(n->L){
    gencodeblock(n->L);
  }

  /*FOR LOOP GENERATION*/
  
  if(strcmp(n->token,"FORLOOP")==0){
    //loopcounter var counts loop number
    // push number for index onto stack
    // jump to loop cond
    //left subtree first condition n->L->L->token number at n->L->L->R->token
    snprintf(codeblock_array[codeblockindex],127,"mov ecx, %s\t;store loop index var on stack\njmp loop%i\n",n->L->L->R->token,loopcounter);
    codeblockindex++;
    //print loop label and push ecx onto the stack
    snprintf(codeblock_array[codeblockindex],127,"loop%i:\npush ecx\t;save loop index on stack\n",loopcounter);
    
    codeblockindex++;

    /*RECURSIVE CALL TO GENERATE CODE WITHIN LOOP*/
    gencodeblock(n->R);
    
    //left subtree comparison cond n->L->R->L comp cond op is n->L->R->L.varname
       //get number value from cond
      int condnum = atoi(n->L->R->L->R->token);
      /*LOOP COUNTER AND END CONDITIONS (!= and == only add to counter and perform comparison)*/
    if(strchr(n->L->R->L->token,'<')!=NULL){
      
      snprintf(codeblock_array[codeblockindex],127,
	       "pop ecx\t;get loop index\nadd ecx, 1\ncmp ecx, %i\njl loop%i\n\n",
	       condnum,loopcounter);
      codeblockindex++;
	loopcounter++;
    }else if(strchr(n->L->R->L->token,'>')!=NULL){ 
      snprintf(codeblock_array[codeblockindex],127,
	       "pop ecx\t;get loop index\nsub ecx, 1\ncmp ecx, %i\njg loop%i\n\n",
	       condnum,loopcounter);
      codeblockindex++;
	loopcounter++;
    }else if((strchr(n->L->R->L->token,'<')!=NULL) && (strchr(n->L->R->L->token,'=')!=NULL)){ 
      snprintf(codeblock_array[codeblockindex],127,
	       "pop ecx\t;get loop index\nadd ecx, 1\ncmp ecx, %i\njle loop%i\n\n",
	       condnum,loopcounter);
      codeblockindex++;
	loopcounter++;
    }else if((strchr(n->L->R->L->token,'>')!=NULL) && (strchr(n->L->R->L->token,'=')!=NULL)){ 
      snprintf(codeblock_array[codeblockindex],127,
	       "pop ecx\t;get loop index\nsub ecx, 1\ncmp ecx, %i\njge loop%i\n\n",
	       condnum,loopcounter);
      codeblockindex++;
	loopcounter++;
    }else if((strchr(n->L->R->L->token,'!')!=NULL) && (strchr(n->L->R->L->token,'=')!=NULL)){ 
      snprintf(codeblock_array[codeblockindex],127,
	       "pop ecx\t;get loop index\nadd ecx, 1\ncmp ecx, %i\njne loop%i\n\n",
	       condnum,loopcounter);
      codeblockindex++;
	loopcounter++;
    }else if((strchr(n->L->R->L->token,'=')!=NULL) && (strchr(n->L->R->L->token,'=')!=NULL)){ 
      snprintf(codeblock_array[codeblockindex],127,
	       "pop ecx\t;get loop index\nsub ecx, 1\ncmp ecx, %i\nje loop%i\n\n",
	       condnum,loopcounter);
      codeblockindex++;
	loopcounter++;
    }
    

    
  }
  /*IF STATEMENT CODE GENERATION*/
  else if(strcmp(n->token,"elif")==0){

    //store first comp value in reg
    snprintf(codeblock_array[codeblockindex],127,"mov ax, %s\t;store if LHS COND var in reg\n",n->L->L->L->token);
    codeblockindex++;

    //store second comp value in reg
    snprintf(codeblock_array[codeblockindex],127,"mov bx, %s\t;store if RHS cond var in reg\n",n->L->L->R->token);
    codeblockindex++;
    //check comparison
     if(strchr(n->L->L->token,'<')!=NULL && totalifstmt > 0){
      snprintf(codeblock_array[codeblockindex],127,
	       "cmp ax, bx\t;compare if stmt conditions\n");
      codeblockindex++;
      //jump to ifstmt
      snprintf(codeblock_array[codeblockindex],127,"jl ifstmt%i\t;jump if lessthan\n",ifstmtcounter);
      codeblockindex++;
      ifstmtcounter++;
      totalifstmt--;
      //generate inside ifblock recursivly
       gencodeblock(n->L->R);
      ifcodeblock(n->L->R);
      //check for else
      if(n->R != NULL){
	//gen code for else block recursivly
	//	gencodeblock(n->R);
	ifcodeblock(n->R);
      }
     }else if(strchr(n->L->L->token,'>')!=NULL && totalifstmt > 0){
      snprintf(codeblock_array[codeblockindex],127,
	       "cmp ax, bx\t;compare if stmt conditions\n");
      codeblockindex++;
      //jump to ifstmt
      snprintf(codeblock_array[codeblockindex],127,"jg ifstmt%i\t;jump if greater than\n",ifstmtcounter);
      ifstmtcounter++;
      codeblockindex++;
      totalifstmt--;
      
      //print ifstmt label
      snprintf(codeblock_array[codeblockindex],127,"ifstmt%i:\t ifstmt start label\n",ifstmtcounter);
      codeblockindex++;
      //generate ifblock content recursivly
      // gencodeblock(n->L->R);
      ifcodeblock(n->L->R);
      //check for else
      if(n->R != NULL){
	//gen code for else block recursivly
	gencodeblock(n->R);
	ifcodeblock(n->R);
      }
     }

     
  }
  
  /*PRINT STATEMENT CODE GENERATION*/
  if(strcmp(n->token,"PRINTSTMT")==0){
    //codeblock_array[codeblockindex]
    //PRINT LITERAL DECLARED INLINE
    if((memcmp(n->R->token,"\"",1))){
      // snprintf(codeblock_array[codeblockindex],127,"")
      //print stmt R node is literal
      snprintf(codeblock_array[codeblockindex],127,"mov ecx, %s\t;store string to print in ecx\nint 0x80\t;print value stored in ecx\n",n->R->token);
      codeblockindex++;
	}else{
      //print predefined string
      if(pstmtcounter < numdefinedstr){
	snprintf(codeblock_array[codeblockindex],127,"mov edx,len%i\nmov dx,msg%i\nmov ebx,1\nmov dx,4\nint 0x80\n\n",
		 pstmtcounter,pstmtcounter);
	pstmtcounter++;
	codeblockindex++;
      }
    }
  }
  //check for scanstmt
  
  //check for assignment

    if(n->R){
      gencodeblock(n->R);
    }

}

void gencode(struct node*n){

  //open and create file to write to
  FILE *fp;
  fp = fopen("output.s","w+a");
  //gen variables
  gencodevars(n);
  //generate strings
  gencodestrings(n);
  printf("section .text\n\n");
  fprintf(fp,"section .text\n\n");
  //global vars here

  //assigning entrypoint
  printf("global_start\n\n");
  fprintf(fp,"global_start\n\n");
  //string section and predefined locals
  printf("section .data\n\n");
  fprintf(fp,"section .data\n\n");
  for(int i = 0; i < 40; i++){
    printf("%s",codevar_array[i]);
    fprintf(fp,"%s",codevar_array[i]);
  }
  for(int i = 0; i < 40; i++){
    printf("%s",string_array[i]);
    fprintf(fp,"%s",string_array[i]);
  }
  //code start section
  printf("\nsection .text\n\n");
  fprintf(fp,"\nsection .text\n\n");

  //start of program
  printf("_start:\n");
  fprintf(fp,"_start:\n");
  //generated code here

  //gencodeblock call
  gencodeblock(n);
  //print codeblock generation
  for(int i = 0; i < 128; i++){
    printf("%s",codeblock_array[i]);
    fprintf(fp,"%s",codeblock_array[i]);
  }
  //exit via kernel syscall
  fprintf(fp,"\nint 0x80\t;END PROGRAM CALLS\nmov ebx,0\nmov eax,1\nint 0x80\n");
  //call kernel
  printf("\nint 0x80\t;END PROGRAM CALLS\n");
  //process exit
  printf("mov ebx,0\n");
  printf("mov eax,1\n");
  //final kernel call
  printf("int 0x80\n");

  //cleanup
  //free tree memory
  cleanup(root);
  //close file
  fclose(fp);
  
}

struct node* createNode(struct node *L, struct node *R, char *tok){
  //allocate memory and set leaf nodes
  struct node* leaf = (struct node*)malloc(sizeof(struct node));
  char *data = (char*)malloc(strlen(tok)+1);
  strcpy(data,tok);
  leaf->L = L;
  leaf->R = R;
  leaf->token = data;
  return leaf;
}

void cleanup(struct node* n){
  //Recursivly delete syntax tree
  if(n == NULL){
    return;
  }
  //delete l child
  cleanup(n->L);
  //delete r child
  cleanup(n->R);
  //delete current node and token data
  free(n->token);
  free(n);
  return;
}

void no_declaration(char *s){
  //check symtable for declared variable if none exists output error
  status = lookup(s);
  if(!status){
    sprintf(errarray[errindex],"ERROR: Line: %i Variable (%s) undeclared before usage.\n",lineno+1,s);
    errindex++;
  }
}

void mult_declaration(char *s){
  /*TODO*/
}

void keyword_var(char *s){
  for(int i = 0; i < 11; i++){
  if(strcmp(s,"begin")==0){
    sprintf(errarray[errindex],"ERROR: Line: %i Variable (%s) cannot be a key word.\n",lineno+1,s);
    errindex++;
  }
  }
}

int type_checker(char *s1, char *s2){
  /*TODO*/
}

char *get_current_type(char *s){
  /*TODO*/
}


int main() {

  printf("Parsing...\n");
  int res = yyparse();

  //ERROR CHECK
  if(errindex > 0){
    //errors detected
    printf("ERRORS OCCURED:\n");
    for(int i = 0; i < errindex; i++){
      printf("%s\n",errarray[i]);
      
    }
    exit(1);
  }
  
  printf("DONE\n");
  printf("DUMPING SYM TABLE\n");
  dumpsymtbl();
  printf("----------PRINTING SYNTAX TREE----------\n");
  printSynTree(root);
  printf("\n------------------DONE------------------\n");
  printf("-------------GENERATING CODE------------\n");
  gencode(root);
  printf("---------DONE CODE GENERATION-----------\n");
  printf("--[Generated code saved to \"output.s\"]--\n");
  return(res);
  
}

