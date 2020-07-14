#include<stdio.h>
#define MAX_DEGREE 50
#include<time.h>
#include<stdlib.h>


typedef struct{
int degree;
float coef[MAX_DEGREE];
}polynomial;

polynomial multypoly(polynomial A,polynomial B);

void printpoly(polynomial);

void main(){
	int seed,Q,i,W;
	seed=time(0);
	srand(seed);
	Q=rand()%5;
	W=rand()%5;
		polynomial A;
			A.degree = Q;
				for(i=0;i<=Q;i++)A.coef[i]=rand()%10;
				
		polynomial B;
			B.degree=W;
				for(i=0;i<=W;i++)B.coef[i]=rand()%10;
		polynomial C;
			C=multypoly(A,B);
		
		printf("\n A(x)=");printpoly(A);
		printf("\n B(x)=");printpoly(B);
		printf("\n C(x)=");printpoly(C);
}

void printpoly(polynomial P){
	int i,degree;
	degree = P.degree;
 		for(i=0;i<=P.degree;i++){
			printf("%3.0fX^%d",P.coef[i],degree--);
			if(i<P.degree)	printf("+");			
					}
		printf("\n");
 			    }			


polynomial multypoly(polynomial A,polynomial B)

{
	int i,k;
	polynomial C;
	C.degree=A.degree+B.degree;

		for(i=0;i<=A.degree + B.degree;i++)	C.coef[i]=0;					   
			
	for(i=0;i<=A.degree;i++){
		for(k=0;k<=B.degree;k++)C.coef[i+k] += A.coef[i] * B.coef[k];
				}

	return C;
}
