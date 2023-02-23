#include<stdlib.h>
#include<stdio.h>

#define isdigit(c) (c >= '0' && c <= '9')
#define NULL    ((void *)0)
#define  EOF  (-1)
int errno;

typedef FILE cpl_FILE;
void *cpl_malloc(unsigned int size);
void *cpl_realloc(void * ptr, unsigned int  size );
void cpl_free(void *ptr);
void  *cpl_memset(void *s,int c, unsigned int count);
void cpl_exit(int status);
char * cpl_strcpy(char *dst,const char *src); 
int cpl_strcmp(const char *str1, const char *str2);
unsigned int cpl_strlen(const char *s);
int cpl_atoi(const char *src);
double cpl_atof(const char *s);
