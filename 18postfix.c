#include<stdio.h>
#include<ctype.h>
struct stack{
    char data[50];
    int top;
};
void init(struct stack *s){
    s->top=-1;
}

void push( struct stack *s ,char c){
    s->top++;
    s->data[s->top]=c;
}

char pop(struct stack  *s){
    return   s->data[s->top--];
}
int priority(char c){
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2; 
    if (c == '^') return 3;
    return 0;
}
int main(){
    struct stack s;
    char exp[20],ch;
    int i;
    init(&s);

    printf("Enter infix expression: ");
    scanf("%s", exp);
    
    for(i=0 ; exp[i] != '\0' ; i++){
        ch=exp[i];
        
        if(isalpha(ch)){
            printf("%c",ch);
        }
        else if(ch == '('){
            push(&s,ch);
        }
        else if(ch == ')'){
            while(s.data[s.top]!= '(')
                printf("%c",pop(&s));
            pop(&s); // remove '('
        }
        else{
            while(s.top != -1 && priority(s.data[s.top]) >= priority(ch)){
                printf("%c",pop(&s));
            }
            push(&s, ch);

        }
    }
while (s.top != -1){
    printf("%c",pop(&s));
}
return 0;
}