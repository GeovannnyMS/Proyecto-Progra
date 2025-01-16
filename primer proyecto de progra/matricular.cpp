#include "matricular.h"

Matricular::Matricular()
{

	for (int i = 0; i < Max_Cursos; i++) {
		for (int x = 0; x < Max_Cursos; x++) {
			ProfeMatriculaN[i][x] = "";
			ProfeMatricula1A[i][x] = "";
			ProfeMatricula2Ape[i][x] = "";
			salon[i][x] = "";
			matricula[i][x] = "";
			diaclases[i][x] = "";
			entrada[i][x] = "";
			salida[i][x] = "";
			ncrmatricula[i][x] = "";
			horario[i][x] = 0;
			creditosMatricula[i][x] = 0;
		}
		total[i] = 0;
		ContadorMatricula[i] = { 0 };
	}
}

void Matricular::matricular(Cursos& curso, estudiantes& estudiante, HorariosClases& hora)
{
	int eleccionE = 0;
	int seleccion = 0;
	int menu = 0;
	int alumnos = estudiante.getContadorE();
	int contador = curso.getcontador();
	int mañamaotarde[Max_Cursos] = { 0 };

	if (alumnos == 0 || contador == 0) {
		cout << "No hay cursos o estudiantes registrados\n";
		return;
	}
	cout << "\nRegistro de matricula\n";

	for (int i = 0; i < alumnos; i++) {
		cout << "Estudiante " << i + 1 << ": " << estudiante.getcedula(i) << " || " << estudiante.getnombres(i) << "  " << estudiante.getapellido(i) << "  " << estudiante.getapellido2(i) << " || " << estudiante.getcarrera(i) << endl;
	}
	cout << "\nQue estudiante desea matricular cursos?: ";
	cin >> eleccionE;
	cout << endl;
	eleccionE--;

	mañamaotarde[seleccion] = hora.getMañanaOTarde(seleccion);

	if (eleccionE < 0 || eleccionE >= alumnos) {
		cout << "Estudiante invalido\n";
		return;
	}

	do
	{

		cout << "Que curso quiere matricular\n";
		curso.MostrarCurso();
		cout << "\nQue curso quieres seleccionar?: ";
		cin >> seleccion;
		cout << endl;
		seleccion--;
		if (seleccion <= 0 || seleccion >= contador) {
			cout << "Curso invalido\n";
			return;
		}

		for (int i = 0; i < contador; i++) {
			if (curso.getcurso(seleccion) == matricula[eleccionE][i]) {
				cout << "Este curso ya esta matriculado\n";
				return;
			}
			if (hora.getdias(seleccion) == diaclases[eleccionE][i]) {
				if (hora.getMañanaOTarde(seleccion) == horario[eleccionE][i]) {
					cout << "Este curso choca en horario con otro\n";
					return;
				}
			}
		}
		matricula[eleccionE][ContadorMatricula[eleccionE]] = curso.getcurso(seleccion);
		ncrmatricula[eleccionE][ContadorMatricula[eleccionE]] = curso.getNCR(seleccion);
		creditosMatricula[eleccionE][ContadorMatricula[eleccionE]] = curso.getcreditos(seleccion);
		ProfeMatriculaN[eleccionE][ContadorMatricula[eleccionE]] = curso.getNomProfe(seleccion);
		ProfeMatricula1A[eleccionE][ContadorMatricula[eleccionE]] = curso.getApe1Profe(seleccion);
		ProfeMatricula2Ape[eleccionE][ContadorMatricula[eleccionE]] = curso.getApe2Profe(seleccion);

		salon[eleccionE][ContadorMatricula[eleccionE]] = hora.getAula(seleccion);
		diaclases[eleccionE][ContadorMatricula[eleccionE]] = hora.getdias(seleccion);
		horario[eleccionE][ContadorMatricula[eleccionE]] = hora.getMañanaOTarde(seleccion);
		entrada[eleccionE][ContadorMatricula[eleccionE]] = hora.getentrada(seleccion);
		salida[eleccionE][ContadorMatricula[eleccionE]] = hora.getsalida(seleccion);

		ContadorMatricula[eleccionE]++;


		total[eleccionE] += curso.getcosto(seleccion);

		cout << "\nEl estudiante debe pagar " << total[eleccionE] << " con base a los cursos que ha matriculado\n\n";

		cout << "Quieres matricular otro curso?\n1 = Si\n0 = No\n";
		cin >> menu;

		if (menu < 0 || menu >= 2) {
			do
			{
				cout << "\nOpcion no valida\n Por favor elija otra: ";
				cin >> menu;
			} while (menu < 0 || menu >= 2);
		}

	} while (menu != 0);





}

void Matricular::VerInformacionEstidiante(Cursos& curso, estudiantes& estudiante)
{
	int estudiantes = estudiante.getContadorE();

	if (estudiantes < 0) {
		cout << "No hay estudiantes registrados\n";
		return;
	}
	cout << "Estudiantes registrados\n";
	for (int i = 0; i < estudiantes; i++) {
		cout << estudiante.getcedula(i) << " || " << estudiante.getnombres(i) << " " << estudiante.getapellido(i) << " " << estudiante.getapellido2(i) << " || Carrera: " << estudiante.getcarrera(i) << " || level: " << estudiante.getNivel(i) << endl;

		if (ContadorMatricula[i] == 0) {
			cout << "El estudiante no ha matriculado ningun curso\n";
			return;
		}
		cout << "\nCursos matriculados\n\n";

		for (int x = 0; x < ContadorMatricula[i]; x++) {

			cout << "=============================================================================\n\n";
			cout << "Curso matriculado " << matricula[i][x] << " || NCR  del curso: " << ncrmatricula[i][x] << " || creditos del curso: " << creditosMatricula[i][x] << endl;
			cout << "dia de la clase: " << diaclases[i][x] << " || hora de entrada: " << entrada[i][x] << " || hora de salida: " << salida[i][x] << endl;
			cout << "aula de clases: " << salon[i][x] << endl;
			cout << "Profesor aignado: " << ProfeMatriculaN[i][x] << " " << ProfeMatricula1A[i][x] << " " << ProfeMatricula2Ape[i][x] << endl;
			cout << "=============================================================================\n\n";
		}
		cout << "=================================================================\n";
	}
}
