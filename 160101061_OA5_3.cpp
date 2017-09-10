#include <bits/stdc++.h>
using namespace std;

struct node			// node contain int data and node pointer
{
	int data;
	node *next;
};

node *createnode(int a){  		// createnode
	
	node *t;
	t=new node;
	t->data=a;
	t->next=NULL;
	return t;
}

void insert_b_in_a(node *head[],int a,int b){
												// insert b in ath linked list
	node *temp=createnode(b);
	node *start=head[a];
	node *t1=start->next;
	node *t=start->next;

	if (start->next==NULL || start->next->data < b)			//	if no data after head node and insert just after head node
	{
		start->next=temp;
		temp->next=t;
	}
	else{													// otherwise insert in between linked list or at last

		while(t!=NULL && t->data > b){				// find the node where create the new node
			t1=t;
			t=t->next;
		}
		t1->next=temp;
		temp->next=t;
	}

	return;
}

void data_entry(node *head[],int E){

	int a,b;
	for (int i = 0; i < E; ++i)
	{
		cin >> a;
		(head[a]->data)++;					// increase value of head a if employee from ath city

		cin >> b;
		insert_b_in_a(head,a,b);			// insert b in head a
	}

	return;
}

bool check(node *head[],int N){				// check it is possible or not

	int noc[N+1]={0};						// array for no. of min cars req.
	node *t;

	for (int i = 1; i <= N; ++i)
	{
		t=head[i];						// t is head of ith sequence
		if (t->data==0)					// is no employee then continue for ith sequence
			continue;

		t=t->next;						// t is now next node
		while(t!=NULL){
			
			noc[i]++;					// no of cars increase by one in every loop
			head[i]->data -= t->data;	// if car is filled then no. of employee is decersed by that no. of employees

			if (head[i]->data<=0)		// no. of employess are negetive denote all cars are full
				break;

			t=t->next;
		}
		
		if (head[i]->data > 0)			// if all cars full and employee are left
			return false;

	}

	for (int i = 1; i <= N; ++i)			// if it is possible then prove
	{
		printf("%d ",noc[i] );
	}
	printf("\n");

	return true;
}

int main(){

	int N,T,E;           // no. of town , position of office , no. of employee
	cin >> N >> T >> E ;

	node *head[N+1];    		// create array of N+1 pointer 

	for (int i = 0; i <= N; ++i)
	{
		head[i]=createnode(0);	// create head node of all element of array is 0
	}

	data_entry(head,E);			// data of employee and passenger per car in decending order

	head[T]->data=0;

	cout << "Output: "<<endl;

	if(check(head,N)==0)			// call check function if any fault then return 0
		printf("IMPOSSIBLE\n");		// and print IMPOSSIBLE

	return 0;
}