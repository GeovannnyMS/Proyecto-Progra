#include "cursos.h"

Cursos::Cursos()
{
	for (int i = 0; i < Max_Cursos; i++) {
		nombresCursos[i] = "";
		NCR[i] = "";
		Creditos[i] = 0;
		NombreProfe[i] = "";
		PrimerApellidoProfe[i] = "";
		SegundoApellidoProfe[i] = "";
		costoCreditos[i] = 0;
	}
	contador_Cursos = 0;
}

string Cursos::getcurso(int i)
{
	return nombresCursos[i];
}
string Cursos::getNCR(int i)
{
	return NCR[i];
}
string Cursos::getNomProfe(int i)
{
	return NombreProfe[i];
}
string Cursos::getApe1Profe(int i)
{
	return PrimerApellidoProfe[i];
}
string Cursos::getApe2Profe(int i)
{
	return SegundoApellidoProfe[i];
}
int Cursos::getcreditos(int i)
{
	return Creditos[i];
}
int Cursos::getcontador()
{
	return contador_Cursos;
}
void Cursos::RegistrarCurso()
{
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
	cin >> PrimerApellidoProfe[contador_Cursos];
	cout << "\nIngrese el segundo apellido del profesor: ";
	cin >> SegundoApellidoProfe[contador_Cursos];

	costoCreditos[contador_Cursos] = Creditos[contador_Cursos] * 1000;

	contador_Cursos++;
	cout << endl;
	cout << "Curso registrado\n";
}

void Cursos::MostrarCurso()
{
	if (contador_Cursos == 0) {
		cout << "No hay cursos registrados\n";
		return;
	}
	cout << "\nCursos registrados\n";
	for (int i = 0; i < contador_Cursos; i++) {
		cout << i + 1 << " Curso: " << nombresCursos[i] << " || NCR del curso: " << NCR[i] << " || Creditos del curso: " << Creditos[i] << endl;
		cout << "============================================================\n";
	}
}

void Cursos::consultas()
{
	if (contador_Cursos <= 0) {
		cout << "No hay cusos registrados\n";
		return;
	}
	cout << "\nCursos registrados\n";
	for (int i = 0; i < contador_Cursos; i++) {
		cout << i + 1 << " Curso: " << nombresCursos[i] << " || NCR del curso: " << NCR[i] << " || Creditos del curso: " << Creditos[i] << endl;
		cout << "Profesor asignado: " << NombreProfe[i] << " " << PrimerApellidoProfe[i] << " " << SegundoApellidoProfe[i] << endl;
		cout << "============================================================\n";
	}
}


int Cursos::getcosto(int i)
{
	return costoCreditos[i];
}