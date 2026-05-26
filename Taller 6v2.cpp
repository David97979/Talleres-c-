#include<iostream>
#include <iomanip>
#include <fstream>
using namespace std;

struct estructuraMueble{
    string tipo;
    float precioUnitario;
    int unidades;
    float costoProduccion;
    float costoTotal;
    float ingresoTotal;
    float utilidadneta; //(ingresototal - costototal)
};
struct estructuraEmpleado {
    int id;
    string nombre;
    string apellido;
    float salario;
    float porcentajeAumento;
    float nuevoSalario;
    
};
struct estructuraestudiantes {
    char nombre[30];
    short int edad;
    float promedio;
};


void pedirpeso(){
float peso = 0;
float libras = 0;

ofstream archivopeso("peso.txt"); // Crea o sobrescribe el archivo
    if (!archivopeso.is_open()) {
        cout << "No se pudo abrir el archivo para escritura." << endl;
        return;
    }
    cout << "Porfavor ingrese su peso en kilogramos:" << endl;
    cin >> peso;

    archivopeso << peso << " kg" << endl;
    libras = peso * 2.2;
    archivopeso<< libras << " lbs" << endl;

    archivopeso.close(); // Siempre cerrar el archivo
}


void AbrirEmpleados (){ 
ifstream archivoEmpleados("empleados.txt"); //archivo de entrada

    if (!archivoEmpleados.is_open()) {
        cout << "No se pudo abrir el archivo para lectura." << endl;
        return;
    }
   estructuraEmpleado empleados[100];
    int n = 0;  
    

    cout << "Contenido del archivo:" << endl;
    while(archivoEmpleados >> empleados[n].id >> empleados[n].nombre >> empleados[n].apellido >> empleados[n].salario >> empleados[n].porcentajeAumento){
        empleados[n].nuevoSalario = empleados[n].salario + (empleados[n].salario * empleados[n].porcentajeAumento / 100);
        n++;
    }
    

    archivoEmpleados.close();
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-1-i; j++){

            if(empleados[j].nuevoSalario < empleados[j+1].nuevoSalario){
                estructuraEmpleado temp;
                temp = empleados[j];
                empleados[j] = empleados[j+1];
                empleados[j+1] = temp;
            }
        }
    }
               
 ofstream archivoAumentos("aumentos.txt");
    
    if (!archivoAumentos.is_open()) {
        cout << "No se pudo abrir el archivo para escritura." << endl;
        return;
    }
     for (int i = 0; i < n; i++) {

    archivoAumentos << right << setw(3) << empleados[i].id << " "
                    << left << setw(20) << empleados[i].nombre
                    << left << setw(20) << empleados[i].apellido
                    << right << setw(15) << fixed << setprecision(4) << empleados[i].nuevoSalario
                    << endl;
     cout << empleados[i].id << "  ";
     cout << empleados[i].nombre  << "  ";
     cout << empleados[i].apellido  << "  ";
     cout << empleados[i].nuevoSalario << endl;
     
     }
   
    archivoAumentos.close(); 

}

void muebles(){
    int n;
    cout << "Ingrese numero de muebles: ";
    cin >> n;
    estructuraMueble muebles[100];

    for(int i = 0; i < n; i++){

        cout << "Tipo: ";
        cin >> muebles[i].tipo;

        cout << "Precio unitario: ";
        cin >> muebles[i].precioUnitario;

        cout << "Unidades vendidas: ";
        cin >> muebles[i].unidades;

        cout << "Costo produccion por unidad: ";
        cin >> muebles[i].costoProduccion;

        muebles[i].costoTotal = muebles[i].costoProduccion * muebles[i].unidades;
        muebles[i].ingresoTotal = muebles[i].precioUnitario * muebles[i].unidades;
        muebles[i].utilidadneta = muebles[i].ingresoTotal - muebles[i].costoTotal;
    }
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-1-i; j++){
            if(muebles[j].utilidadneta < muebles[j+1].utilidadneta){
                estructuraMueble temp;
                temp = muebles[j];
                muebles[j] = muebles[j+1];
                muebles[j+1] = temp;
            }
        }
    }
    ofstream archivoReporte("reporte.txt");

    if(!archivoReporte.is_open()){
        cout << "No se pudo crear reporte.txt"<< endl;
        return;
    }

    archivoReporte << left << setw(12) << "Tipo"
            << right << setw(10) << "Unidades"
            << setw(12) << "Precio"
            << setw(14) << "CostoTotal"
            << setw(15) << "IngresoTotal"
            << setw(12) << "Utilidad" << endl;

    for(int i = 0; i < n; i++){

        archivoReporte << left << setw(12) << muebles[i].tipo
                << right << setw(10) << muebles[i].unidades
                << setw(12) << muebles[i].precioUnitario
                << setw(14) << fixed << setprecision(2)<< muebles[i].costoTotal
                << setw(15) << fixed << setprecision(2)<< muebles[i].ingresoTotal
                << setw(12) << fixed << setprecision(2)<< muebles[i].utilidadneta
                << endl;
    }

    archivoReporte.close();
}

void registroestudiantes(){
    int cantidad;
    cout << "Ingrese la cantidad de estudiantes a registrar: ";
    cin >> cantidad;
    cin.ignore(); 

    
    
    ofstream archivo("estudiantes.dat", ios::binary);
    if(!archivo.is_open()){
        cout << "No se pudo abrir estudiantes.dat para escritura." << endl;
        return;
    }
    for (int i = 0; i < cantidad; ++i) {

        estructuraestudiantes estudiantes;

        cout << "Estudiante #" << (i + 1) << ":"<< endl;

        cout << "Nombre: ";
        cin.getline(estudiantes.nombre, 30);

        cout << "Edad: ";
        cin >> estudiantes.edad;

        cout << "Promedio: ";
        cin >> estudiantes.promedio;

        cin.ignore();  // Limpiar buffer

        archivo.write((char*)&estudiantes, sizeof(estructuraestudiantes));
    }
    archivo.close();
    ifstream lecturaestudiantes("estudiantes.dat", ios::binary);

    if (!lecturaestudiantes.is_open()) {
        cout << "No se pudo abrir el archivo para lectura." << endl;
        return;
    }

    cout << endl <<  "--------Estudiantes con promedio mayor a 4.0--------" << endl;

    estructuraestudiantes estudiantes;

    while (lecturaestudiantes.read((char*)&estudiantes, sizeof(estructuraestudiantes))) {

        if (estudiantes.promedio > 4.0) {
            cout << "Nombre: " << estudiantes.nombre << endl;
            cout << "Promedio: " << estudiantes.promedio << endl;
        }
    }

    lecturaestudiantes.close();

}


int main() {    
    int opcion = -1;

	while(opcion !=0) {
		cout << endl<<  "--------Menu--------" << endl ;
		cout << "1. Crear un archivo donde guarde el peso"<<endl;
		cout << "2. Abrir archivo de empleados y crear archivo de aumentos (Porfavor al crear el empleados no poner ningun caracter especial ) "<<endl;
		cout << "3. Hacer un reporte de muebles y ordenarlos por  mayor utilidad"<<endl;
		cout << "4. Crear un registro de estudiantes y mostrar los que tienen promedio mayor a 4.0"<< endl;
		cout << "Presione 0 para acabar el programa" << endl;
		cin >> opcion;
		
		switch(opcion) {
		case 1 :
			pedirpeso();
			break;
		case 2 :
            AbrirEmpleados();
			break;
		case 3 :
			muebles();
			break;
		case 4 :
			registroestudiantes();
			break;

		}
			
		
	}
	
    return 0;

}