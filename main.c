#include "cpl_lexer.h"
#include "cpl_parser.h"
#include "extrac.h"
#include <stdio.h>

extern cmd_info var_cmd_info;

int main(int argc, char **argv) {

  //yyin = fopen(argv[1], "r");
  cmd_info var_cmd_info;
  FILE *fp = fopen(argv[1], "r");

  if (fp == NULL) {
    puts("Please input a source file (.cpl)!");
    exit(0);
  }

  long file_size;
  fseek(fp, 0L, SEEK_END);
  file_size = ftell(fp);
  rewind(fp);

  char cpl_prog[8192];// = calloc(1, file_size+1);

  fread(cpl_prog, file_size, 1, fp);
  //printf("%d%s\n", file_size, cpl_prog);
  yy_scan_string(cpl_prog); 

  // yyparse(&rootnode);
  if (!yyparse(&rootnode)){
    extract_cmd_info(&var_cmd_info, rootnode);
    print_cmd_info(&var_cmd_info);
    free_cmd_info(&var_cmd_info);
    free_ast(rootnode);
    fclose(fp);
    yylex_destroy();
  }
  else {
    free_ast(rootnode);
    fclose(fp);
    yylex_destroy();
    exit(0);
  }
  //yy_delete_buffer(yy_buf);
  return 0;
}
