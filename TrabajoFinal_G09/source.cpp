#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

#include "controlador.hpp"

void opcion_1(Controlador &controlador, bool &existentes) {
	system("CLS");
	char c;
	if (existentes) {
		cout << "Usuarios existentes ya fueron registrados\n\n\n";
		return;
	}
	cout << "Registrar usuarios existentes [s,n]: ";
	c = getchar();
	while (c != 's' && c != 'n') {
		system("CLS");
		cout << "Registrar usuarios existentes [s,n]: ";
		c = getchar();
	}
	if (tolower(c) == 's') {
		controlador.cargar_usuarios_existentes();
		existentes = true;
		cout << "Usuarios existentes registrados exitosamente\n\n\n";
	}
	else if (tolower(c) == 'n')
		cout << "Usuarios existentes no registrados\n\n\n";	
}
void opcion_2(Controlador &controlador, bool &nuevos) {
	system("CLS");
	char c;
	string nombre, apellido;
	int edad, N;
	float saldo;
	cout << "Numero de nuevos usuarios a registrar = ";
	cin >> N;
	while (N < 1) {
		system("CLS");
		cout << "Numero de nuevos usuarios a registrar = ";
		cin >> N;
	}
	cout << "\n";
	for (int i = 0; i < N; ++i) {
		cout << "#" << i+1 << "\nNombre = ";
		cin  >> nombre;
		c = toupper(nombre[0]);
		nombre[0] = c;
		cout << "Apellido = ";
		cin >> apellido;
		c = toupper(apellido[0]);
		apellido[0] = c;
		cout << "Edad = ";
		cin >> edad;
		cout << "Saldo = $";
		cin >> saldo;
		controlador.insertar_usuario(nombre, apellido, edad, saldo);
	}
	nuevos = true;
	cout << "\n\n";
}
void opcion_3(Controlador &controlador, bool &existentes, bool &nuevos) {
	system("CLS");
	if (!existentes && !nuevos) {
		cout << "No hay usuarios registrados\n\n\n";
		return;
	}
	controlador.mostrar_usuarios_v1();
}
void opcion_4(Controlador &controlador, bool &existentes, bool &nuevos) {
	system("CLS");
	if (!existentes && !nuevos) {
		cout << "No hay usuarios registrados\n\n\n";
		return;
	}
	else {
		if (controlador.num_de_usuarios() < 2) {
			cout << "No hay usuarios registrados suficientes (min. = 2)\n\n\n";
			return;
		}
		bool continuar = true;
		int N, id, origen_idx, destino_idx;
		float importe;		
		char c;

		cout << "Numero de transacciones a realizar = ";
		cin >> N;
		while (N < 1) {
			system("CLS");
			cout << "Numero de nuevos usuarios a registrar = ";
			cin >> N;
		}
		cout << "\n";

		for (int i = 0; i < N && continuar; ++i) {
			controlador.mostrar_usuarios_v1();
			cout << "Origen [Id] = ";
			cin >> id;
			origen_idx = id-1;

			system("CLS");			
			cout << "#" << i+1 << "\n[" << controlador.nombre_usuario(origen_idx) << " -> ###]: $###\n\n";
			controlador.mostrar_usuarios_v2(id-1);
			cout << "Destino [Id] = ";				
			cin >> id;
			destino_idx = id-1;

			system("CLS");
			cout << "#" << i+1 << "\n[" << controlador.nombre_usuario(origen_idx) << " -> " << controlador.nombre_usuario(destino_idx) << "]: $###\n"; 
			cout << "Importe a transferir = $"; 
			cin >> importe;

			system("CLS");
			cout << "#" << i+1 << "\n[" << controlador.nombre_usuario(origen_idx) << " -> " << controlador.nombre_usuario(destino_idx) << "]: $" << importe << "\n\n";

			//Invocar metodo x de controlador

			if (i < N-1) {
				cout << "Continuar con la transaccion #" << i+2 << " [s,n]: ";
				cin >> c;
				while (c != 's' && c != 'n') {
					system("CLS");
					cout << "Continuar con la transaccion #" << i+2 << " [s,n]: ";
					c = getchar();
				}
				if (tolower(c) == 'n') {
					continuar = false;
					cout << "\n\n\n";
				}
				else if (tolower(c) == 's')
					system("CLS");
			}
		}				
	}
}

void show_menu() {
	cout << "      =====PROTOTIPO=====\n\n";	
	cout << "1. Registrar Usuarios Existentes\n";
	cout << "2. Registrar Nuevo Usuario\n";
	cout << "3. Visualizar Usuarios\n";
	cout << "4. Realizar Transferencia\n";
	cout << "5. \n";	
	cout << "6. Salir\n\n";
	cout << "SELECCIONAR = ";
}

int main() {	
	cout << setprecision(2) << fixed;
	bool existentes = false, nuevos = false;
	Controlador controlador;
	short key;
	char c;

	while (true) {
		show_menu();
		cin >> key;
		while (key < 1 || key > 6) {
			system("CLS");
			show_menu();
			cin >> key;
		}

		if (key == 1) opcion_1(controlador, existentes);
		else if (key == 2) opcion_2(controlador, nuevos);
		else if (key == 3) opcion_3(controlador, existentes, nuevos);
		else if (key == 4) opcion_4(controlador, existentes, nuevos);
		else if (key == 6) exit(0);

		system("pause");
		system("CLS");
	}

	return 0;
}