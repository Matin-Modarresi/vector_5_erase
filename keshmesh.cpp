#include<iostream>
#include <iomanip>

using namespace std;

#define Min  -32767

void keshmesh(int,int,int **);
void setArray(int,int,int **);
int  find_Max(int,int);

int main(){
	
	int n , m;
	cin >> n >> m;
	int n1=(n+1)/2+1;
	int **a = new int*[n1];
	setArray( n , m , a);
	keshmesh(n, m , a);

}

void setArray(int n , int m , int **array)
{
	

    int n1=(n+1)/2+1;
  	int *b  = new int[n1*m];
  
        for(int i=0 ; i<n1 ; i++)
                array[i]=&b[i*m];
	int temp;

	   
	for(int i=1 ; i<=n ; i++)
	  for(int j=1 ; j<=m ; j++)
	  {
	  	cin >> temp;
	  	if(temp == 0) temp = Min;
	  	
	  	if(i%2!=0)
	  	 {
	  	 	if(((n-i)/2)%2!=0)
	  	 	 {
	  	 	 	if(j==m)
	  	 	 	   continue;
	  	 	    
	  	 	 	
	  	 	 	*(array[((i+1)/2)-1]+(j-1))=temp;
			 }
		  
		    
		    else
		      {
			  if(n==1)
		      	      {
		      	      	*(array[((i+1)/2)-1]+(j-1))=temp;
		      	      	continue;
				      }
				else
				{
		      	   if(j==1)
		      	      continue;
		      	      
		      	*(array[((i+1)/2)-1]+(j-2))=temp;
		        }
			  }
	     } 
	  }
	  
	 	 for(int i=(n==1?1:0) ; i<n1 ; i++)
	         *(array[i]+(m-1)) = Min;
	   
	    for(int j=0 ; j<m ; j++)
	        *(array[n1-1]+j) = 0;
	  
}


void keshmesh(int n,int m,int **array)
{
	int n1 = (n+1)/2+1;
	
	int ans = Min , index = 0;
	
	for(int i=n1-2 ; i>=0 ; i--)
	  for(int j=m-2 ; j>=0 ; j--)
	  {
	  
	    *(array[i]+j) += find_Max(*(array[i+1]+j) , *(array[i]+(j+1)) );
	    
	    if(ans<=*(array[i]+j)) {
	    	
		        ans = *(array[i]+j);
		        index = i;
	      }
	    
      }
	   
	   cout << "\n\n";
	   
	   if(index == 0 && ans>0)
	     cout << ans << "\n\n";
		 
		 else cout << 0 << "\n\n";  
}
 
 int find_Max(int a , int b)
 {
 	if(a>=b) return a;
 	else return b;
 }
