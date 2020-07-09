#include <iostream>
using namespace std;

void queens(int);
bool promising(int);

int col[9];
int n=8;
int main()
{
	queens(0);
}
int count = 0 , loop = 0;
void queens(int i)
{
	if(promising(i))
	if(i == n)
	{   cout << "answer :  ";
		for(int j=1 ; j<=n ; j++)
		 cout << col[j] << "  ";
		 /*count++;
		 if(count==1)
		 exit(0);*/
		cout << "\n"; 
	}
	
	else
	{
	 loop++;
	for(int j=1 ; j<=n ; j++)
	  {	
	   /* cout << "loop  " << loop << " :\n";
	  	cout << i+1 << " -> " << j << "\n";*/
	  	col[i+1] = j;
	  	queens(i+1);
	  }
    }
}

bool promising(int i)
{
    int k = 1;
	/*cout << k << "    " << i << "\n";
	cout << col[i] << ":  "; */
	
	bool sw = true;
	
	while(k < i && sw)
	{    //cout << col[k] << "	";
		if(col[i] == col[k] || col[i]-col[k] == i-k || col[i]-col[k] == k-i)
		  sw = false;
		 k++;
	}
	//cout << "\n\n";
	return sw;
}


