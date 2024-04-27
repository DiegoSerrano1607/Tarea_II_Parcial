#include <iostream>

using namespace std;

// Definición de la estructura Estudiante
struct Estudiante {
    int id;
    string nom, ape;
    float notas[4];
    float promedio;
    bool aprobado;
};

main() {
    int n;
    // Solicitar al usuario la cantidad de estudiantes
    cout << "Ingrese la cantidad de estudiantes: ";
    cin >> n;
    // Crear un arreglo de estudiantes de tamaño N
    Estudiante estudiantes[n];

    // Iterar sobre cada estudiante para ingresar sus datos
    for (int i = 0; i < n; i++) {
        cout << "Ingrese el ID del estudiante " << i + 1 << ": ";
        cin >> estudiantes[i].id;
        cout << "Ingrese el nombre del estudiante " << i + 1 << ": ";
        cin >> estudiantes[i].nom;
        cout << "Ingrese el apellido del estudiante " << i + 1 << ": ";
        cin >> estudiantes[i].ape;
        
        // Solicitar e ingresar las notas del estudiante
        for (int j = 0; j < 4; j++) {
            cout << "Ingrese la nota " << j + 1 << " de " << estudiantes[i].nom << ": ";
            cin >> estudiantes[i].notas[j];
        }

        // Calcular el promedio del estudiante
        float sumaNotas = 0;
        for (int j = 0; j < 4; j++) {
            sumaNotas += estudiantes[i].notas[j];
        }
        estudiantes[i].promedio = sumaNotas / 4;

        // Determinar si el estudiante aprobó o reprobó
        if (estudiantes[i].promedio >= 60) {
            estudiantes[i].aprobado = true;
        } else {
            estudiantes[i].aprobado = false;
        }
    }

    // Mostrar los resultados
    cout << "\nResultados:" << endl;
    for (int i = 0; i < n; i++) {
    	cout<<"ID: "<<estudiantes[i].id << " " << "Estudiante " << estudiantes[i].nom << " " << estudiantes[i].ape;
        cout << " Promedio: " << estudiantes[i].promedio;
        if (estudiantes[i].aprobado) {
            cout << " (Aprobado)" << endl;
        } else {
            cout << " (Reprobado)" << endl;
        }
    }
}

