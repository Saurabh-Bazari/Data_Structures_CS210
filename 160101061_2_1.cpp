#include<bits/stdc++.h>
using namespace std;

struct node
{
	char data[20];
	node *left;
	node *right;
};

node *froot=NULL;

void fcreate(char s[],node **a){
	
	node *temp=new node;
	
	for (int i = 0; s[i]!='\0'; ++i)
	{
		temp->data[i]=s[i];
	}

	cout << " Made " << temp->data << " in " << (*a)->data << endl ;

	(*a)->left=temp;
	(*a)=temp;

	temp->left=NULL;
	temp->right=NULL;

	return;
}

void fnew(char s[],node **a){

	node *temp=new node;
	temp->left=NULL;
	temp->right=NULL;
	
	for (int i = 0; s[i]!='\0'; ++i)
	{
		temp->data[i]=s[i];
	}

	node *t;
	t=(*a);
	//cout << "bakchodi" <<(*a)->data << endl;
	for (int i = 0; t->right!=NULL; ++i)
		{
			t=t->right;
		}
	t->right=temp;
	cout << " Created " << temp->data << " in " << (*a)->data << endl ;

	
	return;
}

void fdelete(node **a){

	if ((*a)->right==NULL)
	{
		cout << " Cannot delete from root" << endl; 
		return;
	}

	cout << " Deleted " << (*a)->right->data << " from " << (*a)->data << endl ;
	
	(*a)->right=(*a)->right->right;
	
	return;
}

void fback(node **a){

	if ((*a)==froot)
	{
		cout << " Cannot back from root" << endl; 
		return;
	}

	node *t;
	t=froot;
	
	for (int i = 0; t->left->left!=NULL; ++i)
	{
		t=t->left;		
	}

	cout << " Back from " << t->left->data << endl ;

	t->left=NULL;
	(*a)=t;
	return;
}


int main()
{
	string sq = "root";

	froot=new node;
	froot->left=froot->right=NULL;
	for (int i = 0; sq[i]!='\0' ; ++i)
	{
		froot->data[i]=sq[i];
	}

	node *a;
	a=froot;

	char s1[20],s2[20];
	
	printf("Input\n");

	for (int i = 0; 1 ; ++i)
	{
		cin >> s1;
		if (i==0)
		{
			printf("\nOutput\n");
		}
		if (strcmp(s1,"-1")==0)
		{
			break;
		}
		if (strcmp(s1,"NEW")==0 || strcmp(s1,"CREATE")==0 )
		{
			cin >>s2;
		}
		if (strcmp(s1,"NEW")==0)
		{
			fcreate(s2,&a);
		}
		else if (strcmp(s1,"BACK")==0)
		{
			fback(&a);
		}
		else if (strcmp(s1,"CREATE")==0)
		{
			fnew(s2,&a);
		}
		else{
			fdelete(&a);
		}
		s1[0]='\0';
		s2[0]='\0';
	}
	
	return 0;
}
