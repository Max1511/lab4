#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	srand( time( 0 ) );
	int Karlson=60, i, N=50, M=50, Aunt=0;
	int *Jam=(int*) malloc(N*sizeof(int));
	int *Threfs=(int*) malloc(M*sizeof(int));
	
	for (i=0; i<N; i++)
	{
		Jam[i]=1+rand()%5;
	}
	for (i=0; i<M; i++)
	{
		Threfs[i]=1+rand()%5;
	}
	int n=0, m=0;
	while (1)
	{
		Aunt=rand()%2;
		if (!Aunt)
		{
			Karlson+=Jam[n];
			printf("Karlson is eating %dkg jam.\n", Jam[n]);
			n++;
		}
		else
		{
			Karlson-=Threfs[m];
			printf("Karlson is killing %d threfs.\n", Threfs[m]);
			m++;
		}
		if (Karlson<=20)
		{
			printf("Karlson is dead.");
			break;
		}
		if (Karlson>=100)
		{
			printf("Karlson is fet.");
			break;
		}
		if (n==N)
		{
			printf("Karlson have eaten all jam.");
			break;
		}
		if (m==M)
		{
			printf("Karlson have killed all threfs.");
			break;
		}
	}
	free(Jam);
	free(Threfs);
	return 0;
}
