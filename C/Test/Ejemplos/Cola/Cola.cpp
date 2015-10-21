#include <iostream>
using namespace std;

struct nodo{
	int dato;
	nodo *sig;
};

void Insertar(int dato,nodo * &ptrhead,nodo * &ptrtail){
	nodo *Nodo=new nodo;
	Nodo->sig=NULL;
	Nodo->dato=dato;
	if((ptrhead==NULL&&ptrtail==NULL)){
		ptrhead=Nodo;
		ptrtail=Nodo;
	}
	else
		ptrtail->sig=Nodo;
		ptrtail=Nodo;
}

void Leer(nodo * &ptrhead,nodo * &ptrtail){
	nodo *Nodo=ptrhead;
	ptrhead=Nodo->sig;
	cout<<"El dato es:"<<Nodo->dato<<endl;
	delete Nodo;
	if (ptrhead==NULL)ptrtail=NULL;
}

void Quicksort(nodo * &wall,nodo * &pivot){
	nodo *inicio=wall;
	if(pivot!=wall){
		nodo *current=wall;
		while(1){
			int temp=current->dato;
			if (current->dato<pivot->dato){
				wall->dato=current->dato;
				current->dato=temp;
				wall=wall->sig;
			}
			if(current==pivot){
				pivot->dato=wall->dato;
				wall->dato=temp;
				Quicksort(wall,pivot);
				Quicksort(inicio,wall);
			}
		}
	}
}

void recorrer(nodo * &ptrhead){
	for(nodo *ptr=ptrhead;ptr!=NULL;ptr=ptr->sig){
		int dato=ptr->dato;
		cout<<dato<<";";
	}cout<<endl;
}

int main(){
	nodo *ptrhead=NULL;
	nodo *ptrtail=NULL;
	int dato,cat;
	cout<<"CATEGORIAS:"<<endl
	<<1<<") Insertar Nodo"<<endl
	<<2<<") Leer Nodo"<<endl
	<<3<<") Recorrer lista"<<endl
	<<4<<")Ordenar lista"<<endl
	<<0<<") Salir"<<endl;
	while(1){
		cout<<"Selecione categoria:";
		cin>>cat;
		if (cat==0)break;
		switch(cat){
			case 1:{
				cout<<"Ingrese dato:";
				cin>>dato;
				Insertar(dato,ptrhead,ptrtail);
				break;
			}
			case 2:{
				if ((ptrhead==NULL&&ptrtail==NULL))cout<<"Vacio"<<endl;
				else
					Leer(ptrhead,ptrtail);
					break;
			}
			case 3:{
				recorrer(ptrhead);
				break;
			}
			case 4:{
				nodo *wall=ptrhead;
				nodo *pivot=ptrtail;
				Quicksort(wall,pivot);
				cout<<"Ordenado"<<endl;
				break;
			}
			default:break;
		}
	}
	return 0;
}
