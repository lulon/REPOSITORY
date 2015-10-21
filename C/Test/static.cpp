#include <iostream>
using namespace std;
int main()
{
	for(int i=0;i<20;i++)
	{
	static int a=0;
	a++;
	cout<<a<<" ";
	}
return 0;
}
