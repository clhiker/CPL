%option outfile="cpl_lexer.c" header-file="cpl_lexer.h"
%option noyywrap nounput noinput never-interactive

%{
#include "cpl_parser.h"
extern int cpl_atoi(const char *src);
extern double cpl_atof(const char *s);
extern char * cpl_strcpy(char *dst,const char *src);

typedef union{
    int i_num;
    float f_num;
    char str[32];
    struct astnode* node;
} YYLVAL;
#define YYSTYPE YYLVAL

%}

alpha [a-zA-Z]
digit [0-9]

SP  (u8|u|U|L)
ES  (\\(['"\?\\abfnrtv]|[0-7]{1,3}|x[a-fA-F0-9]+))
WS  [ \t\v\n\f]

%%
[ \t]		;
[ \n]   { yylineno = yylineno + 1;}
"int"	{cpl_strcpy(yylval.str, yytext); return INT;}
"float" {cpl_strcpy(yylval.str, yytext); return FLOAT;}
"char"  {cpl_strcpy(yylval.str, yytext); return CHAR;}
"From"  {cpl_strcpy(yylval.str, yytext); return FROM;}
"To"    {cpl_strcpy(yylval.str, yytext); return TO;}
"plus"	{cpl_strcpy(yylval.str, yytext); return PLUS;}
"minus"	{cpl_strcpy(yylval.str, yytext); return MINUS;}
"times" 	   {cpl_strcpy(yylval.str, yytext); return TIMES;}
"devide"  	   {cpl_strcpy(yylval.str, yytext); return DEVIDE;}
"or"               {cpl_strcpy(yylval.str, yytext); return LOR;}
"and"              {cpl_strcpy(yylval.str, yytext); return LAND;}
"not"              {cpl_strcpy(yylval.str, yytext); return LNOT;}
"eq"               {cpl_strcpy(yylval.str, yytext); return EQ;}
"neq"              {cpl_strcpy(yylval.str, yytext); return NEQ;}
"ge"               {cpl_strcpy(yylval.str, yytext); return GE;}
"le"               {cpl_strcpy(yylval.str, yytext); return LE;}
"gt"	           {cpl_strcpy(yylval.str, yytext); return GT;}
"lt"	           {cpl_strcpy(yylval.str, yytext); return LT;}
"de_eq"            {cpl_strcpy(yylval.str, yytext); return DE_EQ;}
"de_neq"           {cpl_strcpy(yylval.str, yytext); return DE_NEQ;}
"de_ge"            {cpl_strcpy(yylval.str, yytext); return DE_GE;}
"de_le"            {cpl_strcpy(yylval.str, yytext); return DE_LE;}
"de_gt"	           {cpl_strcpy(yylval.str, yytext); return DE_GT;}
"de_lt"	           {cpl_strcpy(yylval.str, yytext); return DE_LT;}
"="                {cpl_strcpy(yylval.str, yytext); return ASGN;}
"Mission"          {cpl_strcpy(yylval.str, yytext); return Mission;}
"MissionID"        {cpl_strcpy(yylval.str, yytext); return MissionID;}
"MissionName"      {cpl_strcpy(yylval.str, yytext); return MissionName;}
"Priority"         {cpl_strcpy(yylval.str, yytext); return Priority;}
"ComponentList"    {cpl_strcpy(yylval.str, yytext); return ComponentList;}
"Component"        {cpl_strcpy(yylval.str, yytext); return Component;}
"ComponentID"      {cpl_strcpy(yylval.str, yytext); return ComponentID;}
"ComponentName"    {cpl_strcpy(yylval.str, yytext); return ComponentName;}
"Observation"      {cpl_strcpy(yylval.str, yytext); return Observation;}
"Orientation"      {cpl_strcpy(yylval.str, yytext); return Orientation;}
"Decision"         {cpl_strcpy(yylval.str, yytext); return Decision;}
"Action"           {cpl_strcpy(yylval.str, yytext); return Action;}
[-]*{digit}+       {yylval.i_num = cpl_atoi(yytext); return IntNum;}
[-]*([0-9]*\.[0-9]+)|([0-9]+\.)   {yylval.f_num = cpl_atof(yytext); return FloatNum;}
{alpha}({alpha}|{digit}|_)*       {cpl_strcpy(yylval.str, yytext); return Identifier;}
({SP}?\"([^"\\\n]|{ES})*\"{WS}*)+ {cpl_strcpy(yylval.str, yytext); return STRING;}

\/\/.* {};
\/\*(.*\n)*.*\*\/ {};
.       return yytext[0];
%%
