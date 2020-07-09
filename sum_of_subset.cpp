#include <iostream>
using namespace std;

void sum_of_subset(int,int,int);
bool promising(int,int,int);

string include[6];
int w[6];
int W;
int main(){
	int total = 0 ;
	for(int i=1 ; i<=5 ; i++)
	{
	cin >> w[i];
	total += w[i];
	}
	cin >> W;
	
	sum_of_subset(0,0,total);
}

void sum_of_subset(int i,int weight,int total)
{
	if(promising(i,total,weight))
	if(weight == W)
	 {
	 	for(int k = 1 ; k<= i ; k++ )
	 	 if(include[k] == "Yes")
	 	  cout << 'w' << k << '=' << w[k] << '\t';
	 	 cout << endl;
	 }
	 
	 else
	 {
	 	include[i+1] = "Yes";
	 	sum_of_subset(i+1,weight+w[i+1] , total-w[i+1]);
	 	
	 	include[i+1] = "No";
	 	sum_of_subset(i+1,weight,total-w[i+1]);
	 }
}

bool promising(int i,int total , int weight)
{
   if((weight + total >= W) && (weight == W || weight+w[i+1]<=W))
   return true;
   
   else return false;
}
