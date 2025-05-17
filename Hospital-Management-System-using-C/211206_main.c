#include "211206_header.h"

int main()
{
    printf("\t\tWelcome to the Hospital Management System\t\t\n");
    FILE*p1;
    int input,choice;
    login(p1); //asks for a login
    p1=fopen("patient.txt","rb+");
    if(p1==NULL)
    {
        printf("Error Opening file");
	      printf("If it is first time,plese create patient.txt file in your system and then compile it again");
        exit(0);
    }
   printf("Main Menu\n"); //displays Main Menu
   printf("1.Add Patient Details\n2.Display Patient Record\n3.Search Patient\n4.Delete Patient Details\n5.Update Patient Details\n6.Patient Revisit\n7.Update Credentials\n8.To Exit\n");
   printf("Enter the option : ");
   scanf("%d",&input);
   while(input)
   {
    if(input<=8)
    {
       if(input==1)
       {
         sortbyadmitdate(p1); //First it sorts all the records then
         addpatient(p1); //asks the user to enter a new record
         printf("Main Menu\n");
         printf("1.Add Patient Details\n2.Display Patient Record\n3.Search Patient\n4.Delete Patient Details\n5.Update Patient Details\n6.Patient Revisit\n7.Update Credentials\n8.To Exit\n");
         printf("Enter the option : ");
         scanf("%d",&input);
       }
       if(input==2)
       {
         displaypatient(p1); //displays all patient records
         printf("Main Menu\n");
         printf("1.Add Patient Details\n2.Display Patient Record\n3.Search Patient\n4.Delete Patient Details\n5.Update Patient Details\n6.Patient Revisit\n7.Update Credentials\n8.To Exit\n");
         printf("Enter the option : ");
         getchar();
         scanf("%d",&input);
       }
       if(input==3)
       {
           ////5 different types of search methods
           getchar();
           printf("Do you want to search by \n1.name\n2.Surname\n3.ID(for full details)\n4.Admit date\n5.Recommended Doctor\n(press any other key to return main menu)\n");
           printf("Enter the choice : ");
           scanf("%d",&choice);
           switch(choice)
           {
               case 1 : searchbyname(p1);
                        break;
               case 2 : searchbysurname(p1);
                        break;
               case 3 : searchbyid(p1);
                        break;
               case 4 : searchbyadmitdate(p1);
                        break;
               case 5 : searchbydoctor(p1);
                        break;
               default : break;
           }
           printf("Main Menu\n");
           printf("1.Add Patient Details\n2.Display Patient Record\n3.Search Patient\n4.Delete Patient Details\n5.Update Patient Details\n6.Patient Revisit\n7.Update Credentials\n8.To Exit\n");
           printf("Enter the option : ");
           getchar();
           scanf("%d",&input);
       }
       if(input==4)
       {
         deletepatient(p1); //deletes a patient record of our choice
         printf("Main Menu\n");
         printf("1.Add Patient Details\n2.Display Patient Record\n3.Search Patient\n4.Delete Patient Details\n5.Update Patient Details\n6.Patient Revisit\n7.Update Credentials\n8.To Exit\n");
         printf("Enter the option : ");
         getchar();
         scanf("%d",&input);
       }
       if(input==5)
       {
         editpatient(p1); //edits a patient's basic details
         printf("Main Menu\n");
         printf("1.Add Patient Details\n2.Display Patient Record\n3.Search Patient\n4.Delete Patient Details\n5.Update Patient Details\n6.Patient Revisit\n7.Update Credentials\n8.To Exit\n");
         printf("Enter the option : ");
         getchar();
         scanf("%d",&input);
       }
       if(input==6)
       {
         revisitpatient(p1); //when a patient revisits it stores the details
         printf("Main Menu\n");
         printf("1.Add Patient Details\n2.Display Patient Record\n3.Search Patient\n4.Delete Patient Details\n5.Update Patient Details\n6.Patient Revisit\n7.Update Credentials\n8.To Exit\n");
         printf("Enter the option : ");
         getchar();
         scanf("%d",&input);
       }
       if(input==7)
       {
         updatecredentials(p1);//Updates username and password
         printf("\t\tWelcome to the Hospital Management System\t\t\n");
         login(p1); //Asks for login after updating credentials
         printf("Main Menu\n");
         printf("1.Add Patient Details\n2.Display Patient Record\n3.Search Patient\n4.Delete Patient Details\n5.Update Patient Details\n6.Patient Revisit\n7.Update Credentials\n8.To Exit\n");
         printf("Enter the option : ");
         getchar();
         scanf("%d",&input);
       }
       if(input==8)
       {
         printf("Thank You for using Hospital Management System.\n");
         exit(0);
       }
    }
    else
    {
     printf("Invalid Option.");
     break;
    }
   }
fclose(p1);
}
