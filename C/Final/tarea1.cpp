#include <iostream>
using namespace std;
int contador_repetidas(int *arreglo,int tamanno,int elemento){
    int cantidad=0;
    for (int i=0;i<tamanno;i++){
        if (arreglo[i]==elemento) cantidad++;
        }
    return cantidad;
    }
bool verificar_repetida(int *arreglo_1,int tamanno_1,int *arreglo_2, int tamanno_2){
    for (int i=0;i<tamanno_1;i++){
        if ((contador_repetidas(arreglo_1,tamanno_1,arreglo_1[i]) )> (contador_repetidas(arreglo_2,tamanno_2,arreglo_1[i])) )return true;
        }

    return false;
    }
int contar(int *arreglo,int tamanno){
    int contador=0;
    for (int i=0;i<tamanno;i++){
        if (arreglo[i]==0) break;
        else contador++;
    }
    return contador;
    }

int sumar(int *arreglo,int tamanno){
    int suma=0;
    for(int i=0;i<tamanno;i++)suma=suma+arreglo[i];
    return suma;
        }

void backtrack(int cassete,int n,int *list_canc,int tamano_list_canc,int *arreglo_prov,int tamano_arreglo_prov,int pos,int *arreglo_final, int tamano_arreglo_final){
    static int suma_max=0;

    for (int indice_elem=0;indice_elem<contar(list_canc,tamano_list_canc);indice_elem++){
      arreglo_prov[pos]=list_canc[indice_elem];
      if (contar(arreglo_prov,tamano_arreglo_prov)!=n){
          backtrack(cassete,n,list_canc,tamano_list_canc,arreglo_prov,tamano_arreglo_prov,pos+1,arreglo_final,tamano_arreglo_final);
          arreglo_prov[pos+1]=0;
          }

      else {
        if (verificar_repetida(arreglo_prov,contar(arreglo_prov,tamano_arreglo_prov),list_canc,contar(list_canc,tamano_list_canc))) continue;

        if ((sumar(arreglo_prov,tamano_arreglo_prov)<=cassete)&&(suma_max<=sumar(arreglo_prov,tamano_arreglo_prov))) {
            suma_max=sumar(arreglo_prov,tamano_arreglo_prov);
            for (int i=0;i<tamano_arreglo_prov;i++) arreglo_final[i]=arreglo_prov[i];
            arreglo_final[tamano_arreglo_final-1]=suma_max;
            continue;
        }
      }

    }

}



int main(){
    int cassete;
    int list_canc[20];
    int arreglo_out[]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    int arreglo_prov[]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};  /*se usa como pase entre la lsita de canciones y el arreglo final, que contiene la respuesta*/
    int pos=0;
    const int tamano_prov=20;
    const int tamano_out=21;


    cout<<"Bienvenido,ingrese largo del cassette:"<<endl;
    cin>>cassete;
    cout<<"Ingrese la duracion de las canciones a grabar (Cuando no quiera ingresar mas canciones, ingrese 0 (cero))"<<endl;
    for (int i=0;i<20;i++){
        cout<<"Cancion "<<i+1<<":";
        cin>>list_canc[i];
        if (list_canc[i]==0){
            for (int j=i+1;j<20;j++) list_canc[j]=0;
            break;
            }
        }

    int cant_canciones=contar(list_canc,20);
    for (int k=2;k<=cant_canciones;k++){
        backtrack(cassete,k,list_canc,20,arreglo_prov,tamano_prov,pos,arreglo_out,tamano_out);
        for (int rellenar=0;rellenar<20;rellenar++)arreglo_prov[rellenar]=0;
        }

    for (int imprimir=0;imprimir<=tamano_out;imprimir++){
        if (arreglo_out[imprimir]==0) {
            cout<<"Duracion: "<<arreglo_out[tamano_out-1]<<endl;
            break;
        }
        cout<<arreglo_out[imprimir]<<" ";
    }
    return 0;

}
