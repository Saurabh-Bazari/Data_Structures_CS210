 /**************************************************************************************************************************************************************************
 SAURABH BAZARI
 160101061
 CS210
******************************************************************************************************************************************************************
1. Take input first rows ,coloum and Jungle in interger in 0 & 1 form and also calculate 1 on boundary and store in ct, also store last boundary land element in 
   i1 & j1.
2. If ct is 2 then call Path otherwise bad luck!.
3. Then check if it is single coloum or single row if no, then procced for row greater than 2 and coloum greater than 2.
4. Check i1 and j1 are eligible for which directions.
5. Then call 4 functions move_up,move_down,move_left,move_right acc.to satisfy question need.
6. Also change the value of element if pass from that point for don't  retrace the path again.
7. If unique path then return w=1.
******************************************************************************************************************************************************************
*******************************************************************************************************************************************************************/




#include <bits/stdc++.h>
using namespace std;

//declared functions

int move_up(int r,int c,int i,int j,int w,int** ary);
int move_right(int r,int c,int i,int j,int w,int** ary);
int move_down(int r,int c,int i,int j,int w,int** ary);
int move_left(int r,int c,int i,int j,int w,int** ary);

// function for check entry or exit poinrt

bool on_boundary(int r,int c,int i,int j){
	if (i==0 || i==r-1 || j==0 || j==c-1 )
	{
		return true;
	}
	return false;
}

//function for check left side 

int move_left(int r,int c,int i,int j,int w,int** ary){

	ary[i][j]=-1; //change the value of current position
	j--;   // shift just left
	
	if ( w==-1 || ary[i][j]==-1) //check element is -1 or not and not repeat the same path
	{
		return -1; //if one time w is -1 then it is always -1
	}

	if (ary[i][j]==0)
	{
		return w; // when no land
	}

	if (on_boundary(r,c,i,j)==1)
	{
		return 1;  // when reach at end point 
	}
	
//		next three direction

	w=move_up(r,c,i,j,w,ary);
	w=move_down(r,c,i,j,w,ary);
	w=move_left(r,c,i,j,w,ary);
	return w;
}

	// function for chect right side

int move_right(int r,int c,int i,int j,int w,int** ary){

	ary[i][j]=-1; //change the value of current position
	j++;  // shift just right

	if ( w==-1 || ary[i][j]==-1) //check element is -1 or not and not repeat the same path
	{
		return -1; //if one time w is -1 then it is always -1
	}

	if (ary[i][j]==0)
	{
		return w; // when no land
	}

	if (on_boundary(r,c,i,j)==1)
	{
		return 1;  // when reach at end point
	}
	
//		next three direction

	w=move_up(r,c,i,j,w,ary);
	w=move_down(r,c,i,j,w,ary);
	w=move_right(r,c,i,j,w,ary);
	return w;
}

 // function for up side

int move_up(int r,int c,int i,int j,int w,int** ary){

	ary[i][j]=-1; //change the value of current position
	i--; //shift just upward

	if ( w==-1 || ary[i][j]==-1) //check element is -1 or not and not repeat the same path
	{
		return -1; //if one time w is -1 then it is always -1
	}

	if (ary[i][j]==0)
	{
		return w; // when no land
	} 

	if (on_boundary(r,c,i,j)==1)
	{
		return 1; // when reach at end point
	}
	
//		next three direction

	w=move_up(r,c,i,j,w,ary);
	w=move_right(r,c,i,j,w,ary);
	w=move_left(r,c,i,j,w,ary);
	return w;
}

int move_down(int r,int c,int i,int j,int w,int** ary){

	ary[i][j]=-1;
	i++;

	if ( w==-1 || ary[i][j]==-1) //check element is -1 or not and not repeat the same path
	{
		return -1; //if one time w is -1 then it is always -1
	}

	if (ary[i][j]==0)
	{
		return w; // when no land
	}

	if (on_boundary(r,c,i,j)==1)
	{
		return 1; // when reach at end point
	}
	
//		next three direction

	w=move_right(r,c,i,j,w,ary);
	w=move_down(r,c,i,j,w,ary);
	w=move_left(r,c,i,j,w,ary);
	return w;
}

int Path(int r,int c,int i1,int j1,int w,int** ary){

	if ( (r==1 && ary[i1][j1-1]==1) || (c==1 && ary[i1-1][j1]==1) )
	{
		return 1; // if any single row or single coloum and just pervious element is also land then return w=1 else w=0
	}
	else{

		if (j1!=0) // when element has left side
		{
			w=move_left(r,c,i1,j1,w,ary);
		}
		if (j1!=c-1) // when element has right side
		{
			w=move_right(r,c,i1,j1,w,ary);
		}
		if (i1!=0) // when element has upward side
		{
			w=move_up(r,c,i1,j1,w,ary);
		}
		if (i1!=r-1) // when element has downward side
		{
			w=move_down(r,c,i1,j1,w,ary);
		}
	}
	return w;
}

int main()
{

	while(1){

		int r,c,w=0,ct=0,i1,j1;
		char k;

		cout <<"Enter no. of rows & coloum :  ";
		cin >> r >> c; //input row an coloum

		if (r==0 && c==0)
		{
			break; //break when no row and no coloum
		}

		if (r <=0 || c<=0)
		{
			printf("Wrong Input\n");
			continue;
		}

		int **ary;

		ary = new int *[r];

		for (int i = 0; i < r; ++i)
		{
			ary[i]=new int[c]; 
		}

		

		cout << "Enter the Jungle without space" << endl;

		for (int i = 0; i <r ; ++i)
		{
			for (int j = 0; j <c ; ++j)
			{
				cin >> k;
				if (k=='T')
				{
					ary[i][j]=0; //when tree 
				}
				else{                                //when no tree
					if ( on_boundary(r,c,i,j)==1 )
					{
						ct++; // counter for both land and boundary are present
						i1=i; // store row of last counter
						j1=j; // store coloum of last counter
					}
					ary[i][j]=1; // when land
				}
			}
		}

		if (ct==2) //when only 2 exactly exit and entry point
		{
			w=Path(r,c,i1,j1,w,ary);
			if (w==1)
			{
				printf("Submitted!\n"); // only single path
			}
			else{
				printf("Bad LUCK!\n"); // path not exist or more than 1 path
			}
		}
		else{
			printf("Bad LUCK!\n"); // when not 2 exactly entry and exit point
		}
	}

	return 0;
}

