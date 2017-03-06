/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_SCANNER_TAB_H_INCLUDED
# define YY_YY_SCANNER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    ID = 258,
    INT = 259,
    DOUBLE = 260,
    BOOLEAN = 261,
    STRING = 262,
    VOID = 263,
    CLASS = 264,
    IMPLEMENTS = 265,
    EXTENDS = 266,
    INTERFACE = 267,
    IF = 268,
    ELSE = 269,
    WHILE = 270,
    FOR = 271,
    BREAK = 272,
    RETURN = 273,
    PRINTLN = 274,
    READLN = 275,
    NEWARRAY = 276,
    INTCONSTANT = 277,
    DOUBLECONSTANT = 278,
    STRINGCONSTANT = 279,
    BOOLEANCONSTANT = 280,
    ASSIGNOP = 281,
    OR = 282,
    AND = 283,
    EQUAL = 284,
    NOTEQUAL = 285,
    LESS = 286,
    GREATER = 287,
    LESSEQUAL = 288,
    GREATEREQUAL = 289,
    PLUS = 290,
    MINUS = 291,
    MULTIPLICATION = 292,
    DIVISION = 293,
    MOD = 294,
    NOT = 295,
    UMINUS = 296,
    LEFTBRACKET = 297,
    RIGHTBRACKET = 298,
    PERIOD = 299,
    LEFTBRACE = 300,
    RIGHTBRACE = 301,
    LEFTPAREN = 302,
    RIGHTPAREN = 303,
    SEMICOLON = 304,
    COMMA = 305,
    THEN = 306,
    STATIC = 307
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 12 "scanner.y" /* yacc.c:1909  */
int num; char id;

#line 110 "scanner.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SCANNER_TAB_H_INCLUDED  */
