/* the header liberay of the linked list of prototype */
#include <stdio.h>
#include<stdlib.h>
struct node{
	char data;
	struct node *next;
	};

void display();
struct node* insert_in_begining(struct node *head,char x);
void count();
struct node* insert_after_position(struct node *head,char x,int pos);
void insert_from_end();
void insert_in_the_sorted();
struct node* insert_ascending_order(struct node *head,char x);
struct node* delete(struct node*head,char x);
struct node* un_ion(struct node *H1,struct node*H2);
