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

char Cedulas[Estudiantes][50];
char Carrera[Estudiantes][50];
char nombresCursos[Max_Cursos][50];
char NCR[Max_Cursos][20];
char Creditos[Max_Cursos];

int contador_estudiaes = 0;
int contador_Cursos = 0;

string dias[Max_Cursos];
string HorasEntrada[Max_Cursos];
string HorasSalida[Max_Cursos];
string Aunla[Max_Cursos];


void RegistroEsrudiantes() {
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

	cout << "\nEnter your career with the following format\n(Example: ingenieria_en_sistemas_de_informacion): ";
	cin >> Carrera[contador_estudiaes];
	cout << endl;
	contador_estudiaes++;
	cout << "Registered student\n\n";

}

void RegistroCursos() {
	if (contador_Cursos >= Max_Cursos) {
		cout << "Cannot add that course\n";
		return;
	}

		cout << "Enter the name of the course with the following format\n(Example: Ingenieria_En_Sistemas_De_Informacion): ";
		cin >> nombresCursos[contador_Cursos];
		cout << "\nenter the NCR of the course: ";
		cin >> NCR[contador_Cursos];
		cout << "\nenter course credits: ";
		cin >> Creditos[contador_Cursos];
		cout << "\nEnter the teacher's name: ";
		cin >> NombreProfe[contador_Cursos];
		cout << "\nenter the teacher's first last name: ";
		cin >> PimerApellidoProfe[contador_Cursos];
		cout << "\nEnter the teacher's second las name: ";
		cin >> SegundoApellidoProfe[contador_Cursos];

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
	cout << "\nenter departure time: ";
	cin >> HorasSalida[aux];


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
			break;

		case 'D':
			break;


		}
	} while (menu != 'E');
	cout << "Thank you for using the UNA registration systems";
}
