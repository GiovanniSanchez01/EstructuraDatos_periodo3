#include <iostream>
#include <string>

using namespace std;

class Personaje{
	private:
		string nombre;
		int puntosVida;
		
	public:
		Personaje(string, int);
		void recibirGolpe();
		void estaVivo();
		void getPuntosVida();
		void getNombre();
		void comer();
};

Personaje::Personaje(string _nombre, int _puntosVida){
	nombre = _nombre;
	puntosVida = _puntosVida;
}



void Personaje::recibirGolpe(){
	
	int puntosPerdidos = 10;
	
	if (puntosVida > 0){
		puntosVida = puntosVida - puntosPerdidos;
	}else
	{
		cout << "El personaje esta muerto, no puede ser golpeado" << endl;
	}
	
}

void Personaje::estaVivo(){
	
	if (puntosVida > 0){
		cout << "El personaje sigue con vida" << endl;
	} else {
		cout << "El personaje no tiene vida" << endl;
	}
}

void Personaje::getPuntosVida(){
	
	cout << "Puntos de vida: " << puntosVida << endl;
}

void Personaje::getNombre(){
	
	cout << "Nombre: " << nombre << endl;
}

void Personaje::comer(){
	
	int puntosGanados = 10;
	
	
	if (puntosVida >= 1 && puntosVida <= 90){
		
		puntosVida = puntosVida + 10;
		cout << "Se sumaron 10 puntos de vida" << endl;
	}else if (puntosVida < 1)
	{
		cout << "No se puede comer porque el personaje esta muerto" << endl;
	}else if (puntosVida = 100)
	{
		cout << "No puede comer mas porque su vida esta llena" << endl;
	}
}

int main(){
	
	int opcion;
	
	Personaje datosPersonaje = Personaje("Giovanni Sánchez", 100);
	
	do
{
  
   cout << "¿Que accion desea realizar?" << endl;
   cout << "1- Golpear" << endl;
   cout << "2- Estado de vida" << endl;
   cout << "3- Ver puntos de vida" << endl;
   cout << "4- Ver el nombre" << endl;
   cout << "5- Comer" << endl;
   cout << "6- Salir" << endl;
   cout << "" << endl;
   
   cin >> opcion;
   
   	switch(opcion) //donde opción es la variable a comparar
{

    case 1: datosPersonaje.recibirGolpe();
    	break;
    case 2: datosPersonaje.estaVivo();
    	break;
    case 3: datosPersonaje.getPuntosVida();
    	break;
    case 4: datosPersonaje.getNombre();
		break;
	case 5: datosPersonaje.comer();
		break;
	case 6: exit(-1);
		break;
    default: cout << "No se pudo realizar la accion" << endl;
}
    
   
}
while(opcion = 6);
	
	return 0;
}
