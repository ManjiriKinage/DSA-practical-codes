#include <stdio.h>
#include <string.h>

char stack[50];
int top = -1;

void push(char ch) {
    stack[++top] = ch;
}

char pop() {
    return stack[top--];
}

int main(){
    char exp[50];
    int i;

    printf("Enter expression: ");
    scanf("%s", exp);
    for(i=0;exp[i]!='\0';i++){
        if( exp[i] == '(' || exp[i]=='{' || exp[i] =='['){
            push(exp[i]);
        }
        else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']'){
            if(top==-1){
                printf("not balanced");
                return 0;
            }
        char open=pop();

        if((open == '(' && exp[i] != ')') || 
        (open == '[' && exp[i] != ']') ||
        (open == '{' && exp[i] != '}')){
            printf("not balanced");
            return 0;
        }


        }
    }
        if (top == -1)
        printf("Balanced");
    else
        printf("Not Balanced");

    return 0;

}