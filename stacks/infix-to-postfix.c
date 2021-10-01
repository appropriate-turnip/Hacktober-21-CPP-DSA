#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX 100

char stack[MAX];
int top=-1;
void push(char stack[],char val)
{
    if(top==MAX-1)
        printf("\nStack OverFlow");
    else
    {
        top++;
        stack[top] = val;
    }
}
char pop(char stack[])
{
    char val=' ';
    if(top==-1)
        printf("\n Stack UnderFlow");
    else
    {
        val=stack[top];
        top--;
    }
    return val;
}

int getPriority(char op)
{
    if(op=='/' || op=='*' || op =='%')
    {
        return 1;
    }
    else if(op=='+' || op=='-')
    {
        return 0;
    }
}


void infixtopostfix(char source[],char target[])
{
    int i=0,j=0;
    char temp;
    strcpy(target,"");

    while(source[i]!='\0')
    {
        if(source[i]=='(')
        {
            push(stack,source[i]);
            i++;
        }
        else if(source[i]==')')
        {
            while((top!=-1) && (stack[top]!='('))
            {
                target[j]=pop(stack);
                j++;
            }
            if(top==-1)
            {
                printf("\n Incorrect expression");
                exit(1);
            }
            temp = pop(stack);
            i++;
        }
        else if(isdigit(source[i]) || isalpha(source[i]))
        {
            target[j]=source[i];
            j++;
            i++;
        }
        else if(source[i]=='+' || source[i]=='-' || source[i] == '*' || source[i] == '/' || source[i]=='%')
        {
            while(top!=-1 && (stack[top]!='(') && (getPriority(stack[top])>getPriority(source[i])))
            {
                target[j]=pop(stack);
                j++;
            }
            push(stack,source[i]);
            i++;
        }
        else
        {
            printf("\n Incorrect element in expression");
            exit(1);
        }
    }
    while(top!=-1 && stack[top]!='(')
    {
        target[j]=pop(stack);
        j++;
    }
    target[j]='\0';
}
int main()
{
    char infix[100],postfix[100];
    printf("\n\tEnter infix expression:  ");
    gets(infix);
    strcpy(postfix,"");
    infixtopostfix(infix,postfix);
    printf("\n\t Postfix expression :  ");
    puts(postfix);
    return 0;
}