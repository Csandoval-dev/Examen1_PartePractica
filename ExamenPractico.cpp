#include<iostream>
using namespace std;

// Definición de la estructura Nodo
struct Nodo {
    int dato;
    Nodo *siguiente;
};

// Declaración de funciones
void agregar(Nodo *&, int);
void sacar(Nodo *&, int &);
bool lista_vacia(Nodo *);
int contar_cajas(Nodo *);

// Función principal
int main() {
    Nodo *pila = NULL; // Inicialización de la pila
    int opcion, dato;
    int cajas_despachadas = 0;

    do {
        cout << "Menu de opciones:" << endl;
        cout << "1. Ingresar caja" << endl;
        cout << "2. Despachar caja" << endl;
        cout << "3. Mostrar cajas disponibles" << endl;
        cout << "4. Mostrar cajas despachadas" << endl;
        cout << "5. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingrese el codigo de la caja (EAN-8): ";
                cin >> dato;
                agregar(pila, dato);
                break;
            case 2:
                if (!lista_vacia(pila)) {
                    sacar(pila, dato);
                    cout << "Caja con codigo " << dato << " despachada." << endl;
                    cajas_despachadas++;
                } else {
                    cout << "No hay cajas para despachar." << endl;
                }
                break;
            case 3:
                cout << "Cajas disponibles: " << contar_cajas(pila) << endl;
                break;
            case 4:
                cout << "Cajas despachadas: " << cajas_despachadas << endl;
                break;
            case 5:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opcion invalida, intente nuevamente." << endl;
        }
    } while (opcion != 5);

    return 0;
}

// Función para agregar una caja (push)
void agregar(Nodo *&pila, int n) {
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->dato = n;
    nuevo_nodo->siguiente = pila;
    pila = nuevo_nodo;
    cout << "Elemento " << n << " agregado correctamente." << endl;
}

// Función para sacar una caja (pop)
void sacar(Nodo *&pila, int &n) {
    Nodo *aux = pila;
    n = aux->dato;
    pila = aux->siguiente;
    delete aux;
}

// Función para verificar si la lista está vacía
bool lista_vacia(Nodo *pila) {
    return (pila == NULL);
}

// Función para contar las cajas disponibles en la pila
int contar_cajas(Nodo *pila) {
    int contador = 0;
    Nodo *aux = pila;
    while (aux != NULL) {
        contador++;
        aux = aux->siguiente;
    }
    return contador;
}
