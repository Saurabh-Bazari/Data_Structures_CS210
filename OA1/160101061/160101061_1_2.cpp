#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	node *next;
};


node *Q1=NULL;
node *Q2=NULL;
node *S=NULL;

node *create(){
	node *temp;
	return temp=new node;
}

node *last_node(node *Q){
	node *temp1,*temp;
	temp1=Q;
	while(temp1!=NULL){
		temp=temp1;
		temp1=temp1->next;
	}
	return temp;
}

node* enqueue(node *Q,int d){
	node *temp,*temp1;
	temp=create();
	temp->data=d;
	temp->next=NULL;
	
	if (Q==NULL)
	{
		Q=temp;
	}
	else{
		temp1=last_node(Q);
		temp1->next=temp;
	}
	return Q;
}

int dequeue(){
	int t;
	t=Q1->data;
	Q1=Q1->next;
	return t;
}

void push(int d){
	node *temp;
	temp=create();
	temp->data=d;
	if (S==NULL)
	{
		S=temp;
		temp->next=NULL;
	}
	else{
		temp->next=S;
		S=temp;
	}
}

int pop(){
	int t;
	t=S->data;
	S=S->next;
	
	return t;
}

void print(node *q){
	node *temp;
	temp=q;

	
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<< endl;
}

int main()
{
	int n,t,k,p;
	k=0;
	p=0;
	int y[50];
	cin >> n;

	for (int i = 0; i < n; ++i)
	{

		Q1=enqueue(Q1,i+1);
	}

	for (int i = 0; i < n; ++i)
	{
		cin >> t;
		Q2=enqueue(Q2,t);
	}
	// main function 
	for (int i = 0; Q2!=NULL; ++i)
	{
		if (Q1!=NULL && Q2->data==Q1->data)
		{
			dequeue();
			Q2=Q2->next;
			cout<<"enqueue(Q2, dequeue(Q1))"<<endl;
		}
		else if (Q1!=NULL && Q2->data > Q1->data)
		{
			while(Q2->data!=Q1->data){
				push(dequeue());
				cout<<"push(S, dequeue(Q1))"<<endl;
			}
			if (Q1!=NULL && Q2->data==Q1->data)
			{
				dequeue();
				Q2=Q2->next;
				cout<<"enqueue(Q2, dequeue(Q1))"<<endl;
			}
		}
		else if(Q1!=NULL && Q1->data > Q2->data && S!=NULL){
			y[p]=pop();
			if (Q2->data==y[p])
			{
				Q2=Q2->next;
				cout<<"enqueue(Q2, pop(S))"<<endl;
			}
			else{
				cout<< y[p] <<" is top element of stack instead of "<< Q2->data <<endl;
				break;
			}
			p++;

		}
		else if (Q1==NULL && S!=NULL)
		{
			y[p]=pop();
			if (Q2->data==y[p])
			{
				Q2=Q2->next;
				cout<<"enqueue(Q2, pop(S))"<<endl;
			}
			else{
				cout<< y[p] <<" is top element of stack instead of "<< Q2->data <<endl;
				break;
			}
			p++;

			
		}
		if (k>n)
		{
			printf("ErrOr\n");
			break;
		}

	}

	return 0;
}


