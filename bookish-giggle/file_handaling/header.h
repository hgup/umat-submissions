/* The header for the student details file of simple kind to store the data of the students*/
#include<stdio.h>
struct studentrecord{
	char name[50];
	int age;
	int regdNO;
	float gpa;
};
typedef struct studentrecord student;

void insert(FILE *fp);
void display(FILE *fp);
void fupdata(FILE *fp);
void fdelete(FILE *fp);

