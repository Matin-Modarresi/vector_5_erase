#include <iostream>
#include <vector>
using namespace std;


int main()
{
	vector <int> v = {1,2,3,4,5,6,7,8};
	
	
	for (int i=0 ; i<v.size() ; i++)
	 cout << v.at(i) << " ";
}
