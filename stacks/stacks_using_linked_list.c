#include<stdio.h>
#include<stdlib.h>
#include <windows.h> 
#include<conio.h>

struct node {
    int val;
    struct node *next;
};

struct node* push(struct node* head,int x)
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->val=x;
    if(head==NULL)
    {
        head=temp;
        temp->next=NULL;
    }
    else{
        temp->next=head;
        head=temp;
    }
    return head;
}

void display(struct node* head)
{
    if(head==NULL)
    {
        printf("\033[31m\n\tError!! List is Empty\033[0m");
        return;
    }
    printf("\n\tRequired List: ");
    while(head!=NULL)
    {
        printf("%d->",head->val);
        head=head->next;
    }
    printf("Null");
    return;
}
void delete(struct node *head)
{
    while(head!=NULL){
        struct node *temp=head;
        head=head->next;
        free(temp);
    }
}
struct node* pop(struct node *head)
{
    struct node* temp=head;
    struct node* to_be_deleted;
    if(head==NULL)
    {
        printf("\033[31m\n\tError!! List is Empty\033[0m");
        return;
    }
    if(head->next==NULL)
    {
        to_be_deleted=head;
        head=NULL;
        printf("\n\tValue popped -> %d",to_be_deleted->val);
        free(to_be_deleted);
        return head;
    }
    to_be_deleted=head;
    head=head->next;
    printf("\n\tValue popped -> %d",to_be_deleted->val);
    free(to_be_deleted);
    return head;
}




void peek(struct node *head)
{
    if(head==NULL)
    {
        printf("\033[31m\n\tError!! List is Empty\033[0m");
        return;
    }
    printf("\n\t Peek Value -> %d",head->val);
    return;
}

int peep(struct node *head,int i)
{
    struct node* temp=head;
    if(head==NULL)
    {
        printf("\033[31m\n\tError!! List is Empty\033[0m");
        return -1;
    }
    while(temp!=NULL)
    {
        if(i==0) break;
        temp=temp->next;
        i--;
    }
    if(i!=0)
    {
        printf("\033[31m\n\tError!! Choose valid position for peek operation\033[0m");
        return -1;
    }
    return temp->val;
}

void update(struct node *head,int i,int x)
{
    struct node* temp=head;
    if(head==NULL)
    {
        printf("\033[31m\n\tError!! List is Empty\033[0m");
        return;
    }
    while(temp!=NULL)
    {
        if(i==0) break;
        temp=temp->next;
        i--;
    }
    if(i!=0)
    {
        printf("\033[31m\n\tError!! Choose valid position for peek operation\033[0m");
        return;
    }
    temp->val=x;
}


int main()
{
    HANDLE  hConsole;


    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    struct node* head=NULL;
    int x,n,check,t;
    do
    {
        SetConsoleTextAttribute(hConsole, 5);
        printf("\033[1m\n\n\tMENU\033[0m");
        printf("\n\t\033[1m1.Push\033[0m");
        printf("\n\t\033[1m2.Pop\033[0m");
        printf("\n\t\033[1m3.Peek\033[0m");
        printf("\n\t\033[1m4.Peep\033[0m");
        printf("\n\t\033[1m5.Update\033[0m");
        printf("\n\t\033[1m6.Display\033[0m");
        printf("\n\t\033[1m7.Exit\033[0m\n\t");
        SetConsoleTextAttribute(hConsole, 6);
        scanf("%d",&n);
        switch (n)
        {
            case 1: printf("\n\tEnter the value ");
                    scanf("%d",&x);
                    head=push(head,x);
                    break;
            case 2: head=pop(head);
                    break;
            case 3: peek(head);
                    break;
            case 4: printf("\n\tEnter the ith position ");
                    scanf("%d",&x);
                    check=peep(head,x);
                    if(check!=-1) printf("\n\t%d",check);
                    break;
            case 5: printf("\n\tEnter the position to update ");
                    scanf("%d",&x);
                    printf("\n\tEnter the updated value ");
                    scanf("%d",&t);
                    update(head,x,t);
                    break;
            case 6: display(head);
                    break;
            case 7: delete(head);
                    exit(1);
            default:
                    printf("\n\t\033[31mChoose Correct Choices\033[0m");
                    break;
        }
    } while (1);
    delete(head);
    return 0;
}