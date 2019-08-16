#include "Soldado.cpp"
#include "SAsalto.cpp"
#include "SSoporte.cpp"
#include <fstream>
#include <ctime>    // For time()
#include <cstdlib>  // For srand() and rand()

using namespace std;

int main(){
	srand(time(0));
	vector<Soldado*> equipo1;
	vector<Soldado*> equipo2;
	fstream Leer;
	Leer.open("./Soldados.txt");
	string nombre, puntosdevida, puntosdefuerza, opciona, opcionb, tipo;
	int centinela = 0;
	
	while(! Leer.eof()){
		getline(Leer,tipo,'/');
		if(tipo == "&"){
			centinela = 1;
		}
		if(centinela == 0){
			getline(Leer,nombre,'/');
			getline(Leer,puntosdevida,'/');
			getline(Leer,puntosdefuerza,'/');
			getline(Leer,opciona,'/');
			getline(Leer,opcionb,'/');
			int puntosdevida1, puntosdefuerza1, opciona1, opcionb1;
			stringstream convert;
			convert << puntosdevida;
			convert >> puntosdevida1;
			convert.str("");
			convert.clear();
			convert << puntosdefuerza;
			convert >> puntosdefuerza1;
			convert.str("");
			convert.clear();
			convert << opciona;
			convert >> opciona1;
			convert.str("");
			convert.clear();
			convert << opcionb;
			convert >> opcionb1;
			convert.str("");
			convert.clear();
			if(tipo == "Asalto"){
				equipo1.push_back(new SAsalto(nombre, puntosdevida1, puntosdefuerza1, opciona1, opcionb1));
			}else{
				equipo1.push_back(new SSoporte(nombre, puntosdevida1, puntosdefuerza1, opciona1, opcionb1));
			}
		}else if(centinela == 1){
			getline(Leer, tipo, '/');
			centinela = 2;
		}	
		if(centinela == 2){
			getline(Leer,nombre,'/');
			getline(Leer,puntosdevida,'/');
			getline(Leer,puntosdefuerza,'/');
			getline(Leer,opciona,'/');
			getline(Leer,opcionb,'/');
			int puntosdevida1, puntosdefuerza1, opciona1, opcionb1;
			stringstream convert;
			convert << puntosdevida;
			convert >> puntosdevida1;
			convert.str("");
			convert.clear();
			convert << puntosdefuerza;
			convert >> puntosdefuerza1;
			convert.str("");
			convert.clear();
			convert << opciona;
			convert >> opciona1;
			convert.str("");
			convert.clear();
			convert << opcionb;
			convert >> opcionb1;
			convert.str("");
			convert.clear();
			if(tipo == "Asalto"){
				equipo2.push_back(new SAsalto(nombre, puntosdevida1, puntosdefuerza1, opciona1, opcionb1));
			}else if (tipo == "Soporte"){
				equipo2.push_back(new SSoporte(nombre, puntosdevida1, puntosdefuerza1, opciona1, opcionb1));
			}
		}	
	}
	
	while(true){
		int opcion;
		cout<<"1- Atacar\n2- Listar\n3- Salir\n";
		cin>>opcion;
		switch(opcion){
			case 1:{
				while(true){
					{
						int opcion1, opcion2;
						string tipo1, tipo2;
						opcion1 = rand() % equipo1.size();
						opcion2 = rand() % equipo2.size();
						
						if(typeid(equipo1.at(opcion1))==typeid(SAsalto)){
							tipo1 = "SAsalto";
						}else{
							tipo1 = "SSoporte";
						}
						
						if(typeid(equipo2.at(opcion2))==typeid(SAsalto)){
							tipo2 = "SAsalto";
						}else{
							tipo2 = "SSoporte";
						}
						
						int ataque = equipo1.at(opcion1)->atacar(tipo2);
						bool vivir = equipo2.at(opcion2)->dano(ataque, tipo1);
						
						if(vivir){
							equipo2.erase(equipo2.begin()+opcion2);
						}
					}
					{
						int opcion1, opcion2;
						string tipo1, tipo2;
						opcion1 = rand() % equipo1.size();
						opcion2 = rand() % equipo2.size();
						
						if(typeid(equipo2.at(opcion2))==typeid(SAsalto)){
							tipo1 = "SAsalto";
						}else{
							tipo1 = "SSoporte";
						}
						
						if(typeid(equipo1.at(opcion1))==typeid(SAsalto)){
							tipo2 = "SAsalto";
						}else{
							tipo2 = "SSoporte";
						}
						int ataque = equipo2.at(opcion2)->atacar(tipo1);
						bool vivir = equipo1.at(opcion1)->dano(ataque, tipo2);
						
						if(vivir){
							equipo1.erase(equipo1.begin()+opcion1);
						}
					}
					if(equipo1.size() <= 0){
						ofstream Escribir;
						Escribir.open("./ganadores.txt");
						Escribir<<"Gano el equipo 2: "<<endl;
						string tipoganador;
						for(int i = 0; i < equipo2.size();i++){
							if(typeid(equipo2.at(i))==typeid(SAsalto)){
								tipoganador = "SAsalto";
							}else{
								tipoganador = "SSoporte";
							}	
							Escribir<<"Nombre: "<<equipo2.at(i)->getNombre()<<"  Tipo: "<<tipoganador<<"  Vida Restante: "<<equipo2.at(i)->getPuntosdevida()<<"  Puntos de ataque: "<<equipo2.at(i)->getPuntosdefuerza()<<endl;
						}
						Escribir.close();
						Leer.close();
						exit(0);
						break;
					} else if(equipo2.size() <= 0){
						ofstream Escribir;
						Escribir.open("./ganadores.txt");
						Escribir<<"Gano el equipo 1: "<<endl;
						string tipoganador;
						for(int i = 0; i < equipo1.size();i++){
							if(typeid(equipo1.at(i))==typeid(SAsalto)){
								tipoganador = "SAsalto";
							}else{
								tipoganador = "SSoporte";
							}	
							Escribir<<"Nombre: "<<equipo1.at(i)->getNombre()<<"  Tipo: "<<tipoganador<<"  Vida Restante: "<<equipo1.at(i)->getPuntosdevida()<<"  Puntos de ataque: "<<equipo1.at(i)->getPuntosdefuerza()<<endl;
						}
						Escribir.close();
						Leer.close();
						exit(0);
						break;
					}
					
				}
				
				
				break;
			}
			case 2:{
				cout<<"Equipo 1: "<<endl;
				for(int i = 0; i <equipo1.size();i++){
					equipo1.at(i)->print();
				}
				
				cout<<"Equipo 2:"<<endl;
				for(int i = 0; i <equipo2.size();i++){
					equipo2.at(i)->print();
				}		
				break;
			}
			case 0:{
				exit(0);
				break;
			}
		}	
	}
	
	
		
	
	
	
	system("pause");
	return 0;
}
