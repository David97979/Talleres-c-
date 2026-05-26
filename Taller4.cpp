#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int calcularLimiteMax(int digitos) {
	int limiteMax = 1;

	for(int i=0; i<digitos; i++) {
		limiteMax = limiteMax * 10;
	}
	limiteMax--;

	return limiteMax;

}

int* crearVector(int n) {
	int *v = new int[n];
	return v;
}

void llenarVector(int *v, int n, int limiteMax) {

	for(int i=0; i<n; i++) {
		*(v+i) = 1 + rand()%limiteMax;
	}
}
void mostrarVector(int *v,int n) {
	for(int i=0; i<n; i++) {
		cout<<*(v+i)<<"  ";
	}
	cout<<endl;
}

int** crearMatriz(int filas, int columnas) {

	int **m = new int*[filas];

	for(int i=0; i<filas; i++) {
		*(m+i) = new int[columnas];
		for(int j=0; j<columnas; j++) {
			*(*(m+i)+j) = -1;
		}
	}

	return m;
}
void mostrarMatriz(int **m, int filas, int columnas) {
	for(int i=0; i<filas; i++) {
		for(int j=0; j<columnas; j++) {
			if(*(*(m+i)+j) == -1) {
				cout<<"  -  ";
			}
			else
				cout<< *(*(m+i)+j) <<" ";

		}
		cout << endl;
	}
}

int* crearContador() {
	int *c = new int[10];
	for(int i=0; i<10; i++) {
		*(c+i)=0;
	}
	return c;
}

void llenarCubetas(int *v,int n,int **m,int *cont,int pos) {
	int divisor=1;
	for(int i=0; i<pos; i++) {
		divisor*=10;
	}
	for(int j=0; j<n; j++) {

		int numero=*(v+j);
		int fila=(numero/divisor)%10;

		int columna=*(cont+fila);

		*(*(m+fila)+columna)=numero;

		*(cont+fila)=*(cont+fila)+1;
	}
}

void reconstruirVector(int *v,int n,int **m,int *cont) {

	int k=0;
	for(int fila=0; fila<10; fila++) {
		for(int col=0; col<*(cont+fila); col++) {
			*(v+k)=*(*(m+fila)+col);
			k++;
		}
	}
}
void ordenarCubetas(int *v,int n,int digitos) {

	for(int paso=0; paso<digitos; paso++) {

		cout<<"PASO "<<paso+1<<endl;

		int **matriz=crearMatriz(10,n);
		int *contador=crearContador();

		llenarCubetas(v,n,matriz,contador,paso);

		mostrarMatriz(matriz,10,n);

		reconstruirVector(v,n,matriz,contador);

		cout<<"Vector despues del paso "<<paso+1<<": ";

		mostrarVector(v,n);

		delete[] contador;
		for(int i=0; i<10; i++) {
			delete[] *(matriz+i);
		}
		delete[] matriz;
	}
}

int main() {

	srand(time(NULL));

	int digitos,cantidad;

	cout<<"Ingrese numero de digitos: ";
	cin>>digitos;
	cout<<"Ingrese cantidad de numeros: ";
	cin>>cantidad;

	int limiteMax = calcularLimiteMax(digitos);

	cout<<"Numero maximo posible: "<<limiteMax<<endl;

	int *vector=crearVector(cantidad);

	llenarVector(vector,cantidad,limiteMax);

	cout<<"Vector original:" << endl;
	mostrarVector(vector,cantidad);

	ordenarCubetas(vector,cantidad,digitos);

	cout<<endl <<"Vector ordenado final:" << endl;
	mostrarVector(vector,cantidad);

	delete[] vector;

	return 0;
}