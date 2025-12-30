#include <stdio.h>
#include <stdlib.h>

// Doubly linked list node
struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL, *tail = NULL;

// Insert bit at end (MSB → LSB storage)
void insert(int bit) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = bit;
    newnode->next = NULL;
    newnode->prev = NULL;

    if (head == NULL) {
        head = tail = newnode;
    } else {
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }
}

// Display binary number (MSB → LSB)
void display() {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int n, bit;

    printf("Enter number of bits: ");
    scanf("%d", &n);

    printf("Enter bits (MSB to LSB): ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &bit);
        insert(bit);
    }

    printf("Binary Number: ");
    display();

    return 0;
}
