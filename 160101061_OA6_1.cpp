#include <bits/stdc++.h>
using namespace std;

int search(int **B,int a,int b){ 

	int p1=1,p2=1;

	if (B[a][b]==-1)			// if a after b is exist then return false
		return 0;	
	
	for (int i = 0; i < 26; ++i)
	{
		if (B[a][i]==-1)			// if any element before a then check b before that element
			p1=search(B,i,b);

		if (p1==0)					// if any fault then return 0
			return 0;
	}

	for (int i = 0; i < 26; ++i)
	{
		if (B[b][i]==1)				// if any element after b then check a after that element
			p2=search(B,a,i);

		if (p2==0)					// if any fault then return 0
			return 0;
	}
	
	return 1;						// if it is possible then return 1
}

void change(int **B,int a,int b){

	B[a][b]=1;						// a,b =1
	B[b][a]=-1;						// b,a=-1

	for (int i = 0; i < 26; ++i)
	{							
		if (B[a][i]==-1)			// if any element i before a then change i,b=1 and b,i=-1 
			change(B,i,b);
	}

	for (int i = 0; i < 26; ++i)
	{
		if (B[b][i]==1)				// if any element i after b then change a,i=1 and i,a=-1 
			change(B,a,i);
	}

	return;
}

int main()
{
	int n,j,i;
	cin >> n;		// input n

	char **A;
	int **B;		// 2d matrix of 26*26
	

	A=new char *[n];
	B=new int *[26];

	for ( i = 0; i < n; ++i){
		A[i]=new char[100];
		cin >> A[i];				// input string
	}

	for ( i = 0; i < 26; ++i)
	{
		B[i]=new int[26];

		for ( j = 0; j < 26; ++j)
			B[i][j]=0;				// initial all values 0

	}

	int n1;
	int a,b;

	for ( i = 0; i < n; ++i)
	{
		j=0;
		n1=strlen(A[i]);
		while(j < n1-1 ){

			a=A[i][j]-'a';			// a is first element
			b=A[i][j+1]-'a';		// b is second element
			j++;

			if (a==b)				// if both same then continue
				continue;
			
			if (search(B,a,b)==1){		//if b after a is possible then change values corresponding to a and b
				change(B,a,b);	
			}

			else{						// if not possinle b after a then  print impossible and stop 
				printf("Impossible\n");
				return 0;
			}

		}

	}
	printf("Possible\n");


	return 0;
}