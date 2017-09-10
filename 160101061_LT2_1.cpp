#include <bits/stdc++.h>
using namespace std;


void heap(int a[],int n,int i){

	int large=i;
	int l=2*i+1;
	int r=2*i+2;

	if (l < n && a[l] > a[large] )
	{
		large =l;
	}
	if (r < n && a[r] > a[large])
	{
		large = r;
	}
	if (large !=i ){
		swap (a[large],a[i]);
		heap(a,n,large);
	}

	return;
}


void heap_sort(int a1[],int n,int k){

	int a[n];

	for (int i = 0; i < n; ++i)
	{
		a[i]=a1[i];
	}

	for (int i = (n/2) -1 ; i >= 0 ; --i)
	{
		heap(a,n,i);
	}

	for (int i = 0; i < n-1; ++i)
	{
		swap(a[0],a[n-i-1]);
		heap(a,n-i-1,0);
	}

	for (int i = 0; i < k; ++i)
	{
		cout << a[i] << " ";
	}

	cout << endl;


	return;
}


void max_heap_sort(int a[],int n){

	int p,s;

	for (int i = 1; i < n; ++i)
	{
		s=i;
		p=(i-1)/2;

		while(s>0 && a[p] < a[s]){

			swap(a[p],a[s]);
			s=p;
			p=(s-1)/2;
		}

	}

	return;
}

void heap_sort_0(int a1[],int n,int k){

	int a[n];

	for (int i = 0; i < n; ++i)
	{
		a[i]=a1[i];
	}

	max_heap_sort(a,n);

	for (int i = n-1; i > 0; --i)
	{
		swap(a[0],a[i]);
		//max_heap_sort(a,i);
		heap(a,i,0);
	}
	

	for (int i = 0; i < k; ++i)
	{
		cout << a[i] << " ";
	}

	cout << endl;



	

	return;
}

int main()
{
	int n;
	cout << "Enter the no. of digit:"<< endl;
	cin >> n;

	int a[n];

	cout << "Enter the " << n  <<" numbers :"<< endl;
	
	for (int i = 0; i < n; ++i)
	{
		 cin >> a[i];
	}

	cout << "Enter the value  of k :"<< endl;

	int k;
	cin >> k;

	cout << endl <<  "First:"<< endl;
	heap_sort_0(a,n,k);

	cout << "Second:"<< endl;
	heap_sort(a,n,k);

	return 0;
}