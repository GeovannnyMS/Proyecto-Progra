#include "horariosClases.h"

HorariosClases::HorariosClases()
{
	for (int i = 0; i < 10; i++)
	{
		HorasEntrada[i] = "";
		HorasSalida[i] = "";
		dias[i] = "";
		Aunla[i] = "";
		MañanaOTarde[i] = 0;
	}
}

void HorariosClases::RegistrarHora(Cursos& curso)
{
	int days = 0;
	int contador = curso.getcontador();
	if (contador == 0) {
		cout << "No hay cursos registrados\n";
		return;
	}
	int aux;

	cout << "A cual curso quiere ponerle el horario (1 a " << contador << ")\n\n";
	curso.MostrarCurso();

	cout << "Ingrese el numero del curso a registrar: ";
	cin >> aux;
	aux--;

	if (aux < 0 || aux >= contador) {
		cout << "Curso invalido\n";
		return;
	}

	do
	{
		cout << "Ingrese el dia de la clase\n1 = Lunes\n2 = Martes\n3 = Miercoles\n4 = Jueves\n5 = Viernes\n";
		cin >> days;

		switch (days)
		{
		case 1:
			dias[aux] = "Lunes";
			break;
		case 2:
			dias[aux] = "Martes";
			break;
		case 3:
			dias[aux] = "Miercoles";
			break;
		case 4:
			dias[aux] = "Jueves";
			break;
		case 5:
			dias[aux] = "Viernes";
			break;
		}
	} while (days <= 0 || days >= 6);

	cout << "Desea que el horario sea temprano o en la tarde\n1 = temprano (am)\n2 = tarde (pm)\n";
	cin >> MañanaOTarde[aux];

	if (MañanaOTarde[aux] <= 0 || MañanaOTarde[aux] >= 3) {
		do
		{
			cout << "\nEsa opcion no es valida\nIngrese otra: ";
			cin >> MañanaOTarde[aux];
			cout << endl;
		} while (MañanaOTarde[aux] <= 0 || MañanaOTarde[aux] >= 3);
	}

	switch (MañanaOTarde[aux])
	{
	case 1:
		HorasEntrada[aux] = "8:00";
		HorasSalida[aux] = "11:00";
		break;
	case 2:
		HorasEntrada[aux] = "1:00";
		HorasSalida[aux] = "4:00";
		break;
	}
	cout << "En que aula se daran las clases: ";
	cin >> Aunla[aux];
	cout << endl;
	cout << "Se registro la hora de entrada y salida\n";
}

string HorariosClases::getentrada(int i)
{
	return HorasEntrada[i];
}

string HorariosClases::getsalida(int i)
{
	return HorasSalida[i];
}

string HorariosClases::getdias(int i)
{
	return dias[i];
}

string HorariosClases::getAula(int i)
{
	return Aunla[i];
}


int HorariosClases::getMañanaOTarde(int i)
{
	return MañanaOTarde[i];
}
