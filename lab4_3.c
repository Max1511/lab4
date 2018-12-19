#include <stdio.h>
#include <string.h>
#define LENMAX 64
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	char **R;
	char buf[LENMAX];
	int n=1, m, i;
	R=malloc((sizeof(char*))*LENMAX);
	while (gets(buf)!=NULL)
	{
		R[n]=malloc((sizeof(char))*(strlen(buf)+1));
		strcpy(R[n],buf);
		if (strcmp(R[n],"\0")==0) break;
		for (i=0; i<n; i++)
		{
			if (strcmp(R[i],R[n])==0)
			{
				n--;
				break;
			}
		}
		n++;
	}
	m=n;
	while (gets(buf)!=NULL)
	{
		R[m]=malloc((sizeof(char))*(strlen(buf)+1));
		strcpy(R[m],buf);
		for (i=0; i<n; i++)
		{
			if (strcmp(R[i],R[m])==0)
			{
				m--;
				break;
			}
		}
		m++;
	}
	for (i=0; i<m/2; i++)
	{
		printf("%s\n", R[i]);
	}
	printf("\n");
	for (i=m/2; i<m; i++)
	{
		printf("%s\n", R[i]);
	}
	for (i=0; i<m; i++)
	{
		free(R[i]);
	}
	free(R);
	return 0;
}
