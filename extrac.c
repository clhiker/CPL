#include "extrac.h"
#include "utility.h"
#include "cpl_lexer.h"
//#include <stdio.h>

// global variables

unsigned int symblelist_lenth = 0;
unsigned int this_OB_topics_lenth = 0;
unsigned int this_AC_topics_lenth = 0;
unsigned int this_OR_cmd_list_lenth = 0;
unsigned int this_DE_cmd_list_lenth = 0;
unsigned int needed_nodes_cmp_lenth = 0;

void print_cmd_info(cmd_info *var_cmd_info) {
  unsigned int i = 0;
  printf("-----The following are cmd_info data----\n");
  printf("priority : %d\n\n", var_cmd_info->priority);

  printf("The following are symblelist data\n");
  printf("symblelist_lenth : %d\n", symblelist_lenth);
  for (i = 0; i < symblelist_lenth; i++) {
    printf("Num.%d symbol in symblelist\n", i);
    printf("ooda_symble name : %s\n", var_cmd_info->symblelist[i].name);
    printf("ooda_symble ooda_reg_type %d\n", var_cmd_info->symblelist[i].type);
    if (var_cmd_info->symblelist[i].type == 1) {
      ooda_reg_value t;
      t = var_cmd_info->symblelist[i].value;
      printf("ooda_symble ooda_reg_value %d\n", t.int_value);
      printf("ooda_symble initialised %d\n\n",
             var_cmd_info->symblelist[i].initiallised);
    }
    if (var_cmd_info->symblelist[i].type == 2) {
      ooda_reg_value t;
      t = var_cmd_info->symblelist[i].value;
      printf("ooda_symble ooda_reg_value %g\n", t.float_value);
      printf("ooda_symble initialised %d\n\n",
             var_cmd_info->symblelist[i].initiallised);
    }
    if (var_cmd_info->symblelist[i].type == 0) {
      ooda_reg_value t;
      t = var_cmd_info->symblelist[i].value;
      printf("ooda_symble ooda_reg_value %s\n", t.srt);
      printf("ooda_symble initialised %d\n\n",
             var_cmd_info->symblelist[i].initiallised);
    }
  }
  printf("The following are componment list data\n");
  printf("needed_nodes_cmp_lenth : %d\n", needed_nodes_cmp_lenth);
  for (unsigned int i = 0; i < needed_nodes_cmp_lenth; i++) {
    printf("name : %s\n", var_cmd_info->needed_nodes_cmp[i].name);
  }
  printf("\n");

  printf("The following are this_OB_topics data\n");
  printf("this_OB_topics_lenth : %d\n", this_OB_topics_lenth);
  for (i = 0; i < this_OB_topics_lenth; i++) {
    printf("sub_topic_name : %s\n",
           var_cmd_info->this_OB_topics[i].sub_topic_name);
    printf("target_reg : \n");
    ooda_reg tt = *var_cmd_info->this_OB_topics[i].target_reg;
    printf("reg_name %s\n", tt.name);
    printf("reg_type %d\n", var_cmd_info->this_OB_topics[i].target_reg->type);
    ooda_reg_value t;
    t = var_cmd_info->this_OB_topics[i].target_reg->value;
    int type = var_cmd_info->this_OB_topics[i].target_reg->type;
    if (type == 1) {
      printf("reg_value %d\n", t.int_value);
    }
    if (type == 2) {
      printf("reg_value %g\n", t.float_value);
    }
  }
  printf("\n");

  printf("The following are this_AC_topics data\n");
  printf("this_AC_topics_lenth : %d\n", this_AC_topics_lenth);
  for (i = 0; i < this_AC_topics_lenth; i++) {
    printf("pub_topic_name : %s\n",
           var_cmd_info->this_AC_topics[i].pub_topic_name);
    printf("source_reg : \n");
    ooda_reg tt = *var_cmd_info->this_AC_topics[i].source_reg;
    printf("reg_name %s\n", tt.name);
    printf("reg_type %d\n", var_cmd_info->this_AC_topics[i].source_reg->type);
    ooda_reg_value t;
    t = var_cmd_info->this_AC_topics[i].source_reg->value;
    int type = var_cmd_info->this_AC_topics[i].source_reg->type;
    if (type == 1) {
      printf("reg_value %d\n", t.int_value);
    }
    if (type == 2) {
      printf("reg_value %g\n", t.float_value);
    }
  }
  printf("\n");

  printf("The following are this_OR_cmd_list data\n");
  printf("this_OR_cmd_list_lenth : %d\n", this_OR_cmd_list_lenth);
  for (i = 0; i < this_OR_cmd_list_lenth; i++) {
    printf(" OP : %d\n", var_cmd_info->this_OR_cmd_list[i].OP);
    ooda_reg t1 = *var_cmd_info->this_OR_cmd_list[i].rs1;
    printf("rs1 reg_name %s\n", t1.name);
    printf("rs1 reg_type %d\n", t1.type);
    ooda_reg_value tt1;
    tt1 = t1.value;
    int type = var_cmd_info->this_OR_cmd_list[i].rs1->type;
    if (type == 1) {
      printf("rs1 reg_value %d\n", tt1.int_value);
    }
    if (type == 2) {
      printf("rs1 reg_value %g\n", tt1.float_value);
    }

    // if meets not, just skip this print
    if (var_cmd_info->this_OR_cmd_list[i].rs2 != NULL) {
      ooda_reg t2 = *var_cmd_info->this_OR_cmd_list[i].rs2;
      printf("rs2 reg_name %s\n", t2.name);
      printf("rs2 reg_type %d\n", t2.type);
      ooda_reg_value tt2;
      tt2 = t2.value;
      int type = var_cmd_info->this_OR_cmd_list[i].rs2->type;
      if (type == 1) {
        printf("rs2 reg_value %d\n", tt2.int_value);
      }
      if (type == 2) {
        printf("rs2 reg_value %g\n", tt2.float_value);
      }
    }

    ooda_reg t3 = *var_cmd_info->this_OR_cmd_list[i].rd;
    printf("rd reg_name %s\n", t3.name);
    printf("rd reg_type %d\n", t3.type);
    ooda_reg_value tt3;
    tt3 = t3.value;
    type = var_cmd_info->this_OR_cmd_list[i].rd->type;
    if (type == 1) {
      printf("rd reg_value %d\n", tt3.int_value);
    }
    if (type == 2) {
      printf("rd reg_value %g\n", tt3.float_value);
    }
  }
  printf("\n");

  printf("The following are this_DE_cmd_list data \n");
  printf("this_DE_cmd_list_lenth : %d\n", this_DE_cmd_list_lenth);
  for (i = 0; i < this_DE_cmd_list_lenth; i++) {
    printf(" OP : %d\n", var_cmd_info->this_DE_cmd_list[i].OP);
    ooda_reg t1 = *var_cmd_info->this_DE_cmd_list[i].rs1;
    printf("rs1 reg_name %s\n", t1.name);
    printf("rs1 reg_type %d\n", t1.type);
    ooda_reg_value tt1;
    tt1 = t1.value;
    int type = var_cmd_info->this_DE_cmd_list[i].rs1->type;
    if (type == 1) {
      printf("rs1 reg_value %d\n", tt1.int_value);
    }
    if (type == 2) {
      printf("rs1 reg_value %g\n", tt1.float_value);
    }

    ooda_reg t2 = *var_cmd_info->this_DE_cmd_list[i].rs2;
    printf("rs2 reg_name %s\n", t2.name);
    printf("rs2 reg_type %d\n", t2.type);
    ooda_reg_value tt2;
    tt2 = t2.value;
    type = var_cmd_info->this_DE_cmd_list[i].rs2->type;
    if (type == 1) {
      printf("rs2 reg_value %d\n", tt2.int_value);
    }
    if (type == 2) {
      printf("rs2 reg_value %g\n", tt2.float_value);
    }
  }
  printf("------End of cmd_info data----\n");
}

void extract_cmd_info(cmd_info *var_cmd_info, node *root) {
  int index = root->type;
  switch (index) {
  case NT_priority: {
    var_cmd_info->priority = root->node2->i_value;
    break;
  }

  case NT_stmtVarDecl: {
    // int
    if (root->node1->node1->type == T_INT) {
      save_to_ooda_symble_int(var_cmd_info, root->node2->str, 47, NULL, -1);
      if (root->node3 != NULL) {
        // int a=1;
        if (root->node3->type == T_ASGN) {
          update_to_ooda_symble_int(var_cmd_info, root->node2->str, root->node4->node1);
          if (root->node5 != NULL) {
            root = root->node5;
          } else {
            break;
          }
        } else if (root->node3->type == NT_identifierN) {
          root = root->node3;
        }

        // root = NT_identifierN
        while (root) {
          // ..a=1
          if (root->node2 != NULL) {
            if (root->node2->type == T_ASGN) {
              save_to_ooda_symble_int(var_cmd_info, root->node1->str, 47, root->node3->node1,
                                      1);
              if (root->node4 != NULL) {
                root = root->node4;
              } else {
                break;
              }
            }
          }
          // ..a..
          if (root->node1->type == T_Identifier) {
            if (root->node2 == NULL) {
                save_to_ooda_symble_int(var_cmd_info, root->node1->str, 47, NULL, -1);
                break;
            } else if (root->node2->type == NT_identifierN){
                save_to_ooda_symble_int(var_cmd_info, root->node1->str, 47, NULL, -1);
                root = root->node2;
            } else if (root->node2->type == T_ASGN){
                ;
            }
          }
        }
        break;
      }
    }
    // float
    if (root->node1->node1->type == T_FLOAT) {
      save_to_ooda_symble_float(var_cmd_info, root->node2->str, 48, NULL, -1);
      if (root->node3 != NULL) {
        // int a=1;
        if (root->node3->type == T_ASGN) {
          update_to_ooda_symble_float(var_cmd_info, root->node2->str, root->node4->node1);
          if (root->node5 != NULL) {
            root = root->node5;
          } else {
            break;
          }
        } else if (root->node3->type == NT_identifierN) {
          root = root->node3;
        }

        // root = NT_identifierN
        while (root) {
          // ..a=1
          if (root->node2 != NULL) {
            if (root->node2->type == T_ASGN) {
              save_to_ooda_symble_float(var_cmd_info, root->node1->str, 48,
                                        root->node3->node1, 1);
              if (root->node4 != NULL) {
                root = root->node4;
              } else {
                break;
              }
            }
          }
          // ..a..
          if (root->node1->type == T_Identifier) {
              if (root->node2 == NULL) {
                  save_to_ooda_symble_float(var_cmd_info, root->node1->str, 48, NULL, -1);
                  break;
              } else if (root->node2->type == NT_identifierN){
                  save_to_ooda_symble_float(var_cmd_info, root->node1->str, 48, NULL, -1);
                  root = root->node2;
              } else if (root->node2->type == T_ASGN){
                  ;
              }
          }
        }
        break;
      }
    }
    break;
  }

  case NT_stmtCharArrayDecl: {
    // case 5: char ss[31];
    if (root->node4 == NULL) {
      save_to_ooda_symble_str(var_cmd_info, root->node2->str, 50, "-1", -1);
    }
    // case 6: char ss[31] = "abc";
    else {
      save_to_ooda_symble_str(var_cmd_info, root->node2->str, 50, root->node5->node1->str, 1);
    }
    break;
  }

  case NT_stmtAssign: {
    if (root->node3->node1->type == 47) { // T_InteNum
      update_to_ooda_symble_int(var_cmd_info, root->node1->str, root->node3->node1);
    }
    if (root->node3->node1->type == 48) { // T_FloatNum
      update_to_ooda_symble_float(var_cmd_info, root->node1->str, root->node3->node1);
    }
    break;
  }

  case NT_compName: {
    save_to_needed_nodes_cmp(var_cmd_info, root->node2->node1->str);
    break;
  }

  case NT_stmtFrom: {
    save_to_ob_sub(var_cmd_info, root->node2->node1->str, root->node3->str);
    break;
  }

  case NT_oneOrInst: {
    if (root->node1->node1->type != 21) {
      save_to_or_operate(var_cmd_info, root->node1->node1->type, root->node2->str,
                         root->node3->str, root->node4->str);
      break;
    } else {
      save_to_or_operate(var_cmd_info, root->node1->node1->type, root->node2->str, NULL,
                         root->node3->str);
      break;
    }
  }

  case NT_stmtTo: {
    save_to_ac_pub(var_cmd_info, root->node2->node1->str, root->node3->str);
    break;
  }

  case NT_oneDeInst: {
    save_to_de_comp(var_cmd_info, root->node1->node1->type, root->node2->node1,
                    root->node3->node1);
    break;
  }

  default:
    break;
  }
  if (root->node1 != 0) {
    extract_cmd_info(var_cmd_info, root->node1);
  }
  if (root->node2 != 0) {
    extract_cmd_info(var_cmd_info, root->node2);
  }
  if (root->node3 != 0) {
    extract_cmd_info(var_cmd_info, root->node3);
  }
  if (root->node4 != 0) {
    extract_cmd_info(var_cmd_info, root->node4);
  }
  if (root->node5 != 0) {
    extract_cmd_info(var_cmd_info, root->node5);
  }

  var_cmd_info->symblelist_lenth = symblelist_lenth;
  var_cmd_info->needed_nodes_cmp_lenth = needed_nodes_cmp_lenth;
  var_cmd_info->this_OB_topics_lenth = this_OB_topics_lenth;
  var_cmd_info->this_AC_topics_lenth = this_AC_topics_lenth;
  var_cmd_info->this_OR_cmd_list_lenth = this_OR_cmd_list_lenth;
  var_cmd_info->this_DE_cmd_list_lenth = this_DE_cmd_list_lenth;

}

void save_to_ooda_symble_int(cmd_info *var_cmd_info, char *name, int type, node *t_node, int init) {
  unsigned int i = 0;
  ooda_symble temp_symble;
  // detect dumplicate symbol and update symblelist
  for (i = 0; i < symblelist_lenth; i++) {
    if (cpl_strcmp(name, var_cmd_info->symblelist[i].name) == 0 && init == -1 &&
        t_node == NULL) {
      printf("Error: Redefined variable \"%s\"\n", name);
      free_cmd_info(var_cmd_info);
      free_ast(rootnode);
      //fclose(yyin); // replace this if yyin is not a file
      yylex_destroy();
      cpl_exit(1);
    }
  }
  cpl_strcpy(temp_symble.name, name);
  // T_InteNum --- ooda_Int
  if (type == 47)
    temp_symble.type = ooda_Int;
  // T_STRING --- ooda_Str;
  if (type == 50)
    temp_symble.type = ooda_Str;
  // T_FloatNum --- ooda_Float
  if (type == 48)
    temp_symble.type = ooda_Float;

  ooda_reg_value t;
  if (t_node != NULL) {
    if (t_node->type != T_IntNum) {
      printf("Error: Mismatched type of the variable \"%s\"\n", name);
      free_cmd_info(var_cmd_info);
      free_ast(rootnode);
      //fclose(yyin); // replace this if yyin is not a file
      yylex_destroy();
      cpl_exit(1);
    } else {
      t.int_value = t_node->i_value;
    }
  } else {
    t.int_value = -1;
  }

  temp_symble.value = t;
  if (init != -1)
    temp_symble.initiallised = 1;
  else
    temp_symble.initiallised = -1;
  var_cmd_info->symblelist[symblelist_lenth] = temp_symble;
  symblelist_lenth += 1;
}

void save_to_ooda_symble_float(cmd_info *var_cmd_info, char *name, int type, node *t_node,
                               int initialised) {
  unsigned int i = 0;
  ooda_symble temp_symble;
  // same solution with int symbol
  for (i = 0; i < symblelist_lenth; i++) {
    if (cpl_strcmp(name, var_cmd_info->symblelist[i].name) == 0) {
      printf("Error: Redefined variable \"%s\"\n", name);
      free_cmd_info(var_cmd_info);
      free_ast(rootnode);
      //fclose(yyin); // replace this if yyin is not a file
      yylex_destroy();
      cpl_exit(1);
    }
  }
  cpl_strcpy(temp_symble.name, name);
  if (type == 48)
    temp_symble.type = ooda_Float;

  ooda_reg_value t;

  if (t_node != NULL) {
    if (t_node->type != T_FloatNum) {
      printf("Error: Mismatched type of the variable \"%s\"\n", name);
      free_cmd_info(var_cmd_info);
      free_ast(rootnode);
      //fclose(yyin); // replace this if yyin is not a file
      yylex_destroy();
      cpl_exit(1);
    } else {
      t.float_value = t_node->f_value;
    }
  } else {
    t.float_value = -1;
  }

  temp_symble.value = t;
  if (initialised != -1)
    temp_symble.initiallised = 1;
  else
    temp_symble.initiallised = -1;

  var_cmd_info->symblelist[symblelist_lenth] = temp_symble;
  symblelist_lenth += 1;
}

void save_to_ooda_symble_str(cmd_info *var_cmd_info, char *name, int type, char *value,
                             int initialised) {
  unsigned int i = 0;
  ooda_symble temp_symble;
  // same solution with int symbol
  for (i = 0; i < symblelist_lenth; i++) {
    if (cpl_strcmp(name, var_cmd_info->symblelist[i].name) == 0) {
      printf("Error: Redefined variable \"%s\"\n", name);
      free_cmd_info(var_cmd_info);
      free_ast(rootnode);
      //fclose(yyin); // replace this if yyin is not a file
      yylex_destroy();
      cpl_exit(1);
    }
  }

  cpl_strcpy(temp_symble.name, name);

  if (type == 50)
    temp_symble.type = ooda_Str;

  ooda_reg_value t;
  cpl_strcpy(t.srt, value);
  temp_symble.value = t;

  if (initialised != -1)
    temp_symble.initiallised = 1;
  else
    temp_symble.initiallised = -1;

  var_cmd_info->symblelist[symblelist_lenth] = temp_symble;
  symblelist_lenth += 1;
}

void update_to_ooda_symble_int(cmd_info *var_cmd_info, char *name, node *t_node) {
  unsigned int i = 0;
  if (!checkDefined(var_cmd_info, symblelist_lenth, name)) {
    free_cmd_info(var_cmd_info);
    free_ast(rootnode);
    //fclose(yyin); // replace this if yyin is not a file
    yylex_destroy();
    cpl_exit(1);
  }

  for (i = 0; i < symblelist_lenth; i++) {
    if (cpl_strcmp(name, var_cmd_info->symblelist[i].name) == 0) {
      ooda_reg_value v;
      if (t_node != NULL) {
        if (t_node->type != T_IntNum) {
          printf("Error: Mismatched type of the variable \"%s\"\n", name);
          free_cmd_info(var_cmd_info);
          free_ast(rootnode);
          //fclose(yyin); // replace this if yyin is not a file
          yylex_destroy();
          cpl_exit(1);
        } else {
          v.int_value = t_node->i_value;
        }
      } else {
        v.int_value = -1;
      }

      var_cmd_info->symblelist[i].value = v;
      var_cmd_info->symblelist[i].initiallised = 1;
    }
  }
}

void update_to_ooda_symble_float(cmd_info *var_cmd_info, char *name, node *t_node) {
  unsigned int i = 0;
  if (!checkDefined(var_cmd_info, symblelist_lenth, name)) {
    free_cmd_info(var_cmd_info);
    free_ast(rootnode);
    //fclose(yyin); // replace this if yyin is not a file
    yylex_destroy();
    cpl_exit(1);
  }

  for (i = 0; i < symblelist_lenth; i++) {
    if (cpl_strcmp(name, var_cmd_info->symblelist[i].name) == 0) {
      ooda_reg_value v;
      if (t_node != NULL) {
        if (t_node->type != T_FloatNum) {
          printf("Error: Mismatched type of the variable \"%s\"\n", name);
          free_cmd_info(var_cmd_info);
          free_ast(rootnode);
          //fclose(yyin); // replace this if yyin is not a file
          yylex_destroy();
          cpl_exit(1);
        } else {
          v.float_value = t_node->f_value;
        }
      } else {
        v.float_value = -1;
      }

      var_cmd_info->symblelist[i].value = v;
      var_cmd_info->symblelist[i].initiallised = 1;
    }
  }
}

void save_to_needed_nodes_cmp(cmd_info *var_cmd_info, char *name) {
  node_info temp_node_info;
  cpl_strcpy(temp_node_info.name, name);
  var_cmd_info->needed_nodes_cmp[needed_nodes_cmp_lenth] = temp_node_info;
  needed_nodes_cmp_lenth += 1;
}

void save_to_ob_sub(cmd_info *var_cmd_info, char *sub_topic_name, char *sym_name) {
  unsigned int i = 0;
  ob_sub temp_ob_sub;
  cpl_strcpy(temp_ob_sub.sub_topic_name, sub_topic_name);

  ooda_reg *t = (ooda_reg *)cpl_malloc(sizeof(ooda_reg));

  // find sym_name from symblelist
  if (!checkDefined(var_cmd_info, symblelist_lenth, sym_name)) {
    if(t!=NULL)free(t);
    free_cmd_info(var_cmd_info);
    free_ast(rootnode);
    //fclose(yyin); // replace this if yyin is not a file
    yylex_destroy();
    cpl_exit(1);
  }

  for (i = 0; i < symblelist_lenth; i++) {
    if (cpl_strcmp(sym_name, var_cmd_info->symblelist[i].name) == 0) {
      cpl_strcpy(t->name, sym_name);
      t->type = var_cmd_info->symblelist[i].type;
      t->value = var_cmd_info->symblelist[i].value;
      break;
    }
  }

  temp_ob_sub.target_reg = t;
  var_cmd_info->this_OB_topics[this_OB_topics_lenth] = temp_ob_sub;
  this_OB_topics_lenth += 1;
}

void save_to_ac_pub(cmd_info *var_cmd_info, char *pub_topic_name, char *sym_name) {
  unsigned int i = 0;
  ac_pub temp_ac_pub;
  cpl_strcpy(temp_ac_pub.pub_topic_name, pub_topic_name);

  ooda_reg *t = (ooda_reg *)cpl_malloc(sizeof(ooda_reg));

  // find sym_name from symblelist
  if (!checkDefined(var_cmd_info, symblelist_lenth, sym_name)) {
    if(t!=NULL)cpl_free(t);
    free_cmd_info(var_cmd_info);
    free_ast(rootnode);
    //fclose(yyin); // replace this if yyin is not a file
    yylex_destroy();
    cpl_exit(1);
  }

  for (i = 0; i < symblelist_lenth; i++) {
    if (cpl_strcmp(sym_name, var_cmd_info->symblelist[i].name) == 0) {
      cpl_strcpy(t->name, sym_name);
      t->type = var_cmd_info->symblelist[i].type;
      t->value = var_cmd_info->symblelist[i].value;
      break;
    }
  }

  temp_ac_pub.source_reg = t;
  var_cmd_info->this_AC_topics[this_AC_topics_lenth] = temp_ac_pub;
  this_AC_topics_lenth += 1;
}

void save_to_or_operate(cmd_info *var_cmd_info, int op_type, char *rs1, char *rs2, char *rd) {
  unsigned int i = 0;
  or_operate temp_or_operate;
  // parse first argument
  switch (op_type) {
  case 15:
    temp_or_operate.OP = plus;
    break; // T_PLUS
  case 16:
    temp_or_operate.OP = minus;
    break; // T_MINUS
  case 17:
    temp_or_operate.OP = times;
    break; // T_MULT
  case 18:
    temp_or_operate.OP = devide;
    break; // T_DIV
  case 19:
    temp_or_operate.OP = or ;
    break; // T_LOR
  case 20:
    temp_or_operate.OP = and;
    break; // T_LAND
  case 21:
    temp_or_operate.OP = not ;
    break; // T_NOT
  case 22:
    temp_or_operate.OP = eq;
    break; // T_EQ
  case 23:
    temp_or_operate.OP = neq;
    break; // T_NE
  case 24:
    temp_or_operate.OP = ge;
    break; // T_GE
  case 25:
    temp_or_operate.OP = le;
    break; // T_LE
  case 26:
    temp_or_operate.OP = gt;
    break; // T_GT
  case 27:
    temp_or_operate.OP = lt;
    break; // T_LT
  }

  // parsing later three arguments
  ooda_reg *t1 = (ooda_reg *)cpl_malloc(sizeof(ooda_reg));
  ooda_reg *t2 = (ooda_reg *)cpl_malloc(sizeof(ooda_reg));
  ooda_reg *t3 = (ooda_reg *)cpl_malloc(sizeof(ooda_reg));
  // find variable from symble
  if (!checkDefined(var_cmd_info, symblelist_lenth, rs1)) {
    if(t1!=NULL)cpl_free(t1);
    if(t2!=NULL)cpl_free(t2);
    if(t3!=NULL)cpl_free(t3);
    free_cmd_info(var_cmd_info);
    free_ast(rootnode);
    //fclose(yyin); // replace this if yyin is not a file
    yylex_destroy();
    cpl_exit(1);
  }

  for (i = 0; i < symblelist_lenth; i++) {
    if (cpl_strcmp(rs1, var_cmd_info->symblelist[i].name) == 0) {
      cpl_strcpy(t1->name, rs1);
      t1->type = var_cmd_info->symblelist[i].type;
      t1->value = var_cmd_info->symblelist[i].value;
      break;
    }
  }

  if (rs2 != NULL) {
    if (!checkDefined(var_cmd_info, symblelist_lenth, rs2)) {
      if(t1!=NULL)cpl_free(t1);
      if(t2!=NULL)cpl_free(t2);
      if(t3!=NULL)cpl_free(t3);
      free_cmd_info(var_cmd_info);
      free_ast(rootnode);
      //fclose(yyin); // replace this if yyin is not a file
      yylex_destroy();
      cpl_exit(1);
    }

    for (i = 0; i < symblelist_lenth; i++) {
      if (cpl_strcmp(rs2, var_cmd_info->symblelist[i].name) == 0) {
        cpl_strcpy(t2->name, rs2);
        t2->type = var_cmd_info->symblelist[i].type;
        t2->value = var_cmd_info->symblelist[i].value;
        break;
      }
    }
  } else{
    cpl_free(t2);
    t2 = NULL;
  }

  if (!checkDefined(var_cmd_info, symblelist_lenth, rd)) {
    if(t1!=NULL)cpl_free(t1);
    if(t2!=NULL)cpl_free(t2);
    if(t3!=NULL)cpl_free(t3);
    free_cmd_info(var_cmd_info);
    free_ast(rootnode);
    //fclose(yyin); // replace this if yyin is not a file
    yylex_destroy();
    cpl_exit(1);
  }

  for (i = 0; i < symblelist_lenth; i++) {
    if (cpl_strcmp(rd, var_cmd_info->symblelist[i].name) == 0) {
      cpl_strcpy(t3->name, rd);
      t3->type = var_cmd_info->symblelist[i].type;
      t3->value = var_cmd_info->symblelist[i].value;
      break;
    }
  }

  temp_or_operate.rs1 = t1;
  temp_or_operate.rs2 = t2;
  temp_or_operate.rd = t3;
  var_cmd_info->this_OR_cmd_list[this_OR_cmd_list_lenth] = temp_or_operate;
  this_OR_cmd_list_lenth += 1;
}

void save_to_de_comp(cmd_info *var_cmd_info, int op_type, node *rs1, node *rs2) {
  unsigned int i = 0;
  de_comp temp_de_comp;
  // parsing first argument
  switch (op_type) {
  case 28:
    temp_de_comp.OP = de_eq;
    break; // T_DE_EQ
  case 29:
    temp_de_comp.OP = de_neq;
    break; // T_DE_NE
  case 30:
    temp_de_comp.OP = de_ge;
    break; // T_DE_GE
  case 31:
    temp_de_comp.OP = de_le;
    break; // T_DE_LE
  case 32:
    temp_de_comp.OP = de_gt;
    break; // T_DE_GT
  case 33:
    temp_de_comp.OP = de_lt;
    break; // T_DE_LT
  }

  // pasing the later two arguments
  ooda_reg *t1 = (ooda_reg *)cpl_malloc(sizeof(ooda_reg));
  ooda_reg *t2 = (ooda_reg *)cpl_malloc(sizeof(ooda_reg));

  if (rs1->type == T_Identifier) {
    if (!checkDefined(var_cmd_info, symblelist_lenth, rs1->str)) {
      if(t1!=NULL)cpl_free(t1);
      if(t2!=NULL)cpl_free(t2);
      free_cmd_info(var_cmd_info);
      free_ast(rootnode);
      //fclose(yyin); // replace this if yyin is not a file
      yylex_destroy();
      cpl_exit(1);
    }

    for (i = 0; i < symblelist_lenth; i++) {
      if (cpl_strcmp(rs1->str, var_cmd_info->symblelist[i].name) == 0) {
        cpl_strcpy(t1->name, rs1->str);
        t1->type = var_cmd_info->symblelist[i].type;
        t1->value = var_cmd_info->symblelist[i].value;
        break;
      }
    }
  } else if (rs1->type == NT_num) {
    cpl_strcpy(t1->name, "num");
    if (rs1->node1->type == T_IntNum) {
      t1->type = 1;
      t1->value.int_value = rs1->node1->i_value;
    }
    if (rs1->node1->type == T_FloatNum) {
      t1->type = 2;
      t1->value.float_value = rs1->node1->f_value;
    }
  }

  if (rs2->type == T_Identifier) {
    if (!checkDefined(var_cmd_info, symblelist_lenth, rs2->str)) {
      if(t1!=NULL)cpl_free(t1);
      if(t2!=NULL)cpl_free(t2);
      free_cmd_info(var_cmd_info);
      free_ast(rootnode);
      //fclose(yyin); // replace this if yyin is not a file
      yylex_destroy();
      cpl_exit(1);
    }

    for (i = 0; i < symblelist_lenth; i++) {
      if (cpl_strcmp(rs2->str, var_cmd_info->symblelist[i].name) == 0) {
        cpl_strcpy(t2->name, rs2->str);
        t2->type = var_cmd_info->symblelist[i].type;
        t2->value = var_cmd_info->symblelist[i].value;
        break;
      }
    }

  } else if (rs2->type == NT_num) {
    cpl_strcpy(t2->name, "num");
    if (rs2->node1->type == T_IntNum) {
      t2->type = 1;
      t2->value.int_value = rs2->node1->i_value;
    }
    if (rs2->node1->type == T_FloatNum) {
      t2->type = 2;
      t2->value.float_value = rs2->node1->f_value;
    }
  }

  temp_de_comp.rs1 = t1;
  temp_de_comp.rs2 = t2;
  var_cmd_info->this_DE_cmd_list[this_DE_cmd_list_lenth] = temp_de_comp;
  this_DE_cmd_list_lenth += 1;
}

void free_cmd_info(cmd_info *var_cmd_info) {
  unsigned int i = 0;
  // free ob_sub
  for (i = 0; i < this_OB_topics_lenth; i++) {
    if(var_cmd_info->this_OB_topics[i].target_reg)
      cpl_free(var_cmd_info->this_OB_topics[i].target_reg);
  }
  // cpl_free ac_pub
  for (i = 0; i < this_AC_topics_lenth; i++) {
    if(var_cmd_info->this_AC_topics[i].source_reg)
      cpl_free(var_cmd_info->this_AC_topics[i].source_reg);
  }
  // free or_operate
  for (i = 0; i < this_OR_cmd_list_lenth; i++) {
    if(var_cmd_info->this_OR_cmd_list[i].rs1)
      cpl_free(var_cmd_info->this_OR_cmd_list[i].rs1);

    if(var_cmd_info->this_OR_cmd_list[i].rs2)
      cpl_free(var_cmd_info->this_OR_cmd_list[i].rs2);

    if(var_cmd_info->this_OR_cmd_list[i].rd)
      cpl_free(var_cmd_info->this_OR_cmd_list[i].rd);
  }
  // free de_comp
  for (i = 0; i < this_DE_cmd_list_lenth; i++) {
    if(var_cmd_info->this_DE_cmd_list[i].rs1)
      cpl_free(var_cmd_info->this_DE_cmd_list[i].rs1);

    if(var_cmd_info->this_DE_cmd_list[i].rs2)
      cpl_free(var_cmd_info->this_DE_cmd_list[i].rs2);
  }
}

int checkDefined(cmd_info *var_cmd_info, int symblelist_lenth, char *str) {
  unsigned int i = 0;
  for (i = 0; i < symblelist_lenth; i++) {
    if (cpl_strcmp(str, var_cmd_info->symblelist[i].name) == 0) {
      return 1;
    }
  }
  printf(("Error: Undefined variable \"%s\"\n"), str);
  return 0;
}
