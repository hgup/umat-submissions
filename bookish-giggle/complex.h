// header proto type file 
#include<stdio.h>
struct complex{
		double real;
		double image;
		};
 int add_complex(struct complex *a,struct complex *b);
 void sub_complex(struct complex *x,struct complex *b);
 void mult_complex(struct complex *a,struct complex *b);
  void div_complex(struct complex *a,struct complex *b);
