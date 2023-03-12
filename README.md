CSCI 439 FINAL PROJECT (C Minus Minus)

# cmm.exe

The objective of this program is to create a compiler to compile code from a made up language I
have dubbed C-- to x86 assembly using lex and yacc for parsing and tokenization as well as
C code for translation, symbol table and syntax tree building.

## Technologies

   # Languages
	C
	BASH (makefile)
	LEX (tokenizer)
	YACC (parsing)

   # C LIBRARIES
   <stdio.h>
   <string.h>
   <stdlib.h>
   <ctype.h>
   "y.tab.h"
   "lex.yy.c"

   # FILES
   lexer.lex
   parser.yacc
   makefile
   
   ProjectProposal.pdf
   README

   # Test files
   testprog.txt (test program to be compiled when make-run is entered)
   testloop.txt (simple loop test)
   testsbad/badprog1 (undeclared variable test)
   testsbad/keywordvar (using keyword as variable test)
   testsbad/multdecl (multiple declaration test)

## Build, Installation and Running the executable
   1) Type make to build the executible
   2) Type make-run to run the executible on testprog.txt
   3) Type make clean to clear the executible and associated output file

   ## Run on custom files
   1) To build the executible type make
   2) type ./cmm < program.txt
   This will run the compiled on other files besides testprog.txt if you want to run the
   test files for error checking simply type ./cmm < testsbad/filename.txt (badprog1)
   
## Sample Output
## Sample Code Used
 ![image](https://user-images.githubusercontent.com/58760187/224576044-2af9f885-f4f5-4933-bdfb-ecfb2c4b7b5c.png)

## Symbol Table Generated
 ![image](https://user-images.githubusercontent.com/58760187/224575980-19f4e1f4-ebae-4765-a079-25ea6c2ac41d.png)
 
## X86 Assembly Generated
 <code>
section .text
global_start
section .data
x DQ 9
msg0 DQ "test1", 0 
len0 equ $ - abc
msg1 DQ "test2", 0 
len1 equ $ - xyz
section .text

_start:
mov edx,len0
mov dx,msg0
mov ebx,1
mov dx,4
int 0x80
mov ecx, 0	;store loop index var on stack
jmp loop0
loop0:
push ecx	;save loop index on stack
mov ecx, y	;store string to print in ecx
int 0x80	;print value stored in ecx
mov edx,len1
mov dx,msg1
mov ebx,1
mov dx,4
int 0x80
mov ax, y	;store if LHS COND var in reg
mov bx, 5	;store if RHS cond var in reg
cmp ax, bx	;compare if stmt conditions
jg ifstmt0	;jump if greater than
ifstmt1:	 ifstmt start label
mov ecx, "y is > 5"	;store string to print in ecx
int 0x80	;print value stored in ecx
pop ecx	;get loop index
add ecx, 1
cmp ecx, 10
jl loop0
mov ecx, y	;store string to print in ecx
int 0x80	;print value stored in ecx
mov ax, y	;store if LHS COND var in reg
mov bx, 5	;store if RHS cond var in reg
mov ecx, abc	;store string to print in ecx
int 0x80	;print value stored in ecx
mov ecx, abc	;store string to print in ecx
int 0x80	;print value stored in ecx
mov ecx, xyz	;store string to print in ecx
int 0x80	;print value stored in ecx
mov ecx, abc	;store string to print in ecx
int 0x80	;print value stored in ecx
int 0x80	;END PROGRAM CALLS
mov ebx,0
mov eax,1
int 0x80
</code>

## Known Issues and Bugs

   Currently the only error checking that is working is checking for undeclared variables.
   Using a keyword as a variable name results in error as expected but the error is being
   generated by the lexer rule for unrecognized input instead of a custom rule.

   I was having trouble finding good documentation on x86 scanning so currently scan statements
   are unimplemented. BOOL types are untested and code generation for bool types in currently un-
   implemented.

   There is also an issue with the parsing as statements in scope of a for loop or if statement
   are generated twice in assembly and sometimes with the wrong label number. I will either need to add a element 
   to each tree node to keep track of the current scope and change my generate code functions to
   generate based on scope, Or make separate code generation functions for statements within loop and
   if statement scope and general code block statements.

# Sources
I pulled some inspiration from this implementation of a C compiler
https://medium.com/codex/building-a-c-compiler-using-lex-and-yacc-446262056aaa

x86 assembly guide and resources
https://docs.oracle.com/cd/E19253-01/817-5477/817-5477.pdf
https://en.wikibooks.org/wiki/X86_Assembly/Interfacing_with_Linux
https://montcs.bloomu.edu/Information/LowLevel/Assembly/hello-asm.html
