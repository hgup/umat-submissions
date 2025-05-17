#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<string.h>

int isprime(int x);

int generate_prime_num(int l, int u);

int gcd(int a, int b);

void generatekeys(int p, int q, int *n,int *e,int *d);

unsigned long long mod_exp(unsigned long long base, unsigned long long exp, unsigned long long mod);

int encrypt_file(const char *input_filename, const char *output_filename, unsigned long long e, unsigned long long n);

void decrypt_file(const char *input_filename, const char *output_filename, unsigned long long d, unsigned long long n);