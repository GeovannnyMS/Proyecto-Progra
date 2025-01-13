#pragma once
#include <iostream>
using namespace std;
#define	Max_Cursos 10

class Cursos
{
private:
	string nombresCursos[Max_Cursos];
	string NCR[Max_Cursos];
	int Creditos[Max_Cursos];
	string NombreProfe[Max_Cursos];
	string PrimerApellidoProfe[Max_Cursos];
	string SegundoApellidoProfe[Max_Cursos];
	int costoCreditos[Max_Cursos];
	int contador_Cursos;

public:

	Cursos();

	void RegistrarCurso();
	void MostrarCurso();
	void consultas();

	string getcurso(int);
	string getNCR(int);
	string getNomProfe(int);
	string getApe1Profe(int);
	string getApe2Profe(int);

	int getcreditos(int);
	int getcontador();
	int getcosto(int);
};

