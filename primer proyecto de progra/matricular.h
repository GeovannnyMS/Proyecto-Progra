#pragma once
#include "cursos.h"
#include "estudiantes.h"
#include "horariosClases.h"
class Matricular
{
private:
	string ProfeMatriculaN[Max_Cursos][Max_Cursos];
	string ProfeMatricula1A[Max_Cursos][Max_Cursos];
	string ProfeMatricula2Ape[Max_Cursos][Max_Cursos];
	string salon[Max_Cursos][Max_Cursos];
	string matricula[Max_Cursos][Max_Cursos];
	string diaclases[Max_Cursos][Max_Cursos];
	string entrada[Max_Cursos][Max_Cursos];
	string salida[Max_Cursos][Max_Cursos];
	string ncrmatricula[Max_Cursos][Max_Cursos];
	string horario[Max_Cursos][Max_Cursos];
	int ContadorMatricula[Max_Cursos];
	int total[Max_Cursos];
	int creditosMatricula[Max_Cursos][Max_Cursos];
public:
	Matricular();

	void matricular(Cursos&, estudiantes&, HorariosClases&);

	void VerInformacionEstidiante(Cursos&, estudiantes&);
};
