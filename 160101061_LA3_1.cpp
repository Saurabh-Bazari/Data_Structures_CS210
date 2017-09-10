#include <bits/stdc++.h>
using namespace std;

void bubble1(int ary1[],int N){

	int ct=0;
	int ary[N];
	for (int i = 0; i < N; ++i)
	{
		ary[i]=ary1[i];
	}

	for (int i = 0; i < N-1; ++i)
	{
		ct++;
		for (int j = 0; j < N-1-i; ++j)
		{
			if (ary[j] > ary[j+1])
			{
				swap(ary[j],ary[j+1]);
			}
		}
	}
	cout << ct<<endl;
	for (int i = 0; i < N; ++i)
	{
		cout << ary[i] << " ";
	}
	printf("\n");

	return;
}

void bubble2(int ary1[],int N){

	int r=0,ct=0;
	int ary[N];

	for (int i = 0; i < N; ++i)
	{
		ary[i]=ary1[i];
	}

	for (int i = 0; i < N-1; ++i)
	{
		ct++;
		r=0;
		for (int j = 0; j < N-1-i; ++j)
		{
			if (ary[j] > ary[j+1])
			{
				r=1;
				swap(ary[j],ary[j+1]);
			}
		}
		if (r==0)
		{
			break;
		}
		
	}

	ct=N-1-ct;

	cout << ct <<endl;
	for (int i = 0; i < N; ++i)
	{
		cout << ary[i] << " ";
	}
	printf("\n");

	return;
}

void bubble3(int ary1[],int N){

	int r=0,ct=0;
	int ary[N];

	for (int i = 0; i < N; ++i)
	{
		ary[i]=ary1[i];
	}

	for (int i = 0; i < N-1; ++i)
	{
		ct++;
		r=0;
		for (int j = 0; j < N-1-i; ++j)
		{
			if (ary[j] > ary[j+1])
			{
				r=1;
				swap(ary[j],ary[j+1]);
			}
			if (ary[N-i-1-j] < ary[N-i-2-j])
			{
				r=1;
				swap(ary[N-i-1-j] , ary[N-i-2-j]);
			}
		}

		if (r==0)
		{
			break;
		}
	}

	ct=N-1-ct;

	cout << ct <<endl;
	for (int i = 0; i < N; ++i)
	{
		cout << ary[i] << " ";
	}
	printf("\n");

	return;
}


int main()
{
	int N;
	cin >>N;
	int ary[N];

	for (int i = 0; i < N; ++i)
	{
		cin >> ary[i];
	}

	printf("\nOutput:\n");

	 bubble1(ary,N);

	 bubble2(ary,N);

	bubble3(ary,N);
	

	




	return 0;
}