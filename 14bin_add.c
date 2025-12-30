#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node* insert(struct node *head, int value) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = head;
    return newnode;
}

struct node* addBinary(struct node* h1, struct node* h2) {
    struct node* result = NULL;
    int carry = 0, sum;

    while (h1 != NULL || h2 != NULL || carry) {
        sum = carry;

        if (h1 != NULL) {
            sum += h1->data;
            h1 = h1->next;
        }

        if (h2 != NULL) {
            sum += h2->data;
            h2 = h2->next;
        }

        carry = sum / 2;
        result = insert(result, sum % 2);
    }
    return result;
}

// ✅ Correct display (MSB → LSB)
void display(struct node* head) {
    if (head == NULL)
        return;
    display(head->next);
    printf("%d", head->data);
}

int main() {
    struct node *bin1 = NULL, *bin2 = NULL, *sum = NULL;
    int n, bit;

    printf("Enter number of bits for first binary number: ");
    scanf("%d", &n);
    printf("Enter bits (MSB to LSB): ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &bit);
        bin1 = insert(bin1, bit);
    }

    printf("Enter number of bits for second binary number: ");
    scanf("%d", &n);
    printf("Enter bits (MSB to LSB): ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &bit);
        bin2 = insert(bin2, bit);
    }

    printf("\nFirst Binary Number: ");
    display(bin1);

    printf("\nSecond Binary Number: ");
    display(bin2);

    sum = addBinary(bin1, bin2);

    printf("\nSum of Binary Numbers: ");
    display(sum);

    return 0;
}
