#include<stdio.h>
int stack[20];
int top = -1;

void push(int x) {
    stack[++top] = x;
}
int pop() {
    return stack[top--];
}
int main(){
    int num;

    printf("Enter a decimal number: ");
    scanf("%d", &num);

    if (num == 0) {
        printf("Binary: 0");
        return 0;
    }

    while (num > 0){
        push(num % 2);
        num=num/2;
    }

    printf("BINARY : ");
    while(top!=-1){
        printf("%d",pop());
    }
    return 0;
    
}