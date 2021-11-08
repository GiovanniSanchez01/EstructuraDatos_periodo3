#include <iostream>
#include <string>

using namespace std;

class CuentaBancaria{
	private: //Atributos
		int numeroCuenta;
		string nombreTitular;
		double saldo;
		
	public: //Metodos
		CuentaBancaria(int, string, double); //Constructor
		void getSaldo();
		void getNumeroCuenta();
		void NombreTitular();
		void depositar();
		void retirar();		
};

CuentaBancaria::CuentaBancaria(int _numeroCuenta, string _nombreTitular, double _saldo){
	numeroCuenta = _numeroCuenta;
	nombreTitular = _nombreTitular;
	saldo = _saldo;
}

void CuentaBancaria::getSaldo(){
	
	cout << "Su saldo es de: $" << saldo << endl;
}

void CuentaBancaria::depositar(){
	
	double importeDeposito = 0;
	
	cout << "Cuanto dinero desea depositar?" << endl;
	cin >> importeDeposito;
	
	if (importeDeposito < 0){
		cout << "El deposito no se puede realizar" << endl;
	} else{
		saldo = saldo + importeDeposito;
		cout << "Se realizo el deposito y su saldo es de: $" << saldo << endl; 
	}
}

void CuentaBancaria::getNumeroCuenta(){
	
	cout << "Su numero de cuenta es: " << numeroCuenta << endl;
}

void CuentaBancaria::NombreTitular(){
	
	
	cout << "El nombre del titular de la cuenta es: " << nombreTitular << endl;
}

void CuentaBancaria::retirar(){
	
	double importeRetiro ;

	cout << "¿Cuanto dinero desea retirar?" << endl;
	cin >> importeRetiro;
	
	if (importeRetiro > saldo){
		cout << "El retiro no se pudo realizar: " << endl;
	} else
	{
		saldo = saldo - importeRetiro;
		cout << "El retiro fue realizado con exito" << endl;
	}
}

int main(){
	
	 char respuesta;
	int opcion;
	
	CuentaBancaria CuentaDeBanco = CuentaBancaria(061702304, "Giovanni Sanchez", 0);
	
	
do
{
  
   cout << "¿Que accion desea realizar?" << endl;
   cout << "1- Revisar el saldo de mi cuenta bancaria" << endl;
   cout << "2- Ver el numero de mi cuenta bancaria" << endl;
   cout << "3- Ver el nombre del titular de la cuenta" << endl;
   cout << "4- Realizar un deposito" << endl;
   cout << "5- Realizar un retiro de efectivo" << endl;
   cout << "6- Salir" << endl;
   cout << "" << endl;
   
   cin >> opcion;
   
   	switch(opcion) //donde opción es la variable a comparar
{

    case 1: CuentaDeBanco.getSaldo();
    	break;
    case 2: CuentaDeBanco.NombreTitular();
    	break;
    case 3: CuentaDeBanco.getNumeroCuenta();
    	break;
    case 4: CuentaDeBanco.depositar();
		break;
	case 5: CuentaDeBanco.retirar();
		break;
	case 6: exit(-1);
		break;
    default: cout << "No se pudo realizar la accion" << endl;
}
    
   
}
while(opcion = 6);

	
	return 0;
}
