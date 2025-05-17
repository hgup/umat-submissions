#include "211206_header.h"

#define maxsize 50
#define maxdate 15
#define maxdisease 300
#define maxyear 9999
#define minyear 1000
#define maxrevisits 1000

//function for changing the uppercase letters to lowercase letters
char *strlwr(char *str){
    unsigned char *p = (unsigned char*) str;

    while(*p){
        *p = tolower((unsigned char)*p);
        p++;
    };
    return str;
}

//Adding Patient details like patient's name and surname,age ,gender,patient's father surname and name,address,mobile number,etc
void addpatient(FILE*fp)
{
    patientinfo p;
    char a,y,Y,n;
    int status,option;

    do{
    getchar();
    printf("Enter Patient's surname(first letter in capitals) : ");
    scanf("%[^\n]",p.name.surname);
    status=isnamevalid(p.name.surname); //checks the name valid or not
    if(status==0)
    {
        printf("Invalid surname.Please enter again.\n"); //prompts user to re-enter if not valid
    }}while(status==0);

    do{
    getchar();
    printf("Enter patient's name(first letter in capitals) : "); scanf("%[^\n]",p.name.NAME);
    status=isnamevalid(p.name.NAME);
    if(status==0)
    {
        printf("Invalid name.Please enter again.\n");
    }}while(status==0);

    getchar();
    printf("Enter Patient's Age : ");
    scanf("%u",&p.age);

    fflush(stdin);
    printf("Enter Patient's Gender(M/F/O) : ");
    scanf("%c",&p.gender);

    do{
    getchar();
    printf("Enter father's surname(first letter in capitals) : ");
    scanf("%[^\n]",p.fathername.surname);
    status=isnamevalid(p.fathername.surname);
    if(status==0)
    {
        printf("Invalid surname.Please enter again.\n");
    }}while(status==0);

    do{
    getchar();
    printf("Enter father's name(first letter in capitals) : ");
    scanf("%[^\n]",p.fathername.NAME);
    status=isnamevalid(p.fathername.NAME);
    if(status==0)
    {
        printf("Invalid name.Please enter again.\n");
    }}while(status==0);

    do{
    getchar();
    printf("Enter your Mobile number : ");
    scanf("%[^\n]",p.phonenum);
    status=isphonevalid(p.phonenum); //checks the mobile number valid or not
    if(status==0)
    {
        printf("Invalid number.Please enter again.\n");
    }}while(status==0);

    getchar();
    printf("Enter your house number : ");
    scanf("%[^\n]",p.addy.houseno);

    getchar();
    printf("Enter your house/apartment name : ");
    scanf("%[^\n]",p.addy.housename);

    getchar();
    printf("Enter your street name : ");
    scanf("%[^\n]",p.addy.street);

    getchar();
    printf("Enter your Area : ");
    scanf("%[^\n]",p.addy.area);

    do{
    getchar();
    printf("Enter your district(first letter in capitals) : ");
    scanf("%[^\n]",p.addy.district);
    status=isnamevalid(p.addy.district);
    if(status==0)
    {
        printf("Invalid District name.Enter a valid District name.");
    }}while(status==0);

    do{
    getchar();
    printf("Enter your state(first letter in capitals) : ");
    scanf("%[^\n]",p.addy.state);
    status=isnamevalid(p.addy.state);
    if(status==0)
    {
        printf("Invalid State name.Enter a valid State name.");
    }}while(status==0);

    do{
    getchar();
    printf("Enter your area PINcode : ");
    scanf("%[^\n]",p.addy.pincode);
    status=ispinvalid(p.addy.pincode); //checks the PINcode valid or not
    if(status==0)
    {
        printf("Invalid Pincode.Enter a Valid PINcode.\n");
    }}while(status==0);

    getchar();
    printf("Enter your disease : "); scanf("%[^\n]",p.disease);

    getchar();
    printf("Doctor : \n1.Dr.Ram Kumar MBBS,MS(Gen)\n2.Dr.Karuku Srikanth MBBS,MS(ENT)\n3.Dr.Sunil Nayak MD,MS(Gen)\n4.Dr.Dhanunjay MD(Gen)\n");
    printf("Choose The Option : ");
    scanf("%d",&option);
    switch(option){
           case 1 : strcpy(p.doctor,"Dr.Ram Kumar MBBS,MS(Gen)");
                    break;
           case 2 : strcpy(p.doctor,"Dr.Karuku Srikanth MBBS,MS(ENT)");
                    break;
           case 3 : strcpy(p.doctor,"Dr.Sunil Nayak MD,MS(Gen)");
                    break;
           case 4 : strcpy(p.doctor,"Dr.Dhanunjay MD(Gen)");
                    break;
          default : printf("Invalid option.");
                    getchar();
                    printf("Doctor : \n1.Dr.Ram Kumar MBBS,MS(Gen)\n2.Dr.Karuku Srikanth MBBS,MS(ENT)\n3.Dr.Sunil Nayak MD,MS(Gen)\n4.Dr.Dhanunjay MD(Gen)\n");
                    printf("Choose The Option : ");
                    scanf("%d",&option);
                    break;
    }

    do{
    getchar();
    printf("Enter today's date(DD/MM/YYYY) : "); scanf("%d/%d/%d",&p.date.dd,&p.date.mm,&p.date.yyyy);
    status=isdatevalid(p.date); //checks the date valid or not
    if(status==0)
    {
        printf("Invalid Date.Please Enter a valid date\n");
    }}while(status==0);

    srand((unsigned int)time(NULL)); //Assigning Id's randomly from 10001 to 99999
    p.id=rand()%90000+10000;
    p.revisit_count=0;

    fseek(fp,0,SEEK_END);
    fwrite(&p,sizeof(p),1,fp);

    printf("Patient added successfully with ID %u\n",p.id);
    getchar();
    printf("Do you want to add one more patient?(y/n) : ");
    scanf("%c",&a);
    if(a=='y'||a=='Y')
    {
        addpatient(fp); //calls recursively until user enters N
    }
}

void displaypatient(FILE*fp)
{
    printf("Total patients : %d\n",total(fp)); //Tells count of number of patients
    rewind(fp); patientinfo p;
    //Displays patient details in an ordered format
    while(fread(&p,sizeof(p),1,fp)==1)
    {
        printf("Patient Id : %u\n",p.id);
        printf("Name : %s %s\t",p.name.surname,p.name.NAME);
        printf("Age : %uY\t",p.age);
        printf("Gender : %c\n",p.gender);
        printf("Father's name :%s %s\n",p.fathername.surname,p.fathername.NAME);
        printf("Diagnosis : %s\n",p.disease);
        printf("Recommended doctor : %s\n",p.doctor);
        printf("Admit date: %d/%d/%d\t\t",p.date.dd,p.date.mm,p.date.yyyy);
        printf("Mobile : %s\n",p.phonenum);
        printf("Patient Address : \n");
        printf("%s,%s,%s,%s,%s,%s,India,%s",p.addy.houseno,p.addy.housename,p.addy.street,p.addy.area,p.addy.district,p.addy.state,p.addy.pincode);
        printf("\n");
        printf("----------------------------------------------------------------------------------------------------------------------------------");
        printf("\n");
    }
}

void deletepatient(FILE*fp)
{
    FILE*temp;patientinfo p; unsigned int ID;
    rewind(fp);
    temp=fopen("temporary.txt","wb+"); //creates a temporary txt file
    if(temp==NULL)
    {
        printf("Error Opening File");
        fclose(temp);
    }
    printf("Enter patient's Id to delete : ");
    scanf("%u",&ID);
    while(fread(&p,sizeof(p),1,fp)==1)
        {
            if(p.id!=ID)
                fwrite(&p,sizeof(p),1,temp); //Enters every patient except what we want to delete
        }
    rewind(temp);
    fclose(temp);
    fclose(fp);
    remove("patient.txt");
    rename("temporary.txt","patient.txt"); //removes and renames file
    printf("Deletion of %u Record is Successful!\n",ID);
    fp=fopen("patient.txt","rb+");
}

void searchbyname(FILE*fp)
{
    patientinfo p;char patient[maxsize];int find=0;
    int status;
    rewind(fp);
    do{
    fflush(stdin);
    printf("Enter patient's name to search(first letter in capitals) : "); //search for patient by asking only name of part of name
    scanf("%[^\n]",patient);
    status=isnamevalid(patient);
    if(status==0)
    {
        printf("Invalid name.Please enter again.\n");
    }}while(status==0);
    while(fread(&p,sizeof(p),1,fp)==1)
    {
        //Even if user enters first letter in caps ,it will change to lowercase and search for name
        if(strstr(p.name.NAME, patient)!=NULL||strstr(p.name.NAME,strlwr(patient))!=NULL)
        {
            find++;
        printf("Patient Id : %u\n",p.id);
        printf("Name : %s %s\t",p.name.surname,p.name.NAME);
        printf("Age : %uY\t",p.age);
        printf("Gender : %c\n",p.gender);
        printf("Father's name :%s %s\n",p.fathername.surname,p.fathername.NAME);
        printf("Diagnosis : %s\n",p.disease);
        printf("Recommended doctor : %s\n",p.doctor);
        printf("Admit date: %d/%d/%d\t\t",p.date.dd,p.date.mm,p.date.yyyy);
        printf("Mobile : %s\n",p.phonenum);
        printf("----------------------------------------------------------------------------------------------------------------------------------");
        printf("\n");
        }
    }
        if(find==0)
    {
        printf("Sorry,%s is not found.\n",patient);
    }
}

void searchbysurname(FILE*fp)
{
     patientinfo p;char patient[maxsize];int find=0;int status;
    rewind(fp);
    do{
    fflush(stdin);
    printf("Enter patient's surname to search(first letter in capitals) : ");
    scanf("%[^\n]",patient);
    status=isnamevalid(patient);
    if(status==0)
    {
        printf("Invalid name.Please enter again.\n");
    }}while(status==0);
    while(fread(&p,sizeof(p),1,fp)==1)
    {
        //Even if user enters first letter in caps ,it will change to lowercase and search for surname
        if(strstr(p.name.surname, patient)!=NULL||strstr(p.name.surname,strlwr(patient))!=NULL)
        {
            find++;
        printf("Patient Id : %u\n",p.id);
        printf("Name : %s %s\t",p.name.surname,p.name.NAME);
        printf("Age : %uY\t",p.age);
        printf("Gender : %c\n",p.gender);
        printf("Father's name :%s %s\n",p.fathername.surname,p.fathername.NAME);
        printf("Diagnosis : %s\n",p.disease);
        printf("Recommended doctor : %s\n",p.doctor);
        printf("Admit date: %d/%d/%d\t\t",p.date.dd,p.date.mm,p.date.yyyy);
        printf("Mobile : %s\n",p.phonenum);
        printf("----------------------------------------------------------------------------------------------------------------------------------");
        printf("\n");
        }
    }
    if(find==0)
    {
        printf("Sorry,%s is not found.\n",patient);
    }
}

 void searchbyadmitdate(FILE*fp)
 {
     patientinfo p; Date admit;int find;int status;
     rewind(fp);
     do{
     printf("Enter patient's Admit date(DD/MM/YYYY) : ");
     scanf("%d/%d/%d",&admit.dd,&admit.mm,&admit.yyyy);
     status=isdatevalid(admit); //checks the date valid or not
    if(status==0)
    {
        printf("Invalid Date.Please Enter a valid date\n");
    }}while(status==0);
     while(fread(&p,sizeof(p),1,fp)==1)
     {
         if((p.date.dd==admit.dd)&&(p.date.mm==admit.mm)&&(p.date.yyyy==admit.yyyy))
         {
             find++;
             printf("Patient Id : %u\n",p.id);
             printf("Name : %s %s\t",p.name.surname,p.name.NAME);
             printf("Age : %uY\t",p.age);
             printf("Gender : %c\n",p.gender);
             printf("Father's name :%s %s\n",p.fathername.surname,p.fathername.NAME);
             printf("Diagnosis : %s\n",p.disease);
             printf("Recommended doctor : %s\n",p.doctor);
             printf("Admit date: %d/%d/%d\t\t",p.date.dd,p.date.mm,p.date.yyyy);
             printf("Mobile : %s\n",p.phonenum);
             printf("----------------------------------------------------------------------------------------------------------------------------------");
             printf("\n");
         }
     }
     if(find==0)
     {
         printf("Sorry,no patients admitted on %d/%d/%d\n",admit.dd,admit.mm,admit.yyyy);
     }
 }
void searchbydoctor(FILE*fp)
{
    patientinfo p;int find,option;
    rewind(fp);char doc[maxsize];
     getchar();
    printf("Doctor : \n1.Dr.Ram Kumar MBBS,MS(Gen)\n2.Dr.Karuku Srikanth MBBS,MS(ENT)\n3.Dr.Sunil Nayak MD,MS(Gen)\n4.Dr.Dhanunjay MD(Gen)\n");
    printf("Choose The Option : ");
    scanf("%d",&option);
    switch(option){
           case 1 : strcpy(doc,"Dr.Ram Kumar MBBS,MS(Gen)");
                    break;
           case 2 : strcpy(doc,"Dr.Karuku Srikanth MBBS,MS(ENT)");
                    break;
           case 3 : strcpy(doc,"Dr.Sunil Nayak MD,MS(Gen)");
                    break;
           case 4 : strcpy(doc,"Dr.Dhanunjay MD(Gen)");
                    break;
          default : printf("Invalid option.");
                    getchar();
                    printf("Doctor : \n1.Dr.Ram Kumar MBBS,MS(Gen)\n2.Dr.Karuku Srikanth MBBS,MS(ENT)\n3.Dr.Sunil Nayak MD,MS(Gen)\n4.Dr.Dhanunjay MD(Gen)\n");
                    printf("Choose The Option : ");
                    scanf("%d",&option);
                    break;
    }
    while(fread(&p,sizeof(p),1,fp)==1)
    {
        if(strcmp(p.doctor,doc)==0)
        {
            find++;
        printf("Patient Id : %u\n",p.id);
        printf("Name : %s %s\t",p.name.surname,p.name.NAME);
        printf("Age : %uY\t",p.age);
        printf("Gender : %c\n",p.gender);
        printf("Father's name :%s %s\n",p.fathername.surname,p.fathername.NAME);
        printf("Diagnosis : %s\n",p.disease);
        printf("Recommended doctor : %s\n",p.doctor);
        printf("Admit date: %d/%d/%d\t\t",p.date.dd,p.date.mm,p.date.yyyy);
        printf("Mobile : %s\n",p.phonenum);
        printf("----------------------------------------------------------------------------------------------------------------------------------");
        printf("\n");
        }
    }
    if(find==0)
    {
        printf("Sorry,Patients with %s is not found.\n",p.doctor);
    }
}
void searchbyid(FILE*fp)
{
     patientinfo p;unsigned int ID;
     int find;
    rewind(fp);
    printf("Enter patient's ID to search : ");
    scanf("%u",&ID);
    while(fread(&p,sizeof(p),1,fp)==1)
    {
        if(p.id==ID) //search for a patient by id and gives full details of patient we want
        {
            find=1;
        printf("Patient Id : %u\n",p.id);
        printf("Name : %s %s\t",p.name.surname,p.name.NAME);
        printf("Age : %uY\t",p.age);
        printf("Gender : %c\n",p.gender);
        printf("Father's name :%s %s\n",p.fathername.surname,p.fathername.NAME);
        printf("Diagnosis : %s\n",p.disease);
        printf("Recommended doctor : %s\n",p.doctor);
        printf("Admit date: %d/%d/%d\t\t",p.date.dd,p.date.mm,p.date.yyyy);
        printf("Mobile : %s\n",p.phonenum);
        printf("Patient Address : \n");
        printf("%s,%s,%s,%s,%s,%s,India,%s\n",p.addy.houseno,p.addy.housename,p.addy.street,p.addy.area,p.addy.district,p.addy.state,p.addy.pincode);
        printf("Patient History : \n");
        for(int x=1;x<=p.revisit_count;x++)
            {
                printf("%d.you have visited on %d/%d/%d for %s super visioned by %s\n",x,p.revisit[x].lastvisit.dd,p.revisit[x].lastvisit.mm,p.revisit[x].lastvisit.yyyy,p.revisit[x].diagnosis,p.revisit[x].recdoc);}
        printf("----------------------------------------------------------------------------------------------------------------------------------");
        printf("\n");
        break;
        }
    }
     if(find==0)
       {printf("Sorry,%u is not found.\n",ID);}
}
void editpatient(FILE*fp)
{
    patientinfo p;unsigned int ID;int opt;int status;
    unsigned int a;
    rewind(fp);
    printf("Enter patient's ID to update: ");
    scanf("%u",&ID);

    while(fread(&p,sizeof(p),1,fp)==1)
    {
        if(p.id==ID)
        {
        printf("Your Old data is : \n");
        printf("Patient Id : %u\n",p.id);
        printf("Name : %s %s\t",p.name.surname,p.name.NAME);
        printf("Age : %uY\t",p.age);
        printf("Gender : %c\n",p.gender);
        printf("Father's name :%s %s\n",p.fathername.surname,p.fathername.NAME);
        printf("Diagnosis : %s\n",p.disease);
        printf("Recommended doctor : %s\n",p.doctor);
        printf("Admit date : %d/%d/%d\t\t",p.date.dd,p.date.mm,p.date.yyyy);
        printf("Mobile : %s\n",p.phonenum);
        printf("----------------------------------------------------------------------------------------------------------------------------------");
        printf("\n");
        //Edits the basic details of patients whichever user want
        printf("What do you want to edit : \n");
        printf("1.name\n2.surname\n3.age\n4.gender\n5.father's surname\n6.father's name\n7.Disease\n8.Mobile Number\n9.To Exit Edit\n");
        printf("Enter the option : "); scanf("%d",&opt);
        while(opt)
        {
           if(opt<=9)
           {
            if(opt==1)
            {
                do{
                    getchar();
                printf("Enter the name(first letter in capitals) : ");
                scanf("%[^\n]",p.name.NAME);
                    status=isnamevalid(p.name.NAME);
                if(status==0)
                {
                    printf("Invalid name.Please enter again.\n");
                }}while(status==0);
                printf("Update Menu\n");
                printf("1.name\n2.surname\n3.age\n4.gender\n5.father's surname\n6.father's name\n7.Disease\n8.Mobile Number\n9.To Exit Edit\n");
                printf("Enter the option : "); scanf("%d",&opt);
            }
            if(opt==2)
            {
                do{
                getchar();
                printf("Enter the surname(first letter in capitals) :");
                scanf("%[^\n]",p.name.surname);
                status=isnamevalid(p.name.surname);
                if(status==0)
                {
                    printf("Invalid surname.Please enter again.\n");
                }}while(status==0);
                printf("Update Menu\n");
                printf("1.name\n2.surname\n3.age\n4.gender\n5.father's surname\n6.father's name\n7.Disease\n8.Mobile Number\n9.To Exit Edit\n");
                printf("Enter the option : "); scanf("%d",&opt);
            }
            if(opt==3)
            {
                getchar();
                printf("Enter the age : ");
                scanf("%u",&a);
                p.age=a;
                printf("Update Menu\n");
                printf("1.name\n2.surname\n3.age\n4.gender\n5.father's surname\n6.father's name\n7.Disease\n8.Mobile Number\n9.To Exit Edit\n");
                printf("Enter the option : "); scanf("%d",&opt);
            }
            if(opt==4)
            {
                fflush(stdin);
                printf("Enter the gender : ");
                scanf("%c",&p.gender);
                printf("Update Menu\n");
                printf("1.name\n2.surname\n3.age\n4.gender\n5.father's surname\n6.father's name\n7.Disease\n8.Mobile Number\n9.To Exit Edit\n");
                printf("Enter the option : "); scanf("%d",&opt);
            }
            if(opt==5)
            {
                do{
                getchar();
                printf("Enter the Father's surname(first letter in capitals) : ");
                scanf("%[^\n]",p.fathername.surname);
                status=isnamevalid(p.fathername.surname);
                if(status==0)
                {
                    printf("Invalid surname.Please enter again.\n");
                }}while(status==0);
                printf("1.name\n2.surname\n3.age\n4.gender\n5.father's surname\n6.father's name\n7.Disease\n8.Mobile Number\n9.To Exit Edit\n");
                printf("Enter the option : "); scanf("%d",&opt);
            }
            if(opt==6)
            {
                do{
                getchar();
                printf("Enter the Father's Name(first letter in capitals) : ");
                scanf("%[^\n]",p.fathername.NAME);
                status=isnamevalid(p.fathername.NAME);
                if(status==0)
                {
                    printf("Invalid name.Please enter again.\n");
                }}while(status==0);
                printf("Update Menu\n");
                printf("1.name\n2.surname\n3.age\n4.gender\n5.father's surname\n6.father's name\n7.Disease\n8.Mobile Number\n9.To Exit Edit\n");
                printf("Enter the option : "); scanf("%d",&opt);
            }
            if(opt==7)
            {
                getchar();
                printf("Enter the Disease : ");
                scanf("%[^\n]",p.disease);
                printf("Update Menu\n");
                printf("1.name\n2.surname\n3.age\n4.gender\n5.father's surname\n6.father's name\n7.Disease\n8.Mobile Number\n9.To Exit Edit\n");
                printf("Enter the option : "); scanf("%d",&opt);
            }
            if(opt==8)
            {
                getchar();
                printf("Enter the mobile number : ");
                scanf("%[^\n]",p.phonenum);
                printf("Update Menu\n");
                printf("1.name\n2.surname\n3.age\n4.gender\n5.father's surname\n6.father's name\n7.Disease\n8.Mobile Number\n9.To Exit Edit\n");
                printf("Enter the option : "); scanf("%d",&opt);
            }
            if(opt==9)
            {
                break;
            }
           }
           else
           {
               printf("Invalid option");
               break;
           }
        }
        fseek(fp,-sizeof(p),SEEK_CUR);
        fwrite(&p,sizeof(p),1,fp); //writes to the file
        break;
        }
}
fseek(fp,-sizeof(p),SEEK_CUR);
fread(&p,sizeof(p),1,fp); //read from file and prints it
printf("Your New Data is : \n");
printf("Patient Id : %u\n",p.id);
printf("Name : %s %s\t",p.name.surname,p.name.NAME);
printf("Age : %uY\t",p.age);
printf("Gender : %c\n",p.gender);
printf("Father's name :%s %s\n",p.fathername.surname,p.fathername.NAME);
printf("Diagnosis : %s\n",p.disease);
printf("Recommended doctor : %s\n",p.doctor);
printf("Admit date : %d/%d/%d\t\t",p.date.dd,p.date.mm,p.date.yyyy);
printf("Mobile : %s\n",p.phonenum);
printf("----------------------------------------------------------------------------------------------------------------------------------");
printf("\n");
}

void revisitpatient(FILE*fp)
{
    patientinfo p;
    unsigned int ID;
    int status,option,found=0;
    rewind(fp);
    getchar();
    printf("Enter patient's ID : ");
    scanf("%u",&ID);
    fflush(stdin);
    while(fread(&p,sizeof(p),1,fp)==1)
    {
         if(p.id==ID)
         {
             found=1;
             if(p.revisit_count>=maxrevisits)
             {
                 printf("Maximum revisit records reached for this patient\n");
                 return;
             }
             else
                {
                if(p.revisit_count==0)
                    p.revisit_count=1;
                else    p.revisit_count++;
                }
           do{
                //asks for today's date
              printf("Enter Today's date (DD/MM/YYYY) : "); scanf("%d/%d/%d",&p.revisit[p.revisit_count].lastvisit.dd,&p.revisit[p.revisit_count].lastvisit.mm,&p.revisit[p.revisit_count].lastvisit.yyyy);
              status=isdatevalid(p.revisit[p.revisit_count].lastvisit);}while(status==0);
              if(status==0)
              {
                  printf("Invalid Date.Please Enter a valid date.\n");
              }
              //asks for disease of patient
           getchar();
           printf("Enter your disease : ");
           scanf("%[^\n]",p.revisit[p.revisit_count].diagnosis);

           //asks for choosing the doctor
           getchar();
           printf("Doctor : \n1.Dr.Ram Kumar MBBS,MS(Gen)\n2.Dr.Karuku Srikanth MBBS,MS(ENT)\n3.Dr.Sunil Nayak MD,MS(Gen)\n4.Dr.Dhanunjay MD(Gen)\n");
           printf("Choose The Option : ");
           scanf("%d",&option);
           switch(option){
                case 1 : strcpy(p.revisit[p.revisit_count].recdoc,"Dr.Ram Kumar MBBS,MS(Gen)");
                         break;
                case 2 : strcpy(p.revisit[p.revisit_count].recdoc,"Dr.Karuku Srikanth MBBS,MS(ENT)");
                         break;
                case 3 : strcpy(p.revisit[p.revisit_count].recdoc,"Dr.Sunil Nayak MD,MS(Gen)");
                         break;
                case 4 : strcpy(p.revisit[p.revisit_count].recdoc,"Dr.Dhanunjay MD(Gen)");
                         break;
                default : printf("Invalid option.");
                          getchar();
                          printf("Doctor : \n1.Dr.Ram Kumar MBBS,MS(Gen)\n2.Dr.Karuku Srikanth MBBS,MS(ENT)\n3.Dr.Sunil Nayak MD,MS(Gen)\n4.Dr.Dhanunjay MD(Gen)\n");
                          printf("Choose The Option : ");
                          scanf("%d",&option);
                          break;
    }

           fseek(fp,-sizeof(patientinfo),SEEK_CUR);
           fwrite(&p,sizeof(patientinfo),1,fp);
           printf("patient revisit is successful!\n");
           break;
         }
    }
    if(!found)
    {
        printf("Sorry,%u is not found\n",ID);
        return;
    }

rewind(fp);
while(fread(&p,sizeof(p),1,fp)==1)
{

    if(p.id==ID)
    {
         printf("Patient History : \n");
            {
                 printf("Your last visit was on %d/%d/%d for %s super visioned by %s\n",p.revisit[p.revisit_count].lastvisit.dd,p.revisit[p.revisit_count].lastvisit.mm,p.revisit[p.revisit_count].lastvisit.yyyy,p.revisit[p.revisit_count].diagnosis,p.revisit[p.revisit_count].recdoc);
            }
    }
}

}
//Additional functions
int isleapyear(int year) //checks the year if it's leapyear or not
{
    if(((year/4==0)&&(year/100!=0))||(year/400==0))
        return 1;

return 1;
}

int isdatevalid(Date validdate) ////checks the date valid or not
{
    if(validdate.yyyy<minyear||validdate.yyyy>maxyear)
        return 0;
    if(validdate.mm<1||validdate.mm>12)
        return 0;
    if(validdate.dd<1||validdate.dd>31)
        return 0;
    if(validdate.mm==2)
    {
        if(isleapyear(validdate.yyyy))
            return(validdate.dd<=29);
        else return(validdate.dd<=28);
    }
    if(validdate.mm==4||validdate.mm==6||validdate.mm==9||validdate.mm==11)
        return(validdate.dd<=30);
return 1;
}

int isnamevalid(char name[maxsize]) //checks the name entered valid or not
{
    int i,length;
    length=strlen(name);
    for(i=0;i<length;i++)
    {
        if(isupper(name[0])&&isalpha(name[i]))
            return 1;
        else return 0;
    }
return 1;
}

int isphonevalid(char mobile[11]) //checks the dentered mobile number valid or not
{
    int length;
    length=strlen(mobile);
    if(length==10)
        return 1;
    else return 0;
    for(int i=0;i<length;i++)
    {
        if(isdigit(mobile[i]))
            return 1;
        else return 0;
    }
        if(mobile[0]==6||mobile[0]==7||mobile[0]==8||mobile[0]==9)
            {
                return 1;
            }
        else return 0;
return 1;
}
int ispinvalid(char pin[7]) //checks the PINcode of area valid or not
{
    int length,i;
    length=strlen(pin);
    if(length==6||length==7)
        return 1;
    else return 0;
    for(i=0;i<length;i++)
    {
        if(isdigit(pin[i])||pin[3]==32)
            return 1;
        else return 0;
    }
    if(pin[0]==0)
    {
        return 0;
    }
    else return 1;
return 1;
}
int total(FILE*fp) //gives total number of patients in the file
{
    rewind(fp);
    patientinfo p;
    int count;
    while(fread(&p,sizeof(p),1,fp)==1)
    {
        count++;
    }
return count;
}
void sortbyadmitdate(FILE*fp) //Sorts all the patient records by admitdate
{
 patientinfo p,temp;
 int i,j,minindex,count;
 long int size;
 fseek(fp,0,SEEK_END);
 size=ftell(fp);
 rewind(fp);
 count=size/sizeof(patientinfo);
 patientinfo *s;
 s=(patientinfo*)malloc(count*sizeof(patientinfo));
 fread(s,sizeof(patientinfo),count,fp);

 for(i=0;i<count-1;i++)
 {
     minindex=i;
     for(j=i+1;j<count;j++)
     {
         if((s[minindex].date.yyyy>s[j].date.yyyy)||((s[minindex].date.yyyy==s[j].date.yyyy)&&(s[minindex].date.mm>s[j].date.mm))||
           ((s[minindex].date.yyyy==s[j].date.yyyy)&&(s[minindex].date.mm==s[j].date.mm)&&(s[minindex].date.dd>s[j].date.dd))||
           ((s[minindex].date.yyyy==s[j].date.yyyy)&&(s[minindex].date.mm==s[j].date.mm)&&(s[minindex].date.dd==s[j].date.dd)&&(s[minindex].id>s[j].id)))
              {minindex=j;}
     }
    if(minindex!=i)
        {
            temp=s[i];
            s[i]=s[minindex];
            s[minindex]=temp;
        }
 }
 rewind(fp);
 fwrite(s,sizeof(patientinfo),count,fp);
 free(s);
}
void updatecredentials(FILE*fp) //user can change their credentials
{
    int option;Login p;
    char username[maxsize];char password[maxsize];
    FILE*p2;
    p2=fopen("hmslogin.txt","rb+");
    if(p2==NULL)
    {
        printf("Error Opening File.\n");
        exit(0);
    }
    fseek(p2, 0, SEEK_SET);
    fread(&p, sizeof(p), 1, p2);
    printf("Your Old Username : %s\n",p.username);
    printf("Your Old Password : %s\n",p.password);
    printf("What do you want to update : \n1.Username\n2.Password\n3.To Exit\n ");
    printf("Enter the option : ");
    scanf("%d",&option);
    while(option)
    {
      if(option<=3)
      {
        if(option==1)
        {
            printf("Enter the new username : ");
            scanf("%s[^\n]",username);
            getchar();
            strcpy(p.username,username);
            printf("Your username update successfully!\n");
            printf("What do you want to update : \n1.Username\n2.Password\n3.To Exit\n ");
            printf("Enter the option : ");
            scanf("%d",&option);
        }
        if(option==2)
        {
            printf("Enter the new password : ");
            getchar();
            scanf("%s[^\n]",password);
            strcpy(p.password,password);
            printf("Your password updated successfully!\n");
            printf("What do you want to update : \n1.Username\n2.Password\n3.To Exit\n ");
            getchar();
            printf("Enter the option : ");
            scanf("%d",&option);
        }
        if(option==3)
        {
            break;
        }
       }
       else
       {
        printf("Invalid option.\n");
        break;
       }
    }
    fseek(p2,-sizeof(p),SEEK_CUR);
    fwrite(&p,sizeof(p),1,p2);
fseek(p2,-sizeof(p),SEEK_CUR);
fread(&p,sizeof(p),1,p2);
printf("Your new username : %s\n",p.username);
printf("Your new password : %s\n",p.password);
fclose(p2);
}

void login(FILE*p2) //a login interface
{
    Login p;
    p2=fopen("hmslogin.txt","rb+");
    if(p2==NULL)
    {
        printf("Error Opening File.\n");
        printf("If it is first time ,please create hmslogin.txt in your system and compile it again");
        exit(0);
    }
    else{

        fread(&p, sizeof(p), 1, p2);
        
        if(check_empty(p2))
        {
            printf("No existing credentials found. Setting up new credentials.\n");
            printf("Enter new username: ");
            scanf("%s", p.username);
            printf("Enter new password: ");
            scanf("%s", p.password);
            fseek(p2, 0, SEEK_END);
            fwrite(&p, sizeof(p), 1, p2);
            fclose(p2);
        }
        else {
            char unm[maxsize];char pwd[maxsize];
            int option;
            int l=1;
            printf("Total no.of Attempts : 3\n");
            do{
                printf("\t\t================Login==================\t\t\t\n");
                printf("No.Of Attempts Remaining : %d\n",4-l);
                printf("Enter Username : ");
                scanf("%s",unm);
                printf("Enter Password : ");
                scanf("%s",pwd);
            
                if(strcmp(p.username,unm)==0&&strcmp(p.password,pwd)==0)
                break;
                else {
                    printf("Enter correct Username And Password\n");
                    l++;
                }
            }while(l<=3);
            if(l>3)
            {
                printf("Sorry!Login Failed.");
                exit(0);
            }
        }
    }
}

//checks the file empty or not
int check_empty(FILE*fp){
	if(fp!=NULL){
		fseek(fp, 0, SEEK_END);
		int size= ftell(fp);
		if(0==size){
			return 1;
		}
		return 0;
	}
}
