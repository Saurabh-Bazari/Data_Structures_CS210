#include <bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	node *left;
	node *right;
	bool thread_right;
};

node *most(node *h){

	if (h == NULL){
	 	return NULL;
	}
	
	while (h->left != NULL){
		h = h->left;
	}

	return h;
}

node *create(int n){
	node *temp;
	temp=new node;
	temp->data=n;
	temp->left=NULL;
	temp->right=NULL;
}

node *search(node *start,int b){
	node *temp;
	temp=most(start);
		while(temp!=NULL){
			if (temp->data==b)
			{
				return temp;
			}
			if (temp->thread_right)
			{
				temp=temp->right;
			}
			else{
				temp=most(temp->right);
			}
		}
}

void setleft(node *temp1,node *temp){

	
	temp->left=NULL;
	temp1->left=temp;
	temp->right=temp1;
	temp->thread_right=true;
}

void setright(node *temp1,node *temp){
	node *t;
	temp->left=NULL;
	temp->right=temp1->right;
	temp1->right=temp;
	temp1->thread_right=false;
	temp->thread_right=true;
}

node *build(node *start,int a,char c,int b){

	node *temp,*temp1;
	temp=create(a);
	if (start==NULL)
	{
		start=temp;
		start->thread_right=true;
		return start;
	}
	else
	{
		temp1=search(start,b);
		//printf("%d\n",temp1->data );
		if (c=='L')
		{
			if (temp1->left!=NULL)
			{
				/* code */
				printf(" %d is ignore\n",temp->data);
				return start;
			}
			else {setleft(temp1,temp);}
		}
		else{
			//printf("%d\n",temp1->data );
			
			setright(temp1,temp);
			
		}
	}
	return start;
}





void in( node *h){
	 node *temp = most(h);
	while (temp != NULL){
		printf("%d ",temp->data);
	if (temp->thread_right){
		temp = temp->right;
	}
	else{
		temp = most(temp->right);
	}

	}
}


int main()
{
	int a,b;
	char c;
	node *root=NULL;
	for (int i = 0; 1; ++i)
	{
		cin >> a;
		if (a==-1)
			break;
		scanf(" %c %d",&c,&b);

		root=build(root,a,c,b);

	}

	printf("Inorder: ");

	in(root);



	
	return 0;
}