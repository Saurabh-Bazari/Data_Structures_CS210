#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	node *next;
};
node *head;
node *last;

node *create(){
	node *temp;
	temp=new node;
	return temp;
}

void push_at_start(int d){
	node *temp;
	temp=create();
	temp->data=d;

	if (head==NULL)
	{
		head=temp;
		last=temp;
		temp->next=NULL;		
	}
	else{
		temp->next=head;
		head=temp;
	}
}

void push_at_end(int d){
	node *temp;
	temp=create();
	temp->data=d;

	if (head==NULL)
	{
		head=temp;
		last=temp;
		temp->next=NULL;		
	}
	else{
		temp->next=last->next;
		last->next=temp;
		last=temp;
	}
}

node *search(int d){
	node *temp;
	temp=head;
	int k=0;
	while(temp!=NULL){
		if (temp->data==d)
		{
			return temp;
		}
		temp=temp->next;
	}
}

int circular(){
	node *temp,*temp1;
	temp=head;
	temp1=head->next;
	int k=0;
	while(temp!=NULL && temp1!=NULL && temp1->next!=NULL){
		if (k>1)
		{
			return 1;
		}
		if (temp1==temp)
		{
			k++;
		}

		temp1=temp1->next->next;
		temp=temp->next;
	}
	return 0;
}

bool search_int(int d){
	node *temp,*temp1;
	temp=head;
	temp1=head->next;
	int k=0;
	if (circular()==0)
	{
		while(temp!=NULL){
			if (temp->data==d)
			{
				k=1;
				return true;
			}
		temp=temp->next;
		}
		if (k==0)
		{
			return false;
		}
	}
	else{
		while(1){
			if (temp->data==d)
			{
				return true;
			}
			if (temp1==temp)
			{
				k++;
			}
			if (k>2)
			{
				if (temp->data==d)
				{	
					return true;
				}
				if(k>5){return false;}
			}
			
		temp1=temp1->next->next;
		temp=temp->next;
		}


	}
}


void push(node *temp,int d,node *temp1){
	node *temp2;
	temp2=create();
	temp2->data=d;
	temp2->next=temp1;
	temp->next=temp2;
}

int main()
{
	int s[100][3];
	head=NULL;
	last=head;
	node *temp,*temp1;

	for (int i = 0; i<100; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{	
			cin>>s[i][j];
			if (s[i][0]==-1)
				{
					break;
				}
		}
		if (s[i][0]==-1)
		{
			break;
		}
	}

	for (int i = 0; s[i][0]!=-1; ++i)
	{
		if (s[i][0]==0)
		{
			push_at_start(s[i][1]);
		}
		else if (s[i][2]==0)
		{
			push_at_end(s[i][1]);
		}
		else{
			temp=search(s[i][0]);
			temp1=search(s[i][2]);
			push(temp,s[i][1],temp1);
		}
	}

	int se;
	cin >> se;
	if (search_int(se )==1)
	{
		printf("FOUND\n");
	}
	else{
		printf("NOT FOUND\n");
	}

	return 0;
}
