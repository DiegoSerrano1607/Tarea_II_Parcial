#include <iostream>
using namespace std;

// Definición de la estructura Estudiante
struct Estudiante {
    int id;
    string nombre;
    string apellido;
    float notas[4];
    float promedio;
    bool aprobado;
};

// Función para ingresar datos de un estudiante
void ingresarDatosEstudiante(Estudiante *estudiante) {
    cout << "Ingrese el ID del estudiante: ";
    cin >> estudiante->id; // Se accede al miembro id de la estructura usando un puntero
    cout << "Ingrese el nombre del estudiante: ";
    cin >> estudiante->nombre; // Se accede al miembro nombre de la estructura usando un puntero
    cout << "Ingrese el apellido del estudiante: ";
    cin >> estudiante->apellido; // Se accede al miembro apellido de la estructura usando un puntero

    // Solicitar e ingresar las notas del estudiante
    for (int i = 0; i < 4; i++) {
        cout << "Ingrese la nota " << i + 1 << " de " << estudiante->nombre <<" : ";
        cin >> *(estudiante->notas + i); // Se accede al arreglo de notas usando un puntero
    }
}

// Función para calcular el promedio de un estudiante
void calcularPromedio(Estudiante *estudiante) {
    float sumaNotas = 0;
    for (int i = 0; i < 4; i++) {
        sumaNotas += *(estudiante->notas + i); // Se accede al arreglo de notas usando un puntero
    }
    estudiante->promedio = sumaNotas / 4; // Se asigna el promedio al miembro promedio de la estructura usando un puntero
}

// Función para determinar si un estudiante aprobó o reprobó
void determinarAprobacion(Estudiante *estudiante) {
    if (estudiante->promedio >= 60) { // Se accede al miembro promedio de la estructura usando un puntero
        estudiante->aprobado = true; // Se asigna el valor al miembro aprobado de la estructura usando un puntero
    } else {
        estudiante->aprobado = false; // Se asigna el valor al miembro aprobado de la estructura usando un puntero
    }
}

int main() {
    int N;

    // Solicitar al usuario la cantidad de estudiantes
    cout << "Ingrese la cantidad de estudiantes: ";
    cin >> N;

    // Crear un arreglo dinámico de estudiantes
    Estudiante *estudiantes = new Estudiante[N]; // Se utiliza un puntero para asignar memoria dinámica

    // Iterar sobre cada estudiante para ingresar sus datos
    for (int i = 0; i < N; ++i) {
        ingresarDatosEstudiante(&estudiantes[i]); // Se pasa la dirección de memoria de cada estudiante a la función
        calcularPromedio(&estudiantes[i]); // Se pasa la dirección de memoria de cada estudiante a la función
        determinarAprobacion(&estudiantes[i]); // Se pasa la dirección de memoria de cada estudiante a la función
    }

    // Mostrar los resultados
    cout << "\nResultados:" << endl;
    for (int i = 0; i < N; i++) {
        cout << "Estudiante " << i + 1 << ": " << estudiantes[i].nombre << " " << estudiantes[i].apellido;
        cout << ", ID: " << estudiantes[i].id << ", Promedio: " << estudiantes[i].promedio;
        if (estudiantes[i].aprobado) {
            cout << " (Aprobado)" << endl;
        } else {
            cout << " (Reprobado)" << endl;
        }
    }

    // Liberar la memoria del arreglo dinámico
    delete[] estudiantes; // Se libera la memoria asignada dinámicamente

    return 0;
}

