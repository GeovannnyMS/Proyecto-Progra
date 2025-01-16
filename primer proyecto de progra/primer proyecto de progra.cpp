#include <iostream>
#include "estudiantes.h"
#include "cursos.h"
#include "horariosClases.h"
#include "matricular.h"

using namespace std;

Matricular matricula;
Cursos CURSOS;
estudiantes agregar;
HorariosClases horario;


void SubmenuMatenimiento() {
	int submenu = 0;
	do
	{
		cout << "Que necesita?\n\n1 = Registrar estudiante\n2 = Registrar curso\n3 = Registrar horario\n4 = Atras\n";
		cin >> submenu;

		switch (submenu)
		{
		case 1:
			agregar.RegistrarEstudiantes();
			break;
		case 2:
			CURSOS.RegistrarCurso();
			break;
		case 3:
			horario.RegistrarHora(CURSOS);
			break;
		}

	} while (submenu != 4);
}
void consulta() {
	int menu = 0;
	do
	{
		cout << "Que desea ver?\n1 = Ver estudiantes\n2 = Ver cursos\n3 = Atras\n";
		cin >> menu;
		switch (menu)
		{
		case 1:
			matricula.VerInformacionEstidiante(CURSOS, agregar);
			break;
		case 2:
			CURSOS.consultas();
			break;
		}


	} while (menu != 3);
}

int main()
{
	int menu;
	int submenu = 0;


	do
	{
		cout << "Bienvenido al programa de matricula de la UNA\n1 = Archivo\n2 = Mantenimiento\n3 = Matricula\n4 = Consulta\n0 = Salir\n";
		cin >> menu;

		switch (menu)
		{
		case 1:

			do
			{
				cout << "Que desea hace?\n1 = Acerca de\n2 = Salir\n";
				cin >> submenu;
				if (submenu == 1) {
					cout << "\nDesarrollador del programa: Geovany Morales Sanchez (Yio)\nCedula: 604910543\nCarrera: Ingenieria de sistemas de informacion.\n\nYio es una persona muy vaga, le cuesta mucho tener ganas de hacer algo pero en el momento en que se encuentra con un reto apasionante su motivación se dispara hasta el cielo y no para de estudiar e intentar hasta entenderlo y poder asimilarlo. Eso hace que las acciones de Yio sean etiquetadas como plagio porque nadie ha podido notar esa capacidad de mejorar en silencio..\n";
				}
			} while (submenu != 2 || submenu < 1 || submenu >= 3);
			break;

		case 2:
			SubmenuMatenimiento();
			break;

		case 3:
			matricula.matricular(CURSOS, agregar, horario);
			break;
		case 4:
			consulta();
		}
	} while (menu != 0);
	cout << "Gracias por usar el sistema de matricula de la UNA\nLink de GitHub: ";
	cout << "https://github.com/GeovannnyMS/Proyecto-Progra.git";

}
