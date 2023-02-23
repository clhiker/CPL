#include "ast.h"
#include "include/OODA_types.h"
//#include <string.h>

void extract_cmd_info(cmd_info *var_cmd_info, node *rootnode);
void print_cmd_info(cmd_info *var_cmd_info);

void save_to_ooda_symble_int(cmd_info *var_cmd_info, char *name, int type, node *t_node,
                             int initialised);
void save_to_ooda_symble_float(cmd_info *var_cmd_info, char *name, int type, node *t_node,
                               int initialised);
void save_to_ooda_symble_str(cmd_info *var_cmd_info, char *name, int type, char *value,
                             int initialised);

void update_to_ooda_symble_int(cmd_info *var_cmd_info, char *name, node *t_node);
void update_to_ooda_symble_float(cmd_info *var_cmd_info, char *name, node *t_node);

void save_to_ob_sub(cmd_info *var_cmd_info, char *name, char *sym_name);
void save_to_ac_pub(cmd_info *var_cmd_info, char *name, char *sym_name);
void save_to_or_operate(cmd_info *var_cmd_info, int op_type, char *rs1, char *rs2, char *rd);
void save_to_de_comp(cmd_info *var_cmd_info, int op_type, node *rs1, node *rs2);

void save_to_needed_nodes_cmp(cmd_info *var_cmd_info, char *cmp);
void free_cmd_info(cmd_info *var_cmd_info);

int checkDefined(cmd_info *var_cmd_info, int symblelist_lenth, char *str);
