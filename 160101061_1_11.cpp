#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	node *next;	
};

node *create(){

node *temp;
temp=new node;
return temp;

}

void push(node *last,int n){
node *temp;
temp=create();
temp->next=NULL;
last->next=temp;
}


void print(node *start){
node *temp;
temp=start;
while(temp->next!=NULL){
cout<< temp->data<<endl;
temp=temp->next;
}
}

void reverse(node *start,node *last){
node *temp,*temp1,*temp2;
temp=start;
temp2=start;
temp1=last;

while(temp2!=temp1){
temp2=temp2->next;
temp->next=last;
last=temp;
temp=temp2;
}
}

int main()
{
node *start;
	
start->next=NULL;

int n=10;
node *last1;

last1=start;


while(n!=0){



cin>>n;
if(start->next==NULL){push(start,n);}
else{push(last1,n);}
last1=last1->next;



}



node *last;
last=start;
while(last!=NULL){
last=last->next;
}

reverse(start,last);
print(start);
	return 0;
}
