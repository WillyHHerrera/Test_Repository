#include "usuario.hpp"

class Controlador {
private:
	vector<Usuario> usuarios;
public:	
	Controlador() {
		
	}
	void cargar_usuarios_existentes() {
		fstream archivo("usuarios.txt", ios::in);
		string nombre, apellido;				
		int edad;		
		float saldo;
		
		string linea, criterio;
		getline(archivo, linea);
		while (getline(archivo, linea)) {
			stringstream ss(linea);
			getline(ss, nombre, ',');
			getline(ss, apellido, ',');
			getline(ss, criterio, ',');
			edad = stoi(criterio);
			getline(ss, criterio);			
			saldo = stof(criterio);			
			usuarios.push_back(Usuario(nombre, apellido, edad, saldo));			
		}
		archivo.close();
	}
	void insertar_usuario(string &nombre, string &apellido, int &edad, float &saldo) {
		usuarios.push_back(Usuario(nombre, apellido, edad, saldo));
	}
	void mostrar_usuarios_v1() {
		for (int i = 0; i < usuarios.size(); ++i)
			cout << "[Id=" << i+1 << usuarios[i];
		cout << "\n\n";
	}
	void mostrar_usuarios_v2(size_t idx) {
		for (int i = 0; i < usuarios.size(); ++i)
			if (i != idx) 
				cout << "[Id=" << i+1 << usuarios[i];
		cout << "\n\n";
	}
	string nombre_usuario(size_t idx) {
		return usuarios[idx].get_nombre();
	}
         size_t num_de_usuarios() {
		return usuarios.size();
	}	
};