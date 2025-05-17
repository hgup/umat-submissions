/*This file contains the trapezoidal and simpson's method to calculate the value of an integral in C.
   Written by Sangdup Tamang
   Date: 04-04-2024*/

#include "header.h"

int main()
{
     int n, s;
    double a, b, eps, integral, new_integral, h=0.2;

    printf("\nEnter the lower limit: ");
    scanf("%lf",&a);
    printf("\nEnter the upper limit: ");
    scanf("%lf",&b);
    printf("\nEnter the desired accuracy: ");
    scanf("%lf",&eps);
while(1)
{
printf("Enter the method:\n 1.Trapezoidal\n 2.Simpsons\n 3. corrected_trapezoidal\n 4. corrected_simpsons\n 5.Exit\n");
scanf("%d",&s);
    switch(s)
     {
        case(1):              //Trapezoidal Rule
         { n=2;
            new_integral = trapezoidal(f,a,b,n);  
           do{ 
            integral = new_integral;
            n++;
            new_integral = trapezoidal(f,a,b,n);
           }while(fabs(new_integral-integral) >= eps);   //error is being found inside while loop 

            printf("The integral using Trapezoidal Rule is: %lf with %d intervals\n", new_integral, n); 
            break;
         }

         case(2):             //Simpson's Rule
          {  n=2;
            new_integral = simpsons(f,a,b,n);
             do{
                integral = new_integral;
                n=n+2;
                new_integral = simpsons(f,a,b,n);
                }while(fabs(new_integral-integral) >= eps);
  
                printf("The value of the integral using Simpsons Rule is: %lf with %d intervals\n", new_integral, n);
                break; 
          }

         case(3):             //Corrected Trapezoidal Rule
         {  double deriv, corr, f1, f2, f3;

            new_integral = trapezoidal(f,a,b,n);  
            do{
            integral = new_integral;
            n++;
            new_integral = trapezoidal(f,a,b,n);
            }while(fabs(new_integral-integral) >= eps);   //error is being found inside while loop

             
             deriv = new_integral;
             f1 = diff(h,a);
             f2 = diff(h,b);
             f3 = f2 - f1;
             corr = corrected_trapezoidal(deriv, f3, h);
             printf("The value of integral using corrected trapezoidal rule is: %lf: \n", corr);
            break; 
         } 

         case(4):               //Corrected Simpson's Rule
         {
            double deriv, corr, f1, f2, f3;
            new_integral = simpsons(f, a, b, n);
            do{
                integral = new_integral;
                n=n+2;
                new_integral = simpsons(f,a,b,n);
                }while(fabs(new_integral-integral) >= eps);

            deriv = new_integral;
            f1 = thirddiff(h, a);
            f2 = thirddiff(h, b);
            f3 = f2 - f1;

            corr = corrected_simpsons(deriv, f3, h);
            printf("The value of the integral using corrected simpsons rule is: %lf\n", corr);
            break;

         }

          case(5):
           {
            exit(0);
           }

          default:
          {
            printf("Invalid operation.\n");
            break;
          }
     }
}
return 0;
}
