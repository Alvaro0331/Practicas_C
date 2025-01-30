#include <iostream>
#include <iostream>
using namespace std;

struct nodo{
    char nombre;//nombre del vertice o nodo
    struct nodo *siguiente;
    struct arista *adyacencia;//puntero - primera arista del nodo
};

struct arista{
    struct nodo *destino;//puntero al nodo llegada
    struct arista *siguiente;
};

typedef struct nodo *Tnodo;// Nodo
typedef struct arista *Tarista; // Arista

Tnodo p;//puntero cabeza

void menu();
void insertar_nodo();
void agrega_arista(Tnodo &, Tnodo &, Tarista &);
void insertar_arista();
void vaciar_aristas(Tnodo &);
////void eliminar_nodo();
//void eliminar_arista();
void mostrar_grafo();
//void mostrar_aristas();

int main(int argc, char *argv[]){
    p=NULL;
    int op;
    while(op!=7){
        menu();
        cin>>op;
        switch(op){
            case 1: insertar_nodo();break;
            case 2: insertar_arista(); break;
            // case 3: eliminar_nodo(); break;
            // case 4: eliminar_arista(); break;
            case 5: mostrar_grafo(); break;
            // case 6: mostrar_aristas(); break;
            case 7: break;
            default: cout<<"OPCION NO VALIDA"; break;
            }
            cout<<endl<<endl;
            system("pause"); system("cls");
    }
    system("PAUSE");
    return 0;
}

void menu(){
    cout<<"\n\t GRAFOS DIRIGIDO \n\n";
    cout<<" 1. INSERTAR UN NODO "<<endl;
    cout<<" 2. INSERTAR UNA ARISTA "<<endl;
    //cout<<" 3. ELIMINAR UN NODO "<<endl;
    //cout<<" 4. ELIMINAR UNA ARISTA "<<endl;
    cout<<" 5. MOSTRAR GRAFO "<<endl;
    //cout<<" 6. MOSTRAR ARISTAS DE UN NODO "<<endl;
    cout<<" 7. SALIR "<<endl;
    cout<<"\n INGRESE OPCION: ";
}

void insertar_nodo(){
    Tnodo t,nuevo=new struct nodo;
    cout<<"INGRESE VARIABLE:";
    cin>>nuevo->nombre;
    nuevo->siguiente = NULL;
    nuevo->adyacencia=NULL;
    if(p==NULL){
        p = nuevo;
        cout<<"PRIMER NODO";
    }else {
        t = p;
        while(t->siguiente!=NULL){
        t = t->siguiente;
        }   
    t->siguiente = nuevo;
    cout<<"NODO INGRESADO";
    }
}

void agrega_arista(Tnodo &aux, Tnodo &aux2, Tarista &nuevo) {
    Tarista q;
    if(aux->adyacencia==NULL){
        aux->adyacencia=nuevo;
        nuevo->destino=aux2;
        cout<<"PRIMERA ARISTA";
    }
    else{
        q=aux->adyacencia;
        while(q->siguiente!=NULL)
            q=q->siguiente;
        nuevo->destino=aux2;
        q->siguiente=nuevo;
        cout<<"ARISTA AGREGADA";
    }
}

void insertar_arista(){
    char ini, fin;
    Tarista nuevo=new struct arista;
    Tnodo aux, aux2;
    if(p==NULL) { cout<<"GRAFO VACIO"; return;}
    nuevo->siguiente=NULL;
    cout<<"INGRESE NODO DE INICIO:";
    cin>>ini;
    cout<<"INGRESE NODO FINAL:";
    cin>>fin;
    aux=p;
    aux2=p;
    while(aux2!=NULL){
        if(aux2->nombre==fin) { break;}
        aux2=aux2->siguiente;
    }
    while(aux!=NULL){
        if(aux->nombre==ini){
            agrega_arista(aux,aux2, nuevo);
            return;
        }
        aux = aux->siguiente;
    }
}

void vaciar_aristas(Tnodo &aux){
    Tarista q,r;
    q=aux->adyacencia;
    while(q->siguiente!=NULL){
        r=q;
        q=q->siguiente;
        delete(r);
    }
}

void mostrar_grafo(){
    Tnodo ptr;
    Tarista arista;
    ptr=p;
    cout<<"NODO|LISTA DE ADYACENCIA\n";
    while(ptr!=NULL){
        cout<<" "<<ptr->nombre<<"|";
        if(ptr->adyacencia!=NULL){
            arista=ptr->adyacencia;
            while(arista!=NULL){
                cout<<" "<<arista->destino->nombre;
                arista=arista->siguiente;
            }

        }
         ptr=ptr->siguiente;
        cout<<endl;
    }
}