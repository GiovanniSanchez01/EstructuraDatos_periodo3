#include <iostream>
#include <regex>
#include <iterator>
#include <string>
#include "pila.hpp"
#include <vector>

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;


	
bool revisandoEtiquetas(string caadena){
	
	
	Pila<string> pilaEtiquetas;
	
	const std::string s = caadena;

	
	std::regex words_regrex("<\\w+>|</\\w+>");
	
	 auto words_begin = std::sregex_iterator(s.begin(), s.end(), words_regrex); //funcion para buscar expresiones regulares en un bucle.
	 auto words_end = std::sregex_iterator();
	
	
	for(std::sregex_iterator i = words_begin; i != words_end; ++i){
		std::smatch match = *i; //puntero i
		std::string match_str = match.str();
		cout << match_str << endl;
	}
	

	
	for(std::sregex_iterator i = words_begin; i != words_end; ++i){
		std::smatch match = *i; //puntero i
		std::string match_str = match.str();
		
		if(match_str.substr(0,2) == "</"){
			if(pilaEtiquetas.estaPilaVacia()){
				return false;
			}else if(pilaEtiquetas.extraer() != match_str.replace(match_str.find("/"),1,"")){
				return false;
			}else{
				pilaEtiquetas.pop();
			}
			
		}else{
			pilaEtiquetas.push(match_str);
		}
		
	}
		
	return pilaEtiquetas.estaPilaVacia();
}



int main(){
		string etiquetasNoBalanceadas = "<html><head><title>Pagina</head><body><h1><p>HOLA</p></h1></body></html>";
		string etiquetasBalanceadas = "<html><head><title>Pagina</title></head><body><h1><p>HOLA</p></h1></body></html>";
		
		cout << " *** COMPROBANDO BALANCEO DE ETIQUETAS HTML *** " << endl;
		cout << endl;
		if(revisandoEtiquetas(etiquetasNoBalanceadas)){
			cout << endl;
			cout << "etiquetas balanceadas " << endl;
		}else{
				cout << endl;
			cout << "etiquetas no balanceadas" << endl;
			cout << endl;
		}
		
		cout << endl;
			if(revisandoEtiquetas(etiquetasBalanceadas)){
				cout << endl;
			cout << "etiquetas balanceadas ";
		}else{
			cout << endl;
			cout << "etiquetas no balanceadas";
		}


return 0;
}

