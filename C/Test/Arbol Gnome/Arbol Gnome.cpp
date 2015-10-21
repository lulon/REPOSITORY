#include <iostream>
using namespace std;

struct arbol{
	int dato;
	arbol *sig;
	arbol *ant;
	arbol *padre;
	arbol *hijo;
};

void recorrer(arbol *raiz){
	if(raiz==NULL)return;
	cout<<raiz;
	for(arbol ptr=raiz;ptr!=NULL;ptr=ptr->sig){
		recorrer(ptr->hijo)
	}
}
