#include <iostream>
using namespace std;
struct nodo{
	int dato;
	nodo *sig;};

void ins_primero(int dato,nodo * &ptrhead){
	nodo *Nodo=new nodo;
	Nodo->dato=dato;
	Nodo->sig=ptrhead;
	ptrhead=Nodo;}

void recorrer(nodo * &ptrhead){
	for(nodo *ptr=ptrhead;ptr!=NULL;ptr=ptr->sig){
		int dato=ptr->dato;
		cout<<dato<<";";
	}cout<<endl;
}

nodo *localizar(int dato_loc,nodo * ptrhead){
	for(nodo *ptr=ptrhead;ptr!=NULL;ptr=ptr->sig){
		if(dato_loc==ptr->dato)return ptr;
	}
}
	
void ins_ultimo(int dato,nodo * ptrhead){
	for(nodo *ptr=ptrhead;ptr!=NULL;ptr=ptr->sig){
		if(ptr->sig==NULL){
		nodo *Nodo=new nodo;
		Nodo->dato=dato;
		Nodo->sig=NULL;
		ptr->sig=Nodo;
		break;
		}		
	}
}

void elim_primero(nodo * &ptrhead){
	if(ptrhead){
		nodo *Nodo=ptrhead;
		ptrhead=Nodo->sig;
		delete Nodo;
		cout<<"HECHO"<<endl;
	}
	else
		cout<<"VACIO"<<endl;
}

void insertar(int dato,int dato_loc, nodo * &ptrhead){
	nodo *clave=localizar(dato_loc,ptrhead);
	if(clave==ptrhead){
		nodo *Nodo=new nodo;
		Nodo->dato=dato;
		Nodo->sig=ptrhead;
		ptrhead=Nodo;
	}
	else
		for(nodo *ptr=ptrhead;ptr!=NULL;ptr=ptr->sig){
			if (ptr->sig==clave){
				nodo *antes=ptr;
				nodo *Nodo=new nodo;
				Nodo->dato=dato;
				Nodo->sig=clave;
				antes->sig=Nodo;
				break;
			}
		}
}

void elim_lista(nodo * &ptrhead){
	for(nodo *ptr=ptrhead;ptr!=NULL;ptr=ptr->sig){
		nodo *Nodo=ptrhead;
		ptrhead=Nodo->sig;
		delete Nodo;
	}
	cout<<"HECHO"<<endl;
}

int main(){
	nodo *ptrhead=NULL;
	int dato,cat,dato_loc;
	cout<<"CATEGORIAS:"<<endl
	<<1<<") Insertar un Nodo en el header."<<endl
	<<2<<") Recorrer datos de la lista."<<endl
	<<3<<") Insertar Nodo en la ultima posicion."<<endl
	<<4<<") Insertar en el dato."<<endl
	<<5<<") Eliminar primer Nodo."<<endl
	<<6<<") Eliminar la lista"<<endl
	<<0<<") Salir."<<endl;
	while(1){
		cout<<"Selecione categoria:";
		cin>>cat;
		if (cat==0)break;
		switch(cat){
			case 1:{
				cout<<"Dato:";
				cin>>dato;
				ins_primero(dato,ptrhead);
				break;
			}
			case 2:{
				recorrer(ptrhead);
				break;
			}
			case 3:{
				cout<<"Dato:";
				cin>>dato; 
				ins_ultimo(dato,ptrhead);
				break;
			}
			case 4:{
				cout<<"dato de localizacion:";
				cin>>dato_loc;
				cout<<"Dato:";
				cin>>dato;
				insertar(dato,dato_loc,ptrhead);
				break;
			}
			case 5:{
				elim_primero(ptrhead);
				break;
			}
			case 6:{
				elim_lista(ptrhead);
				break;
			}
			default:break;
		}
	}
	return 0;
}


