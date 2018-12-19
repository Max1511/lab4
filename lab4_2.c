#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NDIG 3
#define EXP ".txt"

int main()
{
	FILE *fp;
	int I=1;
	int flag=0;
	char name[1000];
	char planet[1000];
	char str[NDIG + strlen(EXP)];
	snprintf(str, NDIG + strlen(EXP), "%0*d"EXP, NDIG, I);
	while ((fp=fopen(str, "r"))!=NULL)
	{
		I++;
		fscanf(fp, "%s", &name);
		if (flag)
		{
			if (strcmp(planet,name)==0)
			{
				printf(", %s", str);
			}	
		}
		else
		{
			strcpy(planet,name);
			printf("%s: %s", planet, str);
			flag=1;
		}
		snprintf(str, 6, "%0*d.txt", 3, I);
	}
	return 0;
}
