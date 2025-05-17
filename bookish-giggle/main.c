/* the main function of the linked list */
#include<stdio.h>
#include"linked.h"
int main() {
	struct node *head=NULL,*H1=NULL,*H2=NULL;
//	head=(struct  node *)malloc(sizeof(struct node));
	H1=(struct  node *)malloc(sizeof(struct node));
	H2=(struct  node *)malloc(sizeof(struct node));
	int a,i,b,pos,c;
	char x;
	printf("the number of elements to be inserted :");
	scanf("%d",&a);
	for(i=0;i<a;i++){
		printf("\n Where do you want to insert the charater at\n\t begining=1 \n\tdisplay =2 \n\tcount=3,\n\tafter a position=4,\n\tin ascending order=5,\n\tto delete=6:" );
		scanf("%d",&b);
		switch(b){
		case 1: 
			printf("The charater to be inserted:");
			scanf("%c",&x);
			head=insert_in_begining(head,x);
			break;
		case 2:
			display(head);
			break;
		case 3:
		 	count(head);
			break;
		case 4:
			printf("the position to be inserted :");
			scanf("%d",&pos);
			printf("The charater to be inserted:");
			scanf("%c",&x);
			head=insert_after_position(head,x,pos);
			break;
		case 5:
			printf("the number of charaters to be inserted in ascending order of the list :");
			scanf("%d",&b);
			while(b>0){
				printf("the charater to be added to the list:");
				scanf("%c",&x);
				head=insert_ascending_order(head,x);
				b--;
				}
			break;
		case 6:
			printf("Enter the charater to be deleted:");
			getchar();
			scanf("%c",&x);
			head=delete(head,x);
			break;
		case 7:
		 	printf("The case will union the two lists.");
			printf("The number of elements to be entered:");
			scanf("%i",&c);
			while(c!=0){
				printf("Enter the charater to be :");
				getchar();
				scanf("%c",&x);
				c--;
				H1=insert_in_begining(H1,x);
				H2=insert_in_begining(H2,x);
				}

			head=un_ion(H1,H2);
			display(head);
			break;

		case 8:
			printf("The case will intersect the two lists.");
			}
			}
			return 0;
		}
	
