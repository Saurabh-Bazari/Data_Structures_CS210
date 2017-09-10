#include <bits/stdc++.h>
using namespace std;

void sort(int ary[],int N){    			// Insertion Sort function 
	int r=0,j;

	for (int i = 0; i < N; ++i)						// i = 0 to N
	{
		r=ary[i];						     		// Store first element
		for (j = i-1; j >=0 && ary[j]>r; j--)		// Sort till the i
		{
			ary[j+1]=ary[j]; 
		}
		ary[j+1]=r;							  
	}

	return;
}

void reduce(int ary[],int N){			// reduce the elements  

	for (int i = 0; i < N-1; ++i)		//loop for n-1 times
	{
		ary[i]=ary[i+1]-ary[i];			// reduce element by subtract from next element
	}

	return ;
}

int main()
{
	int N;    						// Lenght of array
	cin >> N; 						// Input lenght of array 

	if (N<1)
	{
		printf("ErrOr  InpuT_valid_Data \n");
		return 0;
	}

	int ary[N];						// Array  
	for (int i = 0; i < N; ++i)
	{
		cin >> ary[i];				//Input Data
	}

	while(N!=1){					// Loop till remain N became 1
		sort(ary,N);				// first the sort
		reduce(ary,N);				// then reduce
		N--;						// decreace N by 1
		
	}

	cout << "Output: "<<endl<<ary[0] << endl; // print output


	return 0;
}

