#include <stdio.h>
#include <stdlib.h>

struct node {
    int prn;
    char name[20];
    char ay[10];
    int coord;           // 1 = coordinator, 0 = member
    struct node *next;
};

struct node *head = NULL;

void add(int c) {
    struct node *newnode, *temp;
    newnode = (struct node*)malloc(sizeof(struct node));

    printf("Enter PRN: ");
    scanf("%d", &newnode->prn);

    printf("Enter Name: ");
    scanf("%s", newnode->name);

    printf("Enter A.Y.: ");
    scanf("%s", newnode->ay);

    newnode->coord = c;
    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
    } else {
        temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}
void countMembers() {
    struct node *temp = head;
    int count = 0;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    printf("Total members = %d\n", count);
}
void display() {
    struct node *temp = head;

    printf("\nPRN\tName\tA.Y.\tRole\n");
    while (temp != NULL) {
        printf("%d\t%s\t%s\t%s\n",
               temp->prn,
               temp->name,
               temp->ay,
               temp->coord ? "Coordinator" : "Member");
        temp = temp->next;
    }
}
void deleteNode(int c) {
    struct node *temp = head, *p = NULL;
    int prn;
  printf("Enter PRN to delete: ");
    scanf("%d", &prn);
    while (temp!=NULL)
    {
        if(temp->prn==prn && temp->coord==c){
            if(p==NULL)
                head=temp->next;
            else
                p->next=temp->next;
            free(temp);
            printf("Deleted successfully\n");
            return;
            
        }
        p=temp;
        temp=temp->next;

    }
     printf("Record not found\n");
    
}
int main() {
    int ch;
    do {
        printf("\n1.Add Member");
        printf("\n2.Add Coordinator");
        printf("\n3.Display");
        printf("\n4.Delete Member");
        printf("\n5.Delete Coordinator");
        printf("\n6.Count Members");
        printf("\n7.Exit");
        printf("\nEnter choice: ");
        scanf("%d", &ch);

        switch (ch) {
        case 1:
            add(0);
            break;

        case 2:
            add(1);
            break;

        case 3:
            display();
            break;

        case 4:
            deleteNode(0);
            break;

        case 5:
            deleteNode(1);
            break;

        case 6:
            countMembers();
            break;

        case 7:
            printf("Exit\n");
            break;

        default:
            printf("Invalid choice\n");
        }

    } while (ch != 7);

    return 0;


}
