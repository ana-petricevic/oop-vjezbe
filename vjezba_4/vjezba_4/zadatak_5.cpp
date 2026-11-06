#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

struct Student {
	std::string jmbag;
	std::string surname;
	int points;
};
int main()
{
	std::vector<Student> registered = {
	{"0302", "Kovac", 78}, {"0117", "Babic", 45},
	{"0255", "Maric", 91}, {"0117", "Babic", 45},
	{"0410", "Novak", 78}, {"0089", "Juric", 62},
	{"0255", "Maric", 91}, {"0520", "Maric", 55},
	{"0333", "Peric", 30} 
	};

	std::sort(registered.begin(), registered.end(), [](const Student& a, const Student& b)
		{
			return a.jmbag < b.jmbag;
		});

	registered.erase(std::unique(registered.begin(), registered.end(), [](const Student& a, const Student& b)
		{
			return a.jmbag == b.jmbag;
		}), registered.end()
			);

	std::cout << "Broj prijavljenih studenata: " << registered.size() << std::endl;

	int prag;
	std::cout << "Unesite prag bodova: ";
	std::cin >> prag;

	registered.erase(std::remove_if(registered.begin(), registered.end(), [prag](const Student& s)
		{
			return s.points < prag;
		}), registered.end()
			);

	std::sort(registered.begin(), registered.end(), [](const Student& a, const Student& b)
		{
			if (a.points != b.points)
			{
				return a.points > b.points;
			}
			return a.surname < b.surname;
		});

	std::cout << "Rang lista: " << std::endl;

	for (std::size_t i = 0; i < registered.size(); i++)
	{
		std::cout << i + 1 << "." << registered[i].surname << ", " << registered[i].jmbag << ", " << registered[i].points << std::endl;

	}
	return 0;
}