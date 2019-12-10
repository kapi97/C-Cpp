#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int strend(char *s, char *t) 
{
   int p, a=0, b=0;
   p=strlen(s)-strlen(t);
   while(b<strlen(t)) 
   {
       if (*(s+p)==*(t+b))
       {
          a=1;
          b++;
          p++;
          continue;
       }
       else
       {
          a=0;
          break;
       }
    }
    return a;
}

int main(void) 
{
   int a=strend(" ", " ");
   printf("%d\n", a);
   return 0;
}