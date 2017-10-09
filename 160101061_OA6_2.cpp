 #include <bits/stdc++.h>
using namespace std;

void heap(long long int **a,long long int n,int i){			//heapify for sorting max_heap

	int large=i;
	int l=2*i+1;
	int r=2*i+2;

	if (l < n && a[l][0] > a[large][0] )
		large =l;

	if (r < n && a[r][0] > a[large][0])
		large = r;
	
	if (large !=i ){
		swap (a[large],a[i]);
		heap(a,n,large);
	}
	return;
}

void heap1(long long int **a,long long int n,int i){			// heapify for priority queue min_heap

	int large=i;
	int l=2*i+1;
	int r=2*i+2;

	if (l < n && a[l][0] < a[large][0] )
		large =l;

	if (r < n && a[r][0] < a[large][0])
		large = r;
	
	if (large !=i ){
		swap (a[large],a[i]);
		heap1(a,n,large);
	}
	return;
}

void heap_sort(long long int **a,long long int n){			//heap sort

	for (int i = (n/2) -1 ; i >= 0 ; --i)				// make heap
		heap(a,n,i);
	
	for (int i = 0; i < n-1; ++i)				// max_heap
	{
		swap(a[0],a[n-i-1]);
		heap(a,n-i-1,0);
	}

	return;
}

void insert(long long int **B,long long int &N1,int k,int index){			// insert in priority queue

	B[N1][0]=k;					// priority queue acc to 1st coloum
	B[N1][1]=index;				// in second coloum it store index
	N1++;

	int s1=N1-1;
	int p=(s1-1)/2;														

	while(s1>0 && B[p][0]>B[s1][0]){		// store at last and it small then its parent them swap with its parent
		swap(B[p],B[s1]);
		s1=p;
		p=(p-1)/2;
	}
	return;
}

int main(){

	long long int N,i=0;
	cin >> N;

	long long int N1=0;

	long long int **A=new long long int *[N];		// input data
	long long int **B=new long long int *[N];		// priority queue

	for (long long int i = 0; i < N; ++i){

		A[i]=new long long int [2];
		B[i]=new long long int [2];
		
		cin >> A[i][0] >> A[i][1];					//input
		B[i][0]=0;
		B[i][1]=0;
	}

	long long int total=0,index=0,curr=0;

	heap_sort(A,N);									// sorting of time

	i=0;
	while(i<N)
	{
		while( i<N && A[i][0] <= curr){				// if backery have order than insert in it
			insert(B,N1,A[i][1],i);					// priority queue store both manufacture time and index
			i++;
		}

		if (N1!=0)
		{
			index=B[0][1];							//index of that cake
			swap(B[0],B[--N1]);						// extract it and then min_heapify
			heap1(B,N1,0);
 			curr=curr+A[index][1];					// change curr time
 			total=total+curr-A[index][0];			// add waiting time
		}

 	 	else{
 	 		curr=A[i][0];							// if no order then shift curr time to next order 
 		}
 	}

	while(N1!=0)						// after insert all cake extract cakes...and adding waiting time
	{
	 	index=B[0][1];
		swap(B[0],B[--N1]);
		heap1(B,N1,0);
 		curr=curr+A[index][1];
 		total=total+curr-A[index][0];
	}

	total=total/N;						// avg waiting time
	cout << total<<endl;				// print waiting time

	return 0;
}