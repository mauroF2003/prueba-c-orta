#include <iostream>
using namespace std; 
const char *nombre_archivo= "archivo.dat";
struct Estudiante {
	int codigo; 
	char nombres[50]; 
	char apellidos[50];
	int notas; 	
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
	int id=0; //Indice o Posicion del registro dentro del archivo
	fread(&estudiante,sizeof(Estudiante),1,archivo);
	cout<<"___________________________________________________________________________________"<<endl; 
	cout<<"ID"<<"|"<<"Codigo"<<"|"<<" Nombres "<<"|"<<" Apellidos "<<"|"<<" Notas "<<endl;
	do{
		cout<<id<<"|"<<estudiante.codigo<<"|"<<estudiante.nombres<<"|"<<estudiante.apellidos<<"|"<<estudiante.notas<<endl;
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
		cout<<"Ingrese Codigo:"; 
		cin>>estudiante.codigo; 
		cin.ignore();
		
		cout<<"Ingrese Nombres:"; 
		cin.getline(estudiante.nombres,50);
		
		cout<<"Ingrese Apellidos:"; 
		cin.getline(estudiante.apellidos,50);
		
		cout<<"Ingrese Nota 1:"; 
		cin>>estudiante.notas;
		
		cout<<"Ingrese Nota 2:"; 
		cin>>estudiante.notas;
		
		cout<<"Ingrese Nota 3:"; 
		cin>>estudiante.notas;
		
		cout<<"Ingrese Nota 4:"; 
		cin>>estudiante.notas;
		
	    fwrite(&estudiante,sizeof(Estudiante),1,archivo);
	    cout<<"Desea Ingresar Otro Estudiante (s/n): ";
    	cin>>res;
	}while(res=='s' || res=='S');
	fclose(archivo);
	Leer();
}
void Actualizar(){
	
	FILE* archivo = fopen(nombre_archivo,"r+b"); //Crea y borra
	Estudiante estudiante;
	int id=0;
	cout<<"Ingrese el ID que desea Modificar:"; 
	cin>>id; 
	fseek(archivo,id * sizeof(Estudiante),SEEK_SET);

		cout<<"Ingrese Codigo:"; 
		cin>>estudiante.codigo; 
		cin.ignore();
		
		cout<<"Ingrese Nombres:"; 
		cin.getline(estudiante.nombres,50);
		
		cout<<"Ingrese Apellidos:"; 
		cin.getline(estudiante.apellidos,50);
		
		cout<<"Ingrese Nota 1:"; 
		cin>>estudiante.notas;
		
		cout<<"Ingrese Nota 2:"; 
		cin>>estudiante.notas;
		
		cout<<"Ingrese Nota 3:"; 
		cin>>estudiante.notas;
		
		cout<<"Ingrese Nota 4:"; 
		cin>>estudiante.notas;
		
	    fwrite(&estudiante,sizeof(Estudiante),1,archivo);
	
	fclose(archivo);
	Leer();
}
void Borrar(){
	const char *nombre_archivo_temp = "archivo_temp.dat"; 
		FILE* archivo = fopen(nombre_archivo,"rb");
		FILE* archivo_temp = fopen(nombre_archivo_temp,"w+b");
		Estudiante estudiante; 
		int id=0,id_n=0; 
		cout<<"Ingrese el ID a eliminar: ";
		cin>>id; 
		while(fread(&estudiante,sizeof(Estudiante),1,archivo)){	
		    if(id_n!=id){
		    	fwrite(&estudiante,sizeof(Estudiante),1,archivo_temp);  	
			}
		    id_n++; 
		}
		fclose(archivo);
		fclose(archivo_temp);
			
		archivo = fopen(nombre_archivo,"rb");
	    archivo_temp = fopen(nombre_archivo_temp,"wb");
	    while(fread(&estudiante,sizeof(Estudiante),1,archivo_temp)){
		fwrite(&estudiante,sizeof(Estudiante),1,archivo);
		
	}
		fclose(archivo);
    	fclose(archivo_temp);
	    Leer();	
}
