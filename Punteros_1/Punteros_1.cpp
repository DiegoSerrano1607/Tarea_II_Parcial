#include <iostream>
using namespace std;

// Definici�n de la estructura Estudiante
struct Estudiante {
    int id;
    string nombre;
    string apellido;
    float notas[4];
    float promedio;
    bool aprobado;
};

// Funci�n para ingresar datos de un estudiante
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

// Funci�n para calcular el promedio de un estudiante
void calcularPromedio(Estudiante *estudiante) {
    float sumaNotas = 0;
    for (int i = 0; i < 4; i++) {
        sumaNotas += *(estudiante->notas + i); // Se accede al arreglo de notas usando un puntero
    }
    estudiante->promedio = sumaNotas / 4; // Se asigna el promedio al miembro promedio de la estructura usando un puntero
}

// Funci�n para determinar si un estudiante aprob� o reprob�
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

    // Crear un arreglo din�mico de estudiantes
    Estudiante *estudiantes = new Estudiante[N]; // Se utiliza un puntero para asignar memoria din�mica

    // Iterar sobre cada estudiante para ingresar sus datos
    for (int i = 0; i < N; ++i) {
        ingresarDatosEstudiante(&estudiantes[i]); // Se pasa la direcci�n de memoria de cada estudiante a la funci�n
        calcularPromedio(&estudiantes[i]); // Se pasa la direcci�n de memoria de cada estudiante a la funci�n
        determinarAprobacion(&estudiantes[i]); // Se pasa la direcci�n de memoria de cada estudiante a la funci�n
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

    // Liberar la memoria del arreglo din�mico
    delete[] estudiantes; // Se libera la memoria asignada din�micamente

    return 0;
}

