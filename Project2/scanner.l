%{
#include "scanner.tab.h"
%}

%%
[ \t\n]		;
"+"		{printf("plus ");return PLUS;}
"-"		{printf("minus ");return MINUS;}
"*"		{printf("multiplication ");return MULTIPLICATION;}
"%"		{printf("mod ");return MOD;}
"//".+		{printf("ACK ");}
"/"		{printf("division ");return DIVISION;}
"("		{printf("leftparen ");return LEFTPAREN;}
")"		{printf("rightparen ");return RIGHTPAREN;}
"{"		{printf("leftbrace \n");return LEFTBRACE;}
"}"		{printf("rightbrace \n");return RIGHTBRACE;}
"["		{printf("leftbrack ");return LEFTBRACKET;}
"]"		{printf("rightbrack ");return RIGHTBRACKET;}
";"		{printf("semicolon \n");return SEMICOLON;}
","		{printf("comma ");return COMMA;}
"."		{printf("period ");return PERIOD;}
"=="		{printf("equal ");return EQUAL;}
"!="		{printf("notequal ");return NOTEQUAL;}
"<"		{printf("less ");return LESS;}
">"		{printf("greater ");return GREATER;}
"<="		{printf("lessequal ");return LESSEQUAL;}
">="		{printf("greaterequal ");return GREATEREQUAL;}
"&&"		{printf("and ");return AND;}
"||"		{printf("or ");return OR;}
"!"		{printf("not ");return NOT;}
"="		{printf("assignop ");return ASSIGNOP;}
"boolean"	{printf("boolean ");return BOOLEAN;}
"break"		{printf("break ");return BREAK;}
"class"		{printf("class ");return CLASS;}
"double"	{printf("double ");return DOUBLE;}
"else"		{printf("else ");return ELSE;}
"if"		{printf("if ");return IF;}
"extends"	{printf("extends ");return EXTENDS;}
"false"		{printf("booleanconstant ");return BOOLEANCONSTANT;}
"for"		{printf("for ");return FOR;}
"implements"	{printf("implements ");return IMPLEMENTS;}
"interface"	{printf("interface ");return INTERFACE;}
"int"		{printf("int ");return INT;}
"newarray"	{printf("newarray ");return NEWARRAY;}
"println"	{printf("println ");return PRINTLN;}
"readln"	{printf("readln ");return READLN;}
"return"	{printf("return ");return RETURN;}
"string"	{printf("string ");return STRING;}
"true"		{printf("booleanconstant ");return BOOLEANCONSTANT;}
"void"		{printf("void ");return VOID;}
"while"		{printf("while ");return WHILE;}

[0-9]+		{printf("intconstant ");return INTCONSTANT;}
0[xX][A-Fa-f0-9]+	{printf("intconstant ");return INTCONSTANT;}
[0-9]+"."[0-9]*	{printf("doubleconstant ");return DOUBLECONSTANT;}
[0-9]+"."[0-9]*("E"|"e")("+"|"-")?[0-9]+	{printf("doubleconstant ");return DOUBLECONSTANT;}
"/*"[^*]*"*"+([^*/][^*]*"*"+)*"/"	{printf("");}
[\"][^"\n"]*[\"]		{printf("stringconstant ");return STRINGCONSTANT;}
[A-Za-z][A-Za-z0-9_]*	{printf("id ");return ID;}

.		{printf("InvalidInput ");}

%%
int yywrap(void) {return 1;}
