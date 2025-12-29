#include <stdio.h>
#include <stdlib.h>
struct node {
    int bit;
    struct node *next;
    struct node *prev;
};
struct node *head=NULL ,*tail=NULL;

/*void insert(int bit){
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->bit = bit;
    newnode->next=NULL;
    newnode->prev=tail;
    if(head==NULL){
        head=newnode;
    }else{
        tail->next=newnode;
    }
    tail=newnode;
}*/

void insert(int bit){
    struct node *temp, *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->bit = bit;
    newnode->next=NULL;
    newnode->prev=NULL;
    if(head==NULL){
        head=newnode;
        return;
    }
    temp=head;
    while(temp->next!= NULL ){
     temp = temp->next;
    }
     temp->next = newnode;
     newnode->prev=temp;
}


void display(){
    struct node *temp =head;
    while(temp != NULL){
        printf("%d",temp->bit);
        temp=temp->next;
    }
    printf("\n");
}
void onescomplement(){
    struct node *temp= head;
    while (temp!=NULL)
    {
      temp->bit = (temp->bit==0) ? 1 : 0;
      temp= temp->next;
    }
    
}
int main(){
    int n,bit,i;
    printf("Enter number of bits: ");
    scanf("%d", &n);
    printf("Enter binary number:\n");
    for(i=0;i<n;i++){
    scanf("%d",&bit);
    insert(bit);
    }

    printf("\nOriginal Binary Number: ");
    display();
    onescomplement();
    printf("1's complement : ");
    display();

    return 0;
}
