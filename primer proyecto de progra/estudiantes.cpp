#include "estudiantes.h"

estudiantes::estudiantes()
{
	for (int i = 0; i < Estudiantes; i++) {
		Nombres_estudiante[i] = "";
		Primer_apellido_estudiante[i] = "";
		Segundo_apellido_estudiante[i] = "";
		Cedulas[i] = "";
		Carrera[i] = "";
		nivel[i] = 0;
	}
	contador_estudiaes = 0;
}

int estudiantes::getContadorE()
{
	return contador_estudiaes;
}

void estudiantes::RegistrarEstudiantes()
{
	int seleccion;

	if (contador_estudiaes >= Estudiantes) {
		cout << "\nLo sentimos, no se puede registrar en estos momentos, intentelo mas tarde\n";
		return;
	}
	cout << "Ingrese el nombre del estudiante: ";
	cin >> Nombres_estudiante[contador_estudiaes];

	cout << "\nIngrese el primer apellido del estudiante: ";
	cin >> Primer_apellido_estudiante[contador_estudiaes];

	cout << "\nIngrese el segundo apellido del estudiante: ";
	cin >> Segundo_apellido_estudiante[contador_estudiaes];

	cout << "\nIngrese la cedula del estudiante: ";
	cin >> Cedulas[contador_estudiaes];

	for (int i = 0; i < contador_estudiaes; i++) {
		if (Cedulas[i] == Cedulas[i + 1]) {
			cout << "El estudiante ya esta registrado\n";
			return;
		}
	}

	cout << "\nElija la carrera\n";
	cout << "1 = Ingenieria En Sistemas\n2 = Aprendisaje Del Ingles\n3 = Topografia\n4 = Administracion\nIngrese El Numero: ";
	cin >> seleccion;
	switch (seleccion)
	{
	case 1:
		Carrera[contador_estudiaes] = "Ingenieria En Sistemas";
		break;
	case 2:
		Carrera[contador_estudiaes] = "Aprendisaje Del Ingles";
		break;
	case 3:
		Carrera[contador_estudiaes] = "Topografia";
		break;
	case 4:
		Carrera[contador_estudiaes] = "Administracion";
		break;
	}
	cout << "\nIngrese el nivel en el que se encuentra el estudiante en forma numerica: ";
	cin >> nivel[contador_estudiaes];

	cout << endl;
	contador_estudiaes++;
	cout << "Estudiante registrado\n\n";
}



void estudiantes::MostrarEstudiantes()
{
	cout << "Estudiantes agregados\n";
	for (int i = 0; i < contador_estudiaes; i++) {
		cout << "Estudiante: " << i + 1 << endl;
		cout << "=================================================================\n";
		cout << "Nombre: " << Nombres_estudiante[i] << " " << Primer_apellido_estudiante[i] << " " << Segundo_apellido_estudiante[i] << " || Cedula: " << Cedulas[i] << endl;
		cout << "Carrera: " << Carrera[i] << " || Nivel: " << nivel[i] << endl;
		cout << "=================================================================\n\n";
	}
}


string estudiantes::getnombres(int i)
{
	return Nombres_estudiante[i];
}

string estudiantes::getapellido(int i)
{
	return Primer_apellido_estudiante[i];
}

string estudiantes::getapellido2(int i)
{
	return Segundo_apellido_estudiante[i];
}

string estudiantes::getcedula(int i)
{
	return Cedulas[i];
}

string estudiantes::getcarrera(int i)
{
	return Carrera[i];
}

int estudiantes::getNivel(int i)
{
	return nivel[i];
}
