#include <bits/stdc++.h>
using namespace std;

int h=INT_MAX;

void create(int ary[],int N){

	srand(time(NULL));

	for (int i = 0; i < N; ++i)
		ary[i]=rand();
	
	return;
}

int search(int ary[],int l,int u,int i,int &comp){

	if (l>u)
		return l;

	int mid;
	mid=(l+u)/2;

	comp++;
	
	if (ary[mid]==ary[i])
		return mid;

	else if (ary[mid] > ary[i])
		return search(ary,l,mid-1,i,comp);

	else 
		return search(ary,mid+1,u,i,comp);
}

void binary_insertion(int ary[],int l,int u,int &comp){

	int k1,j,k;

	for (int i = l; i <=u ; ++i)
	{
		k1=ary[i];
		k=search(ary,l,i-1,i,comp);
		for ( j = i-1 ; j >= k ; --j)
		{
			ary[j+1]=ary[j];
		}
		ary[j+1]=k1;
	}
}

void merge(int ary[],int l,int p,int u,int &comp){

	int n1,n2,l1=0,r1=0,i;
	n1=p-l+1;
	n2=u-p;

	int L1[n1+1];
	int R1[n2+1];

	L1[n1]=R1[n2]=h;

	for ( i = 0; i < n1; ++i)
		L1[i]=ary[l+i];
	

	for ( i = 0; i < n2; ++i)
		R1[i]=ary[p+1+i];

	for ( i = 0; l1 <= n1 && r1 <=n2 ; ++i)
	{
		comp++;

		if ( L1[l1] > R1[r1] )
			ary[l+i]=R1[r1++];

		else
			ary[l+i]=L1[l1++];
	}

	while(l1<=n1)
		ary[l+(i++)]=L1[l1++];

	while(r1<=n2)
		ary[l+(i++)]=R1[r1++];

	return;
}



void merge_sort(int ary[],int l,int u,int &comp){

	int p;
	if (u-l >= 55)
	{
		p=(l+u)/2;
		merge_sort(ary,l,p,comp);
		merge_sort(ary,p+1,u,comp);
		merge(ary,l,p,u,comp);
	}
	else{
		binary_insertion(ary,l,u,comp);
	}
}



int main(){

	int N,comp=0;
	cin >> N;
	int ary[N];

	create(ary,N);

	for (int i = 0; i < N; ++i)
		printf("%d ",ary[i] );

		printf("\n");



	if (N>55)
		merge_sort(ary,0,N-1,comp);
	else
		binary_insertion(ary,0,N-1,comp);


	for (int i = 0; i < N; ++i)
		printf("%d ",ary[i] );

	printf("\n");
	
	printf("Number of comparisons : %d\n",comp );



}