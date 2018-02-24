#include <stdio.h>

int a,b,r,i,q[20];

int main(void){
	a = 1;
	while(a!=0){
		printf("•ªqF");
		scanf("%d", &a);
		printf("•ª•êF");
		scanf("%d", &b);
		
		for (i=0;i<=20;i++){
			q[i]=a/b;
			r=a-q[i]*b;
			a=r*100000;
		}
		printf("%d.", q[0]);
		for (i=1;i<=20;i++){
			printf("%d", q[i]);
		}
		printf("\n");
	}
}