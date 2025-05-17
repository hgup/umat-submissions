/*This file contains the functions used in the main program*/

#include "header.h"


double f(double x)
{
 return 1/(1+x);
}


double diff(double h, double x)                   //This function calculates the first derivative of a given function
{
 double d, a, b, f1, f2;
 a = x + h;
 b = x - h;
 f1 = f(a);
 f2 = f(b);
 d = (f1-f2) / (2*h);
 return d;
}


double thirddiff(double h, double x)              //This function calculates the third derivative of a given function
{
    double d, a, b, f1, f2, f3, f4;
    a = x + 2*h;
    b = x - 2*h;
    
    f1 = f(a);
    f2 = f(a + h);
    f3 = f(b);
    f4 = f(b - h);

    d = (f1 - 2*f2 + 2*f3 - f4) / (2*h*h*h);
    return d;
}


double trapezoidal(double f(double x), double a, double b, int n)         //This function calculates the value of the integral using trapezoidal rule
{
 double h, x,sum = 0,integral;
 int i;
 h = fabs(b-a)/n;
 for(i=1; i<n; i++)
  {
   x = a + i * h;
   sum = sum + f(x);
  }
  integral = (h/2) * (f(a) + f(b) + 2*sum);
  return integral;
}


double corrected_trapezoidal(double deriv, double diff, double h)         //This function calculates the value of the integral using corrected trapezoidal method
{
  return (deriv- (( (h*h) / 12) * diff));
}


double simpsons(double f(double x), double a, double b, int n)          //This function calculates the value of the integral using simpson's rule
{
 double h, integral, x, sum = 0;
 int i;
  h = fabs(b-a)/n;
  for(i=1; i<n; i++)
  {
    x = a + i * h;
    if(i % 2==0)
     {
      sum = sum + 2 * f(x);
     }
    else
     {
      sum = sum + 4 * f(x);
    }
  }
  integral = (h/3) * (f(a) + f(b) + sum);
  return integral;
}

double corrected_simpsons(double deriv, double diff, double h)            //This function calculates the value of the integral using corrected simpson's method
{
 return (deriv-(( (h*h*h*h) / 180) * diff));
}