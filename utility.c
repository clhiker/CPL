#include "utility.h"

void *cpl_malloc(unsigned int size)
{
  return malloc(size);
}

void cpl_free(void *ptr)
{
  return free(ptr);
}

void  *cpl_memset(void *s,int c, unsigned int count)
{
  char *xs = (char *) s;

  while (count--)
    *xs++ = c;

  return s;
}

void *cpl_realloc(void * ptr, unsigned int  size )
{
  return realloc(ptr, size);
}

void cpl_exit(int status)
{
  exit(status);
}


char * cpl_strcpy(char *dst,const char *src)   
{

    char *ret = dst;

    while ((*dst++=*src++)!='\0');

    return ret;
}

/*int cpl_strcmp(const char *str1, const char *str2)
{
    while (*str1++ == *str2++)
    {
        if (*str1 == '\0') 
            return 0;
    }

    if (*str1 - *str2)
        return 1;
    else
        return -1;

}*/

int cpl_strcmp(const char *cs, const char *ct)
{
  register signed char __res;

  while (1) {
    if ((__res = *cs - *ct++) != 0 || !*cs++)
      break;
  }
  return __res;
}

unsigned int cpl_strlen(const char *s)
{
  const char *sc;

  for (sc = s; *sc != '\0'; ++sc)
    /* nothing */;
  return sc - s;
}

int cpl_atoi(const char *src)
{
      int s = 0;
      int is_neg = 0;
  
      while(*src == ' ')
      {
          src++; 
      }
  
      if(*src == '+' || *src == '-')
      {
          if(*src == '-')
          {
              is_neg = 1;
          }
          src++;
      }
      else if(*src < '0' || *src > '9')
      {
          s = 2147483647;
          return s;
      }
  
      while(*src != '\0' && *src >= '0' && *src <= '9')
      {
          s = s * 10 + *src - '0';
          src++;
      }
      return s * (is_neg ? -1 : 1);
 }

double cpl_atof(const char *s)
{

  double a = 0.0;
  int e = 0;
  int c;
  while ((c = *s++) != '\0' && isdigit(c)) {
    a = a*10.0 + (c - '0');
  }
  if (c == '.') {
    while ((c = *s++) != '\0' && isdigit(c)) {
      a = a*10.0 + (c - '0');
      e = e-1;
    }
  }
  if (c == 'e' || c == 'E') {
    int sign = 1;
    int i = 0;
    c = *s++;
    if (c == '+')
      c = *s++;
    else if (c == '-') {
      c = *s++;
      sign = -1;
    }
    while (isdigit(c)) {
      i = i*10 + (c - '0');
      c = *s++;
    }
    e += i*sign;
  }
  while (e > 0) {
    a *= 10.0;
    e--;
  }
  while (e < 0) {
    a *= 0.1;
    e++;
  }
  return a;
}
