/* The file handling simple program for the student details.*/
#include<stdio.h>
#include"header.h"
int main(){
	FILE *fp;
	fp=fopen("studentdetails.txt","r");
	if(fp==NULL){
		printf("New file is created for the details..");
		fp=fopen("studentdetails.txt","w");
		if(fp==NULL){
			printf("Unable to create the file !!!!");
				}
		return 0;
	}
	fclose(fp);
char ch='y';
int x=0;
while(ch =='y'){
	printf("\n The to be performed on the file as followed insert=1,disply=2,updata=3,delete=4 :");
	scanf("%d",&x);
	getchar();
	switch(x){
		case 1:// The case can insert the details of the student.
				insert(fp);
				break;
		case 2:// The case would display the file.
				display(fp);
				break;
		case 3:// The case would updata details of the student on basis of the redg no.
				fupdata(fp);
				break;
		case 4:// The case would delete the student details from the file with referance to redg.no.
				fdelete(fp);
				break;
	}
	printf("\n Do you want continue the process:");
	scanf("%c",&ch);
	getchar();
	printf("%c",ch);
}	
return 0;
}
	





