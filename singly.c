#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

/* Insert at end */
void insert() {
    int val;
    struct node *newnode, *temp;

    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter value: ");
    scanf("%d", &val);

    newnode->data = val;
    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
        return;
    }

    temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newnode;
}

/* Display */
void display() {
    struct node *temp = head;
    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

/* Search */
void search() {
    int key, pos = 1;
    struct node *temp = head;

    printf("Enter value to search: ");
    scanf("%d", &key);

    while (temp != NULL) {
        if (temp->data == key) {
            printf("Value found at position %d\n", pos);
            return;
        }
        temp = temp->next;
        pos++;
    }
    printf("Value not found\n");
}

/* Update */
void update() {
    int oldv, newv;
    struct node *temp = head;

    printf("Enter value to update: ");
    scanf("%d", &oldv);

    while (temp != NULL) {
        if (temp->data == oldv) {
            printf("Enter new value: ");
            scanf("%d", &newv);
            temp->data = newv;
            printf("Updated successfully\n");
            return;
        }
        temp = temp->next;
    }
    printf("Value not found\n");
}

/* Delete using p */
void deleteNode() {
    int key;
    struct node *temp = head, *p = NULL;

    printf("Enter value to delete: ");
    scanf("%d", &key);

    while (temp != NULL) {
        if (temp->data == key) {
            if (p == NULL)          // delete first node
                head = temp->next;
            else
                p->next = temp->next;

            free(temp);
            printf("Deleted successfully\n");
            return;
        }
        p = temp;
        temp = temp->next;
    }
    printf("Value not found\n");
}

/* Count */
void count() {
    int cnt = 0;
    struct node *temp = head;

    while (temp != NULL) {
        cnt++;
        temp = temp->next;
    }
    printf("Total nodes = %d\n", cnt);
}

int main() {
    int ch;
    do {
        printf("\n1.Insert");
        printf("\n2.Display");
        printf("\n3.Search");
        printf("\n4.Update");
        printf("\n5.Delete");
        printf("\n6.Count");
        printf("\n7.Exit");
        printf("\nEnter choice: ");
        scanf("%d", &ch);

        switch (ch) {
        case 1: insert(); break;
        case 2: display(); break;
        case 3: search(); break;
        case 4: update(); break;
        case 5: deleteNode(); break;
        case 6: count(); break;
        case 7: printf("Exit\n"); break;
        default: printf("Invalid choice\n");
        }
    } while (ch != 7);

    return 0;
}
