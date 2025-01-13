#pragma once
#include <iostream>
#include "cursos.h"
using namespace std;

class HorariosClases
{
private:
	string HorasEntrada[Max_Cursos];
	string HorasSalida[Max_Cursos];
	string dias[Max_Cursos];
	string Aunla[Max_Cursos];

public:
	int MañanaOTarde[Max_Cursos];
	HorariosClases();

	void RegistrarHora(Cursos&);

	string getentrada(int);
	string getsalida(int);
	string getdias(int);
	string getAula(int);
	int getMañanaOTarde(int);

};

