#include <iostream>
using namespace std;

void hamiltonian(int);
bool promising(int);

const int n = 8;
int vindex[n];

int w[n+1][n+1]={
	          0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
              0 , 0 , 1 , 1 , 0 , 0 , 0 , 1 , 1 ,
			  0 , 1 , 0 , 1 , 0 , 0 , 0 , 1 , 1 ,
			  0 , 1 , 1 , 0 , 1 , 0 , 1 , 0 , 0 , 
			  0 , 0 , 0 , 1 , 0 , 1 , 0 , 0 , 0 , 
			  0 , 0 , 0 , 0 , 1 , 0 , 1 , 0 , 0 , 
			  0 , 0 , 0 , 1 , 0 , 1 , 0 , 1 , 0 , 
			  0 , 1 , 1 , 0 , 0 , 0 , 1 , 0 , 1 ,
			  0 , 1 , 1 , 0 , 0 , 0 , 0 , 1 , 0  
			
			};
int main()
{
	vindex[0]=1;
	hamiltonian(0);
}

void hamiltonian(int i)
{
	if(promising(i))
	if(i==n-1)
	{
		for(int k=0 ; k<n ; k++)
		 cout << vindex[k] << " ";
		 cout << endl;
	}
	
	else
	{
		for(int j=2 ; j<=n ; j++)
		 {
		   vindex[i+1] = j;
		   hamiltonian(i+1);
	     }
	}
}

bool promising(int i)
{
	bool sw;
	
	if(i==n-1 && !w[vindex[n-1]][vindex[0]])
	    sw = false;
	    
	    else if(i>0 && !w[vindex[i-1]][vindex[i]])
	             sw = false;
	    else
	    {
	    	sw = true;
	    	int j =1;
	    	
	    	while(sw && j<i)
	    	{
	    		if(vindex[i]==vindex[j])
	    		sw=false;
	    		j++;
			}
		}
		
		return sw;
}
