#include <stdio.h>

void strcat(char *s, char *t)
{   
    while(*s++);
    s--;
    while(*s++ = *t++);
}

int main()
{
    printf("Pierwszy ciag znakow\n");
    char *s1=malloc(50*sizeof(char)), *s2=malloc(50*sizeof(char));
	scanf("%ms",s1);
	scanf("%s", s1);
	
    printf("Drugi ciag znakow\n");
    scanf("%ms", s2);
    scanf("%s", s2);
    
    strcat(s1,s2);
    
    printf("Scalone ciagi znakow\n");
    printf("%s",s1);
    return 0;
}