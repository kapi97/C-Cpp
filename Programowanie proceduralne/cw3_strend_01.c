#include <stdio.h>

int strend (char *s, char *t)
{
	char *ps=s;
	char *pt=t;
	for (; *s; s++);
	for (; *t; t++);
	for (; *s==*t; s--,t--)
	    if(t==pt || s==ps) break;
	if (*s==*t && t==pt && *s!='\0')
	return 1;
	else
	return 0;
}

int main (void)
{
    int x;
	char a[]=" ";
	char b[]=" ";
	x=strend(a,b);
	printf ("%d", x);
	return 0;
}