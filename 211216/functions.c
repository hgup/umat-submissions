#include"header.h"

// Calculates if a number is prime
int isprime(int x){
    if(x <= 1)  return 0;
    if(x%2 == 0 && x > 2) return 0;
    for(int i=3;i <= (x/2);i=i+1){
        if(x % i == 0)    return 0;
    }
    return 1;
}

// Generates the prime numbers
int generate_prime_num(int l, int u){
    int p;
    do
    {
        p=rand()%(u - l) + l;
    } while (!isprime(p));
    return p;
    
}

// Calculates the GCD of given 2 numbers
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Generates the RSA keys.
void generatekeys(int p, int q, int *n,int *e,int *d){
    *n=p*q;
    int phi=(p-1)*(q-1);
    *e=2;
    while(gcd(*e,phi)!=1)
        (*e)++;
    int k=2;
    *d = (1 + (k * phi)) / *e;
    while ((*d * *e) % phi != 1) {
        k++;
        *d = (1 + (k * phi)) / *e;
    }
}

// Function to perform modular exponentiation (text^exp % mod)
unsigned long long mod_exp(unsigned long long text, unsigned long long exp, unsigned long long mod) {
    unsigned long long result = 1;
    text = text % mod;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * text) % mod;
        exp = exp >> 1;
        text = (text * text) % mod;
    }
    return result;
}

// Function to encrypt a text file using RSA encryption
int encrypt_file(const char *input_filename, const char *output_filename, unsigned long long e, unsigned long long n) {
    FILE *input_file = fopen(input_filename, "rb");
    if (!input_file) {
        perror("Error opening input file");
        return 0;
    }
    FILE *output_file = fopen(output_filename, "wb");    
    if (!output_file) {
        perror("Error opening output file");
        fclose(input_file);
        exit(1);
    }
    int byte;
    while ((byte = fgetc(input_file)) != EOF) {
        // Encrypt each character
        unsigned long long encrypted_byte = mod_exp(byte, e, n);

        // Write the encrypted charecter to the output file
        fprintf(output_file, "%llu ", encrypted_byte);
    }
    printf("File encrypted successfully.\n");
    fclose(input_file);
    fclose(output_file);
    return 1;
}

// Function to decrypt a text file using RSA decryption
void decrypt_file(const char *input_filename, const char *output_filename, unsigned long long d, unsigned long long n) {
    FILE *input_file = fopen(input_filename, "rb");
    if (!input_file) {
        perror("Error opening input file");
        exit(1);
    }

    FILE *output_file = fopen(output_filename, "wb");
    if (!output_file) {
        perror("Error opening output file");
        fclose(input_file);
        exit(1);
    }

    unsigned long long encrypted_byte;
    while (fscanf(input_file, "%llu", &encrypted_byte) != EOF) {

        // Decrypt the encrypted byte using RSA decryption
        unsigned long long decrypted_byte = mod_exp(encrypted_byte, d, n);

        // Write the decrypted byte to the output file
        fputc((int)decrypted_byte, output_file);
    }

    fclose(input_file);
    fclose(output_file);
}