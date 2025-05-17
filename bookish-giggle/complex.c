/* the functions for the oprations the complex numbers*/
#include"complex.h"
//function to add the two complex numbers
int add_complex(struct complex *a,struct complex *b){
		struct complex *c,l;
		c=&l;
		c->real=a->real+b->real;
		c->image=a->image+b->image;
		printf("the sum of the two complex numbers is %lf+%lfi:",c->real,c->image);
		return 0;
		}
		
// function to sub the two complex numbers.
void sub_complex(struct complex *a,struct complex *b){
	struct complex *c,l;
	c=&l;
	c->real=a->real-b->real;
	c->image=a->image-b->image;
	printf("the substraction of the two complex numbers is %lf+%lfi:",c->real,c->image);
	}

// function to multiply the two complex numbers.
void mult_complex(struct complex *a,struct complex *b){
	struct complex *c,l;
	c=&l;
	c->real=(a->real*b->real)-(a->image*b->image);
	c->image=(a->real*b->image)+(a->image*b->real);
	printf("The multipe of the two complex numbers is %lf+%lfi:",c->real,c->image);
	}
// function to divied two complex numbers.
void div_complex(struct complex *a,struct complex *b){
	struct complex *c,l;
	c=&l;
	c->real=(a->real*b->real+a->image*b->image)/(b->real*b->real+b->image*b->image);
	c->image=((a->image*b->real)-(a->real*b->image))/(b->real*b->real+b->image*b->image);
	}
