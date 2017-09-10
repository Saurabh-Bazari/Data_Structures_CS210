#include <bits/stdc++.h>
using namespace std;

int binary_search(int ary[],int l,int u,int p,int *c){

	int m;							//binary search
	m=(l+u)/2;						// middle element

	if (l>u)						// if their is no element then return in last goes left side then that place so l not change and return l and also for right side next position is return and also l is increased by 1
		return l;

	(*c)++;
	if (ary[m]==p)					// compare middle element first
		return m;

	else if (ary[m] < p)						// compare first right side
		return binary_search(ary,m+1,u,p,c);
	
	else
		return binary_search(ary,l,m-1,p,c); 		// then compare left side
	
}

void insertion(int ary[],int N,int *c){

	int k,l,j;

	for (int i = 0; i < N ; ++i)
	{
		k=binary_search(ary,0,i-1,ary[i],c);    	//actual position of i  in sorted array
		
		l=ary[i];

		for ( j = i-1; j > k-1 ; --j)				// shift the array
			ary[j+1]=ary[j];

		ary[j+1]=l;
	}

	return;
}

void print(int ary[],int N,int *c){

	cout << "Output:"<<endl<< *c << endl;  //comparison

	for (int i = 0; i < N; ++i)
		printf("%d ",ary[i]);			// print array

	printf("\n");

	return;
}

int main(){

	int N,f=0;    			// input no. of elements
	cin >> N;

	int *c;					// pointer of int for counting comparisons
	c=&f;

	int ary[N];
	for (int i = 0; i < N; ++i)
		cin >> ary[i];			// input of array of element N

	insertion(ary,N,c);			// insertion sort by binary search
	print(ary,N,c);				// print comparison and array

	return 0;
}