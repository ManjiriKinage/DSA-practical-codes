#include <stdio.h>
#include <ctype.h>

char stack[15];
int top = -1;

void push(char c)
{
    stack[++top] = c;
}

char pop()
{
    if (top == -1)
        return -1;
    return stack[top--];
}

int prio(char c)
{
    if (c == '(') return 0;
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    if (c == '^' || c == '$') return 3;
    return -1;
}

int main()
{
    char exp[15], c;
    int i;

    printf("Enter infix expression:\n");
    scanf("%s", exp);

    for (i = 0; exp[i] != '\0'; i++)
    {
        if (isalpha(exp[i]))
        {
            printf("%c", exp[i]);
        }
        else if (exp[i] == '(')
        {
            push(exp[i]);
        }
        else if (exp[i] == ')')
        {
            while ((c = pop()) != '(')
                printf("%c", c);
        }
        else
        {
            while (top != -1 && prio(stack[top]) >= prio(exp[i]))
                printf("%c", pop());
            push(exp[i]);
        }
    }

    while (top != -1)
        printf("%c", pop());

    return 0;
}
