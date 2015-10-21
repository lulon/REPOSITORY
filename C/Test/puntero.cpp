#include <iostream>
using namespace std;
int main()
{	
	int *p;
	int n[20];
	n[1]=6;
	p = &n[1];
	cout<<*p;
	return 0;
}
