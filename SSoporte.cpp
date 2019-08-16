#include "Soldado.cpp"

using namespace std;

#ifndef SSOPORTE_CPP
#define SSOPORTE_CPP
class SSoporte: Public Soldado{
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
