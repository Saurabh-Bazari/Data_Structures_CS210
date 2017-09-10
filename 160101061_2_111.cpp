#include <bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	node *left;
	node *right;
};

node *create(int d){
	node *temp;
	temp=new node;
	temp->data=d;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}

node *search(node *root,int d){
	node *temp;	
	if (root==NULL)
	{
		temp=root;
	}
	else if (root->data==d)
	{
		temp=root;
	}
	else{
		temp=search(root->left,d);
		if (temp==NULL)
		{
			temp=search(root->right,d);
		}
	}
	return temp;
}

void input(node (**root),int a,char b,int c){
	node *temp;


	if ((*root)==NULL)
	{
		(*root)=create(a);		
	}
	else{
		temp=search((*root),c);
		if (b=='L')
		{
			if (temp->left!=NULL)
			{
				printf("%d is ignored\n",a );
			}
			else{
				(temp->left)=create(a);
			}
		}
		else{
			if (temp->right!=NULL)
			{
				printf("%d is ignored\n",a );
			}
			else{
				(temp->right)=create(a);
			}
		}
	}
	return;
}

void preorder(node *root){

	if (root!=NULL)
	{
		printf("%d ",root->data );
	}
	if (root==NULL)
	{
		return;
	}

	preorder(root->left);
	preorder(root->right);
}

void inorder(node *root){

	if (root==NULL)
	{
		return;
	}

	if (root!=NULL)
	{
		inorder(root->left);
		printf("%d ",root->data );
		inorder(root->right);
	}
	else{
		return;
	}

}

void postorder(node *root){
	if (root==NULL)
	{
		return;
	}
	if (root!=NULL)
	{
		postorder(root->left);
		printf("%d ",root->data );

		postorder(root->right);
		printf("%d ",root->data );
	}
}

int leaf_node(node *root){
	if (root==NULL)
	{
		return 0;
	}
	if (root->left==NULL && root->right==NULL)
	{
		return 1;
	}
	return leaf_node(root->left)+leaf_node(root->right);
}

void print(node *root){

	if (root!=NULL)
	{
		printf("%d\n",root->data );
	}
	if (root==NULL)
	{
		return;
	}
	print(root->left);
	print(root->right);
}

int main()
{
	node *start;
	start=NULL;

	int a;
	int c;
	char b;

	for (int i = 0; i<1000; ++i)
	{
		//printf("vv\n");
		scanf("%d",&a);
		//printf("nn\n");
		//printf("%d\n",i);
		if (a==-1)
		{
			break;
		}
		scanf(" %c",&b);
		scanf("%d",&c);
		input(&start,a,b,c);
		//print(start);
	}

	printf("Inorder: ");
	inorder(start);
	printf("\n Preorder: ");
	preorder(start);
	printf("\nPostorder: ");
	postorder(start);
	printf("\nLeaf Nodes: %d\n",leaf_node(start));

	return 0;
}