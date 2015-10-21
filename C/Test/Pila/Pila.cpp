#include <iostream>
using namespace std;

struct nodo{
	int dato;
	nodo *sig;};

void Push(int dato,nodo * &ptrhead){
	nodo *Nodo=new nodo;
	Nodo->dato=dato;
	Nodo->sig=ptrhead;
	ptrhead=Nodo;
}

void Pop(nodo * &ptrhead){
	if(ptrhead){
		cout<<"El dato es:"<<ptrhead->dato<<endl;
		nodo *Nodo=ptrhead;
		ptrhead=Nodo->sig;
		delete Nodo;
	}
	else
		cout<<"Pila Vacia"<<endl;
}

int main(){
	nodo *ptrhead=NULL;
	int dato,cat;
	cout<<"CATEGORIAS:"<<endl
	<<1<<") Push"<<endl
	<<2<<") Pop"<<endl
	<<3<<") Recorrer Punteros"<<endl
	<<0<<") Salir"<<endl;
	while (1){
		cout<<"Seleccione categoria:";
		cin>>cat;
		if(cat==0)break;
		else
			switch(cat){
				case 1:{
					cout<<"Ingrese Dato:";
					cin>>dato;
					Push(dato,ptrhead);
					break;
				}
				case 2:{
					Pop(ptrhead);
					break;
				}
				default:break;
			}
	}
	return 0;
}
