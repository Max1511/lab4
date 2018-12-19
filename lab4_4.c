#include <stdio.h>
#include <math.h>
#define H 0.1

typedef double (*Func_T)(double);

double function1 (double x)
{
	return sin(x);
}
double function2 (double x)
{
	return x*cos(x);
}
double function3 (double x)
{
	return (x*x)+x-tan(x);
}
double function4 (double x)
{
	return exp(x)+3;
}
double min (double a, double b)
{
	if (a<b) return a;
	return b;
}
double max (double a, double b)
{
	if (a>b) return a;
	return b;
}

double Integrale (Func_T function, double A, double B, double C)
{
	double a, b, S=0;
	double MIN=min(A,B);
	double MAX=max(A,B);
	for (a=MIN, b=MIN+H; b<MAX; a+=H, b+=H)
	{
		S+=fabs(function(a)-C)*fabs(b-a);
	}
	return S;
}
int main()
{
	double S, A, B, C, ans=0, s1, s2, s3, s4;
	scanf("%lf%lf%lf%lf", &S, &A, &B, &C);
	
	s1=Integrale (function1, A, B, C);
	s2=Integrale (function2, A, B, C);
	s3=Integrale (function3, A, B, C);
	s4=Integrale (function4, A, B, C);
	
	printf("%lf %lf %lf %lf\n", s1, s2, s3, s4);
	if (s1<=S) ans=s1;
	if (s2>ans && s2<=S) ans=s2;
	if (s3>ans && s3<=S) ans=s3;
	if (s4>ans && s4<=S) ans=s4;
	printf("%lf", ans);
	return 0;
}
