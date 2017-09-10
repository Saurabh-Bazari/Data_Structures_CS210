// In merge sort when merge array if first element of left array is greater than first element of right array then no. of inversion is no. of element in left side array


#include <bits/stdc++.h>
using namespace std;

int h=INT_MAX;									// int max

void merge(int a[],int l,int p,int n,int *e){

	int n1,n2;

	n1=p-l+1;			// no. of element in left array
	n2=n-p; 			//n. of element in right array

	int L[n1+1];
	L[n1]=h; 			// last element is int max

	int r[n2+1];
	r[n2]=h;

	for (int i = 0; i < n1; ++i)
	{
		L[i]=a[l+i];			//copy data in new left array
	}

	for (int i = 0; i < n2; ++i)
	{
		r[i]=a[p+1+i];			// copy data in new right array
	}	

	int j=0,k=0;

	for (int i = l; i <= n ; ++i)
	{
		if( L[j] > r[k] ){			// smaller element is replace in original array
			(*e)=(*e)+p-l-j+1;		// count no. of inversion
			a[i]=r[k++];
		}

		else{
			a[i]=L[j++];
		}
	}

	return ;
}

void merge_sort(int a[] ,int l,int n,int *e){

	int p;

	if (l<n)
	{
		p=(l+n)/2;					// middle element	
		merge_sort(a,l,p,e);		// sort array first to middle
		merge_sort(a,p+1,n,e);		// then sort array middle +1 to last
		merge(a,l,p,n,e);
	}

	return ;
}


int main()
{
	int N,c=0;
	cin >> N;			// input N

	int a[N];
	for (int i = 0; i < N; ++i)
	{
		cin >> a[i];			// input array element
	}

	int *e=&c;					// assign pointer for counter

	merge_sort(a,0,N-1,e);		// sort array by merge sort

	cout <<"Output:" <<endl << (*e) <<endl;  // print count of inversion

	return 0;
}