/**************************************************************************************************************************************************************************
******************************************************************************************************************************************************************
 SAURABH BAZARI
 160101061
 CS210
******************************************************************************************************************************************************************
1. Create structure of one data and two pointer in which one point to sequence and other is start of that sequence to start of next sequence.
2. Then take a int array of form of power of 2.
3. Input start of all sequence in array and in other int max. 
4. Find out the smallest integer br Winner tree and call reset function and search data of winner and remove it.
5. Push all winner in winner sequence and in last print winner sequence. 
******************************************************************************************************************************************************************
******************************************************************************************************************************************************************/



#include <bits/stdc++.h>
using namespace std;

int h=INT_MAX; //max interger value

// structure with one data and two pointer

struct node
{
	int data;
	node *right;
	node *down;
};

node *create_node(){
	node *temp=new node; //create node 
	temp->right=NULL;
	temp->down=NULL;
	return temp;
}

void wpush(node **start,int w){ // push data of winner 

	node *temp,*temp1=(*start);
	temp=create_node();
	temp->data=w;

	if ((*start)==NULL)
	{
		(*start)=temp;              	 // if start is null then start is new node
		return;
	}
	while(temp1->right!=NULL){   		 // search last node
		temp1=temp1->right;
	}
	temp1->right=temp;           		// last node linked to new node 
	return;
}

void push(node *start,int n){ 			//push input data
	node *temp,*t=start;
	temp=create_node();
	temp->data=n;

	while(t->right!=NULL){				// search last node
		t=t->right;
	}
	t->right=temp;						//last node linked to new node
	return;
}

void reset(node **start,int n){			// search data n remove it

	node *temp,*t;						
	temp=t=(*start);			
	if ((*start)->data==n)							// if start data is n then start is shift
	{	
		
		(*start)->right->down=(*start)->down;
		(*start)=(*start)->right;
		return;
	}
	else{										//	search n from start of all sequence
		while(temp->data!=n){
			t=temp;
			temp=temp->down;
		}
		t->down=temp->right;  					// reset that node
		temp->right->down=temp->down;
	}
	return;
}

int who_is_winner(node **start,int k){			// search who is winner

	int t,w;

//  if k is not in form of 2^n then find just next integer of 2^n form

	for (int i = 0; i < h; ++i)
	{
	 	if (k<=pow(2,i))
	 	{
	 		t=2*pow(2,i);
	 		break;
	 	}
	}
	int ary[t];  					// declare new array for find winner
	node *temp=(*start);
	for (int i = 0; i < k; ++i)
	{
		ary[(t/2)+i]=temp->data;	// set data from start of all sequence 
		temp=temp->down;
	}
	for (int i = k; i < (t/2); ++i)
	{
		ary[(t/2)+i]=h;   			//	extra data is h =int_max 
	}

// loop for find winner ,  i and i+1 winner store in (i-1)/2

	while(t!=1){
		for (int i = (t/2); i < t-1	; i=i+2)
		{
			if (ary[i]>ary[i+1])
			{
				ary[i/2]=ary[i+1];
			}
			else{
				ary[i/2]=ary[i];
			}
		}
		t=t/2;
	}
	w=ary[1];   			// winner is ary[1] store in w
	if (w!=h)			
	{
		reset(start,w);		// if winner is not int max then call reset function to remove node of data w
	}

	return w;				// return data w
}

int main()
{
	int k;
	cin >> k;
	int n,r,w=0;
	char c;

	node *start=NULL;			// start pointer for input sequence
	node *wstart=NULL;			// wstart pointer for winner sequence 
	start=create_node();		// create node for start
	node *temp=start;
	node *temp1,*t;

	for (int i = 0; i < k; ++i)
	{
		r=0;
		while(1){
			scanf("%d%c",&n,&c);
			if (r==0)					// if start has node only data required
			{
				temp->data=n;
				r=1;
			}
			else{
				push(temp,n);			// push n in sequence whose start is temp
			}
			if (c=='\n')
			{
				push(temp,h);			// if char is enter then in last push int max in sequence and break
				break;
			}

		}
		if (i!=(k-1))					//  last sequence down tends to null so no requried of new node
		{
			temp1=create_node();		// create node for next start of new sequence 
			temp->down=temp1;
			temp=temp1;	
		}
	}

	while(1){

		w=who_is_winner(&start,k); 		// winner
		if (w==h)
		{								// if winner is int max then break
			break;
		}
		else{
			wpush(&wstart,w);			// else push in sequence of winner
		}
	}
	printf("Output: ");
	temp=wstart;
	while(temp!=NULL)
	{
		cout << temp->data << " ";    // print sequence of winners
		temp=temp->right;
	}
	printf("\n");

	return 0;
}

/* End of program
*******************************************************************************************************************************************************************/