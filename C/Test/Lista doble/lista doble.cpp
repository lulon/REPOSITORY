#include <iostream>
using namespace std;

struct nodo{
	int dato;
	nodo *sig;
	nodo *ant;
};

void insertar_prim_vacio(nodo * &lista,int dato){
	nodo *Nodo=new nodo;
	Nodo->dato=dato;
	Nodo->ant=NULL;
	Nodo->sig=NULL;
	lista=Nodo;
}

void insertar_prim_novacio(nodo * &lista,int dato){
	while(lista->ant)lista=lista->ant;
	nodo *Nodo=new nodo;
	Nodo->dato=dato;
	Nodo->ant=NULL;
	Nodo->sig=lista;
	lista->ant=Nodo;
}

void elim_primero_solo(nodo * &lista){
	nodo *Nodo=lista;
	lista=NULL;
	delete Nodo;
}

void elim_primero_nosolo(nodo * &lista){
	nodo *Nodo=lista;
	lista=lista->sig;
	Nodo->sig->ant=NULL;
	delete Nodo;
}

void insertar_prim(nodo * &lista,int dato){
	if(lista==NULL)insertar_prim_vacio(lista,dato);
	else
		insertar_prim_novacio(lista,dato);
}

void elim_primero(nodo * &lista){
	while(lista->ant)lista=lista->ant;
	if((lista->ant==NULL&&lista->sig==NULL))elim_primero_solo(lista);
	else
		elim_primero_nosolo(lista);
}

void recorrer(nodo *lista){
	while(lista->ant)lista=lista->ant;
	while(lista){
		cout<<lista->dato<<";";
		lista=lista->sig;
	}
	cout<<endl;
}

void elim_lista(nodo * &lista){
	while(lista->ant)lista=lista->ant;
	while(lista){
		elim_primero(lista);
	}
}

int main(){
	cout<<"CATEGORIAS:"<<endl
	<<1<<") Ingresar Nodo en primera posicion"<<endl
	<<2<<") Eliminar Nodo en primera posicion"<<endl
	<<3<<") Recorrer lista"<<endl
	<<4<<") Eliminar lista"<<endl
	<<0<<") Salir."<<endl;
	int dato,flag;
	nodo *lista=NULL;
	while(1){
		cout<<"Selecione categoria:";
		cin>>flag;
		if(flag==0)break;
		switch(flag){
			case 1:{
				cout<<"Dato:";
				cin>>dato;
				insertar_prim(lista,dato);
				/*cout<<lista<<" "<<lista->ant<<" "<<lista->dato<<" "<<lista->sig<<endl;*/
				break;
			}
			case 2:{
				if(lista==NULL){
					cout<<"Lista Vacia"<<endl;
					break;
				}
				else
					elim_primero(lista);
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
					elim_lista(lista);
					cout<<"HECHO"<<endl;
					break;
			}
			default:break;
		}
	}
	return 0;
}
