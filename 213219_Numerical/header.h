/*This file includes all the functions definitions.*/

#include<stdio.h>
#include<math.h>
#include<stdlib.h>

double trapezoidal(double f(double x), double a, double b, int n);   // no. of intervals
double simpsons(double f(double x), double a, double b, int n);
double f(double x);
double diff(double h, double x);
double thirddiff(double h, double x);
double corrected_trapezoidal(double deriv, double diff, double h);
double corrected_simpsons(double deriv, double diff, double h);