#include <stdio.h>

void strcat (char s[], char t[])
{
	int i, j;
	i=j=0;
	while (s[i]!='\0') //znajdź koniec tekstu w s
	i++;
	while ((s[i++]=t[j++])!='\0'); //przepisz tekst
}

int main (void)
{
	char a[]="dobry";
	char b[]="zly";
	strcat (a,b);
	puts (a);
}