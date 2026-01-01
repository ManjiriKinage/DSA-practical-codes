#include <stdio.h>

int queue[20];
int front = 0, rear = -1;

void enqueue(int x) {
    queue[++rear] = x;
}

int main() {
    int num, i;

    printf("Enter a decimal number: ");
    scanf("%d", &num);

    if (num == 0) {
        printf("Binary: 0");
        return 0;
    }

    while (num > 0) {
        enqueue(num % 2);
        num = num / 2;
    }

    printf("Binary: ");
    for (i = rear; i >= front; i--) {
        printf("%d", queue[i]);
    }

    return 0;
}
