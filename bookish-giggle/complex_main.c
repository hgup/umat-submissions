/* the main function for the co1+implex operations */
#include<stdio.h>
#include"complex.h"
int main() {
	int choice,x,y,z;
	struct complex l,j,*a,*b,*c;
	a=&l;
	b=&j;
	printf("Enter the complex number");
	scanf("%lf+%lfi",&a->real,&a->image);
	printf("Enter the complex number");
	scanf("%lf+%lfi",&b->real,&b->image);
	printf("press 1=add,2=sub,3=mult,4=div:");
	scanf("%d",&choice);
	switch(choice) {
	case 1:
		printf("addition opration has be selected");
		add_complex(a,b);
	case 2:
		printf("subtraction opration has been selected");
		sub_complex(a,b);
	case 3:
		printf("multiplication opration has been selected");
		mult_complex(a,b);
	case 4:
		printf("division opration has been selected");
		div_complex(a,b);	
		}
		
return 0;
}
	

