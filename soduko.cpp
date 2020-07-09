//Soduko
#include <iostream>
using namespace std;

void soduko(int,int);
void print(int[][9]);
bool promising_1(int,int);
bool promising_2(int,int);

#define J (j+1)%9
#define I (j+1==9 ? i+1 : i)

int table[9][9];

int main()
{
	char ch;
	
	
	for(int i=0 ; i<9 ; i++)
	 for(int j=0 ; j<9 ; j++)
	  {
	  	cin >> ch;
	  	
	  	if(ch =='.')
	  		table[i][j] = 0 ;
	  	else
		  table[i][j] = int(ch)-48;	
		  
	  }
	
	  
	  
	  soduko(0,-1);
	  
}

void soduko(int i , int j )
{
		
	
	if(promising_2(i , j))
	                      {
	                       
	                        if(i==8 && j==8)
	                                        {
		                                     cout << "\n\n";
		                                     print(table);
		                                     exit(0);
	                                        }
	
	                              else
	                                  {
					                     if(promising_1( I, J ))
	                     	               for(int n = 1 ; n <= 9 ; n++)
		                                   {
		 	                                    table[I][J]= n;
		 	                                    soduko(I , J);
		 	                                    
		 	                                    if(n==9) table[I][J]=0;
											}
		                                             else
		                   	                         soduko(I , J);
						              }
	                      }
        
    else if(table[i][j] == 9)
	table[i][j] = 0;
				
		else return ;
}

bool promising_1(int i , int j )
{
	if(table[i][j]!=0)
	 return false;
	 
	   else return true;
}
  
bool promising_2(int i , int j )
{
	
	 if(j==-1) return true;
	  
	 for(int k=0 ; k<9 ; k++)
	  {
	    if(k==i)continue;
	  
	     if(table[k][j] == table[i][j])
	         return false;
      }
	    
	    for(int k =0 ; k<9 ; k++)
	    {
	    	if(k==j)continue;
	    	
	          if(table[i][k] == table[i][j])
	          return false;
	    }
	    
	    int j2 = (i*9+j)/3%3;
	    int i2 = (j*9+i)/3%3;
	   
	   for(int n = i2*3 ; n< (i2+1)*3 ; n++)
	     for(int m = j2*3 ; m < (j2+1)*3 ; m++)
	     {
	     	if(n==i && m==j)
	     	  continue;
	     	  
	     	if(table[n][m] == table[i][j])
	     	  return false;
		 }
	   
	       return true;
	    
}

void print(int a[][9])
{
	int i ,j;
	for( i=0 ; i<9 ; i++)
	{
	  
	    for( j=0 ; j<9 ; j++)
      {	  
              if((j+1)%3==0) 
	             cout << a[i][j] << '\t';
	  
	               else  
	                   cout << a[i][j] << " ";
		if((i+1)%3==0 && j==8)
	       cout <<"\n\n";
	  }
	  
	  cout << "\n";
	}
}
