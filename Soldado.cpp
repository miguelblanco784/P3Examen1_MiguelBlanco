#include <iostream>
#include <iomanip> 
#include <string.h>
#include <vector>
#include <bits/stdc++.h>
#include <typeinfo>

using namespace std;
#ifndef SOLDADO_CPP
#define SOLDADO_CPP
class Soldado{
	private:
		string nombre;
		int puntosdevida;
		int puntosdefuerza;
	public:
		Soldado(string nombre, int puntosdevida, int puntosdefuerza) {
	        this->nombre = nombre;
	        this->puntosdevida = puntosdevida;
	        this->puntosdefuerza = puntosdefuerza;
	    }
	
	    Soldado() {
	    }

		string getNombre() {
	        return nombre;
	    }
	
	    void setNombre(string nombre) {
	        this->nombre = nombre;
	    }
	
	    int getPuntosdevida() {
	        return puntosdevida;
	    }
	
	    void setPuntosdevida(int puntosdevida) {
	        this->puntosdevida = puntosdevida;
	    }
	
	    int getPuntosdefuerza() {
	        return puntosdefuerza;
	    }
	
	    void setPuntosdefuerza(int puntosdefuerza) {
	        this->puntosdefuerza = puntosdefuerza;
	    }
	    
	    void print() = 0;
	    
	    void atacar() = 0;
	    
	    void dano(int ataque) = 0;
		
};
#endif


