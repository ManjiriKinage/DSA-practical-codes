#include<stdio.h>
#include<stdlib.h>
struct node {
    char name[20];
    struct node *next;
};
struct node *front = NULL, *rear = NULL;

void enqueue(){
  struct node *newnode = (struct node*)malloc(sizeof(struct node));
 printf("Enter friend's name: ");
 scanf("%s",newnode->name);
 newnode->next=NULL;
 if(rear==NULL){
    front=rear=newnode;
 }else{
    rear-> next=newnode;
    rear=newnode;
 }

}

void dequeue() {
    if(front== NULL){
         printf("Queue is empty\n");
         return;
    }

    struct node *temp=front;
     printf("Removed: %s\n", temp->name);
     front=front->next;
     free(temp);

     if(front==NULL){
        rear=NULL;
     }
}

void display() {
    struct node *temp = front;

    if (temp == NULL) {
        printf("Queue is empty\n");
        return;
    }
        printf("Friends Queue: ");
        while (temp!=NULL)
        {
            printf("%s->",temp->name);
            temp=temp->next;
        }
        
printf("NULL\n");
}
int main(){
    int ch;
    do{
       printf("\n1.Enqueue");
        printf("\n2.Dequeue");
        printf("\n3.Display");
        printf("\n4.Exit");
        printf("\nEnter choice: ");
        scanf("%d", &ch);
        
        switch(ch){
             case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: printf("Exit\n"); break;
            default: printf("Invalid choice\n");
        }
    }while(ch !=4 );
    return 0;

}