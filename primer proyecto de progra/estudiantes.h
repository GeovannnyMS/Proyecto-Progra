#pragma once
#include <iostream>
using namespace std;


#define Estudiantes 10
class estudiantes
{
private:
	string Nombres_estudiante[Estudiantes];
	string Primer_apellido_estudiante[Estudiantes];
	string Segundo_apellido_estudiante[Estudiantes];
	string Cedulas[Estudiantes];
	string Carrera[Estudiantes];
	int nivel[Estudiantes];

	int contador_estudiaes = 0;
public:

	estudiantes();
	int getContadorE();
	void RegistrarEstudiantes();
	void MostrarEstudiantes();


	string getnombres(int);
	string getapellido(int);
	string getapellido2(int);
	string getcedula(int);
	string getcarrera(int);
	int getNivel(int);
};