#include <bits/stdc++.h>
using namespace std;

int h=INT_MAX;

struct node
{
	char array[10];
	int n;
};

void heap(int a[],int n,int i){     			//heapify

	int large=i;
	int l=2*i+1;
	int r=2*i+2;

	if (l < n && a[l] < a[large] )
	{
		large =l;
	}
	if (r < n && a[r] < a[large])
	{
		large = r;
	}
	if (large !=i ){
		swap (a[large],a[i]);
		heap(a,n,large);
	}
	return;
}

void RemovE(int s[],int &sn,node *A1,int &N1){			//if removemin

	if (sn==0)											// if no element exist then insert 0 and removemin
	{
		strcpy(A1[N1].array,"insert");
		A1[N1++].n=0;
	}

	else{												// else extract min and remove min
		s[0]=s[--sn];
		heap(s,sn,0);
	}
	
	strcpy(A1[N1++].array,"removeMin");

	return;
}

void insert(int s[],int &sn, node A[],node A1[],int k,int &N1){

	s[sn]=k;															// insert in heap
	sn++;

	int s1=sn-1;
	int p=(s1-1)/2;														// then make_heap

	while(s1>0 && s[p]>s[s1]){
		swap(s[p],s[s1]);
		s1=p;
		p=(p-1)/2;
	}

	strcpy(A1[N1].array,"insert");									// copy string
	A1[N1++].n=k;

	return;
}

void GetmIN(int s[],int &sn,node A[],node A1[],int &N1,int min){

	if (sn==0)														//if no element exist then insert then getmin
	{
		strcpy(A1[N1].array,"insert");
		A1[N1++].n=min;

		strcpy(A1[N1].array,"getMin");
		A1[N1++].n=min;
		return;
	}

	if (s[0]==min)											//if min equal to requried min then copy get min
	{
		strcpy(A1[N1].array,"getMin");
		A1[N1++].n=min;

		s[0]=s[--sn];
		heap(s,sn,0);

		return;
	}

	if (s[0] < min)											// if requried min is greater then min then first removemin till no element and requried min is smaller then aur equal to min
	{
		while(sn!=0 && s[0] < min)
		{
			strcpy(A1[N1++].array,"removeMin");
			
			s[0]=s[--sn];
			heap(s,sn,0);
		}
	}

	if (sn==0)									//if no element exist then insert that min then getmin
	{
		strcpy(A1[N1].array,"insert");
		A1[N1++].n=min;

		strcpy(A1[N1].array,"getMin");
		A1[N1++].n=min;
		return;
	}

	if (s[0] == min)							//if min equal to requried min then copy get min
	{
		strcpy(A1[N1].array,"getMin");
		A1[N1++].n=min;
		return;
	}

	if (s[0] > min)								// if min is smaller than requried min then insert that min and getmin
	{
		strcpy(A1[N1].array,"insert");
		A1[N1++].n=min;

		strcpy(A1[N1].array,"getMin");
		A1[N1++].n=min;
		return;
	}

	return ;
}

int main(){

	int N,N1=0;
	cin >> N;

	node A[N],A1[10000];
	int s[10000],sn=0;

	for (int i = 0; i < N; ++i)
	{
		cin >> A[i].array;								// input array

		if (strcmp(A[i].array,"removeMin")==0){				// if removemin then call remonemin
			RemovE(s,sn,A1,N1);
		}
		else if (strcmp(A[i].array,"insert")==0)			// if insert then input int and call insert  
		{
			cin >> A[i].n;
			insert(s,sn,A,A1,A[i].n,N1);
		}
		else if (strcmp(A[i].array,"getMin")==0)			// if getmin then input int and call getmin
		{
			cin >> A[i].n;
			GetmIN(s,sn,A,A1,N1,A[i].n);
		}
	}

	cout << N1 << endl;									// print new matrix

	for (int i = 0; i < N1; ++i)
	{
		cout << A1[i].array;

		if (strcmp(A1[i].array,"removeMin")!=0)
			cout << " " << A1[i].n;

		printf("\n");
	}

	return 0;
}