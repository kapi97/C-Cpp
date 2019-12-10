#include <stdio.h>

int strend (char *s, char *t)
{
	int i;
	while (*s)
	s++;
	while (*t)
	t++;
	while (i>0)
	{
		if (*s==*t)
		{
			--i;
			--s;
			--t;
		}
	else
	return 0;	
}
if (i==0)
return 1;
}

int main (void)
{
    int x;
	char a[]=" ";
	char b[]=" ";
	x=strend(a, b);
	printf ("%d", x);
	return 0;
}