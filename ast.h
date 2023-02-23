//#include <math.h>
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>

enum {
  // terminal node
    T_INT = 10,
    T_FLOAT,
    T_CHAR,
    T_FROM,
    T_TO,
    T_PLUS,
    T_MINUS,
    T_TIMES,
    T_DEVIDE,
    T_LOR,
    T_LAND,
    T_LNOT,
    T_EQ,
    T_NEQ,
    T_GE,
    T_LE,
    T_GT,
    T_LT,
    T_DE_EQ,
    T_DE_NEQ,
    T_DE_GE,
    T_DE_LE,
    T_DE_GT,
    T_DE_LT,
    T_ASGN,
    T_Mission,
    T_MissionID,
    T_MissionName,
    T_Priority,
    T_ComponentList,
    T_Component,
    T_ComponentID,
    T_ComponentName,
    T_Observation,
    T_Orientation,
    T_Decision,
    T_Action,
    T_IntNum,
    T_FloatNum,
    T_Identifier,
    T_STRING,

    // no-terminal node
    NT_mission = 1000,
    NT_ooda,
    NT_missionAttr,
    NT_missionID,
    NT_missionName,
    NT_priority,
    NT_compList,
    NT_comps,
    NT_comp,
    NT_compID,
    NT_compName,
    NT_observation,
    NT_obInsts,
    NT_orientation,
    NT_orInsts,
    NT_oneOrInst,
    NT_opOr,
    NT_opOr1,
    NT_decision,
    NT_deInsts,
    NT_oneDeInst,
    NT_opDe,
    NT_operand,
    NT_action,
    NT_actInsts,
    NT_stmts,
    NT_stmtN,
    NT_stmtVarDecl,
    NT_stmtCharArrayDecl,
    NT_identifierN,
    NT_stmtAssign,
    NT_stmtFrom,
    NT_stmtTo,
    NT_num,
    NT_type,
    NT_string,
};

typedef struct astnode {
    int type;
    int i_value;
    float f_value;
    char str[31];
    struct astnode *node1;
    struct astnode *node2;
    struct astnode *node3;
    struct astnode *node4;
    struct astnode *node5;
} node;

node *rootnode;

node *new_Tnode(int type, int i_value, float f_value, char *str);
node *new_NTnode(int type);
node *add_nodes(node *root, node *n1, node *n2, node *n3, node *n4, node* n5);
void free_ast(node *root);

