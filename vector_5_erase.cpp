#include <iostream>
#include <vector>
using namespace std;


int main()
{
	vector <int> v = {1,2,3,4,5,6,7,8};
	
/*1*/	v.erase(v.end()-1);  // 1 2 3 4 5 6 7
	
/*2*/	v.erase(v.begin()+2); // 1 2 4 5 6 7
	
/*3*/	v.erase(v.begin()+1 , v.begin()+3); // 1 5 6 7
	
	for (int i=0 ; i<v.size() ; i++)
	 cout << v.at(i) << " ";  
	 
	 cout << "\n\n";
	 
	 cout << "Hello World";
	 

}
