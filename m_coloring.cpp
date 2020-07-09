#include <iostream>
using namespace std;

void m_coloring(int);
bool promising(int);


int w[5][5] = { 0 , 0 , 0 , 0 , 0 ,
                0 , 0 , 1 , 1 , 1 ,
				0 , 1 , 0 , 1 , 0 ,
				0 , 1 , 1 , 0 , 1 ,
				0 , 1 , 0 , 1 , 0
              };
int vcolor[5];

int main()
{
	m_coloring(0);
}

void m_coloring(int i)
{
	if(promising(i))
	if(i==4)
	{
		for(int i=1 ; i<5 ; i++)
		 cout << vcolor[i] << " ";
		 cout << endl;
	}
	
	else
	for(int color=1 ;  color<= 3 ; color++ )
	   {
	   	 vcolor[i+1] = color;
	   	 m_coloring(i+1);
	   }
}

bool promising(int i)
{
	bool sw = true;
	int j = 1;
	
	while(sw && j<i)
	{
		if(w[i][j] && vcolor[i]==vcolor[j])
		 sw = false;
		 j++;
	}
	
	return sw;
}
