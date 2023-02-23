/* Bison Directives */
%defines "cpl_parser.h"
%output  "cpl_parser.c"
/* define tokens and the priority of operators */
%parse-param {struct astnode **rootnode} // Adds variables to be passed into yyparse()
/* This section is copied verbatim to the .C file generated */
%code{
#include "ast.h"
#include "cpl_lexer.h"
/* yyerror() needs the parse-param's defined aswell */
void yyerror (struct astnode **rootnode, char const *s);
}

/* YYLVAL types*/
%union{
  int i_num;
  float f_num;
  char str[64];
  struct astnode* node;
};

/* define tokens and the priority of operators */

%token <str>STRING
%token <str>INT FLOAT CHAR
%token <i_num>IntNum
%token <f_num>FloatNum
%token <str>Identifier
%token <str>FROM TO
%token <str>Mission MissionID MissionName Priority
%token <str>ComponentList Component ComponentID ComponentName
%token <str>Observation Orientation Decision Action

%left <str>LOR LAND LNOT
%left <str>EQ NEQ
%left <str>LE GE LT GT
%left <str>PLUS MINUS
%left <str>TIMES DEVIDE
%left <str>DE_EQ DE_NEQ
%left <str>DE_LE DE_GE DE_LT DE_GT
%right <str>ASGN

/* Non Terminal Type DEclaration */
%type <node> mission ooda missionAttr missionID missionName priority
%type <node> compList comps comp compID compName
%type <node> observation obInsts orientation orInsts oneOrInst opOr opOr1
%type <node> decision deInsts oneDeInst opDe operand
%type <node> action actInsts
%type <node> stmts stmtN stmtVarDecl stmtCharArrayDecl
%type <node> identifierN stmtAssign stmtFrom stmtTo num type string
  
%%
%start input;


input
    : mission
    {
      *rootnode = $1;
    }
    ;

mission
    : Mission '{' missionAttr compList ooda '}'
    {
      $$ = new_NTnode(NT_mission);
      node * Mission = new_Tnode(T_Mission, -1, -1, $1);
      $$ = add_nodes($$, Mission, $3, $4, $5, NULL);;
    }
    ;

ooda
    : observation orientation decision action
    {
      $$ = new_NTnode(NT_ooda);
      $$ = add_nodes($$, $1, $2, $3, $4, NULL);;
    }
    ;

missionAttr
    : missionID missionName priority stmts
    {
      $$ = new_NTnode(NT_missionAttr);
      $$ = add_nodes($$, $1, $2, $3, $4, NULL);;
    }
    ;

missionID
    : MissionID ':' IntNum ';'
    {
      $$ = new_NTnode(NT_missionID);
      node * MissionID = new_Tnode(T_MissionID, -1, -1, $1);
      node * IntNum = new_Tnode(T_IntNum, $3, -1, "");
      $$ = add_nodes($$, MissionID, IntNum, NULL, NULL, NULL);
    }
    ;

missionName
    : MissionName ':' string ';'
    {
      $$ = new_NTnode(NT_missionName);
      node * MissionName = new_Tnode(T_MissionName, -1, -1, $1);
      $$ = add_nodes($$, MissionName, $3, NULL, NULL, NULL);
    }
    ;

priority
    : Priority ':' IntNum ';'
    {
      $$ = new_NTnode(NT_priority);
      node * Priority = new_Tnode(T_Priority, -1, -1, $1);
      node * IntNum = new_Tnode(T_IntNum, $3, -1, "");
      $$ = add_nodes($$, Priority, IntNum, NULL, NULL, NULL);
    }
    ;

compList 
    : ComponentList '{' comps '}'
    {
      $$ = new_NTnode(NT_compList);
      node * ComponentList = new_Tnode(T_ComponentList, -1, -1, $1);
      $$ = add_nodes($$, ComponentList, $3, NULL, NULL, NULL);
    }
    ;

comps 
    : comp
    {
      $$ = new_NTnode(NT_comps);
      $$ = add_nodes($$, $1, NULL, NULL, NULL, NULL);
    }
    | comps comp
    {
      $$ = new_NTnode(NT_comps);
      $$ = add_nodes($$, $1, $2, NULL, NULL, NULL);
    }
    ;

comp 
    : Component '{' compID  compName '}'
    {
      $$ = new_NTnode(NT_comp);
      node * Component = new_Tnode(T_Component, -1, -1, $1);
      $$ = add_nodes($$, Component, $3, $4, NULL, NULL);
    }
    ;

compID
    : ComponentID ':' IntNum ';'
    {
      $$ = new_NTnode(NT_compID);
      node * ComponentID = new_Tnode(T_ComponentID, -1, -1, $1);
      node * IntNum = new_Tnode(T_IntNum, $3, -1, "");
      $$ = add_nodes($$, ComponentID, IntNum, NULL, NULL, NULL);
    }
    ;

compName
    : ComponentName ':' string ';'
    {
      $$ = new_NTnode(NT_compName);
      node * ComponentName = new_Tnode(T_ComponentName, -1, -1, $1);
      $$ = add_nodes($$, ComponentName, $3, NULL, NULL, NULL);
    }
    ;

observation
    : Observation '{' obInsts '}'
    {
      $$ = new_NTnode(NT_observation);
      node * Observation = new_Tnode(T_Observation, -1, -1, $1);
      $$ = add_nodes($$, Observation, $3, NULL, NULL, NULL);
    }
    ;

obInsts
    : stmtFrom obInsts
    {
      $$ = new_NTnode(NT_obInsts);
      $$ = add_nodes($$, $1, $2, NULL, NULL, NULL);
    }
    |
    {
      $$ = NULL;
    }
    ;

orientation
    : Orientation '{' orInsts '}'
    {
      $$ = new_NTnode(NT_orientation);
      node * Orientation = new_Tnode(T_Orientation, -1, -1, $1);
      $$ = add_nodes($$, Orientation, $3, NULL, NULL, NULL);
    }
    ;

orInsts
    : oneOrInst orInsts
    {
      $$ = new_NTnode(NT_orInsts);
      $$ = add_nodes($$, $1, $2, NULL, NULL, NULL);
    }
    |
    {
      $$ = NULL;
    }
    ;

oneOrInst
    : opOr Identifier ',' Identifier ',' Identifier ';'
    {
      $$ = new_NTnode(NT_oneOrInst);
      node* Identifier1 = new_Tnode(T_Identifier, -1, -1, $2);
      node* Identifier2 = new_Tnode(T_Identifier, -1, -1, $4);
      node* Identifier3 = new_Tnode(T_Identifier, -1, -1, $6);
      $$ = add_nodes($$, $1, Identifier1, Identifier2, Identifier3, NULL);;
    }
    | opOr1 Identifier ',' Identifier ';'
    {
      $$ = new_NTnode(NT_oneOrInst);
      node* Identifier1 = new_Tnode(T_Identifier, -1, -1, $2);
      node* Identifier2 = new_Tnode(T_Identifier, -1, -1, $4);
      $$ = add_nodes($$, $1, Identifier1, Identifier2, NULL, NULL);
    }
    ;

opOr
    : PLUS
    {
      $$ = new_NTnode(NT_opOr);
      node * PlUS = new_Tnode(T_PLUS, -1, -1, $1);
      $$ = add_nodes($$, PlUS, NULL, NULL, NULL, NULL);
    }
    | MINUS
    {
      $$ = new_NTnode(NT_opOr);
      node * MINUS = new_Tnode(T_MINUS, -1, -1, $1);
      $$ = add_nodes($$, MINUS, NULL, NULL, NULL, NULL);
    }
    | TIMES
    {
      $$ = new_NTnode(NT_opOr);
      node * TIMES = new_Tnode(T_TIMES, -1, -1, $1);
      $$ = add_nodes($$, TIMES, NULL, NULL, NULL, NULL);
    }
    | DEVIDE
    {
      $$ = new_NTnode(NT_opOr);
      node * DEVIDE = new_Tnode(T_DEVIDE, -1, -1, $1);
      $$ = add_nodes($$, DEVIDE, NULL, NULL, NULL, NULL);
    }
    | LOR
    {
      $$ = new_NTnode(NT_opOr);
      node * LOR = new_Tnode(T_LOR, -1, -1, $1);
      $$ = add_nodes($$, LOR, NULL, NULL, NULL, NULL);
    }
    | LAND
    {
      $$ = new_NTnode(NT_opOr);
      node * LAND = new_Tnode(T_LAND, -1, -1, $1);
      $$ = add_nodes($$, LAND, NULL, NULL, NULL, NULL);
    }
    | EQ
    {
      $$ = new_NTnode(NT_opOr);
      node * EQ = new_Tnode(T_EQ, -1, -1, $1);
      $$ = add_nodes($$, EQ, NULL, NULL, NULL, NULL);
    }
    | NEQ
    {
      $$ = new_NTnode(NT_opOr);
      node * NEQ = new_Tnode(T_NEQ, -1, -1, $1);
      $$ = add_nodes($$, NEQ, NULL, NULL, NULL, NULL);
    }
    | GE
    {
     $$ = new_NTnode(NT_opOr);
     node * GE = new_Tnode(T_GE, -1, -1, $1);
     $$ = add_nodes($$, GE, NULL, NULL, NULL, NULL);
    }
    | LE
    {
      $$ = new_NTnode(NT_opOr);
      node * LE = new_Tnode(T_LE, -1, -1, $1);
      $$ = add_nodes($$, LE, NULL, NULL, NULL, NULL);
    }
    | GT
    {
      $$ = new_NTnode(NT_opOr);
      node * GT = new_Tnode(T_GT, -1, -1, $1);
      $$ = add_nodes($$, GT, NULL, NULL, NULL, NULL);
    }
    | LT
    {
      $$ = new_NTnode(NT_opOr);
      node * LT = new_Tnode(T_LT, -1, -1, $1);
      $$ = add_nodes($$, LT, NULL, NULL, NULL, NULL);
    }
    ;

opOr1
    : LNOT
    {
      $$ = new_NTnode(NT_opOr1);
      node * LNOT = new_Tnode(T_LNOT, -1, -1, $1);
      $$ = add_nodes($$, LNOT, NULL, NULL, NULL, NULL);
    }
    ;

decision
    : Decision '{' deInsts '}' 
    {
     $$ = new_NTnode(NT_decision);
     node * Decision = new_Tnode(T_Decision, -1, -1, $1);
     $$ = add_nodes($$, Decision, $3, NULL, NULL, NULL);
    }
    ;

deInsts
    : oneDeInst deInsts
    {
      $$ = new_NTnode(NT_deInsts);                      
      $$ = add_nodes($$, $1, $2, NULL, NULL, NULL);
    }
    |
    {
      $$ = NULL;
    }
    ;

oneDeInst
    : opDe operand ',' operand ';'
    {
      $$ = new_NTnode(NT_oneDeInst);             
      $$ = add_nodes($$, $1, $2, $4, NULL, NULL);
    }
    ;

opDe
    : DE_EQ
    {
      $$ = new_NTnode(NT_opDe);
      node * DE_EQ = new_Tnode(T_DE_EQ, -1, -1, $1);
      $$ = add_nodes($$, DE_EQ, NULL, NULL, NULL, NULL);
    }
    | DE_NEQ
    {
      $$ = new_NTnode(NT_opDe);
      node * DE_NEQ = new_Tnode(T_DE_NEQ, -1, -1, $1);
      $$ = add_nodes($$, DE_NEQ, NULL, NULL, NULL, NULL);
    }
    | DE_GE
    {
      $$ = new_NTnode(NT_opDe);
      node * DE_GE = new_Tnode(T_DE_GE, -1, -1, $1);
      $$ = add_nodes($$, DE_GE, NULL, NULL, NULL, NULL);
    }
    | DE_LE
    {
      $$ = new_NTnode(NT_opDe);
      node * DE_LE = new_Tnode(T_DE_LE, -1, -1, $1);
      $$ = add_nodes($$, DE_LE, NULL, NULL, NULL, NULL);
    }
    | DE_GT
    {
      $$ = new_NTnode(NT_opDe);
      node * DE_GT = new_Tnode(T_DE_GT, -1, -1, $1);
      $$ = add_nodes($$, DE_GT, NULL, NULL, NULL, NULL);
    }
    | DE_LT
    {
      $$ = new_NTnode(NT_opDe);
      node * DE_LT = new_Tnode(T_DE_LT, -1, -1, $1);
      $$ = add_nodes($$, DE_LT, NULL, NULL, NULL, NULL);
    }
    ;
    
operand
    : Identifier
    {
      $$ = new_NTnode(NT_operand);
      node* Identifier = new_Tnode(T_Identifier, -1, -1, $1);
      $$ = add_nodes($$, Identifier, NULL, NULL, NULL, NULL);
    }
    | num
    {
      $$ = new_NTnode(NT_operand);
      $$ = add_nodes($$, $1, NULL, NULL, NULL, NULL);
    }
    ;   

action
    : Action '{' actInsts '}'
    {
      $$ = new_NTnode(NT_action);
      node * Action = new_Tnode(T_Action, -1, -1, $1);
      $$ = add_nodes($$, Action, $3, NULL, NULL, NULL);
    }
    ; 

actInsts
    : stmtTo actInsts
    {
      $$ = new_NTnode(NT_actInsts);
      $$ = add_nodes($$, $1, $2, NULL, NULL, NULL);
    }
    |
    {
      $$ = NULL;
    }
    ;
				
stmts
    : stmtN stmts
    {
      $$ = new_NTnode(NT_stmts);
      $$ = add_nodes($$, $1, $2, NULL, NULL, NULL);
    }
    |
    {
      $$ = NULL;
    }
    ;

stmtN
    : stmtVarDecl
    {
      $$ = new_NTnode(NT_stmtN);
      $$ = add_nodes($$, $1, NULL, NULL, NULL, NULL);
    }
    | stmtCharArrayDecl
    {
      $$ = new_NTnode(NT_stmtN);
      $$ = add_nodes($$, $1, NULL, NULL, NULL, NULL);
    }
    | stmtAssign
    {
      $$ = new_NTnode(NT_stmtN);
      $$ = add_nodes($$, $1, NULL, NULL, NULL, NULL);
    }
    | ';'
    {
      $$ = NULL;
    }
    ;

stmtVarDecl
    : type Identifier identifierN
    {
      $$ = new_NTnode(NT_stmtVarDecl);
      node * Identifier = new_Tnode(T_Identifier, -1, -1, $2);
      $$ = add_nodes($$, $1, Identifier, $3, NULL, NULL);
    }
    | type Identifier ASGN num identifierN
    {
      $$ = new_NTnode(NT_stmtVarDecl);
      node * Identifier = new_Tnode(T_Identifier, -1, -1, $2);
      node * ASGN = new_Tnode(T_ASGN, -1, -1, $3);
      $$ = add_nodes($$, $1, Identifier, ASGN, $4, $5);
    }
    ;

stmtCharArrayDecl
    : CHAR Identifier '[' IntNum ']' ';'
    {
      $$ = new_NTnode(NT_stmtCharArrayDecl);
      node * CHAR = new_Tnode(T_CHAR, -1, -1, $1);
      node * Identifier = new_Tnode(T_Identifier, -1, -1, $2);
      node * IntNum = new_Tnode(T_IntNum, $4, -1, "");
      $$ = add_nodes($$, CHAR, Identifier, IntNum, NULL, NULL);
    }
    | CHAR Identifier '[' IntNum ']' ASGN string ';'
    {
      $$ = new_NTnode(NT_stmtCharArrayDecl);
      node * CHAR = new_Tnode(T_CHAR, -1, -1, $1);
      node * Identifier = new_Tnode(T_Identifier, -1, -1, $2);
      node * IntNum = new_Tnode(T_IntNum, $4, -1, "");
      node * ASGN = new_Tnode(T_ASGN, -1, -1, $6);
      $$ = add_nodes($$, CHAR, Identifier, IntNum, ASGN, $7);
    }
    ;

identifierN
    : ';'
    {
      $$ = NULL;
    }
    | ',' Identifier identifierN
    {
      $$ = new_NTnode(NT_identifierN);
      node * Identifier = new_Tnode(T_Identifier, -1, -1, $2);
      $$ = add_nodes($$, Identifier, $3, NULL, NULL, NULL);
    }
    | ',' Identifier ASGN num identifierN
    {
      $$ = new_NTnode(NT_identifierN);
      node * Identifier = new_Tnode(T_Identifier, -1, -1, $2);
      node * ASGN = new_Tnode(T_ASGN, -1, -1, $3);
      $$ = add_nodes($$, Identifier, ASGN, $4, $5, NULL);
    }
    ;

stmtAssign
    : Identifier ASGN num ';'
    {
      $$ = new_NTnode(NT_stmtAssign);
      node * Identifier = new_Tnode(T_Identifier, -1, -1, $1);
      node * ASGN = new_Tnode(T_ASGN, -1, -1, $2);
      $$ = add_nodes($$, Identifier, ASGN, $3, NULL, NULL);
    }
    ;

stmtFrom
    : FROM string ':' Identifier ';'
    {
      $$ = new_NTnode(NT_stmtFrom);
      node * FROM = new_Tnode(T_FROM, -1, -1, $1);
      node * Identifier = new_Tnode(T_Identifier, -1, -1, $4);
      $$ = add_nodes($$, FROM, $2, Identifier, NULL, NULL);
    }
    ;

stmtTo
    : TO string ':' Identifier ';'
    {
      $$ = new_NTnode(NT_stmtTo);
      node * TO = new_Tnode(T_TO, -1, -1, $1);
      node * Identifier = new_Tnode(T_Identifier, -1, -1, $4);
      $$ = add_nodes($$, TO, $2, Identifier, NULL, NULL);
    }
    ;

num
   : IntNum
   {
     $$ = new_NTnode(NT_num);
     node * IntNum = new_Tnode(T_IntNum, $1, -1, "");
     $$ = add_nodes($$, IntNum, NULL, NULL, NULL, NULL);
   }
   | FloatNum
   {
     $$ = new_NTnode(NT_num);
     node * FloatNum = new_Tnode(T_FloatNum, -1, $1, "");
     $$ = add_nodes($$, FloatNum, NULL, NULL, NULL, NULL);
   }   
   ;

type
   : INT
   {
     $$ = new_NTnode(NT_type);
     node * INT = new_Tnode(T_INT, -1, -1, $1);
     $$ = add_nodes($$, INT, NULL, NULL, NULL, NULL);
   }
   | FLOAT
   {
     $$ = new_NTnode(NT_type);
     node * FLOAT = new_Tnode(T_FLOAT, -1, -1, $1);
     $$ = add_nodes($$, FLOAT, NULL, NULL, NULL, NULL);
   }
   ;

string
    : STRING
    {
      $$ = new_NTnode(NT_string);
      node * STRING = new_Tnode(T_STRING, -1, -1, $1);
      $$ = add_nodes($$, STRING, NULL, NULL, NULL, NULL);
    }
    ;


%%
         
void yyerror (struct astnode **rootnode, char const *s){
	//printf("Syntex Error in line number : %d : %s %s\n", yylineno, s, yytext );
}
