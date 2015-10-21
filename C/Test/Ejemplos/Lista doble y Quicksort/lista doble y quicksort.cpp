#include <iostream>
using namespace std;

struct nodo{
	int dato;
	nodo *sig;
	nodo *ant;
};

void insertar_prim_vacio(nodo * &lista,nodo * &ptrhead,nodo * &ptrtail,int dato){
	nodo *Nodo=new nodo;
	Nodo->dato=dato;
	Nodo->ant=NULL;
	Nodo->sig=NULL;
	lista=Nodo;
	ptrtail=Nodo;
	ptrhead=Nodo;
}

void insertar_prim_novacio(nodo * &lista,nodo * &ptrhead,int dato){
	while(lista->ant)lista=lista->ant;
	nodo *Nodo=new nodo;
	Nodo->dato=dato;
	Nodo->ant=NULL;
	Nodo->sig=lista;
	lista->ant=Nodo;
	ptrhead=Nodo;
}

void elim_primero_solo(nodo * &lista,nodo * &ptrhead,nodo * &ptrtail){
	nodo *Nodo=lista;
	lista=NULL;
	ptrhead=NULL;
	ptrtail=NULL;
	delete Nodo;
}

void elim_primero_nosolo(nodo * &lista,nodo * &ptrhead){
	nodo *Nodo=lista;
	lista=lista->sig;
	ptrhead=lista;
	Nodo->sig->ant=NULL;
	delete Nodo;
}

void insertar_prim(nodo * &lista,nodo * &ptrhead,nodo * &ptrtail,int dato){
	if(lista==NULL)insertar_prim_vacio(lista,ptrhead,ptrtail,dato);
	else
		insertar_prim_novacio(lista,ptrhead,dato);
}

void elim_primero(nodo * &lista,nodo * &ptrhead,nodo * &ptrtail){
	while(lista->ant)lista=lista->ant;
	if((lista->ant==NULL&&lista->sig==NULL))elim_primero_solo(lista,ptrhead,ptrtail);
	else
		elim_primero_nosolo(lista,ptrhead);
}

void recorrer(nodo *lista){
	while(lista->ant)lista=lista->ant;
	while(lista){
		cout<<lista->dato<<";";
		lista=lista->sig;
	}
	cout<<endl;
}

void elim_lista(nodo * &lista,nodo * &ptrhead,nodo * &ptrtail){
	while(lista->ant)lista=lista->ant;
	while(lista){
		elim_primero(lista,ptrhead,ptrtail);
	}
}

void Quicksort(nodo * wall,nodo * pivot){
	int temp;
	nodo *inicio=wall;
	nodo *current=wall;
	while(1){
		temp=current->dato;
		if ((current->dato<pivot->dato)){
			current->dato=wall->dato;
			wall->dato=temp;
			wall=wall->sig;
		}
		if(current==pivot){
			pivot->dato=wall->dato;
			wall->dato=temp;
			if(wall!=inicio)Quicksort(inicio,wall->ant);
			if(wall!=pivot)Quicksort(wall->sig,pivot);
			break;
		}
		current=current->sig;
	}
}

int main(){
	cout<<"CATEGORIAS:"<<endl
	<<1<<") Ingresar Nodo en primera posicion"<<endl
	<<2<<") Eliminar Nodo en primera posicion"<<endl
	<<3<<") Recorrer lista"<<endl
	<<4<<") Eliminar lista"<<endl
	<<5<<") Ordenar lista"<<endl
	<<0<<") Salir."<<endl;
	int dato,flag;
	nodo *lista=NULL;
	nodo *ptrhead=NULL;
	nodo *ptrtail=NULL;
	while(1){
		cout<<"Selecione categoria:";
		cin>>flag;
		if(flag==0)break;
		switch(flag){
			case 1:{
				cout<<"Dato:";
				cin>>dato;
				insertar_prim(lista,ptrhead,ptrtail,dato);
				/*cout<<lista<<" "<<lista->ant<<" "<<lista->dato<<" "<<lista->sig<<endl;*/
				break;
			}
			case 2:{
				if(lista==NULL){
					cout<<"Lista Vacia"<<endl;
					break;
				}
				else
					elim_primero(lista,ptrhead,ptrtail);
					cout<<"HECHO"<<endl;
					break;
			}
			case 3:{
				if(lista==NULL){
					cout<<"Lista Vacia"<<endl;
					break;
				}
				else
					recorrer(lista);
					break;
			}
			case 4:{
				if(lista==NULL){
					cout<<"Lista Vacia"<<endl;
					break;
				}
				else
					elim_lista(lista,ptrhead,ptrtail);
					cout<<"HECHO"<<endl;
					break;
			}
			case 5:{
				Quicksort(ptrhead,ptrtail);
				cout<<"Hecho:";
				recorrer(lista);
				cout<<endl;
				break;
			}
			case 6:{
			cout<<"Dato en ptrhead:"<<ptrhead->dato<<endl
			<<"Dato en ptrtail:"<<ptrtail->dato<<endl;
			}
			default:break;
		}
	}
	return 0;
}
