#include<iostream>
using namespace std;
struct node{
	int data;
	node *next;
	node *prev;
};
node *head=0,*temp,*ptr;

void insert_beg(){
	ptr=new node;
	cout<<"enter The data to be insert at beg : "<<endl;
	cin>>ptr->data;
	ptr->next=0;
	ptr->prev=0;
	ptr->next=head;
	head->prev=ptr;
	head=ptr;
}
void insert_at_pos(){
	int p,i=1;
	cout<<"At which position do want to insert : "<<endl;
	cin>>p;
	temp=head;
	while(i<p-1){
		temp=temp->next;
		i++;
	}
	cout<<"Enter Data : "<<endl;
	ptr=new node;
	cin>>ptr->data;
	ptr->prev=temp;
	ptr->next=temp->next;
	temp->next->prev=ptr;
	temp->next=ptr;
}
void insert_end(){
	ptr=new node;
	cout<<"enter The data to be insert at end : "<<endl;
	cin>>ptr->data;
	ptr->next=0;
	temp=head;
	while(temp->next!=0){
		temp=temp->next;
	}
	temp->next=ptr;
	ptr->prev=temp;
	temp=ptr;
}

void delete_beg(){
	temp=head;
	head=head->next;
	head->prev=0;
	delete temp;
	cout<<"Node deleted from beg :"<<endl;
}
void delete_at_pos(){
	node *newnode;
	int p,i=1;
	temp=head;
	cout<<"At which position do want to delete : "<<endl;
	cin>>p;
	while(i<p-1){
		temp=temp->next;
		i++;
	}
	newnode=temp->next;
	temp->next=newnode->next;
	newnode->next->prev=temp;
	delete newnode;
	cout<<"Node deleted from "<<p<<" position :"<<endl;
}
void delete_end(){
	node *prevlast;
	temp=head;
	while(temp->next!=0){
		prevlast=temp;
		temp=temp->next;
	}
	if(temp==head){
		head=0;
		delete temp;
	}
	else{
		prevlast->next=0;
		delete temp;
	}
	cout<<"Node deleted from last : "<<endl;
}

void reverse(){
	node *prevnode,*currentnode,*nextnode;
	prevnode=0;
	currentnode=head;
	nextnode=head;
	while(nextnode!=0){
		nextnode=nextnode->next;
		currentnode->next=prevnode;
		prevnode=currentnode;
		currentnode=nextnode;
	}
	head=prevnode;
	temp=head;
	while(temp!=0){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}

void display(){
	temp=head;
	while(temp!=0){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}
int main(){
	char choice;
	cout<<"Want to enter nodes : Y/N"<<endl;
	cin>>choice;
	while(choice=='Y'||choice=='y'){
		ptr=new node;
		ptr->next=0;
		ptr->prev=0;
		cout<<"Enter data : "<<endl;
		cin>>ptr->data;
		if(head==0){
			head=ptr;
			temp=ptr;
		}
		else{
			temp->next=ptr;
			ptr->prev=temp;
			temp=ptr;
		}
		cout<<"Do u want to continue ? Y/N"<<endl;
		cin>>choice;
	}
	display();
	int k;
	do{
	cout<<"Enter 1 for insert at beg\n2 for end\n3 for any postion\n4 for display \n0 for exit from inserting: "<<endl;
	cin>>k;
	switch(k){
		case 1:insert_beg();
		break;
		case 2:insert_end();
		break;
		case 3:insert_at_pos();
		break;
		case 4: display();
		break;
	}
	}while(k==1||k==2||k==3||k==4);
	int j;
	do{
	cout<<"Enter 1 for delete at beg\n2 for end\n3 for any postion\n4 for display \n0 for exit  : "<<endl;
	cin>>j;
	switch(j){
		case 1:delete_beg();
		break;
		case 2:delete_end();
		break;
		case 3:delete_at_pos();
		break;
		case 4: display();
		break;
	}
	}while(j==1||j==2||j==3||j==4);
	cout<<"The reverse the list : "<<endl;
	reverse();	
	return 0;
}
