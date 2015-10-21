#include <iostream>
using namespace std;
int inicializar()
{
	static int comb[20];
	for(int i=0;i<20;i++)
	{
		comb[i]=1;
	}
	return 0;
}

/*int sumar(int ar[]){
	int suma=0;
	for (int i=0;i<20;i++)
	{
		suma+=ar[i];
	}
	return suma;
}*/

int contar(int ar[])
{
	int cont=0;
	for(int i=0;i<20;i++)
	{
		if(ar[i]!=0)
		{
			cont+=1;
		}
		else
			break;
	}
	return cont;
}


int main()
{	/*inicializar();*/
	/*int ar[2]={74,58};
	int comb[20]={1,25,1,1,1,1,15,1,1,1,48,1,1,1,27,1,1,1,1,1};*/
	/*for (int i=0;i<20;i++)
	{
		cout<<*(comb+i)<<" ";
	}*/
	int comb[21]={1,25,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,30};
	cout<<contar(comb);
	return 0;
}
