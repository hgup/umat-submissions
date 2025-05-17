/* The set of functions for the file handling such as insert,delete,display,updata.*/
#include<stdio.h>
#include"header.h"
// The function to insert to the file means to write in the file.
void insert(FILE *fp){
	char ch='y';
	student s;
	fp=fopen("studentdetails.txt","a");
	if(fp==NULL)
	  return ;
	while(ch=='y'){
		printf("Enter name ,age ,regdNO ,gpa");
		scanf("%s %d %d %f",s.name,&s.age,&s.regdNO,&s.gpa);
		getchar();
		printf("%s ,%d ,%d ,%f ",s.name,s.age,s.regdNO,s.gpa);
		fwrite(&s,sizeof(s),1,fp);
		printf("Another record (y/n)");
		scanf("%c",&ch);
			getchar();
	}
	fclose(fp);
}
// The function to display the student details record.
void display(FILE *fp){student s;

	fp=fopen("studentdetails.txt","rb");
	while(fread(&s,sizeof(s),1,fp))
		printf("%s %d %d %f\n",s.name,s.age,s.regdNO,s.gpa);
	fclose(fp);
}

// The function to updata the details of the spcified regd number.
void fupdata(FILE *fp){student s;
	fp=fopen("studentdetails.txt","rb+");
	if(fp==NULL){
		puts("Unable to open the file..");
		return;
	}
	int x;
	printf("Enter the regd.no to be updated :");
	scanf("%d",&x);
	getchar();
	//printf("nooooo");
	//fseek(fp,0,SEEK_CUR);
    while(fread(&s,sizeof(s),1,fp)){
		if(s.regdNO==x){
			printf("Enter the new name to be updataed:");
			scanf("%s",s.name);
			getchar();
			printf("Enter the  new age and new gpa :");
			scanf("%d %f",&s.age,&s.gpa);
			getchar();
			// To seek the pointer to the addrese.
			fseek(fp,-sizeof(s),SEEK_CUR);
			fwrite(&s,sizeof(s),1,fp);
			printf("Student details updataed succfully.");
			fclose(fp);
			return ;
		}

	}fclose(fp);
}	
// The function to delete the student details of the specific student based on the redg.No.
void fdelete(FILE *fp){student s;
	int found=0,x;
	fp=fopen("studentdetails.txt","rb");
	if(fp==NULL){
		puts("Unable to open the file sorry !!!!");
		return ;
	}
    FILE *tm;
	tm=fopen("Temp.txt","wb");
	if(tm==NULL){
		puts("Unable to create the space sorry !!!");
		return ;
	}
	printf("Enter the student regd.No to be deleted from the file:");
	scanf("%d",&x);
	getchar();
	while(fread(&s,sizeof(s),1,fp)){
		if(s.regdNO!=x){
			fwrite(&s,sizeof(s),1,tm);
		}
		else{
			found=1;
		}
	}
	fclose(fp);
	fclose(tm);
	remove("studentdetails.txt");
	rename("temp.txt","studentdetails.txt");
	if(found)
		printf("The entered student regdno=%d is deleted succefully.",x);
	else
		printf(" The entered redgno=%d was not found in the file sorry.",x);
}
