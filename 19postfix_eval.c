#include<stdio.h>
#include <ctype.h>

char stack[15];
int top = -1;

void push(char c){
    stack[++top]=c;
}
char pop(){
    return stack[top--];
}
int prio(char c){
    if (c== '+' || c== '-') return 1;
    if (c== '*' || c== '/') return 2;
    return 0;

}
int main(){
    char exp[15],postfix[15],i,k=0;
    printf("enter infix exp : ");
    scanf("%s",exp);

    // infix to postfix

    for(i=0;exp[i] !='\0';i++){
        if(isdigit(exp[i])){
            postfix[k++]=exp[i];
        }
        else{
            while(top != -1 && prio(stack[top])>= prio(exp[i])){
                postfix[k++]=pop();
            }
            push(exp[i]);
        }
    }
    while(top!=-1){
        postfix[k++]=pop();
    }
    postfix[k++]='\0';

     printf("Postfix: %s\n", postfix);


     int val[15],vtop=-1;
     for (i=0;postfix[i]!='\0';i++){
        if(isdigit(postfix[i]))
        val[++vtop]=postfix[i]-'0';
        else{
            int b= val[vtop--];
            int a= val[vtop--];
             if (postfix[i] == '+') val[++vtop] = a + b;
            if (postfix[i] == '-') val[++vtop] = a - b;
            if (postfix[i] == '*') val[++vtop] = a * b;
            if (postfix[i] == '/') val[++vtop] = a / b;

        }

     }

     printf("result= %d ", val[vtop]);
     return 0;
}