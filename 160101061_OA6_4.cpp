#include <bits/stdc++.h>
using namespace std;

struct node
{
	int key;
	int degree;
	node *leftmost;
	node *next;
};

node *create(int k,int d){				// create node

	node *temp=new node;
	temp->key=k;
	temp->degree=d;
	temp->leftmost=temp->next=NULL;

	return temp;
}

node *child(node *x){						// return leftmost
	if (x==NULL || x->leftmost == NULL)
		return NULL;

	return x->leftmost;	
}

node *sibling(node *x){					// return next
	if (x==NULL || x->next == NULL)
		return NULL;

	return x->next;
}

node *merging(node *h1,node *h2){		// merge	

	node *h=NULL,*last=NULL,*temp;

	if (h1==NULL)					// if any one is null return aonther
		return h2;

	if (h2==NULL)
		return h1;

	while(h1!=NULL && h2!=NULL){

		if (h1->degree > h2->degree){		// degree of h2 is small then temp points to h2 and h2 shift to its next

			temp=h2;
			h2=h2->next;
		}

		else{							// degree of h2 is small then temp points to h2 and h2 shift to its next
			temp=h1;
			h1=h1->next;
		}

		if (h==NULL){				// if new heap is null
			h=temp;
			last=temp;
		}

		else{						// else add at last
			last->next=temp;
			last=last->next;
		}
	}

	if (h1!=NULL){					// if any heap is remaining then attach as it is
		last->next=h1;
		h1=NULL;
	}

	if (h2!=NULL){
		last->next=h2;
		h2=NULL;
	}
	
	return h;						// reutrn new heap 
}

node *perv(node **head,node *x){ 			// find prev node of given node

	if (x==(*head))	
		return NULL;

	node *temp=*head;

	while(temp->next!=x)
		temp=temp->next;
	
	return temp;
}

node *last_one(node *x){			// find last node of given node 

	if (x==NULL)
		return NULL;

	while(x->next!=NULL)
		x=x->next;

	return x;
}

node *call(node **head,node *x){	//this function for shifting node for samr degree		

	node *x1;
	x1=x->next;

	if (x->key > x1->key)		// if key of x1 is less
	{
		(x1->degree)++;			// degree is increase by 1

		if (perv(head,x)==NULL)		//next of perv of x  points x1 
			(*head)=x1;
		
		else
			perv(head,x)->next=x1;

			x->next=x1->leftmost;		
			x1->leftmost=x;

			return x1;			// return x1
	}
	else{

		(x->degree)++;			// degree is increase by 1

		x->next=x1->next;		//perv of x1 is x and  next of x points x1 
		x1->next=x->leftmost;	
		x->leftmost=x1;			
		return x;				
	}	
}

void Union (node **head ) {

	node *x=(*head),*x1=NULL;

	if (x==NULL || x->next==NULL)		// if no node or inly one node then return
		return;


	while(sibling(x)!=NULL){			// if atleast two node

		x1=sibling(x);

		if (x->degree != x1->degree)		// if degree is not equal then x shift by one
			x=x1;

		else{

			if (sibling(x1)==NULL)			// if degree are same and no node after that or degree of next of next of x is not equal to x then call call
				x=call(head,x);

			else if (sibling(sibling(x))->degree!=x->degree) 		
				x=call(head,x);

			else						// else shift by one
				x=x1;
		}
	}
	return;
}

node *reverse(node *mt){			// for extract min reverse the order of leftmost of min node

	node *h,*l;
	node *h1=mt->leftmost,*h2,*h3; 

	if (h1==NULL)    				// if no node exist
		return NULL;
		
	if (h1->next==NULL)				// if only one node
		return h1;

	h2=h1->next;

	if (h2->next==NULL)			// if only  two node
	{
		h=h2;
		h2->next=h1;
		h1->next=NULL;
	}
	else{					// more than two node
		h3=h2->next;
		l=h1;				

		while(h3!=NULL){
			h2->next=h1;		// link in reverse order
			h1=h2;
			h2=h3;
			h3=h3->next;
		}
		h2->next=h1;
		h=h2;
		l->next=NULL; 			// last node next to null
	}
	return h;
}

int Extract_min(node **head){

	if ((*head)==NULL)			// if null return -1
		return -1;

	int min=(*head)->key;
	node *t=(*head),*mt=(*head);

	while(t!=NULL){

		if (t->key <= min)		// find min key and its node
		{
			min=t->key;
			mt=t;
		}
		t=t->next;
	}

	if (mt==(*head))				// if min node is head
	{
		(*head)=mt->next;
	}
	else{								// else 
		perv(head,mt)->next=mt->next;
	}

	node *h1;
	h1=reverse(mt);					// reverse of leftmost of min node 
	mt->leftmost=NULL;				// min node leftmost is null
	(*head)=merging(*head,h1);		// merging reversed seq and head
	Union(head);					// union 

	return min;
}

void INSERT(node **head,int d){

	node *temp;
	temp=create(d,0);				// insert new node
	(*head)=merging(*head,temp);	// merge new node with head
	Union(head);

	return;
}

void showHeap( node *head,int depth ){ 			// given in ques

	if ( head->next != NULL )
		showHeap( head ->next, depth );


	if ( head->leftmost != NULL ) {

		for (int i = 0; i <depth+1 ; ++i)
			printf("\t");

		cout << head->key;
	}

	else{

		printf("\t%d\n",head->key);

	}

	if ( child(head) != NULL ){
		showHeap( child(head), depth + 1 );
	}

	return;
}

void showBinomialHeap(node *head){

	
	if ( head == NULL )
		printf("Empty heap\n");

	else {
		printf("Stucture of binomial heap (rotated 90 degrees ccwise):\n");
		showHeap( head, 0 );
	}
	return;
}

void makeheap(node **head){
								// make heap 
	(*head)=NULL;				// initilaze head equal to null

	return;
}

int main()
{
	node *head=NULL;
	node *temp;

	char c;
	int d,e=0,flag=0;

	while(1){			// if heap is empty and futher extract min use then stop it

		cin >> c;

		if (c=='#')					// if input is # ingore till enter
			cin.ignore(10e9,'\n');

		else if (c=='c')			// make heap
			makeheap(&head);
		
		else if (c=='u')		// call union
			Union(&head);
		
		else if (c=='i')		// call insert
		{
			cin >> d;
			INSERT(&head,d);
		}

		else if (c=='d'){			// extract min
			e=Extract_min(&head);

			if (e==-1){
				cout << "Empty Heap" << endl;
				return 0;
			}

			if (flag==0)
				cout << "Minimum extracted: " << e << endl;
		}

		else if (c=='+')		//flag on
			flag=0;
		
		else if (c=='-')  		// flag off
			flag=1;	

		else if (c=='S')		// print heap
			showBinomialHeap(head);
	}

	return 0;
}