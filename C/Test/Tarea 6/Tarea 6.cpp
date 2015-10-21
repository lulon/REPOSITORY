#include <iostream>
using namespace std;

struct nodo{
	int dato;
	nodo *up;
	nodo *down;
	nodo *right;
	nodo *left;
	int coord[2];
	bool rec;
};

struct nodo_L{
	int dato;
	nodo_L *sig;};
	
void ins_primero(int dato,nodo_L * &ptrhead){
	nodo_L *Nodo=new nodo_L;
	Nodo->dato=dato;
	Nodo->sig=ptrhead;
	ptrhead=Nodo;}

bool recorrer(nodo_L * &ptrhead,int dato){
	for(nodo_L *ptr=ptrhead;ptr!=NULL;ptr=ptr->sig){
		if(dato==ptr->dato)return 0;
	}
	return 1;
}

void elim_lista(nodo_L * &ptrhead){
	for(nodo_L *ptr=ptrhead;ptr!=NULL;ptr=ptr->sig){
		nodo_L *Nodo=ptrhead;
		ptrhead=Nodo->sig;
		delete Nodo;
	}
}


void grafo_vacio(nodo & *ini,int c[]){
	nodo *Nodo=new nodo;
	Nodo->up=NULL;
	Nodo->down=NULL;
	Nodo->right=NULL;
	Nodo->left=NULL;
	Nodo->coord[0]=c[0];
	Nodo->coord[1]=c[1];
	ini=Nodo;
}

nodo *Ini_Matriz(nodo *fila_ant,nodo *Left,int &x,int &y,int num_nodos){
	nodo *Nodo=new nodo;
	Nodo->rec=0;
	Nodo->dato=-1;
	Nodo->up=fila_ant;
	Nodo->down=NULL;
	Nodo->right=NULL;
	Nodo->left=Left;
	Nodo->coord[0]=x;
	Nodo->coord[1]=y;
	if(Left)Left->right=Nodo;
	if(fila_ant){
		fila_ant->down=Nodo;
		fila_ant=fila_ant->right;
	}
	if(x+1!=num_nodos)Ini_Matriz(fila_ant,Nodo,x+1,y,num_nodos);
	if(y+1!=num_nodos){
		while((Nodo->coord[0]!=y+1&&x!=y))Nodo=Nodo->left;
		Ini_Matriz(Nodo,NULL,y+1,y+1,num_nodos);
	}
	if(x+1==num_nodos&&y+1==num_nodos){
		while(Nodo->up)Nodo=Nodo->up;
		while(Nodo->left)Nodo=Nodo->left;
		return Nodo;
	}
}

void Ingresar_Costes(nodo * Nodo,int coste,int x,int y){
	while(x!=Nodo->coord[0]&&Nodo->right)Nodo=Nodo->right;
	while(y!=Nodo->coord[1]&&Nodo->down)Nodo=Nodo->down;
	while(y!=Nodo->coord[0]&&Nodo->right)Nodo=Nodo->right;
	Nodo->dato=coste;
}

nodo *Coste_menor(nodo * Nodo,nodo_L &*ptrhead){
	nodo *Min=Nodo;
	min=Nodo->dato;
	while(Nodo->down){
		Nodo=Nodo->down;
		if(((min>Nodo->dato&&Nodo->dato>=0)||min<0)&&(recorrer(ptrhead,Nodo->coord[0])&&recorrer(ptrhead,Nodo->coord[1]))){
			min=Nodo->dato;
			Min=Nodo;
		}
	}
	while(Nodo->right){
		Nodo=Nodo->right;
		if(((min>Nodo->dato&&Nodo->dato>=0)||min<0)&&(recorrer(ptrhead,Nodo->coord[0])&&recorrer(ptrhead,Nodo->coord[1]))){
			min=Nodo->dato;
			Min=Nodo;
		}
	}
	if(recorrer(ptrhead,Min->coord[0]))insertar_prim(Min->coord[0],ptrhead);
	if(recorrer(ptrhead,Min->coord[1]))insertar_prim(Min->coord[1],ptrhead);
	Min->rec=1;
	return Min;
}

void Prim(nodo * Nodo){
	Insertar(Coste_menor(Nodo));
	
}

//void agregar_down(int c[],nodo *fila_ant){
	//nodo *Nodo=new nodo;
	
	//while(fila_ant->right->coord[1]!=c[1])fila_ant->right;
	//Nodo->up=fila_ant;
	//Nodo->down=NULL;
	//fila_ant->down=Nodo;
	//Nodo->right=NULL;
	//Nodo->left=NULL;
//}


//void inicializar_matriz(nodo & *ini,nodo & *act,int num_nodos){
	//int c[2]={0,0};
	//nodo *fila_ant=NULL;
	//nodo *Right=NULL;
	//nodo *Left=NULL;
	//if(ini==NULL){
		//grafo_vacio(ini,c[])
	//}
	//if(act->sig==NULL&&coord[0]+1!=num_nodos){  /*Agregar Nodos a la izquierda*/
		//c[0]+=1;
		//agregar_right(act,c[],fila_ant);
	//}
	//if(){  /*Agregar Nodos Abajo*/
		//c[1]+=1;
	//}
	//insertar(ini,act)
	
//}

int main(){
	nodo *ini_G=NULL;
	nodo *ini_GF=NULL;
}

