#include <stdio.h>

void strcat_1 (char *s, char *t)
{
    while (*s)
	s++;
	while (*s++=*t++);
}

void strcat_2 (char *u, char *w)
{
    while (*u++);
	u--;
	while (*u++=*w++);
}

int main (void)
{
	char a[]="dobry";
	char b[]="zly";
	char c[]="dobry";
	char d[]="zly";
	strcat_1 (a,b);
	strcat_2 (c,d);
	puts (a);
	puts (c);
}