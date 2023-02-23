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

#ifndef YY_YY_CPL_PARSER_H_INCLUDED
# define YY_YY_CPL_PARSER_H_INCLUDED
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
    STRING = 258,
    INT = 259,
    FLOAT = 260,
    CHAR = 261,
    IntNum = 262,
    FloatNum = 263,
    Identifier = 264,
    FROM = 265,
    TO = 266,
    Mission = 267,
    MissionID = 268,
    MissionName = 269,
    Priority = 270,
    ComponentList = 271,
    Component = 272,
    ComponentID = 273,
    ComponentName = 274,
    Observation = 275,
    Orientation = 276,
    Decision = 277,
    Action = 278,
    LOR = 279,
    LAND = 280,
    LNOT = 281,
    EQ = 282,
    NEQ = 283,
    LE = 284,
    GE = 285,
    LT = 286,
    GT = 287,
    PLUS = 288,
    MINUS = 289,
    TIMES = 290,
    DEVIDE = 291,
    DE_EQ = 292,
    DE_NEQ = 293,
    DE_LE = 294,
    DE_GE = 295,
    DE_LT = 296,
    DE_GT = 297,
    ASGN = 298
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 15 "cpl.y" /* yacc.c:1909  */

  int i_num;
  float f_num;
  char str[64];
  struct astnode* node;

#line 105 "cpl_parser.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (struct astnode **rootnode);

#endif /* !YY_YY_CPL_PARSER_H_INCLUDED  */
