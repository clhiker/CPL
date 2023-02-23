#include "ast.h"
#include "utility.h"

node *new_Tnode(int type, int i_value, float f_value, char *str) {
    node *n = NULL;
    if ((n = (node *)cpl_malloc(sizeof(node))) != NULL) {
        n->type = type;
        n->i_value = i_value;
        n->f_value = f_value;
        cpl_strcpy(n->str, str);
        n->node1 = NULL;
        n->node2 = NULL;
        n->node3 = NULL;
        n->node4 = NULL;
        n->node5 = NULL;
    } else
    cpl_exit(0);
    return n;
}

node *new_NTnode(int type) {
    node *n = NULL;
    if ((n = (node *)cpl_malloc(sizeof(node))) != NULL) {
        n->type = type;
        n->i_value = -1;
        n->f_value = -1;
        cpl_strcpy(n->str, "");
        n->node1 = NULL;
        n->node2 = NULL;
        n->node3 = NULL;
        n->node4 = NULL;
        n->node5 = NULL;
    } else
        cpl_exit(0);
    return n;
}

node *add_nodes(node *root, node *n1, node *n2, node *n3, node *n4, node *n5) {
    if (n1 != NULL) {
        root->node1 = n1;
    }
    if (n2 != NULL) {
        root->node2 = n2;
    }
    if (n3 != NULL) {
        root->node3 = n3;
    }
    if (n4 != NULL) {
        root->node4 = n4;
    }
    if (n5 != NULL) {
        root->node5 = n5;
    }
    return root;
}

void free_ast(node *root) {
    if(root == NULL) return;
    free_ast(root->node1);
    free_ast(root->node2);
    free_ast(root->node3);
    free_ast(root->node4);
    free_ast(root->node5);
    cpl_free(root);
}

