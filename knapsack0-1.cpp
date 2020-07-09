#include <iostream>
using namespace std;

void knapsack(int,int,int);
bool promising(int,int,int);

const int n = 4;

string include[n+1];
int p[n+1] , w[n+1];
int W , maxprofit = 0  , numbest = 0;


int main()
{
//	cin >> W;
//	for(int i=1 ; i<=n ; i++)
//	{
//		cin >> p[i] >> w[i];
//	}
	cout << INT_MAX;
//	knapsack(0,0,0);
//	cout << maxprofit << '\n';
//	cout << numbest << '\n';
//	for(int i=1 ; i<= numbest ; i++)
//	cout << include[i] << " ";
}



void knapsack(int i , int weight , int profit)
{
	if(weight <= W && maxprofit<profit)
	{
		maxprofit = profit;
		numbest = i ;
	   // bestest = include[i];
	}
	
	else
	{
		if(promising(i , weight , profit))
		{
			include[i+1]="Yes";
			knapsack(i+1 , weight+w[i+1] , profit+p[i+1]);
			include[i+1]="No";
			knapsack(i+1 , weight , profit);
		}
	}
}

bool promising(int i , int weight , int profit)
{
	int j , k ;
	int totweight;
	float bound ;
	 
	 if(weight >= W)
	 return false;
	 
	 else
	 {
	 	j=i+1;
	 	totweight = weight;
	 	bound = profit;
	   while(j <= n && totweight + w[j] <= W)
	   {
	   	 totweight+=w[j];
	   	 bound+=p[j];
	   	 j++;
		}
		k = j;
		if(k<=n)	
		bound += (W-totweight)*p[k]/w[k]*1.0;
		
		return bound > maxprofit;
	 }
}

