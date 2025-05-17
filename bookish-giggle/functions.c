/* the functionsof the linked list */
#include<stdio.h>
#include"linked.h"
// the function to display the list.
void display(struct node *head){
		struct node *temp=head;
		while(temp!=NULL){
				printf("%c",temp->data);
				temp=temp->next; };

				}

// the function to count the number of elements in the list.
void count(struct node *head){
	int x=0;
	while(head!=NULL){
	 	               x++;     
			       head=head->next;  
			      }
	printf("the number of elements is %d:",x-1);
	}

// the function to insert from the begining.
struct node* insert_in_begining(struct node *head,char x){
			struct node *temp;
			temp=(struct  node *)malloc(sizeof(struct node));
			if (temp!=NULL){
			temp->data=x;
			temp->next=head;
			}
			return temp;
			}

//the function to insert at the position.
struct node* insert_after_position(struct node *head,char x,int pos){
	int c=1;
	struct node *temp;
	struct node *t=head;
	temp=(struct  node *)malloc(sizeof(struct node));
	if(head ==NULL&&pos>0)
		return 0;
	if(pos==0){
		temp->next=head;
		temp->data=x;
		return temp;}
	while(c<pos&&head->next!=NULL) {
		head=head->next;
		c++;
		}
	if(c==pos){
	temp->next=head->next;
	temp->data=x;
	head->next=temp->next;}
	return t;
	}
							
// Delete the word from the list.
struct node* delete(struct node*head,char x){
	 struct node *prev=NULL,*current=head;
	 while(current!=NULL){
	 	if(current->data==x){
			if(current==head)
				head=head->next;
			else 
				prev->next=current->next;
			free(current);}
		else { prev=current;
		current=current->next;
		}
		return head;
		}
		return head;
		}

// The function to insert in the ascending order.
struct node* insert_ascending_order(struct node *head,char x){
	struct node *temp,*t=head;
	temp=(struct node *)malloc(sizeof(struct node));
	if(temp!=NULL) {
		 temp->data=x;
		if(head->data==NULL||head->data>x){
		temp->next=head;
		return temp;}
		else
	 	{	while(t->next!=NULL){
				if(t->data<=x&&t->next->data>x){
					temp->next=t->next;
					t->next=temp;
				return head;
				}
			else
				t=t->next;
				}
				t->next=temp;
				return head;
				}
		}
	else
	{	printf("Not able to allocate the memory.");
		return head;
		}
}

// The function to delete the list.
struct node* delete_list(struct node*head){
		while(head!=NULL){
			head=head->next; }
			return head;
			}

// The function to trim the list.
struct node* trim(struct node*head){
		if(head!=NULL)
			head=head->next;
		return head;
		}

// The function to swap two adjacent nodes.

//struct node* swap_adjacent_nodes(struct node *head){


// The function for the union of the two linked lists.
struct node* un_ion(struct node *H1,struct node *H2){
	struct node *H,*t;
	struct node *head=NULL;
	if(H1==NULL&&H2==NULL)
		return NULL;
	while(H1!=NULL&&H2!=NULL){
			if(t==NULL){
				t=malloc(sizeof(struct node*));
				head=t;
				}
			else { 
				t->next=malloc(sizeof(struct node*));
				t=t->next;
				}
		if(H1->data < H2->data){
			t->data=H1->data;
			H1=H1->next;
			}
			else if(H1->data>H2->data){
				t->data=H2->data;
				H2=H2->next;
				}
				else if(H1->data==H2->data){
					t->data=H1->data;
					H1=H1->next;
					H2=H2->next;
					}
				}

				if(H1!=NULL)
					H=H1;
				else if(H2!=NULL)
					H=H2;
					while(H!=NULL){
						if(head==NULL){
							t=malloc(sizeof(struct node*));
							head=t;
							}
							else {
								t->next=malloc(sizeof(struct node *));
								t=t->next;
								}
								t->data=H->data;
								H=H->next;
							}
							return head;
							
							}



