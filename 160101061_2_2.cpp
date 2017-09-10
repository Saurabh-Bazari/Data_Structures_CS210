#include <bits/stdc++.h>
using namespace std ;

struct node1
{
	char c[50];
	int f;
	node1 *ptr;
	bool isleft;
};
node1 data[100];

struct node{
	node1 *pnt;
	node *next;
};

node *create_list(node1 *pnt){
	node *temp;
	temp=new node;
	temp->pnt=pnt;
	temp->next=NULL;
	return temp;
}

node *last(node *temp1,node *start){
	node *temp;
	temp=start;
	if (temp1==start){
		return temp1;
	}
	
	while(1){
		if (temp->next==temp1)
		{
			return temp;
		}
		temp=temp->next;
	}
	return temp;
}

void makelist(node1 *x,node **start){

	node *temp,*temp1,*temp2;
	int n=0;
	temp=create_list(x);
	temp1=temp2=(*start);
	if (temp1==NULL)
	{	
		temp->next=NULL;
		(*start)=temp;
		return;
	}
	if ((*start)->pnt->f > x->f)
	{
		temp->next=(*start);
		(*start)=temp;
		return;
	}
	if ((*start)->pnt->f == x->f  && (*start)->pnt->c[0] > x->c[0] )
	{
		temp->next=(*start);
		(*start)=temp;
		return;
	}
	while(temp1!=NULL){
		if (x->f == temp1->pnt->f && x->c[0] < temp1->pnt->c[0] )
		{
			break;
		}
		else if (x->f < temp1->pnt->f)
		{
			break;
		}
		temp2=temp1;
		temp1=temp1->next;		
	}

	if (temp1!=NULL)
	{
		temp2->next=temp;
		temp->next=temp1;
		return;
	}
	temp2->next=temp;
	temp->next=NULL;
	return;
}

node *pop(node **xy){
	node *temp;
	temp=(*xy);
	(*xy)=(*xy)->next;
	return temp;
}

void print01(node1 *p,node1 *root){
	if (p==root)
	{
		return;
	}
	print01(p->ptr,root);
	if (p->isleft==1)
	{
		printf("0");
	}
	else{
		printf("1");
	}
}

int main()
{
	string s;
	char ss[555];

	printf("Input\n");

	cin >> s;
	int n=0,n1,ns;
	char k;
	for (int i = 0; s[i]!='\0'; ++i)
	{
		n++;
	}

	ss[0]=s[0];
	ns=1;
	int cnt;
	for (int i = 1; i < n; ++i)
	{
		cnt=0;
		while( s[i] != ss[cnt] ){
			cnt++;
			if (cnt==ns)
			{
				ss[ns]=s[i];
				ns++;
				break;
			}
		}
	}

	for (int i = 0; i < n-1; ++i)
	{
		for (int j = 0; j < n-1; ++j)
		{
			if (s[j]>s[j+1])
			{
				k=s[j];
				s[j]=s[j+1];
				s[j+1]=k;
			}
		}
	}

	int j=0;

	for (int i = 0; i < n; ++i)
	{
		if (i!=0)
		{
			if (s[i-1]!=s[i])
			{
				j++;
				data[j].c[0]=s[i];
				data[j].f =1;
			}
			else{
				(data[j].f)++;
			}
		}
		else{
			data[j].c[0]=s[i];
			data[j].f =1;
		}
	}

	n1=j+1;

	node *start=NULL;

	for (int i = 0; i < n1; ++i)
	{
		makelist(&data[i],&start);
	}
	
	node *m1,*m2;

	while(start->next!=NULL){
		m1=pop(&start);
		m2=pop(&start);
		m1->pnt->isleft=true;
		m2->pnt->isleft=false;

		struct node1 *t;
		t=new node1;
		m1->pnt->ptr=t;
		m2->pnt->ptr=t;
		t->f=m1->pnt->f+m2->pnt->f;
		strcpy(t->c,m1->pnt->c);
		makelist(t,&start);
	}
	node1 *root;
	root=pop(&start)->pnt;
	
	struct node1 *p;


	printf("Output\n");

	for (int i = 0; i < ns; ++i)
	{
		j=0;
		while(1){
			if (data[j].c[0]==ss[i])
			{
				break;
			}
			j++;
		}
		p=&data[j];
		printf("%s=",data[j].c );

		print01(p,root);

		printf("  ");
	}
	printf("\n");
	
	return 0;
}



