#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

const int MAX = 20;

// funcion para registrar los datos
void registrarDatos(string nombres[], float notas[], int& n) {
    cout << "\nCuantos estudiantes hay? (max 20): ";
    cin >> n;

    while (n < 1 || n > MAX) {
        cout << "Numero invalido, intente de nuevo: ";
        cin >> n;
    }

    cin.ignore();

    for (int i = 0; i < n; i++) {
        cout << "\nEstudiante " << i + 1 << endl;
        cout << "Nombre: ";
        getline(cin, nombres[i]);

        cout << "Calificacion: ";
        cin >> notas[i];

        while (notas[i] < 0 || notas[i] > 100) {
            cout << "Nota invalida (0-100): ";
            cin >> notas[i];
        }

        cin.ignore();
    }

    cout << "\nDatos guardados correctamente." << endl;
}

float calcPromedio(float notas[], int n) {
    float suma = 0;
    for (int i = 0; i < n; i++)
        suma += notas[i];
    return suma / n;
}

float notaAlta(float notas[], int n) {
    float mayor = notas[0];
    for (int i = 1; i < n; i++) {
        if (notas[i] > mayor)
            mayor = notas[i];
    }
    return mayor;
}

float notaBaja(float notas[], int n) {
    float menor = notas[0];
    for (int i = 1; i < n; i++) {
        if (notas[i] < menor)
            menor = notas[i];
    }
    return menor;
}

// funcion para mostrar los resultados del grupo
void mostrarDatos(string nombres[], float notas[], int n) {
    if (n == 0) {
        cout << "\nNo hay estudiantes registrados todavia." << endl;
        return;
    }

    cout << "\n--- RESUMEN DEL GRUPO ---" << endl;
    cout << "Cantidad de estudiantes: " << n << endl;
    cout << fixed << setprecision(2);
    cout << "Promedio general: " << calcPromedio(notas, n) << endl;
    cout << "Nota mas alta: " << notaAlta(notas, n) << endl;
    cout << "Nota mas baja: " << notaBaja(notas, n) << endl;
}

void verAprobados(string nombres[], float notas[], int n) {
    if (n == 0) {
        cout << "\nNo hay estudiantes registrados todavia." << endl;
        return;
    }

    cout << "\n--- ESTUDIANTES APROBADOS ---" << endl;
    int cont = 0;

    for (int i = 0; i < n; i++) {
        if (notas[i] >= 70) {
            cout << nombres[i] << " - " << fixed << setprecision(2) << notas[i] << endl;
            cont++;
        }
    }

    if (cont == 0)
        cout << "Ninguno aprobo." << endl;
    else
        cout << "Total aprobados: " << cont << endl;
}

void menu() {

	cout << "==============================" << endl;
    cout << " SISTEMA DE CALIFICACIONES" << endl;
	cout << "==============================" << endl;

    cout << "1. Registrar estudiantes" << endl;
    cout << "2. Ver promedio" << endl;
    cout << "3. Ver nota mas alta" << endl;
    cout << "4. Ver nota mas baja" << endl;
    cout << "5. Ver aprobados" << endl;
    cout << "6. Ver resumen completo" << endl;
    cout << "7. Salir" << endl;
    cout << "Opcion: ";
}

int main() {
    string nombres[MAX];
    float notas[MAX];
    int n = 0;
    int op;

	cout << "-------------------" << endl;
    cout << "=== BIENVENIDO ===" << endl;
	cout << "-------------------" << endl;

    do {
        menu();
        cin >> op;

        switch (op) {
        case 1:
            registrarDatos(nombres, notas, n);
            break;
        case 2:
            if (n == 0)
                cout << "\nPrimero registre los estudiantes." << endl;
            else
                cout << "\nPromedio: " << fixed << setprecision(2) << calcPromedio(notas, n) << endl;
            break;
        case 3:
            if (n == 0)
                cout << "\nPrimero registre los estudiantes." << endl;
            else
                cout << "\nNota mas alta: " << fixed << setprecision(2) << notaAlta(notas, n) << endl;
            break;
        case 4:
            if (n == 0)
                cout << "\nPrimero registre los estudiantes." << endl;
            else
                cout << "\nNota mas baja: " << fixed << setprecision(2) << notaBaja(notas, n) << endl;
            break;
        case 5:
            verAprobados(nombres, notas, n);
            break;
        case 6:
            mostrarDatos(nombres, notas, n);
            break;
        case 7:
            cout << "\nSaliendo del programa..." << endl;
            break;
        default:
            cout << "\nOpcion no valida." << endl;
        }

    } while (op != 7);

    return 0;
}