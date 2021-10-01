#include<stdio.h>
#include<stdlib.h>
// Top declaration
int top=-1; 
int n;
int check_overflow()
{
    if(top==n-1)     
    {
        printf("\n\tStack overFlow");
        return 1;
    }
    return 0;
}
int check_underflow()
{
    if(top==-1)     
    {
        printf("\n\tStack underFlow");
        return 1;
    }
    return 0;
}
void push(int *a,int x)
{
    if(check_overflow())    return;
    top++;
    a[top]=x;
    return;
}
void pop(int *a)
{
    if(check_underflow())   return;
    printf("\n\tvalue deleted %d",a[top]); 
    top--;
    return;
}
int peek(int *a)
{
    if(check_underflow())   return -1;
    return a[top];
}
int peep(int *a,int i)
{
    if(check_underflow())   return -1;
    if(top-i < 0)
    return -1;
    return a[top-i];
}

void update(int *a,int i,int value)
{
    int prevValue ;
    if(top-i < 0)
    return -1;
    prevValue=a[top-i];
    a[top-i]=value;
    printf("\n\t%d is updated to %d\n",prevValue,value);
}
void display(int *a)
{
   if(check_underflow())   return -1;
   for(int i=top;i>=0;i--)
   {
       printf("\n\t%d  ",a[i]);
   } 
   return;
}
int main()
{
    printf("\nEnter the size of stack");
    scanf("%d", &n);
    int *a= (int *)malloc(n*sizeof(int));
    if(a==NULL)
    {
        printf("\033[31m\n\n\tAllocation fails \nStack overflow\033[0m");exit(1);
    }
        printf("\033[31m\n\n\tMENU\033[0m");
        printf("\n\t1.Push");
        printf("\n\t2.Pop");
        printf("\n\t3.Peek");
        printf("\n\t4.Peep");
        printf("\n\t5.Update");
        printf("\n\t6.Display");
        printf("\n\t7.Exit\n\t");
    int x,n,check,t;
    do
    {
        printf("\n\tChoose option\n\t");
        scanf("%d",&n);
        switch (n)
        {
            case 1: printf("\n\tEnter the value to be pushed ");
                    scanf("%d",&x);
                    push(a,x);
                    break;
            case 2: pop(a);
                    break;
            case 3: check=peek(a);
                    if(check!=-1) printf("\n\t%d",check);
                    break;
            case 4: printf("\n\tEnter the value for peep ");
                    scanf("%d",&x);
                    check=peep(a,x);
                    if(check!=-1) printf("\n\t%d",check);
                    break;
            case 5: printf("\n\tEnter the position to update ");
                    scanf("%d",&x);
                    printf("\n\tEnter the updated value ");
                    scanf("%d",&t);
                    update(a,x,t);
                    break;
            case 6: display(a);
                    break;
            case 7: free(a);
                    exit(1);
            default:
                    printf("\n\t\033[31mChoose Correct Choices\033[0m");
                    break;
        }
    } while (1);

    return 0;
}