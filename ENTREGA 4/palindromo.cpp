#include <iostream>
#include <string>
#include <cctype>
#include <algorithm> //Libreria que ayuda a eliminar espacios y signos de puntuacion
#include "pila.hpp"
#include "cola.hpp"

using namespace std;

bool evaluarPalindomo(string palabraEvaluar);
bool evaluarTexto(string mensaje);

int main(){

	string texto;
	string textoIgnorando;
	
	cout << " *** EVALUADOR DE PALABRAS PALINDROMO *** " << endl << endl;
	cout << "Digita la palabra a evaluar: ";
	getline(cin, texto);
	
	textoIgnorando = texto;
	textoIgnorando.erase(std::remove(textoIgnorando.begin(), textoIgnorando.end(), ' '), textoIgnorando.end()); //Ignorando espacios en blanco
	textoIgnorando.erase(std::remove_if(textoIgnorando.begin(), textoIgnorando.end(), [](unsigned char c) { return std::ispunct(c); }), textoIgnorando.end()); //Ignorando signos de puntuacion
	transform(textoIgnorando.begin(), textoIgnorando.end(), textoIgnorando.begin(), [](unsigned char c){ return toupper(c); }); // convierto a mayusculas


 for (int i = 0; i < textoIgnorando.length(); i++) {
    // Y cambiar cada letra por su representación
    // mayúscula
    textoIgnorando[i] = toupper(textoIgnorando[i]);
  }


	cout << endl;
	if(evaluarPalindomo(textoIgnorando)){
		cout << "La palabra: '" << texto << "' es Palindromo!!" << endl;
	}else{
		cout << "La palabra: '" << texto << "' NO es Palindromo!!" << endl;
	}
	
	cout << endl;
	cout << endl;
	
	return 0;
}


//funcion para evaluar palabra
bool evaluarPalindomo(string palabraEvaluar){
	
	char letra;
	string palabraPila;
	string palabraLetra;
	
	//Declaracion de pila y cola a partir de lista generica
	Pila<char> pilaLetra;
	Cola<char> colaLetra;
	
	//Agregando caracteres de la palabra a la pila y cola 
	for(int i = 0; i < palabraEvaluar.length(); i++){
		letra = palabraEvaluar[i];
		pilaLetra.push(letra);
		colaLetra.enqueue(letra);
	}
	
	//Extrayendo caracteres de la pila y cola
	for(int i = 0; i < palabraEvaluar.length(); i++){		
		palabraPila += pilaLetra.pop();
		palabraLetra += colaLetra.dequeue();
	}
		if(palabraPila == palabraLetra){
			cout << "Palabra al derecho: " << palabraPila << endl;
			cout << "Palabra al reves: " << palabraLetra << endl;
		return true;
	}else{
			cout << "Palabra al derecho: " << palabraPila << endl;
			cout << "Palabra al reves: " << palabraLetra << endl;
		return false;
	}
}
