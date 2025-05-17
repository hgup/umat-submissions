#include <stdio.h>
#include <string.h>
#include "header.h"

int main() {
    FILE *file;
    int choice;
    char plname[MAX_PLAYERNAME_LENGTH];
    file = fopen("fifa.txt", "rb+");
    if (file == NULL) {
        printf("Error opening file. If it is the first time, please create a file named fifa.txt.\n");
        return 1;
    }

do{


	
 printf("                //######### FIFA UPDATE ########//           ");
printf("\nMenu:\n");
printf("1.insert new FIFAupdate\n");
printf("2.golden boot award \n");
printf("3.golden Ball award \n");
printf("4.Younger player award\n");
printf("5.Golden glove award\n");
printf("6.fifa fair play award\n");
printf("7.silver boot award \n");
printf("8.Bronze boot award\n");
printf("9.silver ball award\n");
printf("10.bronze Boot award\n");
printf("11.name of country qulified for FIFA2022\n");
printf("12.Which country hosted FIFA2022\n");
printf("13.champion of FIFA2022\n");
printf("14.Runner up of FIFA2022\n");
printf("16.Delete playername\n");
printf("17.Display All new FIFAupdate\n");
printf("15.Exit\n");
printf("Enter a choice:\n");
	scanf("%d",&choice);

switch (choice){
	case 1:
	insertFIFA2022(file);
	break ;
	case 2:
	printf("name:Kylian Mbappe\n");
		printf("jerseynum:10\n");
		printf("Country:France\n");
		break;
	case 3:
		printf("name:Lionel Messi\n");
	       printf("jerseynum:10\n");
               printf("Country:Argentina\n");
	       break;
	case 4:
                printf("name:Enzo Fernandez\n");
                 printf("jerseynum:24\n");
                 printf("Country:Argentina\n");
		 break;
	case 5:
		 printf("name:Emiliano matinez\n");
                 printf("jerseynum:23\n");
                 printf("Country:Argentina\n");
		 break;
	case 6:
		 printf("England");
		 break;
	case 7:
		 printf("name:Lionel Messi\n");
                 printf("jerseynum:10\n");
                 printf("Country:Argentina\n");
		 break;
	case 8:
		 printf("name:Oliver Giroud\n");
                 printf("jerseynum:9\n");
                 printf("Country:France\n");
		 break;
	case 9:
		 printf("name:Kylian Mbappe\n");
                 printf("jerseynum:10\n");
                 printf("Country:France\n");
		 break;
	case 10:
		 printf("name:Luka modire\n");
                 printf("jerseynum:10\n");
                 printf("Country:crotia\n");
		 break;
	case 11:
		 printf("Qatar\n");printf( "Ecuador\n");printf("Senegal\n");printf( "Netherlands\n");
                        printf("England\n");printf("Iran\n"); printf("USA\n"); printf("Wales\n");printf("Argentina\n"); 
			printf("SaudiArabia\n"); printf("Mexico\n");printf("Poland\n");printf("France\n"); 
			printf("Australia\n");printf("Denmark\n"); printf("Tunisia\n");printf("Spain\n");
                         printf("CostaRica\n"); printf("Germany\n"); printf("Japan\n");printf("Belgium\n");
			printf( "Canada\n");printf("Morocco\n");printf( "Croatia\n");printf("Brazil\n");printf( "Serbia\n"); 
			printf("Switzerland\n");printf("Cameroon\n");printf("Portugal\n"); printf("Ghana\n");printf( "Uruguay\n"); 
			printf("SouthKorea\n");
		 break;
	case 12:
		 printf("Qatar");
		 break;
	case 13:
		 printf("Argentina");
		 break;
	case 14:
		 printf("France");
		 break;
	case 16:
		 printf("enter a playername to delete:");
			 scanf("%s",plname);
	         
		 deleteFIFA2022(file,plname);
		 break;
	case 17:

		 sortFIFA2022Bygoals(file);
		 struct FIFA2022 F;
		 rewind(file);
		 while(fread(&F,sizeof(struct FIFA2022),1,file) == 1)
		 {displayFIFA2022(F);
		 } 
		 break;

 default:
		printf("Thank you\n");
}}
while (choice != 15);
fclose(file);
return 0;
}
