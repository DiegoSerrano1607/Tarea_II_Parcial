#include <iostream>
using namespace std; 
const char *nombre_archivo = "notas.dat";
struct Estudiante {
    int id;
    char nom[25];
	char ape[25];
    float notas[4];
    float promedio;
    bool aprobado;
};
void Leer();
void Crear();
void Actualizar();
void Borrar();
main(){
	Leer();
	Crear();
	Borrar();
	Actualizar();
	system("pause");
}
void Leer(){
	system("cls");
	FILE* archivo = fopen(nombre_archivo,"rb");	
	if(!archivo){
		archivo = fopen(nombre_archivo,"w+b");
	}
	Estudiante estudiante;
	int id=0; //indice de los registros 
	fread(&estudiante,sizeof(Estudiante),1,archivo);
	cout<<"___________________________________________"<<endl;
	cout<<"id"<<" | "<<"ID Interno"<<" | "<<"Nombre"<<" | "<<"Apellido"<<" | "<<"Nota 1"<<" | "<<"Nota 2"<<" | "<<"Nota 3"<<" | "<<"Nota 4"<<" | "<<"Promedio"<<" | "<<"Resultado"<<" | "<<endl;
	do{
		cout<<id<<" | "<<estudiante.id<<" | "<<estudiante.nom<<" | "<<estudiante.ape<<" | "<<estudiante.notas[0]<<" | "<<estudiante.notas[1]<<" | "<<estudiante.notas[2]<<" | "<<estudiante.notas[3]<<" | "<<"Prom: "<<estudiante.promedio<<" | "<<estudiante.aprobado<<endl;
		fread(&estudiante,sizeof(Estudiante),1,archivo);
		id+=1;
	}while(feof(archivo)==0);
	fclose(archivo);
}
void Crear(){
	FILE* archivo = fopen(nombre_archivo,"a+b");
	char res;
	Estudiante estudiante;
	do{
		fflush(stdin);
		cout<<"Ingrese ID interno: ";
		cin>>estudiante.id;
		cin.ignore();
		
		cout<<"Ingrese el nombre: ";
		cin.getline(estudiante.nom,25);
		
		cout<<"Ingrese el apellido: ";
		cin.getline(estudiante.ape,25);
		
		cout<<"Ingrese nota 1: ";
		cin>>estudiante.notas[0];
		
		cout<<"Ingrese nota 2: ";
		cin>>estudiante.notas[1];
		
		cout<<"Ingrese nota 3: ";
		cin>>estudiante.notas[2];
		
		cout<<"Ingrese nota 4: ";
		cin>>estudiante.notas[3];
		
		// Calcular el promedio del estudiante
        float sumaNotas = 0;
        for (int j = 0; j < 4; j++) {
            sumaNotas += estudiante.notas[j];
        }
        estudiante.promedio = sumaNotas / 4;

        // Determinar si el estudiante aprobó o reprobó
        if (estudiante.promedio >= 60) {
            estudiante.aprobado = "APROBADO";
        } else {
            estudiante.aprobado = "REPROBADO";
        }
		
		fwrite(&estudiante,sizeof(Estudiante),1,archivo);
		cout<<"Desea ingresar datos de un estudiante?(s/n): ";
		cin>>res;
	}while(res=='s' || res=='S');
	fclose(archivo);
	Leer();
}
void Actualizar(){
	
	FILE* archivo = fopen(nombre_archivo,"r+b");
	Estudiante estudiante;
	int id=0;
	cout<<"Ingrese el id que desea modificar: ";
	cin>>id;
	fseek(archivo,id * sizeof(Estudiante),SEEK_SET);
	
		cout<<"Ingrese ID interno: ";
		cin>>estudiante.id;
		cin.ignore();
		
		cout<<"Ingrese el nombre: ";
		cin.getline(estudiante.nom,25);
		
		cout<<"Ingrese el apellido: ";
		cin.getline(estudiante.ape,25);
		
		cout<<"Ingrese nota 1: ";
		cin>>estudiante.notas[0];
		
		cout<<"Ingrese nota 2: ";
		cin>>estudiante.notas[1];
		
		cout<<"Ingrese nota 3: ";
		cin>>estudiante.notas[2];
		
		cout<<"Ingrese nota 4: ";
		cin>>estudiante.notas[3];
		
		// Calcular el promedio del estudiante
        float sumaNotas = 0;
        for (int j = 0; j < 4; j++) {
            sumaNotas += estudiante.notas[j];
        }
        estudiante.promedio = sumaNotas / 4;

        // Determinar si el estudiante aprobó o reprobó
        if (estudiante.promedio >= 60) {
            estudiante.aprobado = "APROBADO";
        } else {
            estudiante.aprobado = "REPROBADO";
        }
		
		fwrite(&estudiante,sizeof(Estudiante),1,archivo);

	fclose(archivo);
	Leer();
}
void Borrar(){
	const char *nombre_archivo_temp = "notas_temp.dat";
	FILE* archivo_temp = fopen(nombre_archivo_temp,"w+b");	
	FILE* archivo = fopen(nombre_archivo,"rb");	
	Estudiante estudiante;
	int id=0,id_n=0;
	cout<<"Ingrese el id a eliminar: ";
	cin>>id;
	while(fread(&estudiante,sizeof(Estudiante),1,archivo)){
		if(id_n !=id ){
			fwrite(&estudiante,sizeof(Estudiante),1,archivo_temp);
		}
		id_n++;	
	}
	fclose(archivo);
	fclose(archivo_temp);
	
	archivo_temp = fopen(nombre_archivo_temp,"rb");	
	archivo = fopen(nombre_archivo,"wb");
	while(fread(&estudiante,sizeof(Estudiante),1,archivo_temp)){
		fwrite(&estudiante,sizeof(Estudiante),1,archivo);
		
	}
	fclose(archivo);
	fclose(archivo_temp);
	Leer();	
}
