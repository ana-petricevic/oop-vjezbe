#include <iostream>
#include <string>

struct Student
{
	std::string ime;
	std::string JMBAG;
	int godina;
	int ECTS;
	double prosjek;
};

void filter_students(Student s[], int n, void (*action) (Student&), bool (*cond)(const Student&))
{
	for (int i = 0; i < n; i++)
	{
		if (cond(s[i]))
		{
			action(s[i]);
		}
	}
}
void print_student(Student& s)
{
	std::cout << s.ime << " " << s.JMBAG << " " << s.godina << " " << s.ECTS << " " << s.prosjek << std::endl;
}

void increase_year(Student& s)
{
	s.godina++;
}

int main()
{
	Student studenti[] =
	{
		{"Ana", "001", 1, 30, 3.8},
		{"Ivan", "002", 1, 0 , 4.2},
		{"Marko", "003", 2, 50, 3.2},
		{"Iva", "009", 3, 46, 4.9},
		{"Toni", "007", 1, 20, 2.7}
	};
	int n = 5;


	std::cout << "Filtriranje studenata koji su prva godina i imaju barem 1 polozen kolegij" << std::endl;
	filter_students(studenti, n, print_student, [](const Student& s)
		{
			return s.godina == 1 && s.ECTS > 0;
		}
	);

	std::cout << "Filtriranje studenata koji imaju prosjek veci od 3.5: " << std::endl;
	filter_students(studenti, n, print_student, [](const Student& s)
		{
			return s.prosjek > 3.5;
		}
	);

	std::cout << "Povecana godina za 1 ako su studenti ostvarili barem 45 ECTS" << std::endl;
	filter_students(studenti, n, increase_year, [](const Student& s)
		{
			return s.ECTS >= 45;
		}
	);

	std::cout << "Ispis studenata nakon sta je povecana godina: " << std::endl;
	for (int i = 0; i < n; i++)
	{
		print_student(studenti[i]);
	}
	return 0;


}