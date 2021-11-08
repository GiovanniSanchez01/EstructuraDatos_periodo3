#include <iostream>
#include <string>
#include <chrono>
#include <ctime> 

using namespace std;

class Persona{
	private: //Atributos
		string nombre;
		string apellido;
		int anioNacimiento;
		
	public: //Metodos
		Persona(string, string, int); //Constructor
		void nombreCompleto();
		void edad();
				
};

Persona::Persona(string _nombre, string _apellido, int _anioNacimiento){
	nombre = _nombre;
	apellido = _apellido;
	anioNacimiento = _anioNacimiento;
}

void Persona::nombreCompleto(){
	cout << "Nombre: " << nombre << " " << apellido << endl;
}

void Persona::edad(){
	
	int anioActual = 2021;
	int edadPersona;
	
	edadPersona = anioActual - anioNacimiento;
	
	cout << "Edad: " << edadPersona << endl;
	
}

int main(){
	
	Persona datosPersona = Persona("Giovanni", "Sánchez", 1998);
	
	datosPersona.nombreCompleto();
	datosPersona.edad();
	
	
	
	return 0;
}


