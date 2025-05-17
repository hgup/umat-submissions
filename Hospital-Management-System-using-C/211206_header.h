#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define maxsize 50
#define maxdate 15
#define maxdisease 300
#define maxyear 9999
#define minyear 1000
#define maxrevisits 1000

//Structure for storing date
typedef struct{
    int dd;
    int mm;
    int yyyy;
    }Date;
//structure for storing details when patient revisits to hospital
typedef struct{
    char diagnosis[maxdisease];// patients disease
    Date lastvisit; //tells us when the patient visited the hospital lastly
    char recdoc[maxsize]; //recommended doctor
    }Revisit;
//name structure for storing name and surname
typedef struct{
    char surname[maxsize];
    char NAME[maxsize];
    }Name;
//Address structure for storing the complete address
typedef struct {
    char houseno[maxsize];
    char housename[maxsize];
    char street[maxsize];
    char area[maxsize];
    char district[maxsize];
    char state[maxsize];
    char pincode[7];
    }Address;
//structure for storing username and password
typedef struct{
    char username[maxsize];
    char password[maxsize];
    }Login;
//structure for storing complete details of patient
typedef struct{
    Name name;
    unsigned int id,age;
    char phonenum[11];
    char gender;
    Date date;
    Name fathername;
    Address addy;
    char disease[maxdisease];
    char doctor[maxsize];
    Revisit revisit[maxrevisits];
    int revisit_count;
    }patientinfo;

void addpatient(FILE*fp);
void displaypatient(FILE*fp);
void deletepatient(FILE*fp);
void editpatient(FILE*fp);
//5 different types of search methods
void searchbyname(FILE*fp);
void searchbysurname(FILE*fp);
void searchbyadmitdate(FILE*fp);
void searchbydoctor(FILE*fp);
void searchbyid(FILE*fp);
//function for storing details when a patient revisited
void revisitpatient(FILE*fp);
//functions for validations
int isleapyear(int year);
int isdatevalid(Date validdate);
int isnamevalid(char name[maxsize]);
int isphonevalid(char mobile[11]);
int ispinvalid(char pin[7]);
//tells us the count of number of patients
int total(FILE*fp);
void sortbyadmitdate(FILE*fp);//sorts patients by admit date
//functions for login and update credentials
void login(FILE*fp);
void updatecredentials(FILE*fp);
int check_empty(FILE*fp); //checks the file empty or not
char *strlwr(char *str); //changes the uppercase letters to lowercase letters
