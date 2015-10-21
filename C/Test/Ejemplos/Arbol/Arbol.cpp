#include <iostream>
using namespace std;

struct nodoA{
	struct nodoL{
		nodoA *sig_a;
		nodoL *sig_l;
	};
	int dato;
	nodoL *inicio;
};

void ins_primero(nodoA *sig_a,nodoL * &inicio){
	nodoL *Nodo=new nodoL;
	Nodo->sig_a=sig_a;
	Nodo->sig_l=inicio;
	inicio=Nodo;
}

void recorrer(nodoA *raiz){
	if(raiz==NULL)return;
	cout<<raiz->dato<<" ";
	for (nodoL *ptr=raiz->inicio;ptr!=NULL;ptr=ptr->sig_l){
		recorrer(ptr->sig_a);
	}
}

void buscar(nodoA * &raiz){
	if(raiz==NULL){
		int flag;
		cout<<"Arbol Vacio, desea plantar la raiz?"<<endl
		<<1<<") SI"<<endl
		<<0<<") NO"<<endl<<"Seleccione:";
		cin>>flag;
		if(flag)insertar_raiz(raiz,dato);	
	}
	insertar(raiz);
	for (nodoL *ptr=raiz->inicio;ptr!=NULL;ptr=ptr->sig_l){
		recorrer(ptr->sig_a);
	}
}

void insertar_hijo(nodoA *raiz,int dato,int dato_loc){
	if(raiz->dato==dato_loc){
		nodoA *NodoA=new nodoA;
		NodoA->dato=dato;
		NodoA->inicio=NULL;
		ins_primero(NodoA,raiz->inicio);
	}
}

void insertar_raiz(nodoA * &raiz,int dato){
	raiz=new nodoA;
	raiz->dato=dato;
	raiz->inicio=NULL;
}

int main(){
	nodoA *raiz=NULL;
	int dato,dato_loc,cat;
	cout<<"CATEGORIAS:"<<endl
	<<1<<") Insetar hijo"<<endl
	<<2<<") Recorrer"<<endl
	<<0<<") Salir."<<endl;
	cin>>cat;
	while(1){
		if(cat==0)break;
		switch(cat){
			case 1:{
				cout<<"Dato:";
				cin>>dato;
				cout<<"Localizacion del padre:";
				cin>>dato_loc;
				insertar_hijo(raiz,dato,dato_loc);
				break;
			}
			case 2:{
				recorrer(raiz);
				break;
			}
			default:break;
		}
	}
	return 0;
}
