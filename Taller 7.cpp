#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstring>
using namespace std;

struct Mensaje
{
int id;
char* textoOriginal;
char* textoResultado;
};


void leerArchivo(Mensaje* &mensajes, int &cantidad) {
    ifstream archivo("mensajes.txt");
    if (!archivo.is_open()) {
        cout << "No se pudo abrir el archivo para lectura." << endl;
        cantidad = 0;
        return;

    }
    char temp[500];
    cantidad = 0;

    while (archivo.getline(temp,500)){
        cantidad++;
    }

    archivo.close();

    mensajes = new Mensaje[cantidad];

    archivo.open("mensajes.txt");

    int i = 0;

    while (archivo.getline(temp,500)){
       (mensajes+ i)-> id = i + 1;
        int longitud = strlen(temp);
        (mensajes+ i)->textoOriginal = new char[longitud+1];
        strcpy((mensajes+ i)->textoOriginal,temp);
        (mensajes+ i)->textoResultado = new char[longitud+1];

        i++;
    }

    archivo.close();
}
void cifrarMensaje(Mensaje &m, int desplazamiento) {

    int longitud = strlen(m.textoOriginal);

    for(int i = 0; i < longitud; i++) {

        char c = *(m.textoOriginal + i);

        if(c >= 65 && c <= 90) {
            *(m.textoResultado + i) = ((c - 65 + desplazamiento) % 26) + 65;
        }

        else if(c >= 97 && c <= 122) {
            *(m.textoResultado + i) = ((c - 97 + desplazamiento) % 26) + 97;
        }

        else {
            *(m.textoResultado + i) = c;
        }
    }

    *(m.textoResultado + longitud) = 0;
}
void descifrarMensaje(Mensaje &m, int desplazamiento) {
    int longitud = strlen(m.textoOriginal);

    for(int i = 0; i < longitud; i++) {
      char c = *(m.textoOriginal + i);

        if(c >= 65 && c <= 90) {
            *(m.textoResultado + i) = ((c - 65 - desplazamiento + 26) % 26) + 65;
        }
     
        else if(c >= 97 && c <= 122){
            *(m.textoResultado + i) = ((c - 97 - desplazamiento + 26) % 26) + 97;
        }
        else
        {
            *(m.textoResultado + i) = c;
        }
    }

    *(m.textoResultado + longitud) = 0;
}
void mostrarMensajes(Mensaje* mensajes, int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        cout << "Mensaje " << (mensajes+i)->id << endl;
        cout << "Original : " << (mensajes+i)->textoOriginal  << endl;
        cout << "Resultado: " << (mensajes+i)->textoResultado << endl;
        cout << endl;
    }
}
void liberarMemoria(Mensaje* mensajes, int cantidad)
{
    for(int i = 0; i < cantidad; i++){
        delete[] (mensajes+i)->textoOriginal;
        delete[] (mensajes+i)->textoResultado;
    }

    delete[] mensajes;
}

int main()
{
    Mensaje* mensajes = NULL;
    int cantidad;
    int desplazamiento;
    int opcion = -1;

    cout << "Ingrese el numero de desplazamiento: ";
    cin >> desplazamiento;

    while (opcion != 0) {

        cout << endl << "--------Menu--------" << endl;
        cout << "1. Encriptar mensaje" << endl;
        cout << "2. Desencriptar mensaje" << endl;
        cout << "0. Salir" << endl;
        cin >> opcion;

        switch(opcion) {

        case 1:
            leerArchivo(mensajes, cantidad);

            for(int i = 0; i < cantidad; i++){
                cifrarMensaje(*(mensajes+i), desplazamiento);
            }

            mostrarMensajes(mensajes, cantidad);
            liberarMemoria(mensajes, cantidad);

            break;

        case 2:
            leerArchivo(mensajes, cantidad);

            for(int i = 0; i < cantidad; i++){
                descifrarMensaje(*(mensajes+i), desplazamiento);
            }

            mostrarMensajes(mensajes, cantidad);
            liberarMemoria(mensajes, cantidad);

            break;
        }
    }

    return 0;
}

  