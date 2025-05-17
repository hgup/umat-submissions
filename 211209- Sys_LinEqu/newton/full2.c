#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	double data; 
    struct node * next;} node;

typedef struct polynode {
    double coef;
    int exp;
    struct polynode* next;} poly;

poly* sum(poly* A, poly* B)
{
    poly* sum = NULL;
    poly* temp = NULL;
    while (A && B)
    {  if (A->exp > B->exp)
           {if (temp == NULL)
            {temp = malloc(sizeof(poly));
                sum = temp;}
            else
            {temp->next = malloc(sizeof(poly));
             temp = temp->next; }
            temp->coef = A->coef;
            temp->exp =  A->exp;
            A = A->next;}
       else if (A->exp < B->exp)
           {if (temp == NULL)
            {temp = malloc(sizeof(poly));
             sum = temp;}
            else
            {temp->next = malloc(sizeof(poly));
             temp = temp->next;}
            temp->coef = B->coef;
            temp->exp = B->exp;
            B = B->next;  }
        else
        {int co = A->coef + B->coef;
         if (co != 0)
            {if (temp == NULL)
                {temp = malloc(sizeof(poly));
                 sum = temp;}
                else
                {temp->next = malloc(sizeof(poly));
                 temp = temp->next;}
                temp->coef = co;
                temp->exp = A->exp;}
            A = A->next;
            B = B->next;}
        if (A || B) // Check if there are more terms to add
        {temp->next = NULL;}
    }
    poly* extra = A ? A : B;  //A if A else B
    while (extra)
    {   temp->next = malloc(sizeof(poly));
        temp = temp->next;
        temp->exp = extra->exp;
        temp->coef = extra->coef;
        extra = extra->next;
        if (extra) // Check if there are more terms to add
        {temp->next = NULL; }
    }
    return sum;
}

poly* product(poly* A, poly* B)
{ if (A == NULL || B == NULL)
    { return NULL;} 
   poly* result = NULL;
   poly* tempResult = NULL;

   while (A)
    {
        poly* temp = NULL;
        poly* tempResultRow = NULL;
        poly* Bcopy = B;

        while (Bcopy)
             {int coef = A->coef * Bcopy->coef;
             int exp = A->exp + Bcopy->exp;
             if (coef != 0)
                {   poly* newNode = malloc(sizeof(node));
                    newNode->coef = coef;
                    newNode->exp = exp;
                    newNode->next = NULL;
                    if (temp == NULL)         //first iteration
                    {   temp = newNode;
                        tempResultRow = temp;
                    }
                    else
                    {   temp->next = newNode;
                        temp = temp->next;  }
                }    
             Bcopy = Bcopy->next;}
        A = A->next;
        if (temp)
        {  if (result == NULL)           //first iteration of every A
            {   result = tempResultRow;
                tempResult = result;}
            else
            { tempResult = sum(tempResult, tempResultRow); }
        }
    }
    return tempResult;
}

int len(node* list) {
    if (list==NULL) { return 0;}
    else {
        int count=0;
        while(list!=NULL) {
            count+=1; 
            list=list->next;
        }
        return count;
    }
}

node* remove_head(node* list){
    list= list->next;
    return list;
}

node* remove_tail(node* list){
    node* temp= list;
    while(list->next!=NULL){
        list=list->next;
    }
    list=NULL;
    return temp;
}

double head(node* list){
    return list->data;
}
double tail(node* list){
    while(list->next!=NULL){
        list=list->next;
    }
    return list->data;
}


void print(double* X, int n) {
    for (int i=0; i<n; i++) {
        printf("%lf ", X[i]);
    }
    printf("\n");
}

double f(double x, double* X, double*Y, int n) {
    //finid the index in X
    int index;
    for (int i=0;i<n;i++) {
        if (X[i]==x){
        index=i;
        }
    }
    return Y[index];
}

poly* multiply(int n) {
    poly* temp= malloc(sizeof(poly));
    temp->exp=1;
    temp->coef=1;
    poly* cons= malloc(sizeof(poly));
    cons->exp=0;
    cons->coef=-n;
    temp->next= cons;
    cons->next= NULL;
    return temp;               //returns (x-n)
}

poly* factor(int n) {          //return (x-x0)(x-x1)(x-x2)...(x-xn)
    poly* init= malloc(sizeof(poly));
    for (int i=0; i<n; i++) {
        poly* factor= multiply(i);
        init= product(init, factor);
    }
    return init;
}

double divided_diff(node* list, double* X, double* Y, int n) {
    if (len(list)>2) {
        node* dup1= list;
        node* dup2= list;
        double h, t;
        h=head(dup1); //head that's getting chopped
        t=tail(dup2); //tail that's getting chopped
        dup1=remove_head(dup1);
        dup2=remove_tail(dup2);
        return (divided_diff(dup1, X, Y, n)- divided_diff(dup2, X, Y, n)) / (t-h); 
    }
    else{ double h,t,sol;
        h=head(list);
        t=tail(list);
        return( (f(h, X, Y, n) - f(t, X, Y, n)) / (t-h));

    }
}


poly* getfactor(double x, double* X, double* Y, int n){     //final
    poly* init= malloc(sizeof(poly));
    poly* result= init;
    init->exp=0;
    init->coef=f(x,X, Y, n);
    double diff;
    poly* temp= malloc(sizeof(poly));
    for (int i=0; i<n; i++) {
        temp= factor(i); 
        //create a linked list tosend to newton
        node* head= malloc(sizeof(node));
        node* dummy= head;
        for (int j=0; j<i+1; j++){
            head->data= X[j];
            head->next= malloc(sizeof(node));
            head=head->next;
        }
        diff=divided_diff(dummy, X, Y, n);
        //create a polynomial for diff
        poly* difference = malloc(sizeof(poly)); 
        difference->coef= diff;
        difference->exp=0;
        difference->next=NULL;
        temp=product(temp, difference);
        init=sum(init, temp);
    }
return result;    //returns the final polynomial
}

void display(poly* head)
{ while (head!=NULL)
	{ if ((head->exp!=0) &&(head->exp!=1))  {printf("%dx^%d + ", head->coef,head->exp); }
	  else if (head->exp==1) {printf("%dx + ", head->coef);}
	  else { if (head->coef!=0) { printf("%d ", head->coef); } }
	 head=head->next;
	  }
  printf("\n");
}

int main(){
    int n;
    printf("Enter how many data points you have");
    scanf("%d",&n);
    double* X= (double *)malloc(n* sizeof(double));
    double* Y= (double *)malloc(n* sizeof(double));
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &X[i], &Y[i]);
    }
    poly* result;
    result= getfactor(X[0], X, Y, n);
    //print the polynomial
    display(result);
    if (result==NULL) {printf("Hello");}
}