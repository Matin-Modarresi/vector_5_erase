#include <iostream>
using namespace std;

//void keshmesh(int, int , int **);
void set_Array(int,int,int **);

int main()
{
	int n , m;
	cin >> n >> m;
	int **a = new int*[n];
	
	set_Array(n,m,a);
}


//void keshmesh(int n , int m , int **arr)
//{
//	
//}

void set_Array(int n , int m , int**arr)
{
	  int *b  = new int[n*m];
         
 
  for(int i=0 ; i<n ; i++)
       arr[i]=&b[i*m];
       
       for(int i=0 ; i<n ; i++)
        for(int j=0 ; j<m ; j++)
         cin >> *(arr[i]+j); 
}
