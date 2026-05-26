#include <iostream>
#include <cstring>
using namespace std;

struct ESTRUCTURAESTUDIANTES
{
    int  codigo;
    char nombres[1000];
	char carrera[1000];
    char fechanacimiento[1000];
    char datosacademicos[1000];

};



void indice estudiante[50];

void agregarestudiante(ESTRUCTURAESTUDIANTES estudiante[], int n) {

    int cod[10];
    char nbr[1000];
    char carr[1000];
    char fechanac[1000];
    char datosac[1000];
    for(int i=0; i<n; i++) {
        cout << "Ingrese el codigo del estudiante " <<  endl;
        cin >> cod;
        cout << "Ingrese nombres del estudiante" << i+1 << endl;
        cin >> nbr;
        strcpy(estudiante[i].nombres, nbr);
        cout << "Ingrese carrera del estudiantes" << endl;
        cin >> carr;
        strcpy(estudiante[i].carrera, carr);
        cout << "Ingrese la fecha de nacimiento del estudiante" << endl;
        cin >> fechanac;
        strcpy(estudiante[i].fechanacimiento, fechanac);
        cout << "Ingrese los datos academicos del estudiante" << endl;
        cin >> datosac;
        strcpy(estudiante[i].datosacademicos, datosac);
        strcat(estudiante[i].datosacademicos, "_2025");
   }
}

int main(){
ESTRUCTURAESTUDIANTES* apestudiante;
apestudiante = new estudiantes;
}

    
