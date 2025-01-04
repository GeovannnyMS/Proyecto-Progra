#include <iostream>
using namespace std;

//estos son los limites de vectores y matrices 
#define Estudiantes 10
#define	Max_Cursos 10

//varibles pra guardar el nombre y apellidos del estudiante
string Nombres_estudiante[Estudiantes];
string Primer_apellido_estudiante[Estudiantes];
string Segundo_apellido_estudiante[Estudiantes];

//varibles pra guardar el nombre y apellidos del profesor
string NombreProfe[Max_Cursos];
string PimerApellidoProfe[Max_Cursos];
string SegundoApellidoProfe[Max_Cursos];

//varibles donde se van a guardar el aula, la carrera, cedulas,cursos y matricula
string Aunla[Max_Cursos];
string Carrera[Estudiantes];
string Cedulas[Estudiantes];
string nombresCursos[Max_Cursos];
string matricula[Max_Cursos][Max_Cursos];
//aqui se va a guardar los NCR del curso
string NCR[Max_Cursos];

// aqui se va a guardar las horas de entrada,salida, el dia de clases y el horario
string HorasEntrada[Max_Cursos];
string HorasSalida[Max_Cursos];
string dias[Max_Cursos];
string diaclases[Max_Cursos][Max_Cursos];

//aqui se va a guardar el nivel en formato numerico del estudiante
int nivel[Estudiantes];

//esto sirve para verificar que no hayan choque en los horarios
int MañanaOTarde[Max_Cursos];
int horario[Max_Cursos][Max_Cursos];

// los contadores para no sobreescribir informacion
int contador_estudiaes = 0;
int contador_Cursos = 0;
int ContadorMatricula[Max_Cursos];
int contadorHorario[Max_Cursos];

//los creditos y el costo de los creditos y el total a pagar despues de la matricula
int Creditos[Max_Cursos];
int costoCreditos[Max_Cursos];
int total[Max_Cursos];



void RegistroEsrudiantes() {
	int seleccion = 0;
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

void RegistroCursos() {
	if (contador_Cursos >= Max_Cursos) {
		cout << "No se puede agregar ese curso\n";
		return;
	}

	cout << "Ingrese el nombre de la carrera con el siguiente formato\n(Ejemplo: Matematica_Para_informatica): ";
	cin >> nombresCursos[contador_Cursos];
	cout << "\nIngrese el NCR del curso: ";
	cin >> NCR[contador_Cursos];
	cout << "\nIngrese los creditos del curso: ";
	cin >> Creditos[contador_Cursos];
	cout << "\nIngese el nombre del profesor: ";
	cin >> NombreProfe[contador_Cursos];
	cout << "\nIngrese el primer apellido de profesor: ";
	cin >> PimerApellidoProfe[contador_Cursos];
	cout << "\nIngrese el segundo apellido del profesor: ";
	cin >> SegundoApellidoProfe[contador_Cursos];

	costoCreditos[contador_Cursos] = Creditos[contador_Cursos] * 1000;


	contador_Cursos++;
	cout << endl;
	cout << "Curso registrado\n";

}

void RegistroHorarios() {
	int days = 0;
	if (contador_Cursos == 0) {
		cout << "No hay cursos registrados\n";
	}

	int aux;
	cout << "A cual curso quiere ponerle el horario (1 a " << contador_Cursos << ")\n\n";
	for (int i = 0; i < contador_Cursos; i++) {
		cout << i + 1 << " = " << NCR[i] << "|" << nombresCursos[i] << "|" << Creditos[i] << "|" << NombreProfe[i] << " " << PimerApellidoProfe[i] << " " << SegundoApellidoProfe[i] << endl;

	}
	cout << "Ingrese el numero del curso a registrar: ";
	cin >> aux;
	aux--;
	if (aux < 0 || aux >= contador_Cursos) {
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

void SubmenuMatenimiento() {
	int submenu = 0;
	do
	{
		cout << "Que necesita?\n\n1 = Registrar estudiante\n2 = Registrar curso\n3 = Registrar horario\n4 = Atras\n";
		cin >> submenu;

		switch (submenu)
		{
		case 1:
			RegistroEsrudiantes();
			break;
		case 2:
			RegistroCursos();
			break;
		case 3:
			RegistroHorarios();
			break;
		}

	} while (submenu != 4);
}

void Matricular() {
	int eleccionE = 0;
	int seleccion = 0;
	int menu = 0;

	if (contador_estudiaes == 0 || contador_Cursos == 0) {
		cout << "No hay cursos o estudiantes registrados\n";
		return;
	}
	cout << "\nRegistro de matricula\n";

	for (int i = 0; i < contador_estudiaes; i++) {
		cout << i + 1 << " = " << Cedulas[i] << " || " << Nombres_estudiante[i] << "  " << Primer_apellido_estudiante[i] << "  " << Segundo_apellido_estudiante[i] << " || " << Carrera[i] << endl;
	}
	cout << "\nQue estudiante desea matricular cursos?: ";
	cin >> eleccionE;
	cout << endl;
	eleccionE--;
	total[eleccionE] = 0;

	cout << "\nEl estudiante debe pagar " << total[eleccionE] << " con base a los cursos que ha matriculado\n\n";


	if (eleccionE < 0 || eleccionE >= contador_estudiaes) {
		cout << "Estudiante invalido\n";
		return;
	}
	ContadorMatricula[eleccionE] = 0;
	contadorHorario[seleccion] = 0;
	do
	{


		cout << "Que curso quiere matricular\n";
		for (int i = 0; i < contador_Cursos; i++) {
			cout << "Curso " << i + 1 << " || " << NCR[i] << " || " << nombresCursos[i] << endl;
		}
		cout << "\nQue curso quieres seleccionar?: ";
		cin >> seleccion;
		cout << endl;
		seleccion--;

		for (int i = 0; i < contador_Cursos; i++) {
			if (nombresCursos[seleccion] == matricula[eleccionE][i]) {

				cout << "Este curso ya esta matriculado\n";
				return;
			}
			if (dias[seleccion] == diaclases[eleccionE][i]) {
				if (MañanaOTarde[seleccion] == horario[eleccionE][i]) {
					cout << "Este curso choca en horario con otro\n";
					return;
				}
			}

		}
		matricula[eleccionE][ContadorMatricula[eleccionE]] = nombresCursos[seleccion];
		diaclases[eleccionE][contadorHorario[seleccion]] = dias[seleccion];
		horario[eleccionE][contadorHorario[seleccion]] = MañanaOTarde[seleccion];

		ContadorMatricula[eleccionE]++;
		contadorHorario[seleccion]++;

		total[eleccionE] += costoCreditos[seleccion];

		cout << "\nEl estudiante debe pagar " << total[eleccionE] << " con base a los cursos que ha matriculado\n\n";

		cout << "Quieres matricular otro curso?\n1 = Si\n0 = No\n";
		cin >> menu;

	} while (menu != 0);

	
}

void VerEstudiantes() {

	if (contador_estudiaes < 0) {
		cout << "No hay estudiantes registrados\n";
		return;
	}
	cout << "Estudiantes registrados\n";
	for (int i = 0; i < contador_estudiaes; i++) {
		cout << Cedulas[i] << " || " << Nombres_estudiante[i] << " " << Primer_apellido_estudiante[i] << " " << Segundo_apellido_estudiante[i] << " || " << Carrera[i] << " || level: " << nivel[i] << endl;

		cout << "\nCursos matriculados\n\n";

		if (ContadorMatricula[i] == 0) {
			cout << "El estudiante no ha matriculado ningun curso\n";
			return;
		}
		for (int x = 0; x < contador_Cursos; x++) {
			cout << NCR[x] << " || " << Creditos[x] << " || " << matricula[i][x] << endl;
		}
		cout << "=================================================================\n";
	}

}
void VerCursos() {
	if (contador_Cursos == 0) {
		cout << "No hay cursos registrados\n";
		return;
	}
	cout << "Cursos registrados\n";
	for (int i = 0; i < contador_Cursos; i++) {
		cout << "Curso  " << i + 1 << " || " << NCR[i] << " || " << Creditos[i] << " || " << nombresCursos[i] << endl;
	}
}

void consulta() {
	int menu = 0;
	do
	{
		cout << "¿Que desea ver?\n1 = Ver estudiantes\n2 = Ver cursos\n3 = Atras\n";
		cin >> menu;
		switch (menu)
		{
		case 1:
			VerEstudiantes();
			break;

		case 2:
			VerCursos();
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
					cout << "https://github.com/GeovannnyMS/Proyecto-Progra.git.\n\n";
				}


			} while (submenu != 2);
			break;

		case 2:
			SubmenuMatenimiento();
			break;

		case 3:
			Matricular();
			break;

		case 4:

			consulta();

			break;
		}
	} while (menu != 0);
	cout << "Gracias por usar el sistema de matricula de la UNA\n";
	cout << "https://github.com/GeovannnyMS/Proyecto-Progra.git";
}
