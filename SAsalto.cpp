#include "Soldado.cpp"

using namespace std;

#ifndef SASALTO_CPP
#define SASALTO_CPP
class SAsalto: Public Soldado{
	private:
		int velocidad;
		int fuerza;
	public:
		SSoporte() {
	    }
	
	    SSoporte(int velocidad, int fuerza) {
	        this->velocidad = velocidad;
	        this->fuerza = fuerza;
	    }
	
	    int getVelocidad() {
	        return velocidad;
	    }
	
	    void setVelocidad(int velocidad) {
	        this->velocidad = velocidad;
	    }
	
	    int getFuerza() {
	        return fuerza;
	    }
	
	    void setFuerza(int fuerza) {
	        this->fuerza = fuerza;
	    }
		
};
#endif
