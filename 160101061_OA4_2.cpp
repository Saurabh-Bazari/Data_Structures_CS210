#include <bits/stdc++.h>
using namespace std;

struct nodea    // node for Road Information in Sparse matrix as Array
{
	int city1; 			// save city1 name as integer
	int city2; 			// save city3 name as integer
	int km;
};

struct nodel 	// node for Fare Information in Sparse matrix as linked list
{
	int city1; 			// save city1 name as integer
	int city2; 			// save city3 name as integer
	int fare;
	nodel *down;
	nodel *right;
};

nodea createa(int a,int b,int c){ // Create node for Sparse array matrix

	nodea temp;
	temp.city1=a;
	temp.city2=b;
	temp.km=c;

	return temp;
}

nodel *createll(int a,int b,int c){ 		// Create node for Sparse linked list matrix

	nodel *temp;
	temp = new nodel;

	temp->city1=a;
	temp->city2=b;
	temp->fare=c;
	temp->right=NULL;
	temp->down=NULL;

	return temp;
}

int data_store(char city[][25],int N){   	// Store All city names in 2D char array

	static int N1=0;						// store static integer for still no. of cities

	char s[25];								
	cin >> s;								// store city name

	for (int i = 0; i < N1; ++i)
	{
		if (strcmp(city[i],s)==0)			// compare city name with previous input
		{
			return i;						// if found then return index of city
		}
	}
	strcpy(city[N1],s);						// if not found then add in sparse array matrix

	return N1++;							// return index
}

void push(nodel *heada,nodel *headb,int a,int b,int c){		//insert a,b,c in heada as row and headb as coloum

	nodel *temp,*t1,*t2,*t;  				// insert data in sparse linked list matrix

	t1=t=heada->right;						

	temp=createll(a,b,c);					// create node for linked list for sparse matrix

	if (t1==NULL)							// if no node in row then head points to new node 
	{
		heada->right=temp;
	}
	else{													// if any node present 
		while( t1!=NULL && t1->city2 < temp->city2){ 		// find the location of new node  
			t=t1;
			t1=t1->right;
		}													// new node between the t and t1

		if (t==heada)										// if new node just after head
		{
			temp->right=heada->right;
			heada->right=temp;
		}
		else if (t1==NULL)									// if new node at last
		{
			t->right = temp;
		}
		else{												// if new node between t and t1
			temp->right = t->right;
			t->right = temp; 
		}
	}

	t2=t=headb->down;

	if (t2==NULL)											// if no node in coloum then head points to new node
	{
		headb->down=temp;
	}						
	else{													// if any node present
		while(t2!=NULL && t2->city1 < temp -> city1){		// find the location of new node
			t=t2;
			t2=t2->down;
		}													// new node between the t and t2

		if (t==headb)										// if new node just after head
		{										
			temp->down=headb->down;
			headb->down=temp;
		}
		else if (t2==NULL)									// if new node at last
		{
			t->down=temp;
		}
		else{												// if new node between t and t2
			temp->down=t->down;
			t->down=temp;
		}

	}
	return;
}

void spare_matrix_formation(nodel *head[],int N,int F,char citys[][25]){     // sparse matrix as linked list 

	for (int i = 0; i < N; ++i)			     // create heads as array of linkedlist node 
	{
		head[i]=createll(0,0,0);
	}

	int a,b,c;

	for (int i = 0; i < F; ++i)				//	loop run f times
	{
		a=data_store(citys,N);            
		b=data_store(citys,N);
		cin >> c ;
		push(head[a],head[b],a,b,c);  				 // store index of city1 and city2 and fare in node of haed[1] and head[2]
	}

	return;
}

int search(int a,int b,int R,nodea matrix_array[]){ 		  // find matching pair of both matrixs

	for (int i = 1; i < R+1; ++i)
	{
		if (( matrix_array[i].city1 ==a && matrix_array[i].city2 ==b) || (matrix_array[i].city1 ==b && matrix_array[i].city2 ==a ))
		{
			return matrix_array[i].km;							// if match then return km between cities
		}
	}

	return 0;													// else return 0
}

void max(int N,nodel *head[] , int R ,nodea matrix_array[],char citys[][25]){      			// find max fare between cities

	nodel *temp;
	int a,b,c,maxx=0,d=0,e=1;																// maxx is maximum fare between cities

	for (int i = 0; i < N; ++i)
	{
		temp=head[i]->right;

		while(temp!=NULL){										// check  row by row

			a=temp->city1;
			b=temp->city2;
			c=temp->fare;
			c=c* (search(a,b,R,matrix_array));

			if (maxx < c)
			{
				d=a;										// if maxx fare then store index of city 1 and city 2 and fare
				e=b;
				maxx=c;
			}

			temp=temp->right;
		}
	}

	cout << endl <<"Output: "<< endl <<citys[d] << "  " << citys[e]  << "  " << maxx <<endl;    // in last print cities and their fare

	return ;
}



int main()
{
	int N,R,F;
	cin >> N >> R >> F;				// input n,r,f

	if (N<2 || ( R<1 && F<1) )
	{
		printf("ErrOr Input_valid_data\n");
		return 0;
	}

	nodea matrix_array[R+1];    // node for sparse array matrix

	matrix_array[0]=createa(N,N,R);		

	int a,b,c;
	char citys[N][25];			// 2D array for cities

	for (int i = 1; i < R+1; ++i)   // store index of city and km in array 
	{
		a=data_store(citys,N);
		b=data_store(citys,N);
		cin >> c ;

		matrix_array[i] = createa(a,b,c);
	}

	nodel *head[N];  							// header node for linked list matrix

	spare_matrix_formation(head,N,F,citys);		// linked list formation

	max( N , head , R , matrix_array , citys );  // find max fare
	

	return 0;
}