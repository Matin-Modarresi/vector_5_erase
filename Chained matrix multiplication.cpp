#include <iostream>
#include <iomanip>
using namespace std;

const int N = 6;
void multi(int,int[],int[][N+1],int[][N+1]);
void order(int,int,int[][N+1]);
int find_min(int , bool & , int &);


int main()
{
	int P[N+1][N+1] ;
	int M[N+1][N+1] ;
	int d[N+1];
	
	for(int i=0 ; i<=N ; i++)
	cin >> d[i];
	
	for(int i=0 ; i<=N ; i++)
	  for(int j=0 ; j<=N ; j++)
	    {
	    	P[i][j]=-1;
	    	M[i][j]=-1;
		}
	
	
	multi(N , d , P , M);
	
	for(int i=1 ; i<=N ; i++)
	{
	  for(int j=1 ; j<=N ; j++)
	     cout << setw(5) << left <<  M[i][j] ;
	     
	     cout << endl;
    }
    
    cout << endl;
    
    order(1,N,P);
}



void multi(int n , int d[] , int P[][N+1] , int M[][N+1])
{
	for(int i=1 ; i<=n ; i++)M[i][i]=0;
	
	for(int diagonal = 1 ; diagonal <= n-1 ; diagonal++)
	  for(int i=1 ; i<= n-diagonal; i++)
	    {
		 int j = i+diagonal;
		  bool check;
		  int min = INT_MAX;
		  for(int k=i ; k<=j-1 ; k++)
		    {
			  M[i][j] = find_min(M[i][k]+M[k+1][j] + d[i-1]*d[k]*d[j] , check , min);
			  
			  if(check) P[i][j] = k;
		    }
		   
		  
		  
	    }
		  
}

void order(int i , int j , int P[][N+1])
{
	if(i==j)
	  cout << "A" << i;
	  
	  else
	  {
	    int k = P[i][j];
	    cout << '(';
	    order(i,k,P);
	    order(k+1,j,P);
	    cout << ')';
	  }
}


int find_min(int m , bool &k , int &min)
{

  	if(m<min)
  	 {
	   min = m;
	   k = true;
     }
     
     else k=false;
  	 
  	 return min;
}
