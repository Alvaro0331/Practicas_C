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
void eliminar_nodo();
void eliminar_arista();
void mostrar_grafo();
void mostrar_aristas();
void eliminar_aristas_nodo(Tnodo nodo);

int main(int argc, char *argv[]){
    p=NULL;
    int op=0;
    while(op!=7){
        menu();
        cout.flush();
        cin>>op;
        switch(op){
            case 1: insertar_nodo();break;
            case 2: insertar_arista(); break;
            case 3: eliminar_nodo(); break;
            case 4: eliminar_arista(); break;
            case 5: mostrar_grafo(); break;
            case 6: mostrar_aristas(); break;
            case 7: break;
            default: cout<<"OPCION NO VALIDA"; break;
            }
            cout<<endl;
            system("pause"); system("cls");
    }
    system("PAUSE");
    return 0;
}

void menu(){
    cout<<"\n\t GRAFOS DIRIGIDO \n\n";
    cout<<" 1. INSERTAR UN NODO "<<endl;
    cout<<" 2. INSERTAR UNA ARISTA "<<endl;
    cout<<" 3. ELIMINAR UN NODO "<<endl;
    cout<<" 4. ELIMINAR UNA ARISTA "<<endl;
    cout<<" 5. MOSTRAR GRAFO "<<endl;
    cout<<" 6. MOSTRAR ARISTAS DE UN NODO "<<endl;
    cout<<" 7. SALIR "<<endl;
    cout<<" INGRESE OPCION: ";
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

void eliminar_arista(){
    char ini, fin;
    cout << "INGRESE NODO DE INICIO: ";
    cin >> ini;
    cout << "INGRESE NODO FINAL: ";
    cin >> fin;

    Tnodo aux = p;

    // Buscar el nodo de inicio en la lista de nodos
    while (aux != NULL) {
        if (aux->nombre == ini) {
            Tarista actual = aux->adyacencia;
            Tarista anterior = NULL;

            // Recorrer la lista
            while (actual != NULL) {
                if (actual->destino->nombre == fin) {
                    // Si la arista es la primera en la lista de adyacencias
                    if (anterior == NULL) {
                        aux->adyacencia = actual->siguiente;
                    } else {
                        anterior->siguiente = actual->siguiente;
                    }
                    delete actual; // Eliminar la arista
                    cout << "ARISTA ELIMINADA CORRECTAMENTE." << endl;
                    return;
                }
                anterior = actual;
                actual = actual->siguiente;
            }
            cout << "LA ARISTA NO EXISTE EN ESTE NODO." << endl;
            return;
        }
        aux = aux->siguiente;
    }
    cout << "NODO INICIO NO ENCONTRADO." << endl;
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

void eliminar_nodo(){
    char nombre;
    cout << "INGRESE EL NODO A ELIMINAR: ";
    cin >> nombre;

    Tnodo aux = p, anterior = NULL;

    // Buscar el nodo en la lista de nodos
    while (aux != NULL) {
        if (aux->nombre == nombre) {
            //Eliminar aristas del nodo
            eliminar_aristas_nodo(aux);
            Tarista arista = aux->adyacencia;
            while (arista != NULL) {
                Tarista temp = arista;
                arista = arista->siguiente;
                delete temp;
            }

            //Eliminar el nodo de la lista
            if (anterior == NULL) {
                p = aux->siguiente; //Primer elemento
            } else {
                anterior->siguiente = aux->siguiente;
            }

            delete aux; // Eliminar el nodo
            cout << "NODO ELIMINADO CORRECTAMENTE." << endl;
            return;
        }
        anterior = aux;
        aux = aux->siguiente;
    }
    cout << "NODO NO ENCONTRADO." << endl;
}

void eliminar_aristas_nodo(Tnodo nodo){
    Tnodo aux = p; // Apunta al primer nodo del grafo

    while (aux != NULL) {
        Tarista actual = aux->adyacencia;
        Tarista anterior = NULL;

        while (actual != NULL) {
            if (actual->destino == nodo) {
                //Buscar si la arista es la primera
                if (anterior == NULL) {
                    aux->adyacencia = actual->siguiente;
                } else {
                    anterior->siguiente = actual->siguiente;
                }
                delete actual; // Eliminar la arista
                actual = (anterior == NULL) ? aux->adyacencia : anterior->siguiente;
            } else {
                anterior = actual;
                actual = actual->siguiente;
            }
        }
        aux = aux->siguiente;
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

void mostrar_aristas(){
    char nodo;
    cout << "INGRESE EL NODO A CONSULTAR: ";
    cin >> nodo;

    Tnodo aux = p;

    // Buscar el nodo en la lista de nodos
    while (aux != NULL) {
        if (aux->nombre == nodo) {
            cout << "NODO " << nodo << " | LISTA DE ADYACENCIA: ";
            
            // Verificar si tiene aristas
            if (aux->adyacencia == NULL) {
                cout << "SIN ARISTAS." << endl;
                return;
            }

            Tarista arista = aux->adyacencia;
            while (arista != NULL) {
                cout << arista->destino->nombre << " ";
                arista = arista->siguiente;
            }
            cout << endl;
            return;
        }
        aux = aux->siguiente;
    }

    cout << "NODO NO ENCONTRADO." << endl;
}