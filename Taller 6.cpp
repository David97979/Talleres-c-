#include <iostream>
using namespace std;

int main() {
    int num1, num2, num3;
    cout << "Ingrese el primer número: ";
    cin >> num1;
    cout << "Ingrese el segundo número: ";
    cin >> num2;
    cout << "Ingrese el tercer número: ";
    cin >> num3;

    if (num1 > num2 && num1 > num3) {
        cout << "El número mayor es: " << num1 << endl;
    } else if (num2 > num1 && num2 > num3) {
        cout << "El número mayor es: " << num2 << endl;
    } else {
        cout << "El número mayor es: " << num3 << endl;
    }

    return 0;
}