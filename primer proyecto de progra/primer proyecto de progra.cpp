#include <iostream>
using namespace std;

#define Estudiantes 10
#define	Max_Cursos 10

string Nombres_estudiante[Estudiantes];
string Primer_apellido_estudiante[Estudiantes];
string Segundo_apellido_estudiante[Estudiantes];

string NombreProfe[Max_Cursos];
string PimerApellidoProfe[Max_Cursos];
string SegundoApellidoProfe[Max_Cursos];

string dias[Max_Cursos];
string Aunla[Max_Cursos];
string Carrera[Estudiantes];
string Cedulas[Estudiantes];
string nombresCursos[Max_Cursos];
string matricula[Max_Cursos][Max_Cursos];

char NCR[Max_Cursos][20];

int HorasEntrada[Max_Cursos];
int HorasSalida[Max_Cursos];
int Creditos[Max_Cursos];
int contador_estudiaes = 0;
int contador_Cursos = 0;
int contadorHorarios = 0;
int costoCreditos [Max_Cursos];
int total[Max_Cursos];


void RegistroEsrudiantes() {
	int seleccion  = 0 ;
	if (contador_estudiaes >= Estudiantes) {
		cout << "\nSorry we can't rewrite it at this time\n";
		return;
	}
	cout << "Enter your name: ";
	cin >> Nombres_estudiante[contador_estudiaes];

	cout << "\nEnter your first last name: ";
	cin >> Primer_apellido_estudiante[contador_estudiaes];

	cout << "\nEnter yout second last name: ";
	cin >> Segundo_apellido_estudiante[contador_estudiaes];

	cout << "\nEnter your ID: ";
	cin >> Cedulas[contador_estudiaes];

	for (int i = 0; i < contador_estudiaes; i++) {
			if (Cedulas[i] == Cedulas[i + 1]) {
				cout << "This student is already registered\n";
				return;
			}

		
	}

	cout << "\nchoose the career\n";
	cout << "1 = Systems engineering\n2 = English learning\n3 = topography\n4 = administration\nenter the number: ";
	cin >> seleccion;
	switch (seleccion)
	{
	case 1:
		Carrera[contador_estudiaes] = "Systems engineering";
		break;
	case 2:
		Carrera[contador_estudiaes] = "English learning";
		break;
	case 3:
		Carrera[contador_estudiaes] = "topography";
		break;
	case 4:
		Carrera[contador_estudiaes] = "administration";
		break;
	}
	

	cout << endl;
	contador_estudiaes++;
	cout << "Registered student\n\n";

}

void RegistroCursos() {
	if (contador_Cursos >= Max_Cursos) {
		cout << "Cannot add that course\n";
		return;
	}

		cout << "Enter the name of the course with the following format\n(Example: Matematica_Para_informatica): ";
		cin >> nombresCursos[contador_Cursos];
		cout << "\nenter the NCR of the course: ";
		cin >> NCR[contador_Cursos];
		cout << "\nenter course credits: ";
		cin >> Creditos[contador_Cursos];
		cout << "\nenter the classroom: ";
		cin >> Aunla[contador_Cursos];
		cout << "\nEnter the teacher's name: ";
		cin >> NombreProfe[contador_Cursos];
		cout << "\nenter the teacher's first last name: ";
		cin >> PimerApellidoProfe[contador_Cursos];
		cout << "\nEnter the teacher's second las name: ";
		cin >> SegundoApellidoProfe[contador_Cursos];

		costoCreditos[contador_Cursos] = Creditos[contador_Cursos] * 1000;


		contador_Cursos++;
		cout << endl;
		cout << "added course\n";

}

void RegistroHorarios() {

	if (contador_Cursos == 0) {
		cout << "There are no registered courses\n";
	}

	int aux;
	cout << "enter the position to which you want to add the time (1 a " << contador_Cursos << "): ";
	for (int i = 0; i < contador_Cursos; i++) {
		cout << NCR[i] << "|" << nombresCursos[i] << "|" << Creditos[i] << "|" << NombreProfe[i] << " " << PimerApellidoProfe[i] << " " << SegundoApellidoProfe[i] << endl;
	}
	cin >> aux;
	aux--;
	if (aux < 0 || aux >= contador_Cursos) {
		cout << "invalid course\n";
		return;
	}
	cout << "enter the day: ";
	cin >> dias[aux];
	cout << "\nenter the time: ";
	cin >> HorasEntrada[aux];
	if (HorasEntrada[aux] > 12) {
		cout << "that time does not exist\n";
		return;
	}
	cout << "\nenter departure time: ";
	cin >> HorasSalida[aux];
	if (HorasSalida[aux] > 60) {
		cout << "that time does not exist\n";
		return;
	}
	cout << "\nenter the classroom: ";
	cin >> Aunla[aux];
	cout << endl;
	cout << "recorded time\n";

}

void SubmenuMatenimiento() {
	int submenu = 0;
	do
	{
		cout << "what do you need\n\n1 = students\n2 = course\n3 = schedules\n4 = back\n";
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
	int contador = 0;
	
	if (contador_estudiaes == 0 || contador_Cursos == 0) {
		cout << "no students or courses registered\n";
		return;
	}
	cout << "\nregistered students\n";

	for (int i = 0; i < contador_estudiaes; i++) {
		cout << i + 1 << " = " << Cedulas[i] << " || " << Nombres_estudiante[i] << "  " << Primer_apellido_estudiante[i] << "  " << Segundo_apellido_estudiante[i] << " " << Carrera[i] << endl;
	}
	cout << "\nWhich student would you like to enroll?: ";
	cin >> eleccionE;
	cout << endl;
	eleccionE--;
	if (eleccionE < 0 || eleccionE >= contador_estudiaes) {
		cout << "invalid student\n";
		return;
	}
	do
	{
	

		cout << "What course are you going to enroll in?\n";
		for (int i = 0; i < contador_Cursos; i++) {
			cout << "course " << i + 1 << " || " << NCR[i] << " || " << nombresCursos[i] << endl;
		}
		cout << "\nWhich course do you want to select?: ";
		cin >> seleccion;
		cout << endl;
		seleccion--;

		for (int i = 0; i < contador_Cursos; i++) {
			if (nombresCursos[seleccion] == matricula[eleccionE][i]) {

				cout << "This course is already registered\n";
				return;
			}
		
		}
		matricula[eleccionE][contador] = nombresCursos[seleccion];
		contador++;
		total[eleccionE] += costoCreditos[seleccion];

		cout << "Do you want to enroll in more courses?\n1 = Yes\n0 = No\n";
		cin >> menu;
		
	} while (menu != 0 );

	cout << "the student has to pay " << total[eleccionE] << " based on the number of credits enrolled\n\n";
}

void VerEstudiantes() {

	if (contador_estudiaes < 0) {
		cout << "there are no registered students\n";
		return;
	}
	cout << "enrolled students\n";
	for (int i = 0; i < contador_estudiaes; i++) {
		cout <<  "registered courses " << i + 1 << " = " << Cedulas[i] << " || " << Nombres_estudiante[i] << " " << Primer_apellido_estudiante[i] << " " << Segundo_apellido_estudiante[i] << " || " << Carrera[i] << endl;
	}

}
void VerCursos() {
	if (contador_Cursos == 0) {
		cout << "there are no registered courses\n";
		return;
	}
	cout << "registered courses\n";
	for (int i = 0; i < contador_Cursos; i++) {
		cout << "course " << i + 1 << NCR[i] << " || " << Creditos[i] << " || " << nombresCursos[i] << endl;
	}
}

void consulta() {
	int menu = 0;
	do
	{
		cout << "what you want to consult\n1 = students\n2 = courses\n3 = back\n";
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
	char menu;
	int submenu = 0;
	do
	{
		cout << "Welcome to the UNA registration platform\nA = Archive\nB = Maintenance\nC = Tuition\nD = Consultation\nE = Exit\n";
		cin >> menu;

		switch (menu)
		{

		case 'A':
			do
			{

				cout << "what do you need\n1 = About\n2 = Exit\n";
				cin >> submenu;
				if (submenu == 1) {
					cout << "\nProgram developer: Geovany Morales Sanchez (Yio)\nID: 604910543\nCareer: Information systems engineering\n\nYio is a very lazy person, it is very difficult for him to feel like doing something but the moment he encounters an exciting challenge his motivation shoots up to the sky and he does not stop studying and trying until he understands it and can assimilate it, that It causes Yio's actions to be labeled as plagiarism because no one has been able to notice that ability to improve silently.\n\n";
				}


			} while (submenu != 2);
			break;

		case 'B':
			SubmenuMatenimiento();
			break;

		case 'C':
			Matricular();
			break;

		case 'D':

			consulta();

			break;
		}
	} while (menu != 'E');
	cout << "Thank you for using the UNA registration systems";
}
