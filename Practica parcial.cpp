#include <iostream>
using namespace std;
struct Provincia {
    string nombre;
    int poblacion;
    float porcentaje;
};
struct Pais {
    string nombre;
    int cantProvincias;
    int poblacionTotal; // Inicia en 0 
};
struct ResultadoPoblacion {
    string nombreProvincia;
    string nombrePais;
    float porcentajeMaximo;
};

