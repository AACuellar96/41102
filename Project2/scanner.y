%{
#include <stdio.h>
#include <stdlib.h>
#define YYDEBUG 1
void yyerror (char *s);
extern int yylex();
extern int yyparse();
extern FILE *yyin;
extern FILE *yyout;
%}

%union {int num; char id;}
%error-verbose
%token ID
%token INT
%token DOUBLE
%token BOOLEAN
%token STRING
%token VOID
%token CLASS
%token IMPLEMENTS
%token EXTENDS
%token INTERFACE
%token IF
%token ELSE
%token WHILE
%token FOR
%token BREAK
%token RETURN
%token PRINTLN
%token READLN
%token NEWARRAY
%token INTCONSTANT
%token DOUBLECONSTANT
%token STRINGCONSTANT
%token BOOLEANCONSTANT
%token ASSIGNOP "="
%token OR "||"
%token AND "&&"
%token EQUAL "=="
%token NOTEQUAL "!="
%token LESS "<"
%token GREATER ">"
%token LESSEQUAL "<="
%token GREATEREQUAL ">="
%token PLUS "+"
%token MINUS "-"
%token MULTIPLICATION "*"
%token DIVISION "/"
%token MOD "%"
%token NOT "!"
%token UMINUS
%token LEFTBRACKET "["
%token RIGHTBRACKET "]"
%token PERIOD "."
%token LEFTBRACE "{"
%token RIGHTBRACE "}"
%token LEFTPAREN "("
%token RIGHTPAREN ")"
%token SEMICOLON ";"
%token COMMA ","

%right "="
%nonassoc "||"
%nonassoc "&&"
%nonassoc "==" "!="
%nonassoc "<" "<=" ">" ">="
%left "+" "-"
%left "*" "/" "%"
%right "!" UMINUS
%nonassoc "[""]" "."
%nonassoc THEN
%nonassoc ELSE
%nonassoc STATIC
%%

Program : Program Decl;
Program : Decl;
Decl : VariableDecl;
Decl : FunctionDecl;
Decl : ClassDecl;
Decl : InterfaceDecl;
VariableDecl : Variable ";";
Variable : Type ID;
Type : INT;
Type : DOUBLE;
Type : BOOLEAN;
Type : STRING;
Type : Type "[""]";
Type : ID;
FunctionDecl : Type ID "(" Formals ")" StmtBlock;
FunctionDecl : VOID ID "(" Formals ")" StmtBlock;
Formals : Variable;
Formals : Formal "," Variable;
Formals : ;
Formal : Formal "," Variable;
Formal : Variable;
ClassDecl : CLASS ID Ext Iid "{" Field "}";
ClassDecl : CLASS ID Ext Iid "}" "}";
Ext : IMPLEMENTS ID;
Ext : ;
Iid : ;
Iid : EXTENDS ID;
Iid : EXTENDS ID "," Aid;
Aid : Aid "," ID;
Aid : ID;
Field : Field VariableDecl;
Field : Field FunctionDecl;
Field : VariableDecl;
Field : FunctionDecl;
InterfaceDecl : INTERFACE ID "{" Prototype "}";
InterfaceDecl : INTERFACE ID "{" "}";
Prototype : Prototype Type ID "(" Formals ")" ";";
Prototype : Prototype VOID ID "(" Formals ")" ";";
Prototype : Type ID "(" Formals ")" ";";
Prototype : VOID ID "(" Formals ")" ";";
StmtBlock : "{" Vd Sd "}";
StmtBlock : "{" Sd "}";
StmtBlock : "{" Vd "}";
StmtBlock : "{" "}";
Vd : Vd VariableDecl;
Vd : VariableDecl;
Sd : Sd Stmt;
Sd : Stmt;
Stmt : Expr ";";
Stmt : ";";
Stmt : IfStmt ;
Stmt : WhileStmt ;
Stmt : ForStmt ;
Stmt : BreakStmt ;
Stmt : ReturnStmt ;
Stmt : PrintStmt ;
Stmt : StmtBlock ;
IfStmt : IF "(" Expr ")" Stmt %prec THEN ;
IfStmt : IF "(" Expr ")" Stmt ELSE Stmt;
WhileStmt : WHILE "(" Expr ")" Stmt;
ForStmt : FOR "(" Expr ";" Expr ";" Expr ")" Stmt;
ForStmt : FOR "(" ";" Expr ";" Expr ")" Stmt;
ForStmt : FOR "(" ";" Expr ";" ")" Stmt;
ForStmt : FOR "(" Expr ";" Expr ";" ")" Stmt;
BreakStmt : BREAK;
ReturnStmt : RETURN ";";
ReturnStmt : RETURN Expr ";";
PrintStmt : PRINTLN "(" EX ")" ";";
Expr : Lvalue "=" Expr;
Expr : Constant;
Expr : Lvalue;
Expr : Call;
Expr : "(" Expr ")";
Expr : Expr "+" Expr;
Expr : Expr "-" Expr;
Expr : Expr "*" Expr;
Expr : Expr "/" Expr;
Expr : Expr "%" Expr;
Expr : "-" Expr %prec UMINUS;
Expr : Expr "<" Expr;
Expr : Expr "<=" Expr;
Expr : Expr ">" Expr;
Expr : Expr ">=" Expr;
Expr : Expr "==" Expr;
Expr : Expr "!=" Expr;
Expr : Expr "&&" Expr;
Expr : Expr "||" Expr;
Expr : "!" Expr;
Expr : READLN "("")";
Expr : NEWARRAY "(" INTCONSTANT "," Type ")";
Lvalue : ID;
Lvalue : Lvalue "[" Expr "]" ;
Lvalue : Lvalue "." ID;
Call : ID "(" Actuals ")";
Call : ID "." ID "(" Actuals ")" %prec STATIC;
Actuals : EX;
Actuals : ;
EX : EX "," Expr;
EX : Expr;
Constant : INTCONSTANT;
Constant : DOUBLECONSTANT;
Constant : STRINGCONSTANT;
Constant : BOOLEANCONSTANT;
%%

void yyerror (char *s) {fprintf (stderr, "%s\n", s);}
int main(void){
yydebug=1;
yyparse();
return 0;
} 
